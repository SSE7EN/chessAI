/**
 **************************
 * @file    aIEngine.cpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple ai engine implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include "aIEngine.hpp"
#include "../board/board.hpp"
#include "../board/piece.hpp"
#include "../util/move.hpp"
#include "../board/spot.hpp"
#include "../util/mempool.hpp"

#include <bits/stdc++.h> 
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

const int EXACT = 100;
const int UUPPERBOUND = 100000;
const int LOWERBOUND = -100000;

unordered_map<unsigned long long int, ttEntry*> AIEngine::TranspositionMap; 

unsigned long long int ZobristHashing::ZobristTable[8][8][12];
mt19937 mt(01234567); 

void AIEngine::initializeEngine(){
    TranspositionMap.reserve(sizeof(ttEntry*) * 1000000);
}

// Generates a Randome number from 0 to 2^64-1 
unsigned long long int ZobristHashing::randomInt() 
{ 
    uniform_int_distribution<unsigned long long int> 
                                 dist(0, UINT64_MAX); 
    return dist(mt); 
} 

int ZobristHashing::indexOf(Piece* piece){
    if(piece != nullptr){
        if (piece->getColor() == Color::WHITE){
            if (piece->getPieceCode()==PieceCode::PAWN) 
                return 0; 
            if (piece->getPieceCode()==PieceCode::KNIGHT) 
                return 1; 
            if (piece->getPieceCode()==PieceCode::BISHOP) 
                return 2; 
            if (piece->getPieceCode()==PieceCode::ROOK) 
                return 3; 
            if (piece->getPieceCode()==PieceCode::QUEEN) 
                return 4; 
            if (piece->getPieceCode()==PieceCode::KING) 
                return 5;
        }
        else{
            if (piece->getPieceCode()==PieceCode::PAWN) 
                return 6; 
            if (piece->getPieceCode()==PieceCode::KNIGHT) 
                return 7; 
            if (piece->getPieceCode()==PieceCode::BISHOP) 
                return 8; 
            if (piece->getPieceCode()==PieceCode::ROOK) 
                return 9; 
            if (piece->getPieceCode()==PieceCode::QUEEN) 
                return 10; 
            if (piece->getPieceCode()==PieceCode::KING) 
                return 11;
        } 
    }
    else return -1;

}

// Initializes the table 
void ZobristHashing::initTable() 
{ 
    for (int i = 0; i<8; i++) 
      for (int j = 0; j<8; j++) 
        for (int k = 0; k<12; k++) 
          ZobristHashing::ZobristTable[i][j][k] = randomInt(); 
}

unsigned long long int ZobristHashing::computeHash(Board *board) 
{ 
    unsigned long long int h = 0; 
    for (int i = 0; i<8; i++) 
    { 
        for (int j = 0; j<8; j++) 
        { 
            if(board->getSpot(i,j)->getPiece() != nullptr) 
            { 
                int piece = indexOf(board->getSpot(i,j)->getPiece()); 
                h ^= ZobristTable[i][j][piece]; 
            } 
        } 
    } 
    return h; 
} 

ttEntry* AIEngine::transpositionMapLookUp(Board* board){
    ttEntry* ttentry = nullptr;
    unsigned long long int hash = ZobristHashing::computeHash(board);

    auto temp = AIEngine::TranspositionMap.find(hash);
    if( temp != AIEngine::TranspositionMap.end()){
        ttentry = temp->second;
    }
    return ttentry;


}

void AIEngine::transpositionTableStore(Board *board, ttEntry *entry){
    unsigned long long int hash = ZobristHashing::computeHash(board);
    AIEngine::TranspositionMap.insert({hash, entry});
}

int AIEngine::piceSetValue(PieceSet &piceSet){
    int value = 0;
    for(Piece* p : piceSet.getPieceList()){
        if(!p->isKilled()){
            value += p->getValue();
        }
    }

    return value;
}

int AIEngine::evaluate(Board* board, Color color){
    PieceSet *aiSet = board->getPieceSetByColor(color);
    PieceSet *oponentSet = board->getOponetPieces(color);

    return AIEngine::piceSetValue(*aiSet) - AIEngine::piceSetValue(*oponentSet);

}

AIEngineMove::AIEngineMove(MoveType mt){
    if(mt == MoveType::MAX) value = MAX_VALUE;
    else value = MIN_VALUE;
}


int AIEngine::maxMove(Board *board, int depth, Color color){
    int check = 0;
    int check2 = 1;
    if(depth >= DEPTH_LIMIT ){
        return evaluate(board, color);
    }

    int maxValue = MAX_VALUE;
    PieceSet *plays = board->getPlaysPieceSet();

    for(Piece* piece: plays->getPieceList()){
        if(piece->isKilled()) continue;
        for(Spot *spot: piece->getPossibleMoves()){
            Move *mv = new Move(piece, piece->getSpot(), spot);
            if(board->executeMove(mv)){
                maxValue = max(maxValue, minMove(board, depth+1, color));
                board->undoMove(mv);
                delete mv;
            }
        }
    }

    return maxValue;
}

int AIEngine::minMove(Board *board, int depth, Color color){

    int check = 0;
    int check2 = 1;
    if(depth >= DEPTH_LIMIT){
        return evaluate(board, color);
    }

    int minValue = MIN_VALUE;
    PieceSet *plays = board->getPlaysPieceSet();

    for(Piece* piece: plays->getPieceList()){
        if(piece->isKilled()) continue;
        for(Spot *spot: piece->getPossibleMoves()){
            Move *mv = new Move(piece, piece->getSpot(), spot);
            if(board->executeMove(mv)){
                minValue = min(minValue, maxMove(board, depth+1, color));
                board->undoMove(mv);
                delete mv;
            }
        }
    }
    return minValue;
};

/*
AIEngineMove* AIEngine::minMax(Board *board, int depth, Color color){
    AIEngineMove* aiEngineMove = new AIEngineMove(MoveType::MAX);
    PieceSet *plays = board->getPlaysPieceSet();
    int tValue = 0;

    for(Piece* piece: plays->getPieceList()){
        if(piece->isKilled()) continue;
        for(Spot *spot: piece->getPossibleMoves()){
            
            //Spot cannot be nullptr
            if(spot == nullptr) continue;

            Move *mv = new Move(piece, piece->getSpot(), spot);
            if(board->executeMove(mv)){
                board->display();
                tValue = minMove(board, depth+1, color);
                if(tValue > aiEngineMove->getValue()){
                    aiEngineMove->setMove(mv);
                    aiEngineMove->setValue(tValue);
                    board->undoMove(mv);
                }
                else{
                    board->undoMove(mv);
                    delete mv;
                }
            }
        }
    }

    return aiEngineMove;
};
*/

