/**
 **************************
 * @file    board.cpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess board implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include "board.hpp"
#include "spot.hpp"
#include "piece.hpp"
#include "../util/move.hpp"

#include <iostream>

using namespace std;

 PieceSet* Board::getPieceSetByColor(Color color){
	 if(color == Color::WHITE) return &wSet;
	 else return &bSet;
 }

Spot* Board::getSpot(int y, int x){
	Spot* result = nullptr;
	if(y >=0 && y < CHESS_BOARD_DIMENSION && x >= 0 && x < CHESS_BOARD_DIMENSION) result =  this->board[y][x];

	return result;
};

void Board::initializeBoard(){
	//fill board with spots
	for(int y = 0 ; y < CHESS_BOARD_DIMENSION; y++){
		vector<Spot*> row;
		for(int x =0; x < CHESS_BOARD_DIMENSION; x++){
			row.push_back(new Spot(y,x, this));
		}
		this->board.push_back(row);
	}

};

Board::Board(){
    initializeBoard();
	this->plays = Color::WHITE;
	this->bSet = PieceSet(Color::BLACK,this);
	this->wSet = PieceSet(Color::WHITE,this);
}

PieceSet* Board::getOponetPieces(Color color){
	if(color == Color::WHITE) return &this->bSet;
	else return &this->wSet;
};

King* Board::getPlayersKing(Color color){
	if(color == Color::WHITE) return this->wSet.getKing();
	else return this->bSet.getKing();
};

void Board::changePlays(){
	if(this->plays == Color::WHITE) this->plays = Color::BLACK;
	else this->plays = Color::WHITE;
}


bool Board::executeMove(Move *move){
	bool status = false;

	 move->getMovedPiece()->move(*move);
	if(MoveValidator::validateMove(*this, move)){
		this->moveHistory.push_back(move);
		changePlays();
		status = true;
	}
	else{
		move->getMovedPiece()->undoMove(*move);
		status = false;
		delete move;
	}

	return status;
}

std::chrono::microseconds Board::durationExecuteMove;
bool Board::executeMoveMinmax(Move *move){
	auto start = high_resolution_clock::now(); 
	bool status = false;
	Piece *movedPiece = move->getMovedPiece();
	movedPiece->move(*move);
	if(MoveValidator::validateMove(*this, move)){
		this->moveHistory.push_back(move);
		changePlays();
		status = true;
	}
	else{
		movedPiece->undoMove(*move);
		status = false;
	}
	auto stop = high_resolution_clock::now(); 
    Board::durationExecuteMove += duration_cast<microseconds>(stop - start); 

	return status;
}

void Board::display(){
	cout<<endl;
	int i = 0;
	cout<<"     0      1      2      3      4      5      6      7   "<<endl;
	for(vector<Spot*> row : this->board){
		cout<<"  ---------------------------------------------------------"<<endl;
		cout<<" "<<i;
		for(Spot* spot : row){
			cout<<"| ";
			spot->display();
		}
		cout<<"|"<<endl;
		i++;
	}
	cout<<endl;
}

PieceSet* Board::getPlaysPieceSet(){
	PieceSet *pieceSet = nullptr;
	if(this->plays == Color::WHITE) pieceSet = &(this->wSet);
	else pieceSet = &this->bSet;

	return pieceSet;
}

Move* Board::getLastMove(){
	Move *move = nullptr;
	if(!this->moveHistory.empty()){
		move = this->moveHistory.back();
	}
	return move;
}

void Board::undoMove(Move* move){
	move->getMovedPiece()->undoMove(*move);
	this->moveHistory.pop_back();
	this->changePlays();
}
