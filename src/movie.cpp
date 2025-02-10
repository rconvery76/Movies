#include "movie.h"



//GetTitle() returns title
Movie::GetTitle() {
  return title;
}

//GetDirector() returns title
Movie::GetDirector() {
  return director;
}

//GetRating() returns rating
Movie::GetRating() {
  return rating;
}

//GetRuntime() returns the runtime
Movie::GetRuntime() {
  return runtime;
}

//PrintMovieData() to print details
void PrintMovieData(){
    std::cout << "Title: " << title << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Runtime: " << runtime << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}