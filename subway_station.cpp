/*******************************************************************************
  Title          : subway_station.cpp
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
#include <iostream>
#include <vector>
#include "subway_station.h"
#include "subway_entrance.h"
using namespace std;


Subway_Station::Subway_Station()
{
	centroid_lat=0;
	centroid_lon=0;
	station_name="";
	bitmask=0;
	next=NULL;
}
Subway_Station::Subway_Station(Subway_Entrance &entrance)
{
	station_entrances.push_back(entrance);
	centroid_lat = this->average_latitude();
	centroid_lon = this->average_longitude();
	station_name= "";
	bitmask=0;
	if(entrance.getParentIndex()<0)
	{
		station_name= entrance.getName();
	}
	next=NULL;
}

void Subway_Station::insert(Subway_Entrance &ent)
{
	station_entrances.push_back(ent);
}

double Subway_Station::average_latitude()
{
	double total = 0;
	int size = station_entrances.size();
	for(int i=0; i<size;i++)
	{
		total+=station_entrances[i].getLatitude();
	}
	return total/(double)size;
}

double Subway_Station::average_longitude()
{
	double total = 0;
	int size = station_entrances.size();
	for(int i=0; i<size;i++)
	{
		total+=station_entrances[i].getLongitude();
	}
	return total/(double)size;
}
		
double Subway_Station::getLatitude()
{return centroid_lat;}
double Subway_Station::getLongitude()
{return centroid_lon;}
string Subway_Station::getStationName()
{return station_name;}
Subway_Station* Subway_Station::getNext()
{return next;}
unsigned int Subway_Station::getBitmask()
{return bitmask;}

void Subway_Station::setLatitude()
{
	centroid_lat = average_latitude();
}
void Subway_Station::setLongitude()
{
	centroid_lon = average_longitude();
}
void Subway_Station::setStationName(string new_name)
{
	station_name = new_name;
}

void Subway_Station::setBitmask(unsigned int bits)
{
	bitmask=bits;
}


void Subway_Station::setNext(Subway_Station *e1)
{
	next= e1;
}

void Subway_Station::print()
{
	for(int i=0;i<station_entrances.size();i++)
	{
		cout<<station_entrances[i].getName()<<endl;
	}
}