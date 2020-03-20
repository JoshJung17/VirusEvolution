#ifndef CONSTANTS_H
#define CONSTANTS_H
const double PI = 3.1415926535;
const double TIME_RES = 3;
const double VECTOR_SIZE = 10;
const double MAX_IMMUNE = 9;
const double MAX_ATTACK = 1;

const double BOARD_WIDTH = 800;
const double BOARD_HEIGHT = 600;
const double BAT_CAVE_X = 80;
const double BAT_CAVE_Y = 60;
const double HUMAN_MOVE_DIS = 30 / TIME_RES;
const double HUMAN_THETA = 60 * PI / 180 / sqrt(TIME_RES);

const double INFECT_DISTANCE = 30;
const double BAT_INFECT_P = 0.3 / TIME_RES;
const double VIRUS_HALFLIFE = 50 * TIME_RES;
const double INFECT_P = 0.2 / MAX_ATTACK / TIME_RES;

const double VIRUS_MUTATE = 0.01;
const double VIRUS_MORTALITY_MUTATE = 0.05 / TIME_RES;
const double SAME_VIRUS_THR = 0.03;

const double BIRTH_RATE = 0.02;
const double DEATH_RATE = 0.02;

const int INIT_HUMANS = 500;
const int TOTAL_TIME = 2000;
#endif
