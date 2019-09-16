#pragma once
#include<stdint.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Header
{
	private:
		char id[12];
		uint16_t year;
		uint16_t month;
		uint16_t day;
		uint16_t hour;
		uint16_t reltime;
		uint16_t numLevels;
		char p_src[9];
		char np_src[9];
		float latitude;
		float longitude;

		void parse(string);
	
	public:
		// default constructor
		Header() {};

		// initialize header with a line
		Header(string line) {
			parse(line);
		};

		// optional initialization constructor
		Header(char Id[12], uint16_t Year, uint8_t Month, uint8_t Day,
			uint8_t Hour, uint16_t Reltime, uint16_t NumLevels,
			char p_SRC[9], char nP_SRC[9], float Latitude,
			float Longitude) {
			strcpy_s(id, Id);
			year = Year;
			month = Month;
			day = Day;
			hour = Hour;
			reltime = Reltime;
			numLevels = NumLevels;
			strcpy_s(p_src, p_SRC);
			strcpy_s(np_src, nP_SRC);
			latitude = Latitude;
			longitude = Longitude;
		};

		void coutHeader();

		uint16_t getNum_levels() {
			return numLevels;
		}
		
};

