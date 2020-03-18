#include "logger.h"
#include <bits/stdc++.h>

Logger::Logger(): of{}, log_stream{cout.rdbuf()} {}

Logger::Logger(string filename): of{}, log_stream{(of.open(filename), of.rdbuf())} {}

void Logger::init() {
    log_stream << "t,pop,avg_viruses,virus_1_cnt,virus_1_genome\n";
}

void Logger::log(int t, vector<Human> humans) {
    log_stream << t << ',' << humans.size() << ',';
    int tot_viruses = 0;
    vector<const Virus*> all_viruses;
    for (const Human &h: humans) {
        tot_viruses += h.viruses.size();
        for (const Virus &v: h.viruses)
            all_viruses.push_back(&v);
    }
    log_stream << (double)tot_viruses/humans.size() << ',';
    vector<int> cnts(all_viruses.size());
    int maxi = 0;
    int maxIdx = 0;
    for (int i = 0; i < all_viruses.size(); ++i) {
        const Virus *v1 = all_viruses[i];
        for (int j = 0; j < all_viruses.size(); ++j) {
            const Virus *v2 = all_viruses[j];
            if (v1->is_same(*v2)) {
                ++cnts[i];
                if (cnts[i] > maxi) {
                    maxi = cnts[i];
                    maxIdx = i;
                }
            }
        }
    }
    if (all_viruses.size() == 0) {
        log_stream << ",\n";
    }
    else {
        log_stream << maxi << ',';
        log_stream << '"';
        for (double c: all_viruses[maxIdx]->attack) {
            log_stream << c << ",";
        }
        log_stream << "\"\n";
    }

    /*
    sort(all_viruses.begin(), all_viruses.end(), [](const Virus *a, const Virus *b) { 
        return a->attack < b->attack;
    });
    for (int i = 0; i < all_viruses.size(); ++i) {
        Virus *v1 = all_viruses[i];
        for (int j = i; j < all_viruses.size(); ++j) {
            Virus *v2 = all_viruses[j];
        }
    }
    */
}

