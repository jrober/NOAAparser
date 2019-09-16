/*
	NOAA Data Parser
	Author: Justin Roberts
	Data taken from https://www1.ncdc.noaa.gov/pub/data/igra/data/
*/

#include<iostream>
#include<fstream>
#include <string>

#include"Parser.h"
#include"Header.h"
#include "Data_Record.h"

using namespace std;

int main() {
	Parser parser;
	string filename = "C:/Users/A10/Documents/Justins/ACM00078861-data.txt";
	parser.parseFile(filename);
	return 0;
}