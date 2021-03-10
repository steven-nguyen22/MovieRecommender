#ifndef __CATEGORYTYPE_HPP__
#define __CATEGORYTYPE_HPP__

#include <vector>
#include <string>

#include "MovieType.hpp"
#include "Multimedia.hpp"

using namespace std;

class CategoryType : public Multimedia {
  private:
	vector<MovieType *> list_of_movies; //main vector
        vector<CategoryType *> list_of_categories; //category collection to remove or add 

  public:
        CategoryType() : Multimedia() {};  //set default multimedia (new set)
        CategoryType(string title_of_media, vector<string> genres_list): Multimedia(title_of_media, genres_list){}; //given already
        void setMultimediaTitle(string title_tobe_added);
		//initiate multimedia var
        string getMultimediaTitle();
		//get title / genres
        vector<string> getGenres();
        int getMultimediaType();
		// functions for category
		// 	want to add movies and categories to our private vectors/ "library"
	void addMovie(MovieType* movie_to_add);
	void addCategory(CategoryType* category_to_add);
};
#endif

