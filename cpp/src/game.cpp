/**
 **************************
 * @file    game.cpp
 * @author  SE7EN
 * @date    2022-11-10
 * @brief   simple chess game implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */
#include "./board/board.hpp"
#include "./board/piece.hpp"
#include "game.hpp"
#include "./board/spot.hpp"
#include "./util/move.hpp"
#include "./ai/aIEngine.hpp"
#include "./util/mempool.hpp"


#include <iostream>
#include <algorithm>

using namespace std;


void Game::start(){
    this->board = new Board();
    this->aIGame();
}

void Game::playerMove(){
    bool status = true;
    PieceSet *plays = this->board->getPlaysPieceSet();
    Piece* piece = nullptr;
    Spot *spot;
    int x;
    int y;
    status = true;
    while(status){
        cout<<"Give begin spot"<<endl;
        cin>>y;
        cin>>x;
        spot = this->board->getSpot(y,x);
        if(spot != nullptr && spot->getPiece() != nullptr && spot->getPiece()->getColor() == plays->getColor()){
            status = false;
            piece = spot->getPiece();
        }
    }
    status = true;
    while(status){
        cout<<"Give end spot"<<endl;
        cin>>y;
        cin>>x;
        spot = this->board->getSpot(y,x);
        vector<Spot*> tempMoves = piece->getPossibleMoves();
        if(find(tempMoves.begin(), tempMoves.end(), spot) != tempMoves.end()){
            Move *move = new Move(piece, piece->getSpot(),spot);
            if(board->executeMove(move)){
                status = false;
            }else delete move;

        }
    }
}

void Game::game(){
    while(true){
        this->aIGame();
    }
        
}

void Game::aIMove(){

    PieceSet *plays = this->board->getPlaysPieceSet();
    auto start = high_resolution_clock::now();
    this->board->executeMove(AIEngine::aIMove(4,this->board, plays->getColor()));
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<"End time: "<<duration.count()<<endl;
}




void Game::aIGame(){
    bool status = true;
    AIEngine::moveMempool = MempoolManager<Move>();
    AIEngine::moveMempool.init(100000);

    ZobristHashing::initTable();
    AIEngine::initializeEngine();

    while(true){
        this->board->display();
        aIMove();
        this->board->display();
        aIMove();
    }
}

