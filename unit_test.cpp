#include "gtest/gtest.h"
#include "MovieType.hpp"
#include "CategoryType.hpp"
#include "FilterStrategy.hpp"
#include "Parser.hpp"
#include "StrategyPattern.hpp"
#include "main.cpp"


#include <vector> 
#include <string>

using namespace std;


//FactoryPattern* movie_parser = new FactoryPattern();
//movie_parser->parseMovieInfo();
//

MovieType* movie;
movie.setMultimediaTitle("Bob The Builder");
MovieType* movie2;
movie.setMultimediaTitle("Bob The Builder2");

CategoryType* movie_list = new CategoryType();
vector<MovieType*>  listMovies;
vector<CategoryType*> listCateg;

TEST(MovieTest, SetTitles1) {
	listMovies.addMovie(movie);
	listMovies.addMovie(movie2);

	listMovies[0].setMultiMediaTitle("Bob The Builder");
        listMovies[1].setMultiMediaTitle("Bob The Builder2");

	EXPECT_EQ(listMovies[0]->getMultimediaTitle(), "Bob The Builder");
	EXPECT_EQ(listMovies[1]->getMultimediaTitle(), "Bob The Builder2");
}


TEST(MovieTest, SetTitles2) {
        listMovies.addMovie(movie);
        listMovies.addMovie(movie2);
	
	listMovies[0].setMultiMediaTitle("Example1");
	listMovies[1].setMultiMediaTitle("Example2");
        EXPECT_EQ(listMovies[0]->getMultimediaTitle(), "Example1");
        EXPECT_EQ(listMovies[1]->getMultimediaTitle(), "Example2");
}

TEST(MovieTest, AddMovies) {
        listMovies.addMovie(movie);
        listMovies.addMovie(movie2);
	
	string temp1;
	string temp2;
	
	for (int i = 0; i < listMovies.len(); ++i) {
		if ( i == 0 ) { 
			temp1 = listMovies[0].getMultimediaTitle();
		}
		else {
			temp2 = listMovies[0].getMultimediaTitle(); 
		}
	}
        EXPECT_EQ(temp1, "Bob The Builder");
        EXPECT_EQ(temp2,  "Bob The Builder2");
}

TEST(MovieTest, getMovie) {
 	movie.setMultiMediaTitle("example1");
	movie2.setMultiMediaTitle("example2");
       
	
        EXPECT_EQ(movie->getMultiMediaTitle(), "example1");
        EXPECT_EQ(movie2->getMultiMediaTitle(), "example2");
}


TEST(MovieTest, AddCategory) {
        listMovies.addMovie(movie);
        listMovies.addMovie(movie2);
        EXPECT_EQ(movie->getMultimediaTitle(), "Bob The Builder");
        EXPECT_EQ(movie2->getMultimediaTitle(), "Bob The Builder2");
}

vector<string> cast;
TEST(MovieTest, actorsTestPrint) {
	vector<string> example = {"John Bob", "Ben Affleck"};
	
	cast.AddActorsData(example);

	string actors;
	for (int i = 0; i < cast.len(); ++i) {
		actors += cast[i] + " ";
	}
	EXPECT_EQ(actors, "John Bob Ben Affleck");
}
cast = {""};
TEST(MovieTest, actorsTestPrint2) {
        vector<string> example = {"Alex Rider", "Jim Carrey"};

        cast.AddActorsData(example);

        string actors;
        for (int i = 0; i < cast.len(); ++i) {
                actors += cast[i] + " ";
        }
        EXPECT_EQ(actors, "Alex Rider Jim Carrey");
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}	
