fndef __MOVIETYPE_HPP__
#define __MOVIETYPE_HPP__

#include "Multimedia.hpp"
#include <string>
#include <vector>

using namespace std;

class MovieType : public Multimedia {

  private:
    vector<string> list_of_cast;
    string movie_director;
    string description_of_movie;
    int year_of_production;
    double movie_rating;

  public:
    
    MovieType() : Multimedia(){}
    MovieType(string title_of_media, vector<string>genres_list) : Multimedia(title_of_media, genres_list){}
   void setMultimediaTitle(string title_tobe_added);
    void addActorsData(vector<string> actors_tobe_added);
    void addGenreData(string genre_tobe_added);
    void setGenresData(vector<string> genres_tobe_added);
    void addDirectorData(string movie_director);
    void addProductionYearData(int year_of_production);
    void addDescriptionData(string description_of_movie);
    void addRatingData(double movie_rating);
    
    void displayData();

 double getMovieRating();
    vector<string> getListofActors();
    int getMultimediaType();
    int getProductionYear();
    string getDescription();
    string getDirector();

string getMultimediaTitle();
    vector<string> getGenres();
};

#endif


