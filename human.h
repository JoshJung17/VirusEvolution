#ifndef HUMAN_H
#define HUMAN_H

#include <bits/stdc++.h>
#include "virus.h"

using namespace std;

class Human{
  public:
    pair<double,double> pos;
    vector<Virus> viruses;
    double dis(pair<int,int> p1, pair<int,int> p2);
    vector<double> immune_system;
    Human();
    bool checkDie();
    void moveRandom();
    void interact(Human &other);
};

#endif
