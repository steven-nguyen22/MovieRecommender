#ifndef __SORT_HPP__
#define __SORT_HPP__

#include <string>
#include <iostream>
#include <vector>

class Sort 
{
	public:
		virtual ~Sort() = default;

		virtual std::vector<Movies> sort(const MovieData* movies, Category userCat) const = 0;
};

//helper class
class Sort_Many : public Sort 
{
	protected:
		MoviesData* movie

	public:
		Sort_Many(const MovieData* temp) {
			movie = temp;
		}

		virtual std::vector<Movies> sort(const MovieData* movies, Category userCat) const {
			std::vector<Movies> movieList = new std::vector<Movies>;
			return movieList;
			delete movieList;
		}

		//Derived classes can implement this simpler interface for multiple categories
		virtual std::vector<Movies> sort(const MovieData* movies, Category userCat1, Category userCat2) const = 0;
};


#endif //__SORT_HPP__
