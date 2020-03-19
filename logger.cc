#include "logger.h"
#include "virus.h"
#include <bits/stdc++.h>

Logger::Logger(): of{}, log_stream{cout.rdbuf()} {}

Logger::Logger(string filename): of{}, log_stream{(of.open(filename), of.rdbuf())} {}

void Logger::init() {
    log_stream << "[";
}

string Logger::key(string key) {
    return "\"" + key + "\": ";
}

void Logger::log(int t, vector<Human> humans) {
    if (t>0)
        log_stream << ",\n";
    log_stream << "{ ";
    log_stream << key("iteration") << t;
    log_stream << ", ";
    log_stream << key("num_humans") << humans.size();
    log_stream << ", ";
    log_stream << key("humans") << "[ ";
    bool f1 = 0;
    for (Human &h: humans) {
        if (f1) log_stream << ",\n";
        f1 = 1;
        log_stream << "{ ";
        log_stream << key("x") << h.pos.first << ", ";
        log_stream << key("y") << h.pos.second << ", ";
        log_stream << key("num_viruses") << h.viruses.size() << ", ";
        log_stream << key("viruses") << "[ ";
        bool f2 = 0;
        for (Virus &v: h.viruses) {
            if (f2) log_stream << ", ";
            f2 = 1;
            log_stream << "[ ";
            bool f3 = 0;
            for (double c: v.attack) {
                if (f3) log_stream << ", ";
                f3 = 1;
                log_stream << c;
            }
            log_stream << "]";
        }
        log_stream << "]";
        log_stream << "}";
    }
    log_stream << "]";
    log_stream << "}";
}

void Logger::close() {
    log_stream << "]" << endl;
}
