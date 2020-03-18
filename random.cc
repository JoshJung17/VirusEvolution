#include "random.h"
#include <bits/stdc++.h>
#include <random>
double randUnif() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> d(0.0, 1.0);
    return d(gen);
}
