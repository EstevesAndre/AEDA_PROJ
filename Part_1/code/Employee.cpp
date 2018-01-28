#include <iostream>
#include "Employee.h"
#include "Store.h"

using namespace std;

Employee::Employee(int ID, string name, unsigned int y, unsigned int m, unsigned int d) : date_birth(Date(y,m,d)) {
	this->ID = ID;
	this->name = name;
	workplace = NULL;
	this->ID_store = 0; // loja nao atribuida
}

void Employee::show() {
	cout << " ID Employee: " << this->ID << endl << " Name: " << this->name << endl;
	cout << " Date of Birth: ";
	this->date_birth.show();
	cout << endl;
	if (workplace == NULL)
		cout << " No Store Attributed" << endl << " --------------------------" << endl << endl;
	else
	{
		// calling getID() of store pointed by workplace
		int (Store::*ptr) () const;
		ptr = &Store::getID;
		cout << " Store ID: " << ((this->workplace)->*ptr) () << endl << " --------------------------" << endl << endl;
	}
}

int Employee::getID() const {
	return this->ID;
}

int Employee::getID_store() const {
	return this->ID_store;
}

void Employee::setID_store(int val) {
	this->ID_store = val;
}

string Employee::getName() const {
	return this->name;
}

Date Employee::getDate() const {
	return this->date_birth;
}

Store * Employee::getWorkplace() const {
	return this->workplace; 
}


void Employee::setWorkplace(Store * st) {
	this->workplace = st;
}


bool Employee::operator == (Employee & e2) const {
	return (ID == e2.ID);
}