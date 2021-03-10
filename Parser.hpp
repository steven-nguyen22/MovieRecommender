#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>
#include <vector>
#include <map>
#include "MovieType.hpp"
#include "StrategyPattern.hpp"

using namespace std; 

class StrategyPattern; 

class FactoryPattern {

  private: 
    map<string, MovieType*> movie_map;
    StrategyPattern* strategy_functions; 

  public: 
    vector<MovieType*> movie_data_vector;
    void setFilterFunction(StrategyPattern* filterStrategyType){ strategy_functions = filterStrategyType;}
    void parseMovieInfo(); 
    void parseVideoData();
    vector<MovieType*> getMovieVector();
    void setMovieVector(vector<MovieType*> movVec);
    void filtering_strategy();
    bool movieExists(string movName);
    map<string, MovieType*> getMovieMap();
};

#endif

