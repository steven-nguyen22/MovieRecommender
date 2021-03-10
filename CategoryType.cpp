#include "CategoryType.hpp"
#include "MovieType.hpp"

#include <vector>
#include <string>

using namespace std;


//either returning or pushing to private vectors 
string CategoryType::getMultimediaTitle(){
  return this->title_of_media;
}

vector<string> CategoryType::getGenres(){
  return this->genres_list;
}

int CategoryType::getMultimediaType(){
  return 2;
}

void CategoryType::addMovie(MovieType* movie_to_add){
  this->list_of_movies.push_back(movie_to_add);
}

void CategoryType::addCategory(CategoryType* category_to_add){
  this->list_of_categories.push_back(category_to_add);
}

void CategoryType::setMultimediaTitle(string title_tobe_added){
  this->title_of_media =  title_tobe_added;
}

