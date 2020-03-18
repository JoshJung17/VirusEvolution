#include "random.h"
#include "human.h"
#include "virus.h"
#include "constants.h"

int main() {
    double avg_viruses;
    int pop;
    cout << "timestep,pop,avg_viruses" << endl;

    vector<vector<Human>> humans(2);
    humans[0] = vector<Human>(INIT_HUMANS);
    for (int t = 0; t < TOTAL_TIME; ++t) {
        vector<Human> &cur = humans[t%2];
        vector<Human> &nxt = humans[(t+1)%2];
        nxt.clear();

        avg_viruses = 0;
        for (Human &h: cur) {
            h.moveRandom();
            avg_viruses += h.viruses.size();
        }
        pop = cur.size();
        avg_viruses /= pop;
        for (int i = 0; i < cur.size(); ++i) {
            for (int j = i+1; j < cur.size(); ++j) {
                if (randUnif() < 0.5) {
                    cur[i].interact(cur[j]);
                }
                else {
                    cur[j].interact(cur[i]);
                }
            }
        }

        for (Human &h: cur) {
            if (!h.checkDie()) {
                nxt.push_back(h);
            }
        }
        cout << t << ',' << pop << ',' << avg_viruses << endl;
    }
}
