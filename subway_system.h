/*******************************************************************************
  Title          : subway_system.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_system.cpp calss declaration
  Purpose        : container for all the subway stations and hash tables of
  				   lines and stations.
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_system.cpp
  Modifications  : 
 
*******************************************************************************/
#ifndef SUBWAY_SYSTEM
#define SUBWAY_SYSTEM

#include <iostream>
#include <vector>
#include "subway_station.h"
#include "subway_entrance.h"
#include "disj_sets.h"
#include "line.h"
#include "subway_station_hash.h"
#include "subway_line_hash.h"
using namespace std;

class Subway_System
{
	public:
		//default constructor
		Subway_System();
		//constructor taking one parameter of all rows in csv
		Subway_System(vector<string> &data);

		/*	@pre: subway system must be initialized
			@post: prints the station_names of all the stations within the private variable hash table
			no parameters		*/
		void list_all_stations();

		/*	@pre: all stations must have a bitmask to be compared to
			@param: line_id is a string representing the line identifier
			@post: prints all station_name that are on the same line as the line identifier	*/
		void list_line_stations(string line_id);

		/*	@pre: all entrances must have a station name
			@param: station_name is a string that is used to find the station in a station 
					name hash table.
			@post: all names of every entrance is printed */
		void list_entrances(string station_name);
		/*	@pre: none
			@param: data is the rows/lines of the csv table stored in a vector
			@post: the data is read and entrances, stations, hash table and subway system is initialized.*/
		void initialize(vector<string> &data);

		/*	@pre: none
			@param: longitude and latitude are user defined double type gps positions
			@post: the name of the nearest station is printed out*/
		void nearest_station(double longitude, double latitude);

		/*	@pre: none
			@param: longitude and latitude are user defined double type gps positions
			@post: the name of the nearest station is printed out*/
		void nearest_line(double longitude, double latitude);
		/*	the entrance or entrances with the shortest distance to a given GPS position is found and
			the name is printed out
			@pre: longitude and latitude must be reasonable, close to -70 and 40 otherwise
				  there isnt much use in the function
			@param: longitude and latitude is user defined in the command line, vector is data to loop through entrances
			@post: the name of the closest entrance is printed out*/
		void nearest_entrance(double longitude, double latitude, vector<string> &data);
		/*	reverts a bitmask back into the string line identifier form containing  "-"
			@pre: num must be valid unsigned int
			@param: num is an unsigned integer representing a bitmask
			@post: a string is formed with station lines separated by the delimiter of "-"
			@return: the line identifier is returned it is a string
		*/
		string revert(unsigned int num);

	private:
		Subway_Station_Hash ss_h;
		Subway_Line_Hash sl_h;
		vector<Subway_Station> stations;

};

#endif