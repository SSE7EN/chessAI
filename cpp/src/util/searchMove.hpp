#pragma once

/**
 **************************
 * @file    searchMove.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple search chess move implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include <vector>

class Spot;
class Piece;


using namespace std;

class SearchMove{
    public:
	   /*
	    * @brief Return possible moves in given line
	    * @param possibleMoves vector to write Sots to
	    * @param piece Pice to check move for
	    * @param x,y direction of line
	    * @return void
	    * */
	   static void searchLine(vector<Spot*> &possibleMoves,Piece* piece, int y, int x);
	   static Spot* searchSpot(Piece* piece, int y, int x);
};
