#ifndef __MOVIE_DATA_HPP__
#define __MOVIE_DATA_HPP__

#include <string>
#include <iostream>
#include <vector>

class Sort;

class MovieData 
{
	private:
		std::vector<Movies> listOfMovies;
		Sort* sort = nullptr;

	public:
		~MovieData();

		std::vector<Movies> getListMovies() 
		{
			return listOfMovies;
		}

};

#endif //__MOVIE_DATA_HPP__
