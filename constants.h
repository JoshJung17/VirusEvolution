#ifndef CONSTANTS_H
#define CONSTANTS_H
const double VECTOR_SIZE = 10;
const double MAX_IMMUNE = 10;
const double MAX_ATTACK = 1;

const double BOARD_WIDTH = 800;
const double BOARD_HEIGHT = 600;
const double BAT_CAVE_X = 80;
const double BAT_CAVE_Y = 60;
const double HUMAN_MOVE_DIS = 50;

const double INFECT_DISTANCE = 40;
const double BAT_INFECT_P = 0.05;
const double VIRUS_HALFLIFE = 50;
const double INFECT_P = 0.5 / MAX_ATTACK;

const double VIRUS_MUTATE = 0.01;
const double VIRUS_MORTALITY_MUTATE = 0.05;
const double SAME_VIRUS_THR = 0.03;

const int INIT_HUMANS = 500;
const int TOTAL_TIME = 2000;
#endif
