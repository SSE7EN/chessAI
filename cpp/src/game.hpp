#pragma once
/**
 **************************
 * @file    game.hpp
 * @author  SE7EN
 * @date    2022-11-10
 * @brief   simple chess game implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

class Board;

class Game{
    private:
        Board *board = nullptr;
        void game();
        void aIGame();
        void aIMove();
        void playerMove();
    public:
        Game(){};
        void start();
        void end();
};