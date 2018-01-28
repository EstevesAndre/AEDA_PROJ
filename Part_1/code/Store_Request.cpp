#include <iostream>
#include "Store_Request.h"

using namespace std;

Store_Request::Store_Request(int ID, int pub_id, Date d1, Date d2, int q, float price, int s_id) : request_date(d1), delivery_date(d2) {
	this->publication_id = pub_id;
	this->ID = ID;
	this->qnt = q;
	this->unitary_price = price;
	this->store_id = s_id;
}

void Store_Request::show() {
	cout << " ID: " << this->ID << endl << " Publication ID: " << publication_id << endl << " Request date: ";
	this->request_date.show();
	cout << endl << " Delivery date: ";
	this->delivery_date.show();
	cout << endl << " Quantidade: " << this->qnt << endl << " Unitary price: " << this->unitary_price;
	cout << endl << " Store ID: " << this->store_id << endl << " --------------------------\n";
}

int Store_Request::getID() const {
	return this->ID;
}

int Store_Request::getPublicationID() const{
	return publication_id;
}

Date Store_Request::getRequestDate() const {
	return this->request_date;
}

Date Store_Request::getDeliveryDate() const {
	return this->delivery_date;
}

int Store_Request::getQuantity() const {
	return this->qnt;
}

float Store_Request::getUnitaryPrice() const {
	return this->unitary_price;
}

int Store_Request::getStoreID() const {
	return this->store_id;
}

bool Store_Request::operator == (Store_Request & sr2) const {
	return (ID == sr2.ID);
}
