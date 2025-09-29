#include "hofstadter.hpp"
#include <stdexcept>

// ---------- Naive recursive version ----------
int G_naive(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be >= 0");
    }
    if (n == 0) {
        return 0;
    }
    return n - G_naive(G_naive(n - 1));
}

// ---------- Memoized (optimized) version ----------
static std::vector<int> memo(1, 0); // memo[0] = 0

int G_memo(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be >= 0");
    }

    if ((int)memo.size() <= n) {
        memo.resize(n + 1, -1);
        memo[0] = 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int inner = G_memo(G_memo(n - 1));
    int result = n - inner;
    memo[n] = result;
    return result;
}
