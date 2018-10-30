/*******************************************************************************
  Title          : subway_line_hash.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : implementation file for subway_line_hash.cpp class declaration
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
#include <list>
#include "subway_station.h"
#include "subway_entrance.h"
#include "subway_line_hash.h"
#include "line.h"
using namespace std;

Subway_Line_Hash::Subway_Line_Hash()
{
	//table_size=10;
	for(int i=0;i<table_size;i++)
	{
		lines[i]=NULL;
	}
}

int Subway_Line_Hash::hash(unsigned int bits)
{

	return bits% table_size;

}

void Subway_Line_Hash::insert(Line& l)
{
	unsigned int num=l.getBitmask();
	int index= hash(num);
	if(lines[index]==NULL)
	{
		lines[index]=&l;
	}
	else
	{
		Line* ptr= lines[index];
		Line* n= &l;
		while(ptr->getNext() != NULL)
		{
			ptr= ptr->getNext();
		}
		ptr->setNext(n);
	}
}

Line* Subway_Line_Hash::find(string line)
{
	unsigned int bits= line_parser(line);
	int index= hash(bits);
	Line* ptr= lines[index];

	if(ptr==NULL)
	{
		return NULL;
	}
	while(ptr->getNext()!=NULL && ptr->getBitmask()!=bits)
	{
		ptr=ptr->getNext();
	}
	if(ptr->getBitmask()!=bits)
		return NULL;	

	return ptr;
}

unsigned int Subway_Line_Hash::line_parser(string line)
{
	//sir, fs, gs,
	vector<string> line_set;
	size_t pos=0;
	string token;
	string delimiter= "-";
	int result=0;

	while((pos=line.find(delimiter)) < line.npos)
	{	
		token= line.substr(0, pos);
		line_set.push_back(token);
		line.erase(0, pos + 1);
	}
	line_set.push_back(line);

	for(int i=0; i<line_set.size(); i++)
	{
		string sub_line=line_set[i];
		unsigned int adder=0;
			if( sub_line=="A")
				adder=1 ;
			if( sub_line=="B")
				adder=1 <<1;
			if( sub_line=="C")
				adder=1 <<2;
			if( sub_line=="D")
				adder=1 <<3;
			if( sub_line=="E")
				adder=1 <<4;
			if( sub_line=="F")
				adder=1 <<5;
			if( sub_line=="G")
				adder=1 <<6;
			if( sub_line=="J")
				adder=1 <<7;
			if( sub_line=="L")
				adder=1 <<8;
			if( sub_line=="M")
				adder=1 <<9;
			if( sub_line=="N")
				adder=1 <<10;
			if( sub_line=="Q")
				adder=1 <<11;
			if( sub_line=="R")
				adder=1 <<12;
			if( sub_line=="S")
				adder=1 <<13;
			if( sub_line=="W")
				adder=1 <<14;
			if( sub_line=="Z")
				adder=1 <<15;
			if( sub_line=="SIR")
				adder=1 <<16;
			if( sub_line=="GS")
				adder=1 <<17;
			if( sub_line=="FS")
				adder=1 <<18;
			if( sub_line=="1")
				adder=1 <<19;
			if( sub_line=="2")
				adder=1 <<20;
			if( sub_line=="3")
				adder=1 <<21;
			if( sub_line=="4")
				adder=1 <<22;
			if( sub_line=="5")
				adder=1 <<23;
			if( sub_line=="6")
				adder=1 <<24;
			if( sub_line=="7")
				adder=1 <<25;

		result+=adder;
	}
	return result;
}