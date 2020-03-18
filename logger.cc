#include "logger.h"
#include <bits/stdc++.h>

Logger::Logger(): of{}, log_stream{cout.rdbuf()} {}

Logger::Logger(string filename): of{}, log_stream{(of.open(filename), of.rdbuf())} {}

void Logger::init() {
    log_stream << "t,pop,avg_viruses\n";
}

void Logger::log(int t, vector<Human> humans) {
    log_stream << t << ',' << humans.size() << ',';
    int tot_viruses = 0;
    for (const Human &h: humans) {
        tot_viruses += h.viruses.size();
    }
    log_stream << (double)tot_viruses/humans.size() << '\n';
}
