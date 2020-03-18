#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include "human.h"

using namespace std;
class Logger {
    ofstream of;
    ostream log_stream;
  public:
    Logger();
    Logger(string filename);
    void init();
    void log(int t, vector<Human> humans);
};
#endif
