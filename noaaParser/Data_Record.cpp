#include "Data_Record.h"

void Data_Record::parse(string line)
{
	// parsed according to https://www1.ncdc.noaa.gov/pub/data/igra/data/igra2-data-format.txt


	if (line.length() < 51)
		cout << "ERROR -> line isn't long enough to parse data record!\n";

	string inVal;

	// LVLTYPE1
	lvltyp1 = stoi(line.substr(0, 1));

	// LVLTYPE2
	lvltyp2 = stoi(line.substr(1, 1));

	// etime
	etime = stoi(line.substr(3, 5));

	// press
	press = stoi(line.substr(9, 6));

	// pflag
	pflag = line[15];

	// gpg
	gph = stoi(line.substr(16, 5));

	// zflag
	zflag = line[21];

	// temp
	temp = stoi(line.substr(22, 5));

	// tflag
	tflag = line[27];

	// rh
	rh = stoi(line.substr(28, 5));

	// dpdp
	dpdp = stoi(line.substr(34, 5));

	// wdir
	wdir = stoi(line.substr(40, 5));

	// wspd
	wspd = stoi(line.substr(46, 5));

}

void Data_Record::coutData_Record()
{
	cout << setw(1) << lvltyp1 << setw(1) << lvltyp2 << " " << setw(5) << etime << " "
		 << setw(6) << press << setw(1) << pflag << setw(5) << gph << setw(1) << zflag << setw(5) << temp <<
		 setw(1) << tflag << setw(5) << rh << " " << setw(5) << dpdp << " " << setw(5) << wdir << " "
		 << setw(5) << wspd;
}

void Data_Record::fileOut(ofstream& os)
{
	os << setw(1) << lvltyp1 << setw(1) << lvltyp2 << " " << setw(5) << etime << " "
		<< setw(6) << press << setw(1) << pflag << setw(5) << gph << setw(1) << zflag << setw(5) << temp <<
		setw(1) << tflag << setw(5) << rh << " " << setw(5) << dpdp << " " << setw(5) << wdir << " "
		<< setw(5) << wspd;
}