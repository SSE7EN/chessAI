#pragma once

/**
 **************************
 * @file    move.hpp
 * @author  SE7EN
 * @date    2022-11-08
 * @brief   simple move implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

class Spot;
class Piece;
class Board;

class Move{
    private:
        Spot* beginSpot = nullptr;
        Spot* endSpot = nullptr;
        Piece* movedPiece = nullptr;
        Piece* capturedPiece = nullptr;
        bool check = false;
    
    public:
        Move(Piece *movePiece, Spot *beginSpot, Spot *endSpot, Piece *capturedPiece):beginSpot(beginSpot),endSpot(endSpot),movedPiece(movePiece),capturedPiece(capturedPiece){};
        Move(Piece *movePiece, Spot *beginSpot, Spot *endSpot):beginSpot(beginSpot),endSpot(endSpot),movedPiece(movePiece){};
        Move(){};
        Spot* getBeginSpot(){return this->beginSpot;};
        Spot* getEndSpot(){return this->endSpot;};
        Piece* getMovedPiece(){return this->movedPiece;};
        Piece* getCapturedPiece(){return this->capturedPiece;};
        void setCapturedPiece(Piece *piece){ this->capturedPiece = piece;};
        void initialize(Piece *movePiece, Spot *beginSpot, Spot *endSpot, Piece *capturedPiece){this->movedPiece = movePiece; this->beginSpot = beginSpot; this->endSpot = endSpot; this->capturedPiece = capturedPiece;}; 




};


class MoveValidator{
    public:
        static bool validateMove(Board& board, Move* move);
};
