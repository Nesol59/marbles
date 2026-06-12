#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <stack>

class BallRemover {
private:
    std::stack<std::pair<int, int>> st;

public:
    BallRemover();
    void process(int color);
    int getDestroyed(int n) const;
    void clear();
};

#endif