
/**
 **************************
 * @file    spot.hpp
 * @author  SE7EN
 * @date    2022-11-07
 * @brief   simple chess spot implementation
 **************************
 */

/* Includes ---------------------------------------------------------------- */

#include "spot.hpp"
#include "piece.hpp"

#include <iostream>

using namespace std;

void Spot::display(){
    cout<<" ";
    if(this->piece != nullptr){
        this->piece->display();
    }
    else{
        cout<<"   ";
    }
    cout<<" ";
}
