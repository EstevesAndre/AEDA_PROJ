#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(int id, string desc, string col) : Publication(id, desc, col) {

};

void Book::show() {
	cout << " Book" << endl;
	Publication::show();
}

string Book::getOutPut(int type) {
	string ret;
	if (type == 0)
		ret = to_string(getID()) + " ; " + getDescripiton() + " ; " + getColection();
	return ret;
}

int Book::getType() const {
	return 0;
}