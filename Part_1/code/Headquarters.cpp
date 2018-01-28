#include <iostream>
#include <algorithm>
#include <fstream>
#include "Headquarters.h"
#include "Book.h"
#include "Journal.h"
#include "Store_Request.h"
#include "Production_Request.h"

using namespace std;

Headquarters::Headquarters(){
}

void Headquarters::showPublications() const
{
	cout << "\n < PUBLICATIONS >\n\n";
	for (unsigned int i = 0; i < publications.size(); i++)
	{
		publications.at(i)->show();
		cout << " HQ Stock: " << hq_stock.at(i) << endl << " -----------------------" << endl;
		if(i != publications.size() - 1)
			cout << endl;
	}

	if (publications.size() == 0)
		cout << "No publications found" << endl;
}

void Headquarters::showEmployees() const
{
	cout << "\n < EMPLOYEES >\n\n";
	for (unsigned int i = 0; i < employees.size(); i++)
	{
		employees.at(i)->show();
	}

	if (employees.size() == 0)
		cout << "No employees found" << endl;
}

void Headquarters::showStores() const
{
	for (unsigned int i = 0; i < stores.size(); i++)
	{
		stores.at(i)->show();
		if (i != stores.size() - 1)
			cout << endl;
	}

	if (stores.size() == 0)
		cout << "No stores found" << endl;
}

void Headquarters::showStoreRequests() const
{
	for (unsigned int i = 0; i < store_requests.size(); i++)
	{
		store_requests.at(i)->show();
		if (i != store_requests.size() - 1)
			cout << endl;
	}

	if (store_requests.size() == 0)
		cout << "No store requests found" << endl;
}

void Headquarters::showProductionRequests() const
{
	for (unsigned int i = 0; i < production_requests.size(); i++)
	{
		production_requests.at(i)->show();
		if (i != production_requests.size() - 1)
			cout << endl;
	}

	if (production_requests.size() == 0)
		cout << "No production requests found" << endl;
}

void Headquarters::addPublication() // Pedir ao utilizador
{
	int type = 0; 
	int id ;
	string description;
	string colection;
	int volume;
	int number;
	int year;

	// select type
	cout << "Select type of publication:" << endl << "1 - Book" << endl << "2 - Journal" << endl;
	cin >> type;
	while (cin.fail() || (type != 1 && type!=2))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid type ";
		cin >> type;
	}

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	//VER ISTO: se inserirmos um id ja existente ele volta ao menu.

	Publication p(id, "", "");
	vector<Publication *>::iterator it = find_if(publications.begin(), publications.end(), [&p](const Publication * P) {return *P == p; }); // searches if there's already a publication with that id

	if (it != publications.end()) // if found a publication with same id
		throw ExistingID<int>(id);

	cin.ignore(1000, '\n');

	// set description
	cout << "Description? ";
	getline(cin, description);
	if (description == "") {
		while (description == "")
		{
			cout << "Is not accepted a nule string.\nDescription? ";
			getline(cin,description);
		}
	}

	// set colection
	cout << "Collection? ";
	getline(cin, colection);
	if (colection == "") {
		while (colection == "")
		{
			cout << "Is not accepted a nule string.\nCollection? ";
			getline(cin, colection);
		}
	}

	if (type == 1) // if book
	{
		Publication * b = new Book(id, description, colection);
		publications.push_back(b);
		hq_stock.push_back(0);

	}
	else // if journal
	{
		//set volume
		cout << "Volume? ";
		cin >> volume;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid volume ";
			cin >> volume;
		}

		// set number
		cout << "Number? ";
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid number ";
			cin >> number;
		}

		//set year
		cout << "Year? ";
		cin >> year;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid year ";
			cin >> year;
		}

		cin.ignore(1000, '\n');

		Publication * j = new Journal(id, description, colection, volume, number, year);
		publications.push_back(j);
		hq_stock.push_back(0);
	}
}

