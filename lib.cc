#include <bits/stdc++.h>
#include "random.h"

using namespace std;
vector<double> change(vector<double> v, double mutate_range) {
    vector<double> w(v.size());
    for (int i = 0; i < v.size(); ++i) {
        w[i] = v[i] + (randUnif() - 0.5) * mutate_range;
    }
    return w;
}