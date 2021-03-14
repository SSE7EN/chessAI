/**
 **************************
 * @file    main.cpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess main function
 **************************
 */

/* Includes ---------------------------------------------------------------- */
#include "./board/board.hpp"
#include "./board/spot.hpp"
#include "./board/enums.hpp"
#include "game.hpp"


#include <vector>
#include <iostream>

using namespace std;

int main(){
    Game game;
    game.start();

    return 0;
}
