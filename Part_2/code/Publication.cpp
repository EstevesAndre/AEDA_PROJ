#include <iostream>
#include "Publication.h"

using namespace std;

Publication::Publication(int id, string desc, string col) {
	this->ID = id;
	this->description = desc;
	this->colection = col;
}

void Publication::show() {
	cout << " ID: " << this->ID << endl << " Description: " << this->description << endl << " Colection: " << this->colection << endl;
}

int Publication::getID() const {
	return this->ID;
}

string Publication::getDescripiton() const {
	return this->description;
}

string Publication::getColection() const {
	return this->colection;
}

bool Publication::operator == (const Publication & p2) const {
	return (this->ID == p2.ID);
}

string Publication::getOutPut(int type) {
	string ret;

	return ret;
}

