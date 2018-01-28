#include <iostream>
#include "Journal.h"

using namespace std;

Journal::Journal(int id, string desc, string col, int vol, int n, int y) : Publication(id, desc, col)
{
	volume = vol;
	number = n;
	year = y;
}

void Journal::show() {
	cout << " Journal" << endl;
	Publication::show();
	cout << " Volume: " << this->volume << endl << " Number: " << this->number << endl << " Year: " << this->year << endl;
}

int Journal::getVolume() const {
	return this->volume;
}

int Journal::getNumber() const {
	return this->number;
}

int Journal::getYear() const {
	return this->year;
}

string Journal::getOutPut(int type) {
	string ret;
	if (type == 1)
		ret = to_string(getID()) + " ; " + getDescripiton() + " ; " + getColection() + " ; " + to_string(getVolume()) + " " + to_string(getNumber()) + " " + to_string(getYear());
	return ret;
}
int Journal::getType() const {
	return 1;
}