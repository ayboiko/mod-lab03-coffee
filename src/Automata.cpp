#include "Automata.h"
#include <iostream>
#include <string>
CofeeMachine :: CofeeMachine(int* prices_, std :: string* menu_, int kol_){
  st= OFF , indchoose= -1 , cash = 0;
  prices = prices_, menu = menu_, kol = kol_;
}
void CofeeMachine :: on(){
  if(st == OFF){
    st = WAIT;
  }
}
void CofeeMachine :: of(){
  if(st == WAIT){
    st = OFF;
  }
}
void CofeeMachine :: coin(int a){
  if(st == WAIT || st == ACCEPT){
    st = ACCEPT;
    cash = cash + a;
  }
}
void CofeeMachine :: cancel(){
  if(st == ACCEPT || st == CHECK){
    st = WAIT;
    indchoose = -1;
  }
}
void CofeeMachine :: finish(){
  if(st == COOK){
    st = WAIT;
    indchoose = -1;
    std :: cout<< "Take your drink \n";
  }
}
void CofeeMachine :: cook(){
  if(st == ACCEPT){
    st = COOK;
  }
}
void CofeeMachine :: choice(int ind){
  if(st == ACCEPT){
    if( ind >= 1 && ind <= kol ){
    indchoose = ind - 1; st = CHECK;
    }
    else{
      indchoose = -1;
    }
  }
}
void CofeeMachine :: check(){
  if(st == CHECK){
    if( cash >= prices[indchoose] && indchoose != -1){
      cash=cash-prices[indchoose];
    }
  }
}
std :: string CofeeMachine :: getState(){
  switch(st){
    case OFF : return "OFF";
    case WAIT : return "WAIT";
    case ACCEPT : return "ACCEPT";
    case CHECK : return "CHECK";
    case COOK : return "COOK";
  }
}
std::string CofeeMachine :: getMenu() {
    std::string menu;
    for (int i = 0; i < _count; ++i) {
        menu += std::to_string(i + 1) + ". " + menu[i]
          + " - " + std::to_string(prices[i]) + " рублей \n";
    }
    return menu;
}
