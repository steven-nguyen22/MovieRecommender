#ifndef __SORT_MULTIPLE_HPP__
#define __SORT_MULTIPLE_HPP__

//#include "category.hpp"

#include <string>
#include <iostream>
#include <vector>

class Sort_Multiple : public Sort_Many
{
	public:
		Sort_Multiple(const MovieData* movie, Category& new_userCategory1, Category& new_userCategory2) : Sort_Many(movie) {
			userCat1 = new_userCatgegory1;
			userCat2 = new_userCategory2;
		}

		virtual std::vector<Movies> sort(const MovieData* movies, Category cat1, Category cat2) const {
			std::vector<Movies> vector1;
			std::vector<Movies> vector2;

			std::vector<Movies> temp = movies->getListMovies();
			
			//need code to sort vector of movies by cat1 and put those into vector1
			//
			//movie functions have not been made yet, this is just temporary
			for(auto i : temp) {
				if(i.getCat() == userCat1)
					vector1.push_back(i);
				else if(i.getCat() == userCat2)
					vector2.push_back(i);
			}			

			//need code to sort vector of movies by cat2 and put those into vector2 

			//code to combine both the vectors together
			vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
			return vector1; 
		}

	private:
		Category userCat1;
		Category userCat2;

}; 

#endif //_SORT_MULTIPLE_HPP__
