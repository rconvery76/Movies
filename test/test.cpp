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

TEST_CASE("Create Movie")
{
    SECTION("valid movie creation")
    {
        std::vector<std::string> titles{"Movie 1", "Movie 2"};
        std::vector<std::string> directors{"d1", "d2"};
        std::vector<int> runtimes{137, 180};
        std::vector<int> ids{1, 2};
        std::vector<double> ratings{5.2, 10.0};
        std::vector<Movie*> movies = CreateMovies(titles, directors, runtimes, ids, ratings);
        REQUIRE(movies.size() == 2);
        REQUIRE(movies[0]->GetTitle() == "Movie 1");
        REQUIRE(movies[0]->GetDirector() == "d1");
        REQUIRE(movies[0]->GetRuntime() == 137);
        REQUIRE(movies[0]->GetRating() == 5.2);
        REQUIRE(movies[1]->GetTitle() == "Movie 2");
        REQUIRE(movies[1]->GetDirector() == "d2");
        REQUIRE(movies[1]->GetRuntime() == 180);
        REQUIRE(movies[1]->GetRating() == 10.0);
    }

    SECTION("invalid movie creation - different sizes")
    {
        std::vector<std::string> titles{"Movie 1", "Movie 2"};
        std::vector<std::string> directors{"d1", "d2", "d3"};
        std::vector<int> runtimes{137, 180};
        std::vector<int> ids{1, 2};
        std::vector<double> ratings{5.2, 11.0};
        REQUIRE_THROWS_AS(CreateMovies(titles, directors, runtimes, ids, ratings), std::invalid_argument);
    }

    SECTION("invalid movie creation - negative runtime")
    {
        std::vector<std::string> titles{"Movie 1", "Movie 2"};
        std::vector<std::string> directors{"d1", "d2"};
        std::vector<int> runtimes{137, -180};
        std::vector<int> ids{1, 2};
        std::vector<double> ratings{5.2, 10.0};
        REQUIRE_THROWS_AS(CreateMovies(titles, directors, runtimes, ids, ratings), std::invalid_argument);
    }

    SECTION("invalid movie creation - rating out of range [high]")
    {
        std::vector<std::string> titles{"Movie 1", "Movie 2"};
        std::vector<std::string> directors{"d1", "d2"};
        std::vector<int> runtimes{137, 180};
        std::vector<int> ids{1, 2};
        std::vector<double> ratings{5.2, 11.0};
        REQUIRE_THROWS_AS(CreateMovies(titles, directors, runtimes, ids, ratings), std::invalid_argument);
    }
    
    SECTION("invalid movie creation - rating out of range [low]")
    {
        std::vector<std::string> titles{"Movie 1", "Movie 2"};
        std::vector<std::string> directors{"d1", "d2"};
        std::vector<int> runtimes{137, 180};
        std::vector<int> ids{1, 2};
        std::vector<double> ratings{5.2, -1.0};
        REQUIRE_THROWS_AS(CreateMovies(titles, directors, runtimes, ids, ratings), std::invalid_argument);
    }
}