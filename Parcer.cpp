#include "MovieType.hpp"
#include "CategoryType.hpp"
#include "Multimedia.hpp"
#include "Parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include <stdlib.h>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

void FactoryPattern::parseMovieInfo(){

    string read_line = "";
    
    string input_file = "OGMovieData.csv";

    ifstream file_stream;
    file_stream.open(input_file);

    string movie_title = "";
    string movie_description = "";
    string movie_director = ""; 
    string movie_genre = "";
    string movie_actor = "";
    
    int year;
    double score;
    vector<string> actors;
    vector<string> genres_list;

    if (!file_stream.is_open()) {
      cout<<"Error couldnt open "<<input_file<<endl;
      return;
    }

    while(getline(file_stream, read_line)){
        tokenizer<escaped_list_separator<char> > tok(read_line);
        tokenizer<escaped_list_separator<char> >::iterator token_iterator = tok.begin();
        
        MovieType* current_movie = new MovieType();
        
        movie_title = *token_iterator;
        ++token_iterator;

        for(int i =0; i < token_iterator->size(); i++){
            if(token_iterator->at(i) != ','){
                movie_genre+= token_iterator->at(i);
            }
            if(token_iterator->at(i) == ','){
                genres_list.push_back(movie_genre);
                movie_genre = "";
            }
        }
        genres_list.push_back(movie_genre);
        movie_genre = "";
        ++token_iterator;

        movie_description = *token_iterator;
        ++token_iterator;

        movie_director = *token_iterator;
        ++token_iterator;
        
        for(int i =0; i < token_iterator->size(); i++){
            if(token_iterator->at(i) != ','){
                movie_actor+= token_iterator->at(i);
            }
            if(token_iterator->at(i) == ','){
                actors.push_back(movie_actor);
                movie_actor = "";
            }
        }
        actors.push_back(movie_actor);
        movie_actor = "";
        ++token_iterator;

        year = stoi(*token_iterator);
        ++token_iterator;

        score = stod(*token_iterator);
        
        current_movie->setMultimediaTitle(movie_title);
        current_movie->setGenresData(genres_list);
        current_movie->addDescriptionData(movie_description);
        current_movie->addDirectorData(movie_director);
        current_movie->addActorsData(actors);
        current_movie->addProductionYearData(year);
        current_movie->addRatingData(score);

        movie_map.emplace(movie_title, current_movie);
        movie_data_vector.push_back(current_movie);

        genres_list.clear();
        actors.clear();
        movie_description = "";
        movie_title = "";
        year = 0;
        score = 0.0;

    }
        
    file_stream.close();

    return;
}

vector<MovieType*> FactoryPattern::getMovieVector(){
  
  return this->movie_data_vector;
}

void FactoryPattern::filtering_strategy(){
  strategy_functions->filtering_strategy(this);
}

void FactoryPattern::setMovieVector(vector<MovieType*> movVec){
    this->movie_data_vector = movVec;
}

bool FactoryPattern::movieExists(string movName){
  map<string, MovieType*>::iterator it;
  it = movie_map.find(movName);
  if(it == movie_map.end()){
    return false;
  }
  return true;
}

 map<string, MovieType*> FactoryPattern::getMovieMap(){
   return this->movie_map;
 }

