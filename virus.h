#ifndef VIRUS_H
#define VIRUS_H

#include <bits/stdc++.h>
class Human;

using namespace std;
class Virus{
    vector<double> attack;
    double mortality_rate;
    void normalize();
  public:
    Virus();
    Virus(vector<double> attack, double mortality_rate);
    bool kills(Human &h);
    bool infect(Human &h);
    Virus mutate();
    bool is_same(Virus &v);
};

#endif
