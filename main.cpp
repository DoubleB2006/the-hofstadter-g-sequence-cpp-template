#include <iostream>
#include "src/factorial.hpp"

int main() {
    std::cout << "Hofstadter G sequence (naive):" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "G_naive(" << i << ") = " << G_naive(i) << std::endl;
    }

    std::cout << "\nHofstadter G sequence (memoized):" << std::endl;
    for (int i = 0; i <= 50; i++) {
        std::cout << "G_memo(" << i << ") = " << G_memo(i) << std::endl;
    }

    return 0;
}
