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
	
	//string filename = "C:/Users/A10/Documents/Justins/PKM00041780-data.txt"; // all years for station PKM00041780
	//string filename = "C:/Users/A10/Documents/Justins/USW00013859-data.txt"; // all years for station USW00013859
	//string filename = "C:/Users/A10/Documents/Justins/ZZV00ASEU05-data.txt"; // all years for station ZZV00ASEU05
	string filename = "C:/Users/A10/Documents/Justins/ACM00078861-data.txt"; // all years for station ACM00078861
	//string filename = "C:/Users/A10/Documents/Justins/AEM00041217-data.txt"; // ytd for station AEM00041217
	//string filename = "C:/Users/A10/Documents/Justins/ACM00078861-data_header.txt"; // only one data block for station ACM0078861

	ifstream is(filename);

	if (!is.good()) {
		cout << "Error -> invalid filename " << filename << endl;
	}
	else {
		parser.parseFile(is);
	}

	is.close();
	return 0;
}