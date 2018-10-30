/*******************************************************************************
  Title          : subway_station.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_station.h class declaration
  				   container for all the subway entrances making it easier to store 
  				   and retrieve data associated with the disjoint sets where each root 
  				   represents a station 
  Purpose        : this is where subway station comes in and stores all the entraces leading to 
  					the root in a vector and every station has station pointers allowing for 
  					the separate chaining collision resolution in the hash table
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_station.cpp
  Modifications  : 
 
*******************************************************************************/
#ifndef SUBWAY_STATION
#define SUBWAY_STATION

#include <iostream>
#include <vector>
#include "subway_entrance.h"
#include "disj_sets.h"
using namespace std;

class Subway_Station
{
	public:
		//constructors
		Subway_Station();
		Subway_Station(Subway_Entrance &entrance);
		
		//inserts a station entrance into a station container
		void insert(Subway_Entrance &ent);

		//simple accessor functions
		double getLatitude();
		double getLongitude();
		string getStationName();

		//simple mutator functions
		void setLatitude();
		void setLongitude();
		void setStationName(string new_name);

		//averages the gps locations of all entrances to find the centroid
		double average_latitude();
		double average_longitude();

		//accessor and mutator of the next pointer to a station
		Subway_Station* getNext();
		void setNext(Subway_Station *e1);

		//get and set / accessor and mutator functions of bitmask
		unsigned int getBitmask();
		void setBitmask(unsigned int bits);

		//prints the entrances of each of the stations
		void print();
	private:
		vector<Subway_Entrance> station_entrances;
		string station_name;
		double centroid_lat;
		double centroid_lon;
		unsigned int bitmask;
		Subway_Station* next;
		
};

#endif