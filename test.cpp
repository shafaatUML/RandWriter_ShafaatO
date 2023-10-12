// Copyright [2022] <Shafaat Osmani>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE unit_testing
#include <boost/test/unit_test.hpp>
#include "RandWriter.hpp"

BOOST_AUTO_TEST_CASE(freq) {
RandWriter k1("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_THROW(k1.freq("gaaa"), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(freqW) {
RandWriter k1("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_NO_THROW(k1.freq("ga"));
}
BOOST_AUTO_TEST_CASE(freqc) {
RandWriter k1("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_THROW(k1.freq("gaaa", 'g'), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(freqcW) {
RandWriter k1("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_NO_THROW(k1.freq("ga", 'g'));
}
BOOST_AUTO_TEST_CASE(kRand) {
RandWriter k1("gagggagaggcgagaaa", 2);
RandWriter k2("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_THROW(k1.kRand("gaaa"), std::runtime_error);
BOOST_REQUIRE_THROW(k2.kRand("str"), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(kRandW) {
RandWriter k1("gagggagaggcgagaaa", 2);
BOOST_REQUIRE_NO_THROW(k1.kRand("ga"));
}
BOOST_AUTO_TEST_CASE(gen) {
    RandWriter k1("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_THROW(k1.generate("gaaa", 1), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(genW) {
    RandWriter k1("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_NO_THROW(k1.generate("ga", 10));
}
