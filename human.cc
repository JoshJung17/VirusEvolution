#include <bits/stdc++.h>
#include "virus.h"
#include "random.h"
#include "constants.h"
#include "human.h"
// INFECT_DISTANCE
// VECTOR_SIZE
// VIRUS_HALFLIFE
// MAX_IMMUNE
// MAX_ATTACK

using namespace std;
double PI = 3.141592653589;

double Human::dis(pair<int,int> p1, pair<int,int> p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx*dx+dy*dy);
}

Human::Human() {
    immune_system = vector<double>(VECTOR_SIZE);
    double sum = 0;
    for (double &c: immune_system) {
        c = randUnif();
        sum += c;
    }
    double scaleFac = MAX_IMMUNE / sum;
    for (double &c: immune_system) {
        c *= scaleFac;
    }
    pos.first = randUnif() * BOARD_WIDTH;
    pos.second = randUnif() * BOARD_HEIGHT;
}

bool Human::checkDie() {
    for (Virus v: viruses) {
        if (v.kills(*this))
            return true;
    }
    return false;
}

void Human::moveRandom() {
    vector<Virus> new_viruses;
    for (Virus v: viruses) { 
        if (randUnif() < 1 - pow(0.5, 1.0/VIRUS_HALFLIFE)) {
            //virus dies
        }
        else {
            new_viruses.push_back(v);
        }
    }
    viruses = new_viruses;

    pos.first = randUnif() * BOARD_WIDTH;
    pos.second = randUnif() * BOARD_HEIGHT;
    /*
    double theta = randUnif() * 2 * PI;
    pos.first += HUMAN_MOVE_DIS * cos(theta);
    pos.second += HUMAN_MOVE_DIS * sin(theta);
    */

    pos.first = max(0., pos.first);
    pos.first = min(BOARD_WIDTH, pos.first);
    pos.second = max(0., pos.second);
    pos.second = min(BOARD_HEIGHT, pos.second);

    if (pos.first < BAT_CAVE_X && pos.second < BAT_CAVE_Y) {
        Virus v;
        if (randUnif() < BAT_INFECT_P && v.infect(*this)) {
            viruses.push_back(v);
        }
    }
}

void Human::interact(Human &other) {
    if (dis(pos, other.pos) > INFECT_DISTANCE)
        return;
    for (Virus v: viruses) {
        if (v.infect(other)) {
            other.viruses.push_back(v.mutate());
        }
    }
}