void Headquarters::addEmployee() // Pedir ao utilizador
{
	int id;
	string name;
	int y, m, d;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}


	Employee e(id, "", 1, 1, 1);
	vector<Employee *>::iterator it = find_if(employees.begin(), employees.end(), [&e](const Employee *E) {return *E == e; }); // searches if there's already an employee with that id

	if (it != employees.end()) // if found an employee with same id
		throw ExistingID<int>(id);

	cin.ignore(1000, '\n');

	// set name
	cout << "Name? ";
	getline(cin, name);

	// set birth date

	//set year
	cout << "Birth date: year? ";
	cin >> y;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y;
	}

	//set month
	cout << "Birth date: month? ";
	cin >> m;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m;
	}

	//set day
	cout << "Birth date: day? ";
	cin >> d;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d;
	}


	cin.ignore(1000, '\n');

	Employee * emp = new Employee(id, name, y, m, d);
	employees.push_back(emp);
}

void Headquarters::addStore()  // Pedir ao utilizador
{
	int id;
	string city;
	unsigned long pn;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}


	Store s(id, "", 0);
	vector<Store *>::iterator it = find_if(stores.begin(), stores.end(), [&s](const Store *S) {return *S == s; }); // searches if there's already a store with that id

	if (it != stores.end()) // if found a store with same id
		throw ExistingID<int>(id);

	cin.ignore(1000, '\n');

	// set city
	cout << "City? ";
	getline(cin, city);

	//set phone number
	cout << "Phone Number? ";
	cin >> pn;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid phone number ";
		cin >> pn;
	}

	cin.ignore(1000, '\n');

	Store * st = new Store(id, city, pn);
	stores.push_back(st);
}

void Headquarters::addStoreRequest() // Pedir ao utilizador
{
	int id;
	int publication_id;
	int y1, m1, d1;
	int y2, m2, d2;
	int qnt;
	float unitary_price;
	int store_id;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}


	Store_Request sr(id, 0, Date(1,1,1), Date(1,1,1), 0, 0, 0);
	vector<Store_Request *>::iterator it = find_if(store_requests.begin(), store_requests.end(), [&sr](const Store_Request *SR) {return *SR == sr; }); // searches if there's already a store request with that id

	if (it != store_requests.end()) // if found a store request with same id
		throw ExistingID<int>(id);

	//set publication id
	cout << "Publication ID? ";
	cin >> publication_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a ID ";
		cin >> publication_id;
	}

	Publication p(publication_id, "", "");
	vector<Publication *>::iterator it2 = find_if(publications.begin(), publications.end(), [&p](const Publication *P) {return *P == p; }); // searches if there's already a publication with that id

	if (it2 == publications.end()) // if did not found a publication with same id
		throw IDNotFound<int>(publication_id);

	// set reqeust date

	//set year
	cout << "Request date: year? ";
	cin >> y1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y1;
	}

	//set month
	cout << "Request date: month? ";
	cin >> m1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m1;
	}

	//set day
	cout << "Request date: day? ";
	cin >> d1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d1;
	}

	// set deadline

	//set year
	cout << "Deadline: year? ";
	cin >> y2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y2;
	}

	//set month
	cout << "Deadline: month? ";
	cin >> m2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m2;
	}

	//set day
	cout << "Deadline: day? ";
	cin >> d2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d2;
	}

	//set quantity
	cout << "Quantity? ";
	cin >> qnt;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid quantity ";
		cin >> qnt;
	}

	//set price
	cout << "Unitary Price? ";
	cin >> unitary_price;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid price ";
		cin >> unitary_price;
	}

	//set store id
	cout << "Store ID? ";
	cin >> store_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> store_id;
	}

	Store s(store_id, "", 0);
	vector<Store *>::iterator it3 = find_if(stores.begin(), stores.end(), [&s](const Store *S) {return *S == s; }); // searches if there's already a store with that id

	if (it3 == stores.end()) // if did not found a store with same id
		throw IDNotFound<int>(store_id);

	cin.ignore(1000, '\n');

	Store_Request * str = new Store_Request(id, publication_id, Date(y1, m1, d1), Date(y2, m2, d2), qnt, unitary_price, store_id);
	store_requests.push_back(str);
}

