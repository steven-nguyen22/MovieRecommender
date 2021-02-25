#ifndef __CATEGORY_HPP___
#define __CATEGORY_HPP__


#include <string>
#include <iostream>
#include <vector>
// #include "Movies.hpp"

class Category 
{
	protected:
		int parameter;	
		string param_str;
		vector<Category*> categs;
		int rating = 0;
		string release;
		string genre;
		string actor;
		string director;
	public :
		virtual ~Category();

			//deallocate space for (sub)categories
			//delete this->rating = rating;
			//..
			//
		Category(): rating(0), genre(""), director(""), actor(""), release("") {
			//add default to vector 
		}		
		Category(int num);
		Category(string word);

		//initialise with input if taken from user
		
		virtual Category MakeCategory() {
			//comm to user specified categ
			// if rating specified ..
			//
			Category* example = new Category();
			//set example.rating to the taken value 
			categs.push_back(parameter);
			
		}

		virtual Category removeCategory(Category* example) {
			//populate categs
			vector<Category* > scan; //group of possible categories
			for (scan  = categs.begin(); scan!= categs.end(); scan++) {
				if((*scan) == *example) {   //relate content of obj to 
					// delete specified user category
				}
				else {
					(*scan)->removeCategory(example);
				}
			}
		}

		virtual Category getCategory() {

		}
};


#endif
