#pragma once

/**
 **************************
 * @file    spot.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess spot implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

class Piece;
class Board;

class Spot{

    private:
        int x;
        int y;
        Piece *piece;
        Board *board;
    
    public:
        Spot(int y, int x, Board *board):y(y),x(x), board(board), piece(nullptr){};
        void setPiece(Piece *piece){this->piece = piece;};
        Piece* getPiece(){return this->piece;};      
        int getX(){return this->x;};
        int getY(){return this->y;};
        void setX(int x){this->x = x;};
        void setY(int y){this->y =y;};
        Board* getBoard(){ return this->board;};

        void display();
};
