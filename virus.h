#ifndef VIRUS_H
#define VIRUS_H

#include <bits/stdc++.h>
class Human;

using namespace std;
class Virus{
  public:
    vector<double> attack;
    double mortality_rate;
    void normalize();
    Virus();
    Virus(vector<double> attack, double mortality_rate);
    bool kills(Human &h);
    bool infect(Human &h);
    Virus mutate();
    bool is_same(const Virus &v) const;
};

#endif
