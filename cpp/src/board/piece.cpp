/**
 **************************
 * @file    piece.cpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess piece implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include "board.hpp"
#include "piece.hpp"
#include "spot.hpp"
#include "../util/searchMove.hpp"
#include "../util/move.hpp"

#include <iostream>
#include <algorithm>
#include <stdlib.h>  
#include <vector>

using namespace std;

Piece::Piece(Spot *spot, Color color, PieceCode pieceCode):spot(spot),color(color),pieceCode(pieceCode){
    spot->setPiece(this);
	switch(pieceCode){
		case PieceCode::PAWN:
			this->imgString = "PW";
			break;
		case PieceCode::ROOK:
			this->imgString = "R ";
			break;
		case PieceCode::BISHOP:
			this->imgString = "B ";
			break;
		case PieceCode::KNIGHT:
			this->imgString = "KN";
			break;
		case PieceCode::QUEEN:
			this->imgString = "Q ";
			break;
		case PieceCode::KING:
			this->imgString = "K ";
			break;
	}
}

void Piece::setSpot(Spot *spot){
	this->spot->setPiece(nullptr);
	this->spot = spot;
	this->spot->setPiece(this);
}
void Piece::move(Move &move){
	if(move.getEndSpot()->getPiece() != nullptr){
		move.setCapturedPiece(move.getEndSpot()->getPiece());
		move.getCapturedPiece()->setIsKilled(true);
	}
	this->setSpot(move.getEndSpot());
	this->moved = true;
	

}

void Piece::undoMove(Move &move){
	move.getEndSpot()->setPiece(nullptr);
	move.getMovedPiece()->setSpot(move.getBeginSpot());
	if(move.getCapturedPiece() != nullptr){
		move.getCapturedPiece()->getSpot()->setPiece(move.getCapturedPiece());
		move.getCapturedPiece()->setIsKilled(false);
	}
	this->moved =false;
}

void Piece::display(){
	cout<<this->color<<imgString;
}


Pawn::Pawn(Color color):Piece(color, PieceCode::PAWN){
    if(color == Color::WHITE) this->direction = 1;
    else this->direction = -1;

	this->value = 100;
};
Pawn::Pawn(Color color, Spot *spot):Piece(spot, color, PieceCode::PAWN){
    if(color == Color::WHITE) this->direction = 1;
    else this->direction = -1;
	
	this->value = 100;

};


std::chrono::microseconds PieceSet::durationGetSpot;

vector<Spot*> Pawn::getPossibleMoves(){
 	auto start = high_resolution_clock::now(); 
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*6);
	if(!this->killed){
		
		Board *board = this->spot->getBoard();
		Move* lastMove = board->getLastMove();
		Spot *tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX());

		//check if can move forward
		if(tSpot != nullptr && tSpot->getPiece() == nullptr){
			possibleMoves.push_back(tSpot);
			//check if can do double move
			if(!this->moved){
				tSpot = board->getSpot((this->spot->getY()+2*this->direction), this->spot->getX());
				if(tSpot !=nullptr && tSpot->getPiece() == nullptr){
					possibleMoves.push_back(tSpot);
				}
			}
		}

		//check if can attack
		tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX() -1);
		if(tSpot != nullptr &&  (tSpot->getPiece() != nullptr && tSpot->getPiece()->getColor() != this->color)){
			possibleMoves.push_back(tSpot);
		}
		tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX() +1);
		if(tSpot != nullptr &&  (tSpot->getPiece() != nullptr && tSpot->getPiece()->getColor() != this->color)){
			possibleMoves.push_back(tSpot);
		}

		//special attack
		if(lastMove != nullptr){
			if(lastMove->getCapturedPiece() == nullptr && lastMove->getEndSpot()->getY() && lastMove->getBeginSpot()->getY() == this->direction && abs(lastMove->getBeginSpot()->getX()-lastMove->getEndSpot()->getX()) == 1 && lastMove != nullptr &&
						lastMove->getMovedPiece()->getPieceCode() == PieceCode::PAWN && abs(lastMove->getEndSpot()->getY() - lastMove->getBeginSpot()->getY()) == 2 && lastMove->getEndSpot()->getX() == lastMove->getEndSpot()->getX() &&
						(lastMove->getEndSpot()->getY() - (this->direction *(-1))) == lastMove->getEndSpot()->getY()){
					possibleMoves.push_back(tSpot);
				}
		}
	}

 	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start); 
    return possibleMoves;
};

void Pawn::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now(); 
	if(!this->killed){
		Board *board = this->spot->getBoard();
		Spot *tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX());

		//check if can attack
		tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX() -1);
		if(tSpot != nullptr &&  (tSpot->getPiece() != nullptr && tSpot->getPiece()->getColor() != this->color)){
			attackedSpots.push_back(tSpot);
		}
		tSpot = board->getSpot(this->spot->getY()+this->direction, this->spot->getX() +1);
		if(tSpot != nullptr &&  (tSpot->getPiece() != nullptr && tSpot->getPiece()->getColor() != this->color)){
			attackedSpots.push_back(tSpot);
		}
	}
	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start); 
};

void Pawn::move(Move &move){
	//special attack
	Move* lastMove = this->getSpot()->getBoard()->getMoveHistory().back();

	if(move.getEndSpot()->getPiece() != nullptr){
		move.setCapturedPiece(move.getEndSpot()->getPiece());
		move.getCapturedPiece()->setIsKilled(true);
		move.getCapturedPiece()->setSpot(nullptr);
	}
	this->setSpot(move.getEndSpot());
	if(lastMove != nullptr){
		if(lastMove->getCapturedPiece() == nullptr && lastMove->getEndSpot()->getY() && lastMove->getBeginSpot()->getY() == this->direction && abs(lastMove->getBeginSpot()->getX()-lastMove->getEndSpot()->getX()) == 1 && lastMove != nullptr &&
                    lastMove->getMovedPiece()->getPieceCode() == PieceCode::PAWN && abs(lastMove->getEndSpot()->getY() - lastMove->getBeginSpot()->getY()) == 2 && lastMove->getEndSpot()->getX() == lastMove->getEndSpot()->getX() &&
                    (lastMove->getEndSpot()->getY() - (this->direction *(-1))) == lastMove->getEndSpot()->getY()){
                lastMove->getMovedPiece()->setIsKilled(true);
				lastMove->getMovedPiece()->getSpot()->setPiece(nullptr);
				lastMove->getMovedPiece()->setSpot(nullptr);
            }
	}

	this->moved = true;
}

Rook::Rook(Color color):Piece(color, PieceCode::ROOK){

	this->value = 500;

};
Rook::Rook(Color color, Spot *spot):Piece(spot, color, PieceCode::ROOK){
	this->value = 500;
};

vector<Spot*> Rook::getPossibleMoves(){
	auto start = high_resolution_clock::now(); 
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*16);

	if(!this->killed){
		// search in x axis;
		SearchMove::searchLine(possibleMoves, this, 0, 1);
		//search in y axis
		SearchMove::searchLine(possibleMoves, this, 1, 0);
	}

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

	return possibleMoves;
		
};

void Rook::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now(); 
	if(!this->killed){
		// search in x axis;
		SearchMove::searchLine(attackedSpots, this, 0, 1);
		//search in y axis
		SearchMove::searchLine(attackedSpots, this, 1, 0);
	}


	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

};


Bishop::Bishop(Color color):Piece(color, PieceCode::BISHOP){
	this->value = 310;
};
Bishop::Bishop(Color color, Spot *spot):Piece(spot, color, PieceCode::BISHOP){
	this->value = 310;
};

vector<Spot*> Bishop::getPossibleMoves(){
	auto start = high_resolution_clock::now();
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*16);

	if(!this->killed){
		// search in x axis;
		SearchMove::searchLine(possibleMoves, this, 1, 1);
		//search in y axis
		SearchMove::searchLine(possibleMoves, this, -1, 1);
	}

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

	return possibleMoves;
		
};

void Bishop::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now(); 

	if(!this->killed){
		// search in x axis;
		SearchMove::searchLine(attackedSpots, this, 1, 1);
		//search in y axis
		SearchMove::searchLine(attackedSpots, this, -1, 1);
	}

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);
};

Knight::Knight(Color color):Piece(color, PieceCode::KNIGHT){
	this->value = 300;
};
Knight::Knight(Color color, Spot *spot):Piece(spot, color, PieceCode::KNIGHT){
	this->value = 300;
};

vector<Spot*> Knight::getPossibleMoves(){
	auto start = high_resolution_clock::now(); 
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*8);

	if(!this->killed){
		//Search knight moves
		Spot *spot = SearchMove::searchSpot(this,-2,1);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,-1,2);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,1,2);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,2,1);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,-1,-2);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,-2,-1);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,1,-2);
		if(spot != nullptr) possibleMoves.push_back(spot);
		spot = SearchMove::searchSpot(this,2,-1);
		if(spot != nullptr) possibleMoves.push_back(spot);

	}
	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);
	

	return possibleMoves;
		
};

void Knight::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now();

	if(!this->killed){
		//Search knight moves
		Spot *spot = SearchMove::searchSpot(this,-2,1);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,-1,2);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,1,2);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,2,1);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,-1,-2);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,-2,-1);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,1,-2);
		if(spot != nullptr) attackedSpots.push_back(spot);
		spot = SearchMove::searchSpot(this,2,-1);
		if(spot != nullptr) attackedSpots.push_back(spot);
	}

		auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

};



Queen::Queen(Color color):Piece(color, PieceCode::QUEEN){

	this->value = 900;
};
Queen::Queen(Color color, Spot *spot):Piece(spot, color, PieceCode::QUEEN){
	this->value = 900;
};

vector<Spot*> Queen::getPossibleMoves(){
	auto start = high_resolution_clock::now();
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*20);
	if(!this->killed){
		SearchMove::searchLine(possibleMoves, this, 1, 1);
		SearchMove::searchLine(possibleMoves, this, -1, 1);
		SearchMove::searchLine(possibleMoves, this, 0, 1);
		SearchMove::searchLine(possibleMoves, this, 1, 0);

	}

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

	return possibleMoves;
		
};

void Queen::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now();
	if(!this->killed){
		SearchMove::searchLine(attackedSpots, this, 1, 1);
		SearchMove::searchLine(attackedSpots, this, -1, 1);
		SearchMove::searchLine(attackedSpots, this, 0, 1);
		SearchMove::searchLine(attackedSpots, this, 1, 0);
	}

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);

};

King::King(Color color):Piece(color, PieceCode::KING){
	this->value = 10;
};
King::King(Color color, Spot *spot):Piece(spot, color, PieceCode::KING){
	this->value = 10;
};

vector<Spot*> King::getPossibleMoves(){
	auto start = high_resolution_clock::now();
	vector<Spot*> possibleMoves;
	possibleMoves.reserve(sizeof(Spot*)*8);

	PieceSet *oponentPieces = this->getSpot()->getBoard()->getOponetPieces(this->color);
	vector<Spot*> oponentAttackedSpots = oponentPieces->getAttackedSpots();


	Spot *spot = SearchMove::searchSpot(this, 0, 1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);
	spot = spot = SearchMove::searchSpot(this, 1, 1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end())possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, 1, 0);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, 0, -1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, -1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, 0);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, 1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end())possibleMoves.push_back(spot);
	spot = SearchMove::searchSpot(this, 1, -1);
	if(spot != nullptr && find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), spot) == oponentAttackedSpots.end()) possibleMoves.push_back(spot);



	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);


	return possibleMoves;
		
};

void King::getAttackedSpots(vector<Spot*> &attackedSpots){
	auto start = high_resolution_clock::now();
	Spot *spot = SearchMove::searchSpot(this, 0, 1);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = spot = SearchMove::searchSpot(this, 1, 1);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, 1, 0);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, 0, -1);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, -1);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, 0);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, -1, 1);
	if(spot != nullptr) attackedSpots.push_back(spot);
	spot = SearchMove::searchSpot(this, 1, -1);
	if(spot != nullptr) attackedSpots.push_back(spot);

	auto stop = high_resolution_clock::now(); 
	PieceSet::durationGetSpot += duration_cast<microseconds>(stop - start);
};

void PieceSet::setPieces(Board &board){
	
	// set start position (depends on color)
	int y1 = 0;
	int y2 = 1;
	if(this->color == Color::BLACK){
		y1 = 7;
		y2 = 6;
	}
	

        //add pawns
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][0]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][1]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][2]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][3]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][4]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][5]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][6]));
        this->pieceList.push_back(new Pawn(this->color, board.getBoard()[y2][7]));

		//add king
        this->pieceList.push_back(new King(this->color, board.getBoard()[y1][3]));
		this->king = (King*)board.getBoard()[y1][3]->getPiece();

        //add queen
        this->pieceList.push_back(new Queen(this->color, board.getBoard()[y1][4]));


        //add rook
        this->pieceList.push_back(new Rook(this->color, board.getBoard()[y1][0]));
        this->pieceList.push_back(new Rook(this->color, board.getBoard()[y1][7]));

        //add bishop

        this->pieceList.push_back(new Bishop(this->color, board.getBoard()[y1][2]));
        this->pieceList.push_back(new Bishop(this->color, board.getBoard()[y1][5]));

        //add knight

        this->pieceList.push_back(new Knight(this->color, board.getBoard()[y1][1]));
        this->pieceList.push_back(new Knight(this->color, board.getBoard()[y1][6]));

}

PieceSet::PieceSet(Color color, Board* board):color(color){
	this->setPieces(*board);
}

vector<Spot*> PieceSet::getAttackedSpots(){
		vector<Spot*> attackedSpots;
		attackedSpots.reserve(sizeof(Spot*)*20*16);
		
		for(Piece *piece : this->pieceList){
			if(!piece->isKilled()) piece->getAttackedSpots(attackedSpots);
		}

	return attackedSpots;
}

int Pawn::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wPawnTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bPawnTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}

int Rook::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wRookTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bRookTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}

int Bishop::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wBishopTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bBishopTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}

int Knight::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wKnightTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bKnightTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}

int Queen::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wQueenTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bQueenTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}
int King::getValue(){
	int value = this->value;
	if(this->color == Color::WHITE) value+=wKingTable[this->getSpot()->getY()][this->getSpot()->getX()];
	else value+=bKingTable[this->getSpot()->getY()][this->getSpot()->getX()];
	
	return value;
}


