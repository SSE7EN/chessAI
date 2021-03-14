#pragma once

/**
 **************************
 * @file    aIEngine.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple ai engine implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#define DEPTH_LIMIT 1
#define MAX_VALUE -1000000000
#define MIN_VALUE 1000000000

#include "../board/enums.hpp"
#include "../util/mempool.hpp"
#include <unordered_map>


using namespace std;



class Board;

class Move;

class PieceSet;

class Piece;

enum MoveType{MAX, MIN};

class ZobristHashing{
    public:
        static unsigned long long int ZobristTable[8][8][12];
        static unsigned long long int randomInt();
        static int indexOf(Piece *piece);
        static void initTable();
        static unsigned long long int computeHash(Board* borad);
};

struct ttEntry{
    int flag;
    int depth;
    int value;
};


class AIEngineMove{
    private:
        int value;
        Move* move;
    
    public:
        AIEngineMove(MoveType mt);
        AIEngineMove(int value):value(value){};
        int getValue(){return this->value;};
        void setValue(int value){this->value = value;};
        Move* getMove(){return this->move;};
        void setMove(Move *mv){this->move =mv;};
};

class AIEngine{
    public:
        static AIEngineMove* minMax(Board *board, int depth, Color color);
        static AIEngineMove* minMax(Board *board, int depth, Color color, bool maximizing);
        static int minmax(Board *board, int depth, Color color,int alpha, int beta, bool maximizing);
        static Move* aIMove(int depth,Board *board, Color color);
        static int piceSetValue(PieceSet &piceSet);
        static void initializeEngine();

        static unordered_map<unsigned long long int, ttEntry*>TranspositionMap;
        static ttEntry* transpositionMapLookUp(Board* board);
        static void transpositionTableStore(Board* board, ttEntry *entry);

        static int minmax2(Board *board, int depth, Color color, int alpha, int beta,bool maximizing);
        static MempoolManager<Move> moveMempool;
        
    private:
        static int maxMove(Board *board, int depth, Color color);
        static int minMove(Board *board, int depth, Color color);
        static int evaluate(Board *board, Color color);
};

