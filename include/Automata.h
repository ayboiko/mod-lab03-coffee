#ifndef AUTOMAT_
#define AUTOMAT_
#include<iostream>
#include<string>
class CofeeMachine{
  public:
  CofeeMachine(int* prices, std :: string* menu, int kol);
  void on();
  void off();
  void coin(int a);
  std :: string etMenu();
  int* getState();
  int choice();
  void check();
  void cancel();
  void cook();
  void finish();
  private:
  int kol;
  int cash;
  std :: string* menu;
  int* prices;
  enum state { OFF, WAIT, ACCEPT, CHECK, COOK };
  int indchoose;
  state st;
};
#endif