void Headquarters::addProductionRequest() // Pedir ao utilizador
{
	int id;
	int publication_id;
	int y1, m1, d1;
	int y2, m2, d2;
	int qnt;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}


	Production_Request pr(id, 0, Date(1, 1, 1), Date(1, 1, 1), 0);
	vector<Production_Request *>::iterator it = find_if(production_requests.begin(), production_requests.end(), [&pr](const Production_Request *PR) {return *PR == pr; }); // searches if there's already a production request with that id

	if (it != production_requests.end()) // if found a production request with same id
		throw ExistingID<int>(id);

	//set publication id
	cout << "Publication ID? ";
	cin >> publication_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a ID ";
		cin >> publication_id;
	}

	Publication p(publication_id, "", "");
	vector<Publication *>::iterator it2 = find_if(publications.begin(), publications.end(), [&p](const Publication *P) {return *P == p; }); // searches if there's already a publication with that id

	if (it2 == publications.end()) // if did not found a publication with same id
		throw IDNotFound<int>(publication_id);

	// set reqeust date

	//set year
	cout << "Request date: year? ";
	cin >> y1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y1;
	}

	//set month
	cout << "Request date: month? ";
	cin >> m1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m1;
	}

	//set day
	cout << "Request date: day? ";
	cin >> d1;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d1;
	}

	// set deadline

	//set year
	cout << "Deadline: year? ";
	cin >> y2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y2;
	}

	//set month
	cout << "Deadline: month? ";
	cin >> m2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m2;
	}

	//set day
	cout << "Deadline: day? ";
	cin >> d2;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d2;
	}

	//set quantity
	cout << "Quantity? ";
	cin >> qnt;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid quantity ";
		cin >> qnt;
	}

	cin.ignore(1000, '\n');

	Production_Request * pror = new Production_Request(id, publication_id,  Date(y1, m1, d1), Date(y2, m2, d2), qnt);
	production_requests.push_back(pror);
}

