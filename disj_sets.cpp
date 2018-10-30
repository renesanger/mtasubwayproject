/*******************************************************************************
  Title          : disj_sets.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : implementation of a disj_set object that initializes the vector of all entrances
  					and unions them to create trees with fast retrieval method and a fast find method.
  Purpose        : implemented for the creation of stations and because of the efficiency of the algorithm
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11s disj_sets.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include "disj_sets.h"
#include "subway_entrance.h"
#include "haversine.cpp"
using namespace std;


Disj_Sets::Disj_Sets()
{
	distance=0.391;
}

Disj_Sets::Disj_Sets(vector<string> &row)
{

	distance=0.391;
	for(int i=0;i<row.size();i++)
	{
		Subway_Entrance temp(row[i]);
		temp.setPos(i);
		stations.push_back(temp);
	}
	
}

void Disj_Sets::unify()
{
	for(int pos=0;pos<stations.size()-1;pos++)
	{


	for(int i=pos;i<stations.size();i++)
	{

		if (stations[pos].getBitset()==stations[i].getBitset()
			&& haversine(stations[pos].getLatitude(), stations[pos].getLongitude(), stations[i].getLatitude(), stations[i].getLongitude()) <= 0.391)
			{	
				unions(stations[pos],stations[i]);

			}
	}
}
}

void Disj_Sets::unions(Subway_Entrance &e1, Subway_Entrance &e2)
{
	int e1_idx = e1.getParentIndex();
	int e2_idx = e2.getParentIndex();
	if(e1_idx<0 && e2_idx<0)
	{
		if(e1_idx<=e2_idx)
		{
			e2.setParentIndex(e1.getPos());
			e1.setParentIndex(--e1_idx);
			return;
		}
		else
		{
			e1.setParentIndex(e2.getPos());
			e2.setParentIndex(--e2_idx);
			return;
		}
	}
	else
	{
		Subway_Entrance new_e1;
		Subway_Entrance new_e2;
		new_e1 = find(e1);
		new_e2= find(e2);
		unions(new_e1, new_e2);
	}
	
}

Subway_Entrance& Disj_Sets::find(Subway_Entrance &x)
{
	int pos= x.getPos();
	int root_idx=-1;
	while(pos>=0)
	{
		pos=stations[pos].getParentIndex();
		if(pos>=0)
		{
			root_idx=pos;
		}
	}
	if(root_idx<0)
	{
		root_idx=x.getPos();
	}
	return stations[root_idx];
}

vector<Subway_Entrance>& Disj_Sets::getStations()
{return stations;}

void Disj_Sets::setDistance(double new_dist)
{
	distance=new_dist;
}

/*if the Subway_Entrance ar connected 
	meaning:
	if bitset1 = bitset2 and distance between e1 and e2 is <= num (0.28) 
		then union the two sets 
		-find out which set is bigger 
		-default is first set
		-update parent index
		-larger remains -1 and the latter points to the 1st.*/