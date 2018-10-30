/*******************************************************************************
  Title          : line.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : implementation file for line.h class declaration
  				   container holding the information of a given line such as the bitmask, the
  				   stations associated with the line.
  Purpose        : this object is needed in order to find out which station maps to which line
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 line.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <vector>
#include "subway_station.h"
#include "line.h"
using namespace std;

Line::Line(){
	bitmask=0;
}

Line::Line(string line_id, vector<Subway_Station>& stat){
	bitmask = line_parser(line_id);
	for (int i=0;i<stat.size();i++)
	{
		if(stat[i].getBitmask() & bitmask==bitmask)
		{
			stations.push_back(stat[i]);
		}
	}
}

unsigned int Line::line_parser(string line)
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

void Line::insert(Subway_Station &stat)
{
	stations.push_back(stat);
}

unsigned int Line::getBitmask()
{return bitmask;}

vector<Subway_Station>& Line::getStations()
{
	return stations;
}

Line* Line::getNext()
{
	return next;
}

void Line::setNext(Line *l)
{
	next= l;
}