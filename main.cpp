#include "iostream"
#include "string"

int main() {
	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "                     Movie Recommender Program                         \n";
	std::cout << "    by: Abhinav Ramachandran, Ishaan Bijor, and Steven Nguyen          \n";
	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "1. Recommendations for a movie you like \n";
	std::cout << "2. Add a movie to the data base \n";
	std::cout << "3. Remove a movie from the data base \n";
	std::cout << "4. Add a category to the data base \n";
	std::cout << "5. Remove a category from the data base \n";
	std::cout << "6. Display the movies already in the data base\n";
	std::cout << "7. Display the categories already in the data base\n";
	std::string choice;
	std::cout << "Enter a number for the function you would like to perform: ";
	std::cin >> choice;
	
	if(choice == "1") {
		std::cout << "Enter the name of the movie you like: ";
		std::string userMovie;
		std::cin >> userMovie;
		std::cout << "Would you like to sort by a specific category (yes/no): ";
		std::string userChoice;
		std::cin >> userChoice; 
		
		/*
		if(userChoice == "yes") {
			//write all the options to sort by
			std<<cout " ...";
		}
		else {
			//default sort setting
		}*/
	}

	else if(choice == "2") {
		std::cout << "Name of the movie you want to add: ";
	}

	else if(choice == "3") {
		std::cout << "Name of the movie you want to remove: ";
	}

	else if(choice == "4") {
		std::cout << "Name of the category you want to add: ";
	}

	else if(choice == "5") {
		std::cout << "Name of the category you want to remove: ";
	}
	
	else if(choice == "6") {
		//display data base
	}

	else if(choice == "7") {
		//display categories
	}
	

	return 0;
}
