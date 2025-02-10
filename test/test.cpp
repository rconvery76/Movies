#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "movie.h"
#include "movie_factory.h"

TEST_CASE("Movie class") {
  SECTION("Movie class constructor valid")
 {
    Movie movie("Inception", "Christopher Nolan", 148, 1, 8.8);
    REQUIRE(movie.GetTitle() == "Inception");
    REQUIRE(movie.GetDirector() == "Christopher Nolan");
    REQUIRE(movie.GetRuntime() == 148);
    REQUIRE(movie.GetRating() == 8.8);
  }
    SECTION("Movie class constructor invalid")
    {
        //Negative Runtime
        REQUIRE_THROWS_AS(Movie("Inception", "Christopher Nolan", -148, 1, 8.8), std::invalid_argument);
        //Rating out of range
        REQUIRE_THROWS_AS(Movie("Inception", "Christopher Nolan", 148, 1, 11), std::invalid_argument);
        REQUIRE_THROWS_AS(Movie("Inception", "Christopher Nolan", 148, 1, -1), std::invalid_argument);
    }
}