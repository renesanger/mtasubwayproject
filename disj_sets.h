/*******************************************************************************
  Title          : disj_sets.h
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for disj_sets.h class declaration
  				   container for all the subway stations. it holds a vector of all the entrances initially
  				   and turns into a unioned set where all stations are joined together in an efficient manner
  Purpose        : the vector shows which entrance points to which parent trees and allows for the creatin 
  					of stations through this object
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 disj_sets.cpp
  Modifications  : 
 
*******************************************************************************/
#ifndef DISJ_SETS
#define DISJ_SETS

#include <iostream>
#include <vector>
#include "subway_entrance.h"

using namespace std;

class Disj_Sets
{
	public:
		//constructors
		Disj_Sets();
		//@param: csv rows to create entrance and then disj_sets
		Disj_Sets(vector<string> &row);
		//@pre:none
		//unify used to loop through whole vector and union op every entrance to respective stations
		void unify();
		//@pre:none
		//the actual union operation taking in two subway_entrances and unioning the smaller tree
		void unions(Subway_Entrance &e1, Subway_Entrance &e2);
		//@pre:none
		//find the root of the tree by passing in the parameter of an entrance 
		//@return: subway entrance param
		Subway_Entrance& find(Subway_Entrance &x);
		//@pre:none
		//@return: returns the reference to the private variable stations
		vector<Subway_Entrance>& getStations();
		//mutator that sets the distance constraint to new_dist paramer
		void setDistance(double new_dist);
	private:
		vector<Subway_Entrance> stations;
		double distance;
		
};

#endif