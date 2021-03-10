#ifndef _FILTERSTRATEGY_HPP_
#define _FILTERSTRATEGY_HPP_

#include "FilterStrategy.hpp"
#include "MovieType.hpp"
#include "StrategyPattern.hpp"
#include "Parser.hpp"
#include "Multimedia.hpp"

#include <string>

using namespace std; 

class CategoryType; 

class TopTenStrategy : public StrategyPattern {
  public:
    TopTenStrategy():StrategyPattern(){};
    void filtering_strategy(FactoryPattern* movie);
};

class TopTenRecentStrategy : public StrategyPattern{
  private:
    int year;

  public:
    TopTenRecentStrategy():StrategyPattern(){};
    TopTenRecentStrategy(int year) {this->year = year;}
    int getProductionYear(); 
    void filtering_strategy(FactoryPattern* movie);
};

class ActorStrategy : public StrategyPattern{
  private:
    string actor;

  public:
    ActorStrategy():StrategyPattern(){};
    ActorStrategy(string actor) {this->actor= actor;}
    string getActor(); 
    void filtering_strategy(FactoryPattern* movie);
};

class GenreStrategy : public StrategyPattern{
  private:
    string genre;

  public:
    GenreStrategy():StrategyPattern(){};
    GenreStrategy(string genre) {this->genre = genre;}
    string getGenre();
    void filtering_strategy(FactoryPattern* movie);
};

class DirectorStrategy : public StrategyPattern {
  private:
    string movie_director;

  public:
    DirectorStrategy():StrategyPattern(){};
    DirectorStrategy(string movie_director) {this->movie_director = movie_director;} 
    string getDirector(); 
    void filtering_strategy(FactoryPattern* movie);
};

#endif //__FILTER_STRATEGY_HPP__
