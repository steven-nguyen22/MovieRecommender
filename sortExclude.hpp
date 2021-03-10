#ifndef __SORT_EXCLUDE_HPP__
#define __SORT_EXCLUDE_HPP__

#include <string>
#include <iostream>
#include <vector>

class sortExclude : public Sort{
private:
    Category excludeCat;
    
public: 
    sortExclude(const MovieData* movies, Category userCat){
    excludeCat = userCat;
    }
    
    std::vector<Movies> sort (const Movies * movies, Category userCat) const {
    	std::vector<Movies> MoviesLeft;
    for(int i = 0; i < movies.size(); i++)
        {
            if(strcmp(movies[i].getcategory(),excludeCat) == 0)
            {
               MoviesLeft.push_back(movies[i]);
            }
        }
        return MoviesLeft;
    }
    
};

#endif //__SORT_EXCLUDE_HPP__

