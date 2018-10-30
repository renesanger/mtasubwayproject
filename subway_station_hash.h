/*******************************************************************************
  Title          : subway_station_hash.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_station_hash.h class declaration
  				   container for all the subway stations making it easier to store 
  				   and retrieve data
  Purpose        : this is used to store all the stations in one hash function
  					making it easier to get the names.
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_station_hash.cpp
  Modifications  : 
 
*******************************************************************************/

#ifndef SUBWAY_STATION_HASH
#define SUBWAY_STATION_HASH

#include <iostream>
#include <vector>
#include "subway_station.h"
#include "subway_entrance.h"
#include "disj_sets.h"
using namespace std;

class Subway_Station_Hash
{
	public:
		//hash teable constructor
		Subway_Station_Hash();

		//remove the given station with the key of station name 
		void remove(string s);
		//finds where the station is in the hash table and returns the pointer
		Subway_Station* find(string s);
		//hash function that uses horners rule and hashes a station name param into an index of type int
		int hash(string key);
		//inserts the parameter stat of type subway station& and inserts it into the hash table
		void insert(Subway_Station& stat);
		//prints the station hash and all the names of the stations
		void print();

	private:
		static const int table_size=101;
		Subway_Station* stations[table_size]; 
		
};

#endif