/*
AIEngineMove* AIEngine::minMax(Board *board, int depth, Color color, bool maximizing){
    

    if(depth == 0){

        AIEngineMove* aiEngine = new AIEngineMove(AIEngine::evaluate(board, color));
        return aiEngine;
    };

    AIEngineMove* aiEngineMove = nullptr;
    PieceSet *plays = board->getPlaysPieceSet();

    if(maximizing){
        

        for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                
                Move *mv = new Move(piece, piece->getSpot(), spot);
                if(board->executeMove(mv)){

                    AIEngineMove* tValue = minMax(board, depth-1, color, false);
                    if(aiEngineMove == nullptr || aiEngineMove->getValue() < tValue->getValue()){
                        if(aiEngineMove !=nullptr) delete aiEngineMove;
                        aiEngineMove = tValue;
                        aiEngineMove->setMove(mv);
                        board->undoMove(mv);
                    }
                    else{
                        board->undoMove(mv);
                        delete tValue;
                        delete mv;
                    }
                }   
            }
        }
    }
    else{
         for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                
                Move *mv = new Move(piece, piece->getSpot(), spot);
                if(board->executeMove(mv)){

                    AIEngineMove* tValue = minMax(board, depth-1, color, true);
                    if(aiEngineMove == nullptr || aiEngineMove->getValue() > tValue->getValue()){
                        if(aiEngineMove !=nullptr) delete aiEngineMove;
                        aiEngineMove = tValue;
                        aiEngineMove->setMove(mv);
                        board->undoMove(mv);
                    }
                    else{
                        board->undoMove(mv);
                        delete tValue;
                        delete mv;
                    }
                }   
            }
        }
    }

    return aiEngineMove;

}
*/



