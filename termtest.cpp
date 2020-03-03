//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <fstream>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"


string roda(const string & dado) {
    Terminal term(PROG);

    term.escreva(dado+'\n');
    auto res = term.leiaTudo();
    strip(res);
    return res;
}

TEST(TermTest, OK) {
    Terminal term(PROG);
    string res = term.leiaTudo();
    auto v = split(res,",");

    if (v.size() != 10) {
        FAIL() << "Deveriam ser apresentados 10 valores, mas seu programa apresentou "+to_string(v.size());
    }

    vector<int> vi;

    try {
        for (auto &s: v) vi.push_back(stoi(s));
    } catch(...) {
        FAIL() << "Deveriam ser apresentados 10 números inteiros, mas seu programa apresentou isto: "+res;
    }
}
