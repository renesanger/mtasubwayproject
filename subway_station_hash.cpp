/*******************************************************************************
  Title          : subway_station_hash.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : implementation file that takes in subway stations and inserts
  					them into a separate chaining collision resloution hash table
  					with a fixed table size of 101 a prime number.
  Purpose        : stations will be stored here for quick access within the 
  					find function and the quick insertion as well as remove 
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_station_hash.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <vector>
#include <list>
#include "subway_station.h"
#include "subway_entrance.h"
#include "subway_station_hash.h"

using namespace std;

Subway_Station_Hash::Subway_Station_Hash()
{
	for(int i=0;i<table_size;i++)
	{
		stations[i]=NULL;
	}
}

int Subway_Station_Hash::hash(string key)
{
	unsigned long long hashval=0;
	int RADIX=2;
	for(int i=0;i< key.length(); i++)
	{
		int jump= key[i]+0;
		hashval=key[i]+ RADIX * hashval;
	}
	return hashval% table_size;

}

void Subway_Station_Hash::insert(Subway_Station& stat)
{
	string str=stat.getStationName();
	int index= hash(str);
	if(stations[index]==NULL)
	{
		stations[index]=&stat;
	}
	else
	{
		Subway_Station* ptr= stations[index];
		Subway_Station* n= &stat;
		while(ptr->getNext() != NULL)
		{
			ptr= ptr->getNext();
		}
		ptr->setNext(n);
	}
}

void Subway_Station_Hash::print()
{

	for(int i=0; i< table_size; i++)
	{
		if(stations[i]!=NULL)
			cout<<stations[i]->getStationName()<<endl;
		Subway_Station* ptr= stations[i];
		//cout<<i<<endl;
		while(ptr!=NULL)
		{
			cout<<ptr->getStationName()<<endl;
			ptr=ptr->getNext();
		}

		/*else
			cout<<"NULL"<<endl;*/
	}
}

Subway_Station* Subway_Station_Hash::find(string s)
{
	int index= hash(s);

	Subway_Station* ptr= stations[index];

	if(ptr==NULL)
	{
		return NULL;
	}
	while(ptr->getNext()!=NULL && ptr->getStationName()!=s)
	{

		ptr=ptr->getNext();
	}
	if(ptr->getStationName()!= s)
		return NULL;	

	return ptr;
}

void Subway_Station_Hash::remove(string s)
{
	int index= hash(s);

	Subway_Station* delptr;
	Subway_Station* p1;
	Subway_Station* p2;

	if(stations[index]==NULL)
		return;

	else if (stations[index]->getStationName()==s && stations[index]->getNext() == NULL)
	{
		delptr= stations[index];
		stations[index]=NULL;
		return;
	}

	else if (stations[index]->getStationName()==s)
	{
		delptr= stations[index];
		stations[index]=stations[index]->getNext();
		//delete delptr;
	}	

	else
	{
		p1= stations[index]->getNext();
		p2= stations[index];

		while(p1 != NULL && p1->getStationName()!= s)
		{
			p2=p1;
			p1=p1->getNext();
		}

		//name was not found in the hash table
		if(p1==NULL)
		{
			return;
		}
		else
		{
			delptr=p1;
			p1=p1->getNext();
			p2->setNext(p1);

			//delptr->setNext(NULL);
			//delete delptr;
		}
	}

	return;
}
