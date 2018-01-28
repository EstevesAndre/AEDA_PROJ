#include <iostream>
#include <iomanip>
#include "Store.h"

using namespace std;

Store::Store(int id, string city, unsigned long pn) {
	this->ID = id;
	this->city = city;
	this->phone_number = pn;
	worker = NULL;
	this->ID_employee = 0; // nao esta atribuido nenhum empregado
}

void Store::show() {
	cout << " ID: " << this->ID << endl << " Phone number: " << this->phone_number << endl << " City: " << this->city << endl;

	if (worker == NULL)
		cout << " No Employee Attributed" << endl;
	else
	{
		// calling getID() of store pointed by workplace
		int (Employee::*ptr) () const;
		ptr = &Employee::getID;
		cout << " Employee ID: " << ((this->worker)->*ptr) () << endl;
	}

	if (publications.size() == 0)
		cout << " No Publications in Store" << endl;
	else
	{
		cout << " Publications in Store: " << endl << endl;
		for (unsigned int i = 0; i < this->publications.size(); i++)
		{
			if (publications.at(i)->getType() == 0){
				publications.at(i)->show();
			}
			else{
				publications.at(i)->show();
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << " ------------------------" << endl;

}

int Store::getID() const {
	return this->ID;
}

int Store::getID_employee() const {
	return this->ID_employee;
}

void Store::setID_employee(int val) {
	this->ID_employee = val;
}

string Store::getCity() const {
	return this->city;
}

Employee Store::getWorker() const {
	return *this->worker;
}

unsigned long Store::getPhoneNumber() const {
	return this->phone_number;
}

vector<Publication * > Store::get_publications_store(){
	return this->publications;
}

void Store::setWorker(Employee * worker) {
	this->worker = worker;
}

void Store::addPublication(Publication * publication, int stock_min) { //0 if not journal
	publications.push_back(publication);
	stock.push_back(0);
	minimun_stock.push_back(stock_min); //0 if not journal
}

void Store::addStock(int publication_id, int amount) {
	for (unsigned int i = 0; i < publications.size(); i++) {
		if (publications.at(i)->getID() == publication_id)
			stock.at(i) += amount;
	}
}

void Store::removePublication(int id)
{
	for (unsigned int i = 0; i < publications.size(); i++)
	{
		if (publications.at(i)->getID() == id)
		{
			for (unsigned int j = i; j < (publications.size() - 1); j++)
			{
				publications.at(j) = publications.at(j + 1);
				stock.at(j) = stock.at(j + 1);
				minimun_stock.at(j) = minimun_stock.at(j + 1);
			}
			publications.resize(publications.size() - 1);
			stock.resize(stock.size() - 1);
			minimun_stock.resize(minimun_stock.size() - 1);
		}
	}

}

bool Store::operator == (Store & s2) const {
	return (ID == s2.ID);
}
