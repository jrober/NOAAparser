#include "Header.h"

void Header::parse(string line)
{	
	// parsed according to https://www1.ncdc.noaa.gov/pub/data/igra/data/igra2-data-format.txt

	if (line.length() < 71)
		cout << "ERROR -> line isn't long enough to parse header!\n";

	string inVal;

	// ID
	inVal = line.substr(0, 12);
	if (inVal[0] != '#')
		cout << "invalid header, missing #" << endl;
	inVal.erase(0, 1);
	strcpy_s(id, inVal.c_str());

	// Year
	year = stoi(line.substr(13, 4));

	// Month
	month = stoi(line.substr(18, 2));

	// Day
	day = stoi(line.substr(21, 2));

	// Hour
	hour = stoi(line.substr(24, 2));

	// reltime
	reltime = stoi(line.substr(27, 4));

	// numLevels
	numLevels = stoi(line.substr(32, 4));

	// P_SRC
	inVal = line.substr(37, 8);
	strcpy_s(p_src, inVal.c_str());

	// NP_SRC
	inVal = line.substr(46, 8);
	strcpy_s(np_src, inVal.c_str());

	// Latitude 
	latitude = stoi(line.substr(55, 7));

	// longitude
	longitude = stoi(line.substr(63, 8));

	/*
	string inVal;
	int whitespaceCount = 0;
	int lineSkip_thresh = 6;

	// ID
	inVal = parser.trim(line, whitespaceCount);
	if (inVal[0] != '#')
		cout << "invalid header, missing #" << endl;
	// get rid of the #
	inVal.erase(0, 1);
	strcpy_s(id, inVal.c_str());

	// Year
	inVal = parser.trim(line, whitespaceCount);
	year = stoi(inVal);

	// Month
	inVal = parser.trim(line, whitespaceCount);
	if (inVal.length() > 1 && inVal[0] == '0')
		inVal.erase(0, 1);
	month = stoi(inVal);

	// Day
	inVal = parser.trim(line, whitespaceCount);
	if (inVal.length() > 1 && inVal[0] == '0')
		inVal.erase(0, 1);
	day = stoi(inVal);

	// Hour
	inVal = parser.trim(line, whitespaceCount);
	if (inVal.length() > 1 && inVal[0] == '0')
		inVal.erase(0, 1);
	hour = stoi(inVal);

	// reltime
	inVal = parser.trim(line, whitespaceCount);
	reltime = stoi(inVal);

	// numLevels
	inVal = parser.trim(line, whitespaceCount);
	numLevels = stoi(inVal);

	// P_SRC and NP_SRC
	inVal = parser.trim(line, whitespaceCount);
	
	// P_SRC was skipped
	if (whitespaceCount > lineSkip_thresh) {
		strcpy_s(P_SRC, "NA");
		strcpy_s(NP_SRC, inVal.c_str());
		// latitude
		inVal = parser.trim(line, whitespaceCount);
		latitude = stoi(inVal);
		// longitude
		inVal = parser.trim(line, whitespaceCount);
		longitude = stoi(inVal);
	}
	// P_SRC was not skipped
	else {
		strcpy_s(P_SRC, inVal.c_str());
		// NP_SRC
		inVal = parser.trim(line, whitespaceCount);
		
		// NP_SRC was skipped
		if (whitespaceCount > lineSkip_thresh) {
			strcpy_s(NP_SRC, "NA");
			latitude = stoi(inVal);
			// longitude
			inVal = parser.trim(line, whitespaceCount);
			longitude = stoi(inVal);
		}
		// NP_SRC was not skipped
		else {
			strcpy_s(NP_SRC, inVal.c_str());
			inVal = parser.trim(line, whitespaceCount);
			latitude = stoi(inVal);
			// longitude
			inVal = parser.trim(line, whitespaceCount);
			longitude = stoi(inVal);
		}
	}*/

}



void Header::coutHeader()
{
	cout << "#" << setw(11) << id << " " << setw(4) << year << " ";
	if (month < 10)
		cout << setw(1) << 0 << setw(1) << month << " ";
	else
		cout << setw(2) << month << " ";
	if (day < 10)
		cout << setw(1) << 0 << setw(1) << day << " ";
	else
		cout << setw(2) << day << " ";
	if (hour < 10)
		cout << setw(1) << 0 << setw(1) << hour << " ";
	else
		cout << setw(2) << hour << " ";
		
	cout << setw(4) << reltime << " " <<
		 setw(4) << numLevels << " " << setw(8) << p_src << " " << setw(8) << np_src << " " <<
		 setw(7) << latitude << " " << setw(8) << longitude;
}


void Header::fileOut(ofstream& os)
{
	os << "#" << setw(11) << id << " " << setw(4) << year << " ";
	if (month < 10)
		os << setw(1) << 0 << setw(1) << month << " ";
	else
		os << setw(2) << month << " ";
	if (day < 10)
		os << setw(1) << 0 << setw(1) << day << " ";
	else
		os << setw(2) << day << " ";
	if (hour < 10)
		os << setw(1) << 0 << setw(1) << hour << " ";
	else
		os << setw(2) << hour << " ";

	os << setw(4) << reltime << " " <<
		setw(4) << numLevels << " " << setw(8) << p_src << " " << setw(8) << np_src << " " <<
		setw(7) << latitude << " " << setw(8) << longitude;
}