void Headquarters::deletePublication()  // Pedir ao utilizador
{
	int id;
	bool found = false;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	unsigned int i = 0;
	//searches for publication
	for (; i < publications.size(); i++)
	{
		if (publications.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
		throw IDNotFound<int>(id);

	//eliminates publication from vector
	for (unsigned int j = i; j < (publications.size() - 1); j++)
	{
		publications.at(j) = publications.at(j + 1);
		hq_stock.at(j) = hq_stock.at(j + 1);
	}

	publications.resize(publications.size() - 1);
	hq_stock.resize(hq_stock.size() - 1);

	//eliminates publication from stores
	for (i = 0; i < stores.size(); i++)
	{
		stores.at(i)->removePublication(id);
	}

	//eliminates publication from production requests
	for (i = 0; i < production_requests.size(); i++)
	{
		if (production_requests.at(i)->getPublicationID() == id)
		{
			for (unsigned int j = i; j < production_requests.size(); j++)
			{
				production_requests.at(j) = production_requests.at(j + 1);
			}
			production_requests.resize(production_requests.size() - 1);
		}
	}

	//eliminates publication from store requests
	for (i = 0; i < store_requests.size(); i++)
	{
		if (store_requests.at(i)->getPublicationID() == id)
		{
			for (unsigned int j = i; j < store_requests.size(); j++)
			{
				store_requests.at(j) = store_requests.at(j + 1);
			}
			store_requests.resize(store_requests.size() - 1);
		}
	}
}

void Headquarters::deleteEmployee() // Pedir ao utilizador
{
	int id;
	bool found = false;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	unsigned int i = 0;
	//searches for employee
	for (; i < employees.size(); i++)
	{
		if (employees.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
		throw IDNotFound<int>(id);

	//eliminates employee from vector
	for (unsigned int j = i; j < (employees.size() - 1); j++)
	{
		employees.at(j) = employees.at(j + 1);
	}

	employees.resize(employees.size() - 1);

	//eliminates employee from stores
	for (i = 0; i < stores.size(); i++)
	{
		if (stores.at(i)->getWorker().getID() == id) {
			stores.at(i)->setWorker(NULL);
			stores.at(i)->setID_employee(0);
		}
	}
}

void Headquarters::deleteStore() // Pedir ao utilizador
{
	int id;
	bool found = false;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	unsigned int i = 0;
	//searches for store
	for (; i < stores.size(); i++)
	{
		if (stores.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
		throw IDNotFound<int>(id);

	//eliminates store from vector
	for (unsigned int j = i; j < (stores.size() - 1); j++)
	{
		stores.at(j) = stores.at(j + 1);
	}

	stores.resize(stores.size() - 1);

	//eliminates store from employees
	for (i = 0; i < employees.size(); i++)
	{
		if (employees.at(i)->getWorkplace()->getID() == id) {
			employees.at(i)->setWorkplace(NULL);
			employees.at(i)->setID_store(0);
		}
	}

	//eliminates store from store requests
	for (i = 0; i < store_requests.size(); i++)
	{
		if (store_requests.at(i)->getStoreID() == id)
		{
			for (unsigned int j = i; j < store_requests.size(); j++)
			{
				store_requests.at(j) = store_requests.at(j + 1);
			}
			store_requests.resize(store_requests.size() - 1);
		}
	}
}

void Headquarters::deleteStoreRequest() // Pedir ao utilizador
{
	int id;
	bool found = false;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	unsigned int i = 0;
	//searches for store request
	for (; i < store_requests.size(); i++)
	{
		if (store_requests.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
		throw IDNotFound<int>(id);

	//eliminates store request from vector
	for (unsigned int j = i; j < (store_requests.size() - 1); j++)
	{
		store_requests.at(j) = store_requests.at(j + 1);
	}

	store_requests.resize(store_requests.size() - 1);
}

void Headquarters::deleteProductionRequest()  // Pedir ao utilizador
{
	int id;
	bool found = false;

	//set id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	unsigned int i = 0;
	//searches for production request
	for (; i < production_requests.size(); i++)
	{
		if (production_requests.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
		throw IDNotFound<int>(id);

	//eliminates store request from vector
	for (unsigned int j = i; j < (production_requests.size() - 1); j++)
	{
		production_requests.at(j) = production_requests.at(j + 1);
	}

	production_requests.resize(production_requests.size() - 1);
}

void Headquarters::attributeStore() 
{
	int store_id, employee_id;

	//set store id
	cout << "Store ID? ";
	cin >> store_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> store_id;
	}

	Store s(store_id, "", 0);
	vector<Store *>::iterator it = find_if(stores.begin(), stores.end(), [&s](const Store *S) {return *S == s; }); // searches if there's already a store with that id

	if (it == stores.end()) // if did not found a store with same id
		throw IDNotFound<int>(store_id);

	//set employee id
	cout << "Employee ID? ";
	cin >> employee_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> employee_id;
	}

	Employee e(employee_id, "", 1, 1, 1);
	vector<Employee *>::iterator it2 = find_if(employees.begin(), employees.end(), [&e](const Employee *E) {return *E == e; }); // searches if there's already a store with that id

	if (it2 == employees.end()) // if did not found a store with same id
		throw IDNotFound<int>(employee_id);

	(*it)->setWorker(*it2);
	(*it2)->setWorkplace(*it);
	(*it)->setID_employee(employee_id);
	(*it2)->setID_store(store_id);

	cin.ignore(1000, '\n');
}

void Headquarters::satisfyStoreRequests(bool priority)
{
	bool found = false;

	if (priority)
		sort(store_requests.begin(), store_requests.end(), [](const Store_Request * p1, const Store_Request * p2) {return (p1->getRequestDate() < p2->getRequestDate()); });// sorts with priority "first request made"
	else
		sort(store_requests.begin(), store_requests.end(), [](const Store_Request * p1, const Store_Request * p2) {return (p1->getDeliveryDate() < p2->getDeliveryDate()); });// sorts with priority "nearest deadline

	size_t i = 0;

	for (; i < store_requests.size(); i++)
	{
		for (size_t j = 0; j < publications.size(); j++)
		{
			if (publications.at(j)->getID() == store_requests.at(i)->getPublicationID())
			{
				if (hq_stock.at(j) >= store_requests.at(i)->getQuantity())
				{
					hq_stock.at(j) -= store_requests.at(i)->getQuantity();
					for (size_t k = 0; k < stores.size(); k++)
					{
						if (stores.at(k)->getID() == store_requests.at(i)->getStoreID())
						{
							stores.at(k)->addStock(store_requests.at(i)->getPublicationID(), store_requests.at(i)->getQuantity());
							break;
						}
					}
					break;
				}
				else
					break;
			}
			if (found)
				break;
		}
	}

	for (; i < (store_requests.size() - 1); i++) // deletes sattisfied request
	{
		store_requests.at(i) = store_requests.at(i + 1);
	}

	store_requests.resize(store_requests.size() - 1);
}

void Headquarters::produce(bool priority)
{
	if (priority)
		sort(production_requests.begin(), production_requests.end(), [](const Production_Request * p1, const Production_Request * p2) {return (p1->getRequestDate() < p2->getRequestDate()); });// sorts with priority "first request made"
	else 
		sort(production_requests.begin(), production_requests.end(), [](const Production_Request * p1, const Production_Request * p2) {return (p1->getDeadline() < p2->getDeadline()); });// sorts with priority "nearest deadline"

	Publication P(production_requests.at(0)->getPublicationID(), "", ""); //dummy publication for comparrison

	vector<Publication *>::iterator it = find_if(publications.begin(), publications.end(), [&P](Publication * &p) {return P == *p; }); //finds publication in headquarters

	int pos = 0;

	for (vector<Publication *>::iterator it2 = publications.begin(); it != publications.end(); it++) // finds position corresponding to iterator it
	{
		if (it2 == it)
			break;
		else
			pos++;
	}

	hq_stock.at(pos) += production_requests.at(0)->getQuantity(); //updates hq stock of said publication

	for (size_t i = 0; i < (production_requests.size() - 1); i++) // deletes first request
	{
		production_requests.at(i) = production_requests.at(i + 1);
	}

	production_requests.resize(production_requests.size() - 1);
}

vector<Publication *> Headquarters::getPublications() const {
	return this->publications;
}

vector<Employee *> Headquarters::getEmployees() const {
	return this->employees;
}

vector<Store *> Headquarters::getStores() const {
	return this->stores;
}

vector<Store_Request *> Headquarters::getStore_requests() const {
	return this->store_requests;
}

vector<Production_Request *> Headquarters::getProduction_requests() const {
	return this->production_requests;
}

int Headquarters::count_types(int ind) const {

	int ret = 0;
	for (unsigned int i = 0; i < publications.size(); i++) {
		if (publications.at(i)->getType() == ind)
			ret++;
	}
	return ret;
}


void Headquarters::set_publication_to_store(){

	int store_id, pub_id;

	//get store id
	cout << "Store ID? ";
	cin >> store_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> store_id;
	}

	Store s(store_id, "", 0);
	vector<Store *>::iterator it = find_if(stores.begin(), stores.end(), [&s](const Store *S) {return *S == s; }); // searches if there's already a store with that id

	if (it == stores.end()) // if did not found a store with same id
		throw IDNotFound<int>(store_id);

	//get publication id
	cout << "Publication ID? ";
	cin >> pub_id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> pub_id;
	}

	Publication p(pub_id, "", "");
	vector<Publication *>::iterator it2 = find_if(publications.begin(), publications.end(), [&p](const Publication *P) {return *P == p; }); // searches if there's already a publication with that id

	if (it2 == publications.end()) // if did not found a store with same id
		throw IDNotFound<int>(pub_id);

	for(unsigned int k = 0; k < this->getStores().size() ; k++){
		if (getStores().at(k)->getID() == store_id){
			getStores().at(k)->addPublication(*it2,0);
		}
	}

	cin.ignore(1000, '\n');
}

bool Headquarters::verifica_set_publications (int store_id, int store_request_pub_id){


	for(unsigned int k = 0; k < this->getStores().size() ; k++){
		if (getStores().at(k)->getID() == store_id){
			for (unsigned int j = 0; j < this->getStores().at(k)->get_publications_store().size(); j++){
				if (getStores().at(k)->get_publications_store().at(j)->getID() == store_request_pub_id){
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
