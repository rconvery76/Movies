#include "movie_factory.h"


//movie_factory.cpp
 /*
 Write function definition CreateMovies() that 
 accepts (attributes in the below order)
   vector of titles, 
   vector of directors, 
   vector of runtimes, 
   vector of ids, 
   vector of ratings and 
 return 
   vector of pointers of Movie objects
 */

std::vector<Movie*> CreateMovies(std::vector<std::string> titles, std::vector<std::string> directors, std::vector<int> runtimes, std::vector<int> ids, std::vector<double> ratings) {

    //Validate Titles, Directors, Runtimes, IDs, Ratings
    if (titles.size() != directors.size() || titles.size() != runtimes.size() || titles.size() != ids.size() || titles.size() != ratings.size()) {
        throw std::invalid_argument("All vectors must be of the same size");
    }

    //Validate Runtime, Rating
    for (int i = 0; i < runtimes.size(); i++) {
        if (runtimes[i] < 0) {
            throw std::invalid_argument("Runtime must be >= 0");
        }
        if(ratings[i] < 0 || ratings[i] > 10) {
            throw std::invalid_argument("Rating must be in the range 0-10");
        }
    }

    //Create Movies using the vectors if all inputs are valid
    std::vector<Movie*> movies;
    for (int i = 0; i < titles.size(); i++) {
        Movie* movie = new Movie(titles[i], directors[i], runtimes[i], ids[i], ratings[i]);
        movies.push_back(movie);
    }
    return movies;