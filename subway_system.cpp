/*******************************************************************************
  Title          : subway_system.cpp
  Author         : Rene Sanger
  Created on     : May 14, 2018
  Description    : The implementation of a container class that wraps all the 
  				   other object classes including the hash tables, station, and
  				   entrance classes. 
  Purpose        : purpose is to make it easier for the command line.
  Usage          : implementation should be hidden from user
  Build with     : g++ -std=c++11 subway_system.cpp
  Modifications  : 
 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "subway_system.h"
#include "subway_station.h"
#include "subway_entrance.h"
#include "subway_station_hash.h"

#include "line.h"
#include "haver.cpp"



using namespace std;

Subway_System::Subway_System()
{

}
	

Subway_System::Subway_System(vector<string> &data)
{
	initialize(data);
}

void Subway_System::initialize(vector<string> &data)
{
	Disj_Sets subl(data);
	subl.unify();

	vector<Subway_Entrance> stat=subl.getStations();


	for(int i=0;i<stat.size();i++)
	{
		if(stat[i].getParentIndex()<=-1)
		{
			Subway_Station substat;
			substat.insert(stat[i]);
			for(int j=0;j<stat.size();j++)
			{	
				if(stat[i].getPos()==subl.find(stat[j]).getPos())
				{
					substat.insert(stat[j]);
				}
			}
			substat.setStationName(stat[i].getName());
			substat.setBitmask(stat[i].getBitset());
			substat.setLatitude();
			substat.setLongitude();
			stations.push_back(substat);
		}
	}
	for(int i=0; i< stations.size();i++)
	{
		ss_h.insert(stations[i]);
		
	}




}

string Subway_System::revert(unsigned int num)
{

	string s="";
	string delimiter= "-";
	int length=0;
	unsigned int x=0;
	x+=num;

		if((num& 1)== 1)
			s+="A"+ delimiter;
		if((num&(1<<1))==(1<<1))
			s+="B"+ delimiter;
		if((num&(1<<2))==(1<<2))
			s+="C"+ delimiter;
		if((num&(1<<3))==(1<<3))
			s+="D"+ delimiter;
		if((num&(1<<4))==(1<<4))
			s+="E";
		if((num&(1<<5))==(1<<5))
			s+="F"+ delimiter;
		if((num&(1<<6))==(1<<6))
			s+="G"+ delimiter;
		if((num&(1<<7))==(1<<7))
			s+="J"+ delimiter;
		if((num&(1<<8))==(1<<8))
			s+="L"+ delimiter;
		if((num&(1<<9))==(1<<9))
			s+="M"+ delimiter;
		if((num&(1<<10))==(1<<10))
			s+="N"+ delimiter;
		if((num&(1<<11))==(1<<11))
			s+="Q"+ delimiter;
		if((num&(1<<12))==(1<<12))
			s+="R"+ delimiter;
		if((num&(1<<13))==(1<<13))
			s+="S"+ delimiter;
		if((num&(1<<14))==(1<<14))
			s+="W"+ delimiter;
		if((num&(1<<15))==(1<<15))
			s+="Z"+ delimiter;
		if ((num&(1<<16))==(1<<16))
			s+="FS"+ delimiter;
		if((num&(1<<17))==(1<<17))
			s+="GS"+ delimiter;
		if((num&(1<<18))==(1<<18))
			s+="SIR"+ delimiter;
		if((num&(1<<19))==(1<<19))
			s+="1"+ delimiter;
		if((num&(1<<20))==(1<<20))
			s+="2"+ delimiter;
		if((num&(1<<21))==(1<<21))
			s+="3"+ delimiter;
		if((num&(1<<22))==(1<<22))
			s+="4"+ delimiter;
		if((num&(1<<23))==(1<<23))
			s+="5"+ delimiter;
		if((num&(1<<24))==(1<<24))
			s+="6"+ delimiter;
		if((num&(1<<25))==(1<<25))
			s+="7"+ delimiter;


		length=length*2-1;
		string result="";

	return s.substr(0,s.length()-1);
}

void Subway_System::list_line_stations(string line_id)
{
	cout<<"list_line_stations"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	
	Line l(line_id, stations);
	vector<Subway_Station> all_in_line=l.getStations();
	sl_h.insert(l);
	vector<Subway_Station> subs=sl_h.find(line_id)->getStations();
	for(int i=0;i<subs.size();i++)
	{
		cout<<subs[i].getStationName()<<endl;
	}
}

void Subway_System::list_all_stations()
{
	cout<<"list_all_stations"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	ss_h.print();
}

void Subway_System::list_entrances(string station_name)
{
	cout<<"list_entrances"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	Subway_Station* ss=ss_h.find(station_name);
	ss->print();
}

void Subway_System::nearest_station(double longitude, double latitude)
{
	cout<<"nearest_station"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	double distance= 100;

	//finds the closest distance
	for(int i=0; i< stations.size();i++)
	{
		double result = haver(stations[i].getLatitude(),stations[i].getLongitude(), latitude,longitude );
		if(result<distance)
		{
			distance=result;
		}
		
	}

	for(int i=0; i< stations.size();i++)
	{
		double result = haver(stations[i].getLatitude(),stations[i].getLongitude(), latitude,longitude );
		if(result<=distance)
		{
			cout<<stations[i].getStationName()<<endl;
		}
		
	}
}

void Subway_System::nearest_line(double longitude, double latitude)
{
	cout<<"nearest_line"<<endl;
	cout<<"-----------------------------------------------"<<endl;

	double distance= 100;
	//finds the closest distance
	for(int i=0; i< stations.size();i++)
	{
		double result = haver(stations[i].getLatitude(),stations[i].getLongitude(), latitude,longitude );
		if(result<distance)
		{
			distance=result;
		}
		
	}

	for(int i=0; i< stations.size();i++)
	{
		double result = haver(stations[i].getLatitude(),stations[i].getLongitude(), latitude,longitude );
		if(result<=distance)
		{
			cout<<revert(stations[i].getBitmask())<<endl;
		}
		
	}
}

void Subway_System::nearest_entrance(double longitude, double latitude, vector<string> &data)
{
	cout<<"nearest_etrance"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	Disj_Sets subl(data);
	subl.unify();
	vector<Subway_Entrance> stat=subl.getStations();
	
	double distance= 100;
	//finds the closest distance
	for(int i=0; i< stat.size();i++)
	{
		double result = haver(stat[i].getLatitude(),stat[i].getLongitude(), latitude,longitude );
		if(result<distance)
		{
			distance=result;
		}
		
	}

	for(int i=0; i< stat.size();i++)
	{
		double result = haver(stat[i].getLatitude(),stat[i].getLongitude(), latitude,longitude );
		if(result<=distance)
		{
			cout<<stat[i].getName()<<endl;
		}
		
	}
}