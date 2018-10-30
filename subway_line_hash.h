/*******************************************************************************
  Title          : subway_line_hash.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_line_hash.cpp class declaration
  				   container for all the subway entrances making it easier to store 
  				   and retrieve data in a hash function fast retrieval of lines
  Purpose        : very similar to station hash tabl but has conditioning statements that 
  					allow for line objects to be inserted into the hash table containg information
  					such as stations and bitmasks representing line identifiers
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_line_hash.cpp
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include "subway_station.h"
#include "subway_entrance.h"
#include "line.h"
using namespace std;

class Subway_Line_Hash
{
	public:
    //constructor
		Subway_Line_Hash();

    //parses a string into a bitmask
		unsigned int line_parser(string line );
    //returns a line pointer 
		Line* find(string line);
    //hash function that returns an index
		int hash(unsigned int bits);
    //insets a line object int the hash table
		void insert(Line& l);


	private:
		static const int table_size=101;
		Line* lines[table_size]; 
		
};