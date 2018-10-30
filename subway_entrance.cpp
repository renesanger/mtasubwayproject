/*******************************************************************************
  Title          : subway_entrance.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : header file for subway_entrance.h class declaration
  				   container placing all valuebal data of each entrance in the input file into 
  				   entrance object
  Purpose        : this is the most primitive object in the program and yet the most important
  					because each line in the csv file is translated to a subway entrance object
  Usage          : use constructors and mutator and accessor functions
  Build with     : g++ -std=c++11 subway_entrance.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "subway_entrance.h"
using namespace std;

Subway_Entrance::Subway_Entrance()
{
	parent_index=-1;
	ObjectID=0;
	URL="";
	name="";
	latitude=0;
	longitude=0; 
	line=""; 
	bitset=0;
	position=0;
}

Subway_Entrance::Subway_Entrance(string row)
{
	stringstream ss(row);
	vector<string> fields;
	string str;
	while(getline(ss, str, ','))
	{
		fields.push_back(str);
	}

	double temp_lon;
	double temp_lat;
	point_parser(fields[3], temp_lon , temp_lat);

	parent_index=-1;
	ObjectID= stoi(fields[0]);
	URL= fields[1];
	name= fields[2];
	latitude= temp_lat;
	longitude= temp_lon; 
	line=fields[4]; 
	bitset=line_parser(fields[4]);
	position=0;
}

void Subway_Entrance::point_parser(string &point, double &lon_double, double &lat_double)
{
	int i=0; 
	bool open_paren=false;
	bool isin_lon=false;
	bool isin_lat=false;
	string lon;
	string lat;
	while(i<point.length())
	{

		if(point[i]==' ') 
			isin_lon=false;

		if(point[i]==')')
			isin_lat=false;

		if(isin_lon && point[i]!='(')
		{
			lon+=point[i];
		}
		else if(isin_lat && point[i]!=' ')
		{
			lat+=point[i];
		}

		if(open_paren && point[i]==' ')
			isin_lat=true;
		

		if(point[i]=='(') 
		{
			open_paren=true;
			isin_lon=true;
		}

		i++;
	}
	lon_double= stod(lon);
	lat_double= stod(lat);

}

unsigned int Subway_Entrance::line_parser(string line)
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

string Subway_Entrance::getName()
{return name;}

unsigned int Subway_Entrance::getBitset()
{return bitset;}

double Subway_Entrance::getLatitude()
{return latitude;}

double Subway_Entrance::getLongitude()
{return longitude;}

void Subway_Entrance::setParentIndex(int new_idx)
{
	parent_index=new_idx;	
}

int Subway_Entrance::getParentIndex()
{return parent_index;}

int Subway_Entrance::getPos()
{return position;}
void Subway_Entrance::setPos(int new_pos)
{position=new_pos;}