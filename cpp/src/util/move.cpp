/**
 **************************
 * @file    move.hpp
 * @author  SE7EN
 * @date    2022-11-08
 * @brief   simple move implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */
#include "move.hpp"
#include "../board/board.hpp"

#include <algorithm>


bool MoveValidator::validateMove(Board& board, Move* move){
    bool result = false;
    PieceSet* oponentPieceSet = board.getOponetPieces(move->getMovedPiece()->getColor());
    King* king = board.getPlayersKing(move->getMovedPiece()->getColor());

    vector<Spot*> oponentAttackedSpots = oponentPieceSet->getAttackedSpots();
    if(find(oponentAttackedSpots.begin(), oponentAttackedSpots.end(), king->getSpot()) == oponentAttackedSpots.end()) result = true;

    return result;
}
