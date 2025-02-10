#include "movie.h"

#include <iostream>

//Movie constructor
Movie::Movie(std::string title, std::string director, int runtime, int id, double rating)
    : title(title), director(director), runtime(runtime), id(id), rating(rating) {
    if (runtime < 0) {
        throw std::invalid_argument("Runtime must be greater than or equal to 0");
    }
    if (rating < 0 || rating > 10) {
        throw std::invalid_argument("Rating must be between 0 and 10");
    }
}

//GetTitle() returns title
std::string Movie::GetTitle() {
  return title;
}

//GetDirector() returns title
std::string Movie::GetDirector() {
  return director;
}

//GetRating() returns rating
double Movie::GetRating() {
  return rating;
}

//GetRuntime() returns the runtime
int Movie::GetRuntime() {
  return runtime;
}

//PrintMovieData() to print details
void Movie::PrintMovieData(){
    std::cout << "Title: " << title << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Runtime: " << runtime << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}