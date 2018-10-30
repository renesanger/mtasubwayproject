/*******************************************************************************
  Title          : line.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for line.h class declaration
  				   container holding the information of a given line such as the bitmask, the
  				   stations associated with the line.
  Purpose        : this object is needed in order to find out which station maps to which line
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 line.cpp
  Modifications  : 
 
*******************************************************************************/
#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <vector>
#include "subway_station.h"
using namespace std;

class Line
{
	public:
		//constructors 
		Line();
		Line(string line_id, vector<Subway_Station>& stat);

		//parses line parameter into a bitmask
		unsigned int line_parser(string line );
		//insert a subway station into a given set of stations vector
		void insert(Subway_Station& stat);

		//accessor methods 
		//@return: bitmask unsigned int
		unsigned int getBitmask();
		//@return: address of stations vector private variable to be manipulated in another class
		vector<Subway_Station>& getStations();
		//gets the next line of the pointer private variable
		Line* getNext();

		//mutator to set the next pointer to another line.
		void setNext(Line *l);

	private:
		unsigned int bitmask;
		vector<Subway_Station> stations;
		Line* next;
		
};

#endif