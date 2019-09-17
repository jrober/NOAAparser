#pragma once
#include<stdint.h>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

class Data_Record
{
	private:
		uint16_t lvltyp1;
		uint16_t lvltyp2;
		int16_t etime;
		int32_t press;
		char pflag;
		int32_t gph;
		char zflag;
		int16_t temp;
		char tflag;
		int16_t rh;
		int16_t dpdp;
		int16_t wdir;
		int16_t wspd;

		void parse(string);

	public:
		// Default constructor
		Data_Record() {};

		// initialize with a line
		Data_Record(string line) {
			parse(line);
		};

		void coutData_Record();

		void fileOut(ofstream& os);

};

