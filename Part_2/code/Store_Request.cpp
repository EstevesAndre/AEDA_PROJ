#include <iostream>
#include "Store_Request.h"

using namespace std;

Store_Request::Store_Request(int ID, int pub_id, Date d1, Date d2, int q, float price, Store * s) : request_date(d1), delivery_date(d2) {
	this->publication_id = pub_id;
	this->ID = ID;
	this->qnt = q;
	this->unitary_price = price;
	this->store = s;
}

void Store_Request::show() {
	cout << " ID: " << this->ID << endl << " Publication ID: " << publication_id << endl << " Request date: ";
	this->request_date.show();
	cout << endl << " Delivery date: ";
	this->delivery_date.show();
	cout << endl << " Quantity " << this->qnt << endl << " Unitary price: " << this->unitary_price;
	cout << endl << " Store ID: " << this->store->getID() << endl << " --------------------------\n";
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

Store * Store_Request::getStore() const {
	return this->store;
}

bool Store_Request::operator == (Store_Request & sr2) const {
	return (ID == sr2.ID);
}

bool Store_Request::operator < (Store_Request & sr2) const{
	int p_id1 = this->getPublicationID(), p_id2 = sr2.getPublicationID();
	Store * s1 = this->getStore(), * s2 = sr2.getStore();
	int ref1, ref2;

	for (unsigned int i = 0; i < s1->get_publications_store().size(); i++)
	{
		if (s1->get_publications_store().at(i)->getID() == p_id1)
		{
			ref1 = i;
			break;
		}
	}

	for (unsigned int i = 0; i < s2->get_publications_store().size(); i++)
	{
		if (s2->get_publications_store().at(i)->getID() == p_id2)
		{
			ref2 = i;
			break;
		}
	}

	return s1->get_stock().at(ref1) < s2->get_stock().at(ref2);
}
