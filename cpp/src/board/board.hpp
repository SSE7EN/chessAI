#pragma once

/**
 **************************
 * @file    board.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess board implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */
#include <vector>
#include "piece.hpp"

#define CHESS_BOARD_DIMENSION 8

using namespace std;

class Spot;

class Move;

class Board{
    private:
        vector<vector<Spot*>> board;
        vector<Move*> moveHistory;
        PieceSet wSet;
        PieceSet bSet;
        Color plays;
        void initializeBoard();
        void changePlays();

    public:
        Piece* getPiece(int y, int x);
        vector<vector<Spot*>> getBoard(){return this->board;};
        PieceSet* getWhitePieces(){return &this->wSet;};
        PieceSet* getBlackPieces(){return &this->bSet;};
        PieceSet* getOponetPieces(Color color);
        King* getPlayersKing(Color color);
        vector<Move*>& getMoveHistory(){return this->moveHistory;};
        Move* getLastMove();
        bool executeMove(Move* move);
        bool executeMoveMinmax(Move *move);
        void undoMove(Move *move);
        void display();
        Spot* getSpot(int y, int x);
        Color getPlaysColor(){return this->plays;};
        PieceSet* getPieceSetByColor(Color color);
        PieceSet* getPlaysPieceSet();
        Board();
        static std::chrono::microseconds durationExecuteMove;
        


};

