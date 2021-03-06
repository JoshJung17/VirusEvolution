#ifndef HUMAN_H
#define HUMAN_H

#include <bits/stdc++.h>
#include "virus.h"

using namespace std;

class Human{
    double theta;
  public:
    pair<double,double> pos;
    vector<Virus> viruses;
    double dis(pair<int,int> p1, pair<int,int> p2);
    vector<double> immune_system;
    Human();
    Human(vector<double> immune_system, pair<double, double> pos, vector<Virus> viruses);
    bool checkDie();
    void moveRandom();
    void interact(Human &other);
    Human reproduce();
};

#endif
