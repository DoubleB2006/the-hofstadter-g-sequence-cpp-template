#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hofstadter.hpp"   // contains G_naive and G_memo

TEST_CASE( "G_naive computes small Hofstadter G values correctly" ) {
    REQUIRE( G_naive(0) == 0 );
    REQUIRE( G_naive(1) == 1 );
    REQUIRE( G_naive(2) == 1 );
    REQUIRE( G_naive(3) == 2 );
    REQUIRE( G_naive(4) == 3 );
    REQUIRE( G_naive(5) == 3 );
    REQUIRE( G_naive(6) == 4 );
    REQUIRE( G_naive(7) == 4 );
    REQUIRE( G_naive(8) == 5 );
    REQUIRE( G_naive(9) == 6 );
    REQUIRE( G_naive(10) == 6 );
}

TEST_CASE( "G_memo computes the same Hofstadter G values correctly" ) {
    for (int n = 0; n <= 50; ++n) {
        REQUIRE( G_memo(n) == G_naive(n) );
    }
}

TEST_CASE( "Benchmarking Hofstadter G (naive vs memoized)" ) {
    BENCHMARK("G_naive(20)") {
        return G_naive(20);
    };

    BENCHMARK("G_naive(25)") {
        return G_naive(25);
    };

    BENCHMARK("G_memo(500)") {
        return G_memo(500);
    };

    BENCHMARK("G_memo(5000)") {
        return G_memo(5000);
    };
}
