#ifdef MOVIE_H
#define MOVIE_H


class Movie {
    private:
      int id;
    
      std::string title;
      std::string director;
      int runtime; // runtime in minutes >= 0
      double rating; // range 0-10

    public:

      Movie(std::string t, std::string d, int r, int i, double rate);

      GetTitle() returns title
      GetDirector() returns title
      GetRating() returns rating
      GetRuntime() returns the runtime
    
      void PrintMovieData(); // to print details
  };

#endif