#include <iostream>
#include "Production_Request.h"

using namespace std;

Production_Request::Production_Request(int id, int p_id, Date d1, Date d2, int q) : request_date(d1), deadline(d2) {
	this->ID = id;
	this->publication_id = p_id;
	this->qnt = q;
}

void Production_Request::show() {
	cout << " ID: " << this->ID << endl << " Publication ID: " << this->publication_id << endl << " Quantity: " << this->qnt << endl << " Request date: ";
	this->request_date.show();
	cout << endl << " Deadline: "; 
	this->deadline.show();
	cout << endl << " -------------------------\n";
}

int Production_Request::getID() const {
	return this->ID;
}

int Production_Request::getPublicationID() const {
	return this->publication_id;
}

Date Production_Request::getRequestDate() const {
	return this->request_date;
}

Date Production_Request::getDeadline() const {
	return this->deadline;
}

int Production_Request::getQuantity() const {
	return this->qnt;
}

bool Production_Request::operator == (Production_Request & pr2) const {
	return (ID == pr2.ID);
}