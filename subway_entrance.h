/*******************************************************************************
  Title          : subway_entrance.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_entrance.h class declaration
  				   container placing all valuebal data of each entrance in the input file into 
  				   entrance object
  Purpose        : this is the most primitive object in the program and yet the most important
  					because each line in the csv file is translated to a subway entrance object
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_entrance.cpp
  Modifications  : 
 
*******************************************************************************/
#ifndef SUBWAY_ENTRANCE
#define SUBWAY_ENTRANCE

#include <iostream>

using namespace std;

class Subway_Entrance
{
	public:
		//constructors
		Subway_Entrance();
		//constructs an entrance and defines the private fields using a parsed row
		Subway_Entrance(string row);

		//helper methods that parse strings
		//point parser parses a string that contains a point in form POINT (#, #) 
		void point_parser(string &point, double &lon_double, double &lat_double);
		//line parser takes line as string and parses it returning a bitmask
		unsigned int line_parser(string line);

		// simple accessor functions
		string getName();
		//@return bitmask or what i referred to as bitset
		unsigned int getBitset();
		//@return: latitude and longitude
		double getLatitude();
		double getLongitude();
		//returns the parent index of a given station to be used in disj_sets
		int getParentIndex();
		//gets the position of the entrance within a vector
		int getPos();

		// mustator functions
		void setParentIndex(int new_idx);
		//used as an initializer to set each element to the index it is in the vector
		void setPos(int new_pos);


	private:
		int parent_index;
		int ObjectID;
		string URL;
		string name;
		double latitude;
		double longitude; 
		string line; 
		unsigned int bitset;
		int position;
};

#endif