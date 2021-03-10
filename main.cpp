#include <iostream>
#include "MovieType.hpp"
#include "Multimedia.hpp"
#include "CategoryType.hpp"
#include "Parser.hpp"
#include "FilterStrategy.hpp"
#include <vector>
#include <map>
#include <string>
using namespace std;

class MovieType;

//Function prototypes
void displayMenu(FactoryPattern*);
void moviesSort(vector<MovieType*>& vec);
int qsPartition(vector<MovieType*>& values, int left, int right);
void quickSort(vector<MovieType*>& values, int left, int right);
void movieRecommendation(vector<MovieType*> values, string movie_name, map<string, MovieType*> movie_map);

int main() {

  //Factory pattern used for creating movie objects
   FactoryPattern* movie_parser = new FactoryPattern();
   movie_parser->parseMovieInfo();

  //Sorting the movies by score
  vector<MovieType*> temporary_holder = movie_parser->getMovieVector();
  moviesSort(temporary_holder);
  movie_parser->setMovieVector(temporary_holder);

  //Displaying the menu
   displayMenu(movie_parser);

   return 0;
}

void displayMenu(FactoryPattern* movie) {

    int selected_option;

    do {
        cout << "-----------------------------------------------------------------------\n";
        cout << "                     Movie Recommender Program                         \n";
        cout << "    by: Abhinav Ramachandran, Ishaan Bijor, and Steven Nguyen          \n";
        cout << "-----------------------------------------------------------------------\n";
        cout << "Please enter the correct menu digit -> " << endl << endl;
        cout << "* Print movies by score - Enter 1" << endl;
        cout << "* Print movies by actor - Enter 2" << endl;
        cout << "* Print movies by genre - Enter 3" << endl;
        cout << "* Recommend me a movie  - Enter 4" << endl;
        cout << "* Print most recent     - Enter 5" << endl;
        cout << "* Print by director     - Enter 6" << endl;
        cout << "* Quit from application - Enter 9" << endl;

        cin >> selected_option;

        if (selected_option == 1) {
            movie->setFilterFunction(new TopTenStrategy());
            movie->filtering_strategy();
        }

        else if (selected_option == 2) {
            string actor;
            cout << "Enter the name of actor or actress: " << endl;
            cin.ignore();
            getline(cin, actor);
            movie->setFilterFunction(new ActorStrategy(actor));
            movie->filtering_strategy();
        }

        else if (selected_option == 3) {
            string genre;
            cout << "Enter the genre: " << endl;
            cin >> genre;
            movie->setFilterFunction(new GenreStrategy(genre));
            movie->filtering_strategy();
        }

        else if (selected_option == 4) {
            string movName;
            cout << "\n\nWhich movie do you like?\nWe will recommend you another!" << endl;
            cin.ignore();
            getline(cin, movName);


            if (!(movie->movieExists(movName))) {
                cout << "\nError: Movie not found." << endl << endl;
            }
            else {

                movieRecommendation(movie->getMovieVector(), movName, movie->getMovieMap());

            }

        }

        else if (selected_option == 5) {
            int year;
            cout << "Enter the year of production: " << endl;
            cin >> year;
            movie->setFilterFunction(new TopTenRecentStrategy(year));
            movie->filtering_strategy();
        }

        else if (selected_option == 6) {
            string movie_director;
            cout << "Enter the name of director: " << endl;
            cin.ignore();
            getline(cin, movie_director);
            movie->setFilterFunction(new DirectorStrategy(movie_director));
            movie->filtering_strategy();
        }

        else {

            if (selected_option != 9) {
                cout << "\nInvalid selection: Select from 1 to 5" << endl << endl;
            }

        }
    } while (selected_option != 9);
}

void moviesSort(vector<MovieType*>& vec) {
    quickSort(vec, 0, vec.size() - 1);
}

int qsPartition(vector<MovieType*>& values, int left, int right) {
    double pivot_index = left + (right - left) / 2;
    double pivot_value = values.at(pivot_index)->getMovieRating();
    double i = left, j = right;
    MovieType* temporary_holder;
    while (i <= j) {
        while (values.at(i)->getMovieRating() > pivot_value) {
            i++;
        }
        while (values.at(j)->getMovieRating() < pivot_value) {
            j--;
        }
        if (i <= j) {
            temporary_holder = values[i];
            values[i] = values[j];
            values[j] = temporary_holder;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(vector<MovieType*>& values, int left, int right) {
    if (left < right) {
        int pivot_index = qsPartition(values, left, right);
        quickSort(values, left, pivot_index - 1);
        quickSort(values, pivot_index, right);
    }
}

void movieRecommendation(vector<MovieType*> values, string movie_name, map<string, MovieType*> movie_map) {

    MovieType* selected_movie = movie_map.find(movie_name)->second;

    int movie_index = 0;
    int while_index = 0;
    vector<string> selected_movie_actors = selected_movie->getListofActors();
    vector<string> selected_movie_genres = selected_movie->getGenres();
    cout << endl << "We recommend you the following: " << endl << endl;

    for (unsigned int i = 0; i < values.size() && movie_index < 3; ++i) {
        int similarity_count = 0;
        if (movie_name == values.at(i)->getMultimediaTitle()) {
            i++;
        }
        vector<string> temporary_holder = values.at(i)->getListofActors();
        for (int j = 0; j < selected_movie_actors.size(); j++) {
            for (int k = 0; k < temporary_holder.size(); k++) {
                if (selected_movie_actors.at(j) == temporary_holder.at(k)) {
                    similarity_count++;
                }
            }
        }

        if (values.at(i)->getDirector() == selected_movie->getDirector()) {
            similarity_count++;
        }

        vector<string> temp2 = values.at(i)->getGenres();
        for (int j = 0; j < selected_movie_genres.size(); j++) {
            for (int k = 0; k < temp2.size(); k++) {
                if (selected_movie_genres.at(j) == temp2.at(k)) {
                    similarity_count++;
                }
            }
        }

        if (similarity_count >= 3) {
            values.at(i)->displayData();
            cout << endl;
            movie_index++;
        }

    }
}
