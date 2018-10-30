#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdint>
#include "subway_entrance.h"
#include "subway_station.h"
#include "subway_system.h"
#include "subway_station_hash.h"
#include "command.h"
using namespace std;

int main(int argc, char** argv)
{
	vector<string> csv_rows;
	ifstream file(argv[1]);
	//take the first row out
	string s;
	getline(file, s);

	string temp;
	if(file.is_open())
	{
		while(getline(file, temp))
		{
			csv_rows.push_back(temp);
		}
		file.close();
	}


	Subway_System mta(csv_rows);
	
	string line_id;
    string station_name;
    double longitude;
    double latitude;
    bool result;

	string command_str;
	ifstream command(argv[2]);
	vector<string> command_prompts;
	while(getline(command,command_str))
	{
		command_prompts.push_back(command_str);
	}

	for(int i=0;i<command_prompts.size();i++)
	{
		cout<<command_prompts[i]<<endl;
	}
	int i=0;
	while(i<command_prompts.size())
	{
	vector<string> tokens;
	size_t pos=0;
	string token;
	string delimiter= " ";
	string com=command_prompts[i];
	while((pos=com.find(delimiter)) < com.npos)
	{	
		token= com.substr(0, pos);
		tokens.push_back(token);
		com.erase(0, pos + 1);
	}
	tokens.push_back(com);
	string command_name= tokens[0];

	int len=tokens.size();
	if(command_name=="list_line_stations" && len==2)
	{
		line_id= tokens[1];
		mta.list_line_stations(line_id);
	}
	else if(command_name=="list_all_stations" && len==0)
	{
		mta.list_all_stations();
	}
	else if(command_name=="list_entrances" && len==1)
	{
		station_name= tokens[1];
		mta.list_entrances(station_name);
	}
	else if(command_name=="nearest_station" && len==2)
	{
		longitude= stod(tokens[1]);
		latitude= stod(tokens[2]);
		mta.nearest_station(longitude, latitude);
	}
	else if(command_name=="nearest_lines" && len==2)
	{
		longitude= stod(tokens[1]);
		latitude= stod(tokens[2]);
		mta.nearest_line(longitude, latitude);
	}
	else if(command_name=="nearest_entrance" && len==2)
	{
		longitude= stod(tokens[1]);
		latitude= stod(tokens[2]);
		station_name= tokens[1];
		mta.nearest_entrance(longitude, latitude,csv_rows);
	}
	else
	{
		cout<<"invalid command"<<endl;
	}
	i++;
	cout<<"=============================================================="<<endl;
	cout<<"=============================================================="<<endl;
	}

	return 0;
}