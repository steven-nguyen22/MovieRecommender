#ifndef __SORT_CATEGORY_HPP__
#define __SORT_CATEGORY_HPP__

#include <string>
#include <iostream>
#include <vector>


class sortCategory : public Sort{
private: 
    Category chosenCat;
public: 
    sortCategory(const MovieData* movies, Category userCat){
    chosenCat = userCat;
    }

    std::vector<Movies> sort (const Movies * movies, Category userCat) const {
    	std::vector<Movies> selectedMovies;
        for(int i = 0; i < movies.size(); i++)
        {
            if(strcmp(movies[i].getcategory(),chosenCat))
            {
               selectedMovies.push_back(movies[i]);
            }
        }
        return selectedMovies;
    }

};

#endif //__SORT_CATEGORY_HPP__