//minimax with alpha beta pruning and TT
int AIEngine::minmax(Board *board, int depth, Color color, int alpha, int beta,bool maximizing){
    
    //transposition table
    ttEntry* _ttEntry = nullptr;
    _ttEntry = AIEngine::transpositionMapLookUp(board);
    if(_ttEntry != nullptr && _ttEntry->depth >= depth){
        if (_ttEntry->flag == EXACT ) return _ttEntry->value;
        else if(_ttEntry->flag == LOWERBOUND) alpha = max(alpha, _ttEntry->value);
        else if (_ttEntry->flag == UUPPERBOUND) beta = min(beta, _ttEntry->value);

        if(alpha >= beta) return _ttEntry->value;
    }

    if(depth == 0){        
        return AIEngine::evaluate(board, color);
    };

    PieceSet *plays = board->getPlaysPieceSet();
    

    if(maximizing){
        int maxValue = MAX_VALUE;

        for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                
                Move *mv = new Move(piece, piece->getSpot(), spot);
                if(board->executeMove(mv)){
                    int tValue = minmax(board, depth-1, color,alpha, beta, false);
                    maxValue =max(maxValue, tValue);
                    alpha = max(alpha, tValue);
                    board->undoMove(mv);
                    delete mv;   
                    if(beta <= alpha) break;
                }
                
            }
        }

        _ttEntry = new ttEntry;
        _ttEntry->value = maxValue;
        if(maxValue <= alpha) _ttEntry->flag = UUPPERBOUND;
        else if(maxValue > beta) _ttEntry->flag = LOWERBOUND;
        else _ttEntry->flag = EXACT;
        _ttEntry->depth = depth;

        AIEngine::transpositionTableStore(board, _ttEntry);

        return maxValue;
    }
    else{
        int minValue = MIN_VALUE;
        for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                
                Move *mv = new Move(piece, piece->getSpot(), spot);
                if(board->executeMove(mv)){
                    int tValue = minmax(board, depth-1, color,alpha,beta, true);
                    minValue =min(minValue, tValue);
                    beta = min(beta, tValue);
                    board->undoMove(mv);
                    delete mv;
                    if(beta <= alpha) break;

                }
                
            }
        }


        _ttEntry = new ttEntry;
        _ttEntry->value = minValue;
        if(minValue <= alpha) _ttEntry->flag = UUPPERBOUND;
        else if(minValue > beta) _ttEntry->flag = LOWERBOUND;
        else _ttEntry->flag = EXACT;
        _ttEntry->depth = depth;

        AIEngine::transpositionTableStore(board, _ttEntry);

        return minValue;
    }


}


