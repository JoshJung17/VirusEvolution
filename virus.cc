#include <bits/stdc++.h>
#include "virus.h"
#include "random.h"
#include "constants.h"
#include "human.h"

using namespace std;

Virus::Virus() {
    attack = vector<double>(VECTOR_SIZE);
    for (double &c: attack) {
        c = randUnif();
    }
    normalize();
    
    mortality_rate = randUnif() / 10 / VIRUS_HALFLIFE;
}

Virus::Virus(vector<double> attack, double mortality_rate): attack{attack}, mortality_rate{mortality_rate} {
    normalize();
}

void Virus::normalize() {
    double sum;
    for (double &c: attack) {
        if (c < 0) c = 0;
        sum += c * c;
    }
    double scaleFac = MAX_ATTACK / sqrt(sum);
    for (double &c: attack) {
        c *= scaleFac;
    }
    mortality_rate = max(0., min(1., mortality_rate));
}

bool Virus::kills(Human &h) {
    if (randUnif() < mortality_rate)
        return true;
    return false;
}

bool Virus::infect(Human &h) {
    double infectiousness = 0;
    for (int i = 0; i < attack.size(); ++i) {
        infectiousness += max(0., attack[i] - h.immune_system[i]);
    }
    if (randUnif() < INFECT_P * infectiousness)
        return true;
    return false;
}

Virus Virus::mutate() {
    vector<double> new_attack(attack.size());
    for (int i = 0; i < attack.size(); ++i) {
        new_attack[i] = attack[i] + (randUnif() - 0.5) * VIRUS_MUTATE;
    }
    double new_mortality = mortality_rate + (randUnif() - 0.5) * VIRUS_MORTALITY_MUTATE;
    return Virus(new_attack, new_mortality);
}
