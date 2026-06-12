#include "classes.h"

BallRemover::BallRemover() {}

void BallRemover::process(int color) {
    if (!st.empty() && st.top().first == color) {
        st.top().second++;
    }
    else {
        if (!st.empty() && st.top().second >= 3) {
            st.pop();
            if (!st.empty() && st.top().first == color) {
                st.top().second++;
            }
            else {
                st.push({ color, 1 });
            }
        }
        else {
            st.push({ color, 1 });
        }
    }
}

int BallRemover::getDestroyed(int n) const {
    std::stack<std::pair<int, int>> temp = st;

    if (!temp.empty() && temp.top().second >= 3) {
        temp.pop();
    }

    int remaining = 0;
    while (!temp.empty()) {
        remaining += temp.top().second;
        temp.pop();
    }

    return n - remaining;
}

void BallRemover::clear() {
    while (!st.empty()) st.pop();
}