#ifndef AUTOMAT_
#define AUTOMAT_
#include<iostream>
#include<string>
class CofeeMachine{
  public:
  CofeeMachine(int* prices_, std :: string* menu_, int kol_);
  void on();
  void off();
  void coin(int a);
  void getMenu();
  std :: string getState();
  void choice(int ind);
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
