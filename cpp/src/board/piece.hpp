#pragma once

/**
 **************************
 * @file    piece.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess piece implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include <vector>
#include <iostream>

#include "enums.hpp"

#include <chrono> 

using namespace std;
using namespace std::chrono; 

using namespace std;

class Board;

class Spot;

class Move;

const int bKingTable[8][8] = {
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -10,-20,-20,-20,-20,-20,-20,-10,
     20, 20,  0,  0,  0,  0, 20, 20,
     20, 30, 10,  0,  0, 10, 30, 20
};
const int bQueenTable[8][8] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5,  5,  5,  5,  0,-10,
     -5,  0,  5,  5,  5,  5,  0, -5,
      0,  0,  5,  5,  5,  5,  0, -5,
    -10,  5,  5,  5,  5,  5,  0,-10,
    -10,  0,  5,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20
};
const int bRookTable[8][8] = {
      0,  0,  0,  0,  0,  0,  0,  0,
      5, 10, 10, 10, 10, 10, 10,  5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
      0,  0,  0,  5,  5,  0,  0,  0
};
const int bBishopTable[8][8] = {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -20,-10,-10,-10,-10,-10,-10,-20
};
const int bKnightTable[8][8] = {
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50
};
const int bPawnTable[8][8] = {
     0,  0,  0,  0,  0,  0,  0,  0,
    50, 50, 50, 50, 50, 50, 50, 50,
    10, 10, 20, 30, 30, 20, 10, 10,
     5,  5, 10, 25, 25, 10,  5,  5,
     0,  0,  0, 20, 20,  0,  0,  0,
     5, -5,-10,  0,  0,-10, -5,  5,
     5, 10, 10,-20,-20, 10, 10,  5,
     0,  0,  0,  0,  0,  0,  0,  0
};


const int wKingTable[8][8] = {
     20, 30, 10,  0,  0, 10, 30, 20,
     20, 20,  0,  0,  0,  0, 20, 20,
    -10,-20,-20,-20,-20,-20,-20,-10,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30
};
const int wQueenTable[8][8] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5,  5,  5,  5,  0,-10,
      0,  0,  5,  5,  5,  5,  0, -5,
     -5,  0,  5,  5,  5,  5,  0, -5,
    -10,  5,  5,  5,  5,  5,  0,-10,
    -10,  0,  5,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20
};
const int wRookTable[8][8] = {
      0,  0,  0,  5,  5,  0,  0,  0,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
     -5,  0,  0,  0,  0,  0,  0, -5,
      5, 10, 10, 10, 10, 10, 10,  5,
      0,  0,  0,  0,  0,  0,  0,  0
};
const int wBishopTable[8][8] = {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10,-10,-10,-10,-10,-20
};
const int wKnightTable[8][8] = {
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50
};
const int wPawnTable[8][8] = {
      0,  0,  0,  0,  0,  0,  0,  0,
      5, 10, 10,-20,-20, 10, 10,  5,
      5, -5,-10,  0,  0,-10, -5,  5,
      0,  0,  0, 20, 20,  0,  0,  0,
      5,  5, 10, 25, 25, 10,  5,  5,
     10, 10, 20, 30, 30, 20, 10, 10,
     50, 50, 50, 50, 50, 50, 50, 50,
      0,  0,  0,  0,  0,  0,  0,  0
};

class Piece{
    protected:
        PieceCode pieceCode;
		string imgString;
        Spot *spot;
        Color color;
        bool moved = false;
        bool killed = false;
		int value;
		int posValue;


    public:
        virtual vector<Spot*> getPossibleMoves() =0;
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots) =0;
		virtual int getValue() =0;
		
        Piece(Color color,PieceCode pieceCode):color(color),pieceCode(pieceCode){};
        Piece(Spot *spot, Color color, PieceCode pieceCode);
		PieceCode getPieceCode(){return this->pieceCode;};
        Spot* getSpot(){ return this->spot;};
		void setSpot(Spot *spot);
        bool isMoved(){return this->moved;};
        void setIsMoved(bool moved){ this->moved = moved;};
        bool isKilled(){return this->killed;};
        void setIsKilled(bool killed){ this->killed = killed;};
		Color getColor(){return this->color;};
        void display();
        void move(Move &move);
		void undoMove(Move &move);
		
};

class Pawn: public Piece{
    private:
        int direction;

    public:
        Pawn(Color color);
        Pawn(Color color, Spot *spot);
        virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		virtual int getValue();
		void move(Move &move);
		void display();


};

class Rook: public Piece{
	public:
		Rook(Color color);
		Rook(Color color, Spot *spot);
		virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		virtual int getValue();


};

class Bishop: public Piece{
	public:
		Bishop(Color color);
		Bishop(Color color, Spot *spot);
		virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		virtual int getValue();


};	
class Knight: public Piece{
	public:
		Knight(Color color);
		Knight(Color color, Spot *spot);
		virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		virtual int getValue();

};	


class Queen: public Piece{
	public:
		Queen(Color color);
		Queen(Color color, Spot *spot);
		virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		virtual int getValue();

};	

class King: public Piece{
	private:
		bool check = false;	
	
	
	public:
		King(Color color);
		King(Color color, Spot *spot);
		virtual vector<Spot*> getPossibleMoves();
		virtual void getAttackedSpots(vector<Spot*> &attackeSpots);
		bool isChecked(){return this->check;};
		virtual int getValue();
};	


class PieceSet{
	private:
		vector<Piece*> pieceList;
		King* king;
		Color color;

	public:
		PieceSet(Color color, Board* board);
		PieceSet(){};
		void setPieces(Board& board);
		vector<Spot*> getAttackedSpots();
		vector<Piece*> getPieceList(){return this->pieceList;};
		King* getKing(){return this->king;};
		int getPieceSetValue();
		Color getColor(){return this->color;};
		vector<Spot*> getPossibleMoves();
        static std::chrono::microseconds durationGetSpot;


};
