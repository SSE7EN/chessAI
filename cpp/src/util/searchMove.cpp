/**
 **************************
 * @file    searchMove.cpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple search chess move implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include "searchMove.hpp"
#include "../board/piece.hpp"
#include "../board/spot.hpp"
#include "../board/board.hpp"

#include <vector>

void  SearchMove::searchLine(vector<Spot*> &possibleMoves, Piece* piece, int y, int x){
	Board *board = piece->getSpot()->getBoard();
	Spot *tSpot = piece->getSpot(); 
	tSpot = board->getSpot(tSpot->getY() + y, tSpot->getX() + x);
	
	//move in one direction
	while(tSpot != nullptr && tSpot->getY() >= 0 && tSpot->getY() < CHESS_BOARD_DIMENSION && tSpot->getX() >= 0 && tSpot->getX() < CHESS_BOARD_DIMENSION ){

		if(tSpot->getPiece() == nullptr){
			possibleMoves.push_back(tSpot);
			tSpot = board->getSpot(tSpot->getY() + y, tSpot->getX() + x);
		}else if(tSpot->getPiece()->getColor() != piece->getColor()){
			possibleMoves.push_back(tSpot);
			break;
		}else{
			break;
		}
	}
	//move in second direction
		
	tSpot = board->getSpot(piece->getSpot()->getY() - y, piece->getSpot()->getX() - x);
	while(tSpot != nullptr && tSpot->getY() >= 0 && tSpot->getY() < CHESS_BOARD_DIMENSION && tSpot->getX() >= 0 && tSpot->getX() < CHESS_BOARD_DIMENSION ){

		if(tSpot->getPiece() == nullptr){
			possibleMoves.push_back(tSpot);
			tSpot = board->getSpot(tSpot->getY() - y, tSpot->getX() - x);
		}else if(tSpot->getPiece()->getColor() != piece->getColor()){
			possibleMoves.push_back(tSpot);
			break;
		}else{
			break;
		}
	}
	
}


Spot* SearchMove::searchSpot(Piece* piece, int y, int x){
	Spot* result = nullptr;
	Spot* spot = nullptr;
	Board* board = piece->getSpot()->getBoard();
	spot = board->getSpot(piece->getSpot()->getY() + y, piece->getSpot()->getX() + x );
	if(spot != nullptr && (spot->getPiece() == nullptr || spot->getPiece()->getColor() != piece->getColor())) result = spot;

	return result;	
};

