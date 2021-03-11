#include "MovieType.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//returning members inherited from MovieType header and Multimedia 
string MovieType::getMultimediaTitle(){
  return this->title_of_media;
}

vector<string> MovieType::getListofActors() {
  return this->list_of_cast;
}
int MovieType::getProductionYear(){
  return this->year_of_production;
}
int MovieType::getMultimediaType(){
  return 1;
}

double MovieType::getMovieRating(){
  return movie_rating;
}

void MovieType::setMultimediaTitle(string title_tobe_added){
  this->title_of_media = title_tobe_added;
}
void MovieType::addActorsData(vector<string> actors_tobe_added){
  list_of_cast = actors_tobe_added;
}

void MovieType::addGenreData(string genre_tobe_added){
  this->genres_list.push_back(genre_tobe_added);
}

void MovieType::setGenresData(vector<string> genres_tobe_added){
  this->genres_list = genres_tobe_added;
}

void MovieType::addDirectorData(string movie_director){
  this->movie_director = movie_director;
}

void MovieType::addProductionYearData(int year_of_production){
  this->year_of_production = year_of_production;
}

void MovieType::addDescriptionData(string description_of_movie){
  this->description_of_movie = description_of_movie;
}

void MovieType::addRatingData(double movie_rating){
  this->movie_rating = movie_rating;
}

string MovieType::getDirector(){
  return this->movie_director;
}

string MovieType::getDescription(){
  return this->description_of_movie;
}
vector<string> MovieType::getGenres(){
  return this->genres_list;
}

void MovieType::displayData(){
    cout<<endl<<this->title_of_media<<": "<<movie_rating<<endl<< "Director: "<<movie_director<<endl<<"Genres: ";
    
    for(int i = 0; i < genres_list.size(); i++){
        cout<<genres_list.at(i)<<" ";
    }
    cout<<endl<<"Description: "<<description_of_movie<<endl<<"Cast: ";
    for(int j = 0; j < list_of_cast.size(); j++){
        cout<<list_of_cast.at(j)<<" ";
    }
    cout<<endl<<year_of_production<<endl;

    return;
}

