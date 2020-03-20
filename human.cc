#include <bits/stdc++.h>
#include "virus.h"
#include "random.h"
#include "constants.h"
#include "human.h"

using namespace std;

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
    theta = randUnif() * 2 * PI;
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

    theta += (randUnif() - 0.5) * HUMAN_THETA;
    pos.first += randUnif() * HUMAN_MOVE_DIS * cos(theta);
    pos.second += randUnif() * HUMAN_MOVE_DIS * sin(theta);

    if (pos.first < 0)
        pos.first += BOARD_WIDTH;
    if (pos.first > BOARD_WIDTH)
        pos.first -= BOARD_WIDTH;
    if (pos.second < 0)
        pos.second += BOARD_HEIGHT;
    if (pos.second > BOARD_HEIGHT)
        pos.second -= BOARD_HEIGHT;

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

Human Human::reproduce() {
    return Human();
}
