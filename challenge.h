#ifndef CHALLENGE_H
#define CHALLENGE_H
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Challenge {
    public:
        virtual void run() = 0;
        virtual ~Challenge() {}
};

#endif // CHALLENGE_H