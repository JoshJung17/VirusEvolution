#ifndef CONSTANTS_H
#define CONSTANTS_H
const double VECTOR_SIZE = 10;
const double MAX_IMMUNE = 100;
const double MAX_ATTACK = 100;

const double BOARD_WIDTH = 800;
const double BOARD_HEIGHT = 600;
const double BAT_CAVE_X = 40;
const double BAT_CAVE_Y = 30;
const double HUMAN_MOVE_DIS = 10;

const double INFECT_DISTANCE = 20;
const double BAT_INFECT_P = 0.1;
const double VIRUS_HALFLIFE = 50;
const double INFECT_P = 0.1 / MAX_ATTACK;

const double VIRUS_MUTATE = 5;
const double VIRUS_MORTALITY_MUTATE = 0.05;

const int INIT_HUMANS = 200;
const int TOTAL_TIME = 1000;
#endif