std::chrono::microseconds durationTMLU;
std::chrono::microseconds duration2;
std::chrono::microseconds duration3;
MempoolManager<Move> AIEngine::moveMempool;
//minimax with alpha beta pruning and TT
int AIEngine::minmax2(Board *board, int depth, Color color, int alpha, int beta,bool maximizing){
    auto start3 = high_resolution_clock::now();
    //transposition table
    ttEntry* _ttEntry = nullptr;
    auto start = high_resolution_clock::now();
    _ttEntry = AIEngine::transpositionMapLookUp(board);
    auto stop = high_resolution_clock::now(); 
    durationTMLU += duration_cast<microseconds>(stop - start);

    if(_ttEntry != nullptr && _ttEntry->depth >= depth){
        if (_ttEntry->flag == EXACT ) return _ttEntry->value;
        else if(_ttEntry->flag == LOWERBOUND) alpha = max(alpha, _ttEntry->value);
        else if (_ttEntry->flag == UUPPERBOUND) beta = min(beta, _ttEntry->value);

        if(alpha >= beta) return _ttEntry->value;
    }

    if(depth == 0){        
        return AIEngine::evaluate(board, color);
    };

    PieceSet *plays = board->getPlaysPieceSet();
    

    if(maximizing){
        int maxValue = MAX_VALUE;
        
        for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                auto start = high_resolution_clock::now();
                mempoolBlockS<Move> *mvBlock = moveMempool.allocateBlock(Move(piece, piece->getSpot(), spot));
                Move *mv = &(mvBlock->data);
                auto stop = high_resolution_clock::now(); 
                duration2 += duration_cast<microseconds>(stop - start);
                if(board->executeMoveMinmax(mv)){
                    int tValue = minmax2(board, depth-1, color,alpha, beta, false);
                    auto start = high_resolution_clock::now();
                    maxValue =max(maxValue, tValue);
                    alpha = max(alpha, tValue);
   //                 board->display();
                    board->undoMove(mv);
     //               board->display();
                    moveMempool.freeBlock(mvBlock);
                    auto stop = high_resolution_clock::now(); 
                    duration2 += duration_cast<microseconds>(stop - start);
                    if(beta <= alpha) break;
                }
                else moveMempool.freeBlock(mvBlock);
                
            }
        }
        auto start = high_resolution_clock::now();
        _ttEntry = new ttEntry;
        _ttEntry->value = maxValue;
        if(maxValue <= alpha) _ttEntry->flag = UUPPERBOUND;
        else if(maxValue > beta) _ttEntry->flag = LOWERBOUND;
        else _ttEntry->flag = EXACT;
        _ttEntry->depth = depth;
        auto stop = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop - start);

        
        start = high_resolution_clock::now();
        AIEngine::transpositionTableStore(board, _ttEntry);
        stop = high_resolution_clock::now(); 
        durationTMLU += duration_cast<microseconds>(stop - start);
        return maxValue;
    }
    else{

        int minValue = MIN_VALUE;
        for(Piece* piece: plays->getPieceList()){
            if(piece->isKilled()) continue;
            for(Spot *spot: piece->getPossibleMoves()){
                auto start = high_resolution_clock::now();
                mempoolBlockS<Move> *mvBlock = moveMempool.allocateBlock(Move(piece, piece->getSpot(), spot));
                Move *mv = &(mvBlock->data);
                auto stop = high_resolution_clock::now(); 
                duration2 += duration_cast<microseconds>(stop - start);
                if(board->executeMoveMinmax(mv)){
                    int tValue = minmax2(board, depth-1, color,alpha,beta, true);
                    auto start = high_resolution_clock::now();
                    minValue =min(minValue, tValue);
                    beta = min(beta, tValue);
  //                  board->display();
                    board->undoMove(mv);
  //                  board->display();

                    moveMempool.freeBlock(mvBlock);
                    auto stop = high_resolution_clock::now(); 
                    duration2 += duration_cast<microseconds>(stop - start);
                    if(beta <= alpha) break;

                }
                else moveMempool.freeBlock(mvBlock);
                
            }
        }

        start = high_resolution_clock::now();
        _ttEntry = new ttEntry;
        _ttEntry->value = minValue;
        if(minValue <= alpha) _ttEntry->flag = UUPPERBOUND;
        else if(minValue > beta) _ttEntry->flag = LOWERBOUND;
        else _ttEntry->flag = EXACT;
        _ttEntry->depth = depth;
        stop = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop - start);
        start = high_resolution_clock::now();
        AIEngine::transpositionTableStore(board, _ttEntry);
        stop = high_resolution_clock::now(); 
        durationTMLU += duration_cast<microseconds>(stop - start);


        auto stop3 = high_resolution_clock::now(); 
        duration3+= duration_cast<microseconds>(stop3 - start3);
        return minValue;
    }


}

Move* AIEngine::aIMove(int depth,Board *board, Color color){
    
    int maxValue = MAX_VALUE;
    Move *move = nullptr;
    auto start = high_resolution_clock::now(); 
    PieceSet *plays = board->getPlaysPieceSet();

    for(Piece* piece: plays->getPieceList()){
        if(piece->isKilled()) continue;
        for(Spot *spot: piece->getPossibleMoves()){
            Move *mv = new Move(piece, piece->getSpot(), spot);
            if(board->executeMove(mv)){
                
 //               int tValue = minmax(board, depth-1, color, MAX_VALUE, MIN_VALUE,false);
                int tValue = minmax2(board, depth-1, color, MAX_VALUE, MIN_VALUE,false);
                board->undoMove(mv);

                if(maxValue < tValue){
                    maxValue = tValue;
                    if(move != nullptr){
                        delete move;
                    }
                    move = mv;
                }
                else delete mv;
                
            }
        }
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<"Total time: "<<duration.count()<<endl;
    cout<<"TT time: "<<durationTMLU.count()<<endl;
    cout<<"PieceSet time: "<<PieceSet::durationGetSpot.count()<<endl;
    cout<<"Board execute: "<<Board::durationExecuteMove.count()<<endl;
    cout<<"duration2 time: "<<duration2.count()<<endl;
    cout<<"duration3 time: "<<duration3.count()<<endl;

    return move;
};
