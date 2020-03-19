#include "random.h"
#include "human.h"
#include "virus.h"
#include "constants.h"
#include "logger.h"

int main() {
    Logger logger;

    logger.init();

    vector<vector<Human>> humans(2);
    humans[0] = vector<Human>(INIT_HUMANS);
    for (int t = 0; t < TOTAL_TIME; ++t) {
        vector<Human> &cur = humans[t%2];
        vector<Human> &nxt = humans[(t+1)%2];
        nxt.clear();

        map<pair<int,int>, vector<Human*>> human_map;

        for (Human &h: cur) {
            h.moveRandom();
            int x = (int)(h.pos.first / INFECT_DISTANCE);
            int y = (int)(h.pos.second / INFECT_DISTANCE);
            human_map[make_pair(x,y)].push_back(&h);
        }
        for (int i = 0; i < cur.size(); ++i) {
            int x = (int)(cur[i].pos.first / INFECT_DISTANCE);
            int y = (int)(cur[i].pos.second / INFECT_DISTANCE);
            for (int p = -1; p < 2; ++p) {
                for (int q = -1; q < 2; ++q) {
                    for (Human *h: human_map[make_pair(x+p, y+q)]) {
                        cur[i].interact(*h);
                    }
                }
            }
        }

        for (Human &h: cur) {
            if (!h.checkDie()) {
                nxt.push_back(h);
            }
        }

        logger.log(t, cur);
    }
    logger.close();
}
