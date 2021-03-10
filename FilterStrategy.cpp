#include "FilterStrategy.hpp"
#include <string>
#include <iostream>
#include "CategoryType.hpp"
#include "MovieType.hpp"
#include <vector>
#include "Parser.hpp"

using namespace std;

void TopTenStrategy::filtering_strategy(FactoryPattern* movie) {
    vector<MovieType*> temporary_holder = movie->getMovieVector();
    for (unsigned int i = 0; i < 10; ++i) {
        cout << i + 1 << ") " << temporary_holder.at(i)->getMultimediaTitle() << ": " << temporary_holder.at(i)->getMovieRating() << endl << temporary_holder.at(i)->getDescription() << endl << endl;
    }
    return;
}

void TopTenRecentStrategy::filtering_strategy(FactoryPattern* movie) {
    int year = this->year;
    vector<MovieType*> temporary_holder = movie->getMovieVector();
    vector<MovieType*> top_10_recent;
    int counter = 0;
    for (unsigned int i = 0; i < temporary_holder.size() && top_10_recent.size() < 10; ++i) {
        if (temporary_holder.at(i)->getProductionYear() == year) {
            top_10_recent.push_back(temporary_holder.at(i));
            cout << counter + 1 << ") " << temporary_holder.at(i)->getMultimediaTitle() << ": " << temporary_holder.at(i)->getMovieRating() << endl << temporary_holder.at(i)->getDescription() << endl << endl;
            counter++;
        }

    }
}
int TopTenRecentStrategy::getProductionYear() {
    return this->year;
}

void ActorStrategy::filtering_strategy(FactoryPattern* movie) {
    string actor = this->actor;
    vector<MovieType*> temporary_holder = movie->getMovieVector();
    int i = 0;
    int counter = 0;
    while (i < 10 && counter <= temporary_holder.size() - 1) {
        vector<string>temp1 = temporary_holder.at(counter)->getListofActors();
        for (int j = 0; j < temp1.size(); j++) {
            if (temp1.at(j) == actor) {
                cout << counter + 1 << ") " << temporary_holder.at(counter)->getMultimediaTitle() << ": " << temporary_holder.at(counter)->getMovieRating() << endl << temporary_holder.at(counter)->getDescription() << endl << endl;
                i++;
                break;
            }
        }
        counter++;
    }
}

string ActorStrategy::getActor() {
    return this->actor;
}

void GenreStrategy::filtering_strategy(FactoryPattern* movie) {
    string genre = this->genre;
    vector<MovieType*> temporary_holder = movie->getMovieVector();
    int counter = 0;

    for (unsigned int i = 0; i < temporary_holder.size() && counter < 10; ++i) {
        MovieType* current_movie = temporary_holder.at(i);
        vector<string> temp_genres = temporary_holder.at(i)->getGenres();
        for (unsigned int j = 0; j < temp_genres.size(); ++j) {
            if (temp_genres.at(j) == genre) {
                cout << counter + 1 << ") " << current_movie->getMultimediaTitle() << ": " << current_movie->getMovieRating() << endl << current_movie->getDescription() << endl << endl;
                counter++;
                break;
            }
        }
    }
}

string GenreStrategy::getGenre() {
    return this->genre;
}

void DirectorStrategy::filtering_strategy(FactoryPattern* movie) {
    string movie_director = this->movie_director;
    vector<MovieType*> temporary_holder = movie->getMovieVector();
    int cntr = 0;
    for (int i = 0; i < temporary_holder.size() && cntr < 10; ++i) {
        if (temporary_holder.at(i)->getDirector() == movie_director) {
            cout << cntr + 1 << ") " << temporary_holder.at(i)->getMultimediaTitle() << ": " << temporary_holder.at(i)->getMovieRating() << endl << temporary_holder.at(i)->getDescription() << endl << endl;
            cntr++;
        }
    }
}

string DirectorStrategy::getDirector() {
    return this->movie_director;
}

