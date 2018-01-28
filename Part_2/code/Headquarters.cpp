#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "Headquarters.h"
#include "Book.h"
#include "Journal.h"
#include "Store_Request.h"
#include "Production_Request.h"
#include "Store.h"

using namespace std;

Headquarters::Headquarters() : production_requests(BST<Production_Request>(Production_Request(-1, -1, Date(1, 1, 1), Date(1, 1, 1), 0))){

}

Suspended_Request::Suspended_Request(): d(1,1,1){};


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

//DONE
void Headquarters::showStoreRequests() const
{
	priority_queue<Store_Request *> requests = store_requests;
	for (unsigned int i = 0; i < store_requests.size(); i++)
	{
		requests.top()->show();
		if (i != store_requests.size() - 1)
			cout << endl;
		requests.pop();
	}

	if (store_requests.size() == 0)
		cout << "No store requests found" << endl;
}

void Headquarters::showSuspendedRequests() const
{
	tabHSuspencion::const_iterator it = suspended_requests.begin();
	while (it != suspended_requests.end()) {
		(*it).sr->show();
		cout << endl << "Suspension Date: ";
		(*it).d.show();
		cout << endl << endl;
		it++;
	}

	if (suspended_requests.size() == 0)
		cout << "No suspended requests found" << endl;
}
void Headquarters::showStoreRequestsBelowX() const
{
	bool found = false;
	priority_queue<Store_Request *> requests = store_requests;
	int n;

	cout << "Stock Limit? ";
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid stock limit ";
		cin >> n;
	}
	for (unsigned int i = 0; i < store_requests.size(); i++)
	{
		int p_id = requests.top()->getPublicationID();
		Store * s = requests.top()->getStore();
		int ref;

		for (unsigned int i = 0; i < s->get_publications_store().size(); i++)
		{
			if (s->get_publications_store().at(i)->getID() == p_id)
			{
				ref = i;
				break;
			}
		}
		if (requests.top()->getStore()->get_stock().at(ref) < n)
		{
			found = true;
			requests.top()->show();
			cout << endl;
		}

		requests.pop();
	}
	if (store_requests.size() == 0 || !found)
		cout << "No store requests found" << endl;
}
/*
void Headquarters::showStoreRequestsBelowX() const
{
	bool found = false;
	priority_queue<Store_Request *> requests = store_requests;
	int n;

	cout << "Stock Limit? ";
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid stock limit ";
		cin >> n;
	}

	for (unsigned int i = 0; i < store_requests.size(); i++)
	{
		int p_id = requests.top()->getPublicationID();
		Store * s = requests.top()->getStore();
		int ref = -1;

		for (unsigned int i = 0; i < s->get_publications_store().size(); i++)
		{
			if (s->get_publications_store().at(i)->getID() == p_id)
			{
				ref = i;
				break;
			}
		}


		if (requests.top()->getStore()->get_stock().at(ref) < n && ref != -1)
		{
			found = true;
			requests.top()->show();
			cout << endl;
		}
		ref = -1;
		requests.pop();
	}

	if (store_requests.size() == 0 || !found)
		cout << "No store requests found" << endl;
}
*/
//DONE
void Headquarters::showProductionRequests() const
{
	BSTItrIn<Production_Request> it(production_requests);
	while(! it.isAtEnd())
	{
		it.retrieve().show();
		cout << endl;
		it.advance();
	}

	if (production_requests.isEmpty())
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


	stack<Store_Request *> stk;
	bool found = false;

	while (!store_requests.empty())
	{
		if (store_requests.top()->getID() == id)
		{
			found = true;
			break;
		}
		else
		{
			stk.push(store_requests.top());
			store_requests.pop();
		}
	}

	while (!stk.empty())
	{
		store_requests.push(stk.top());
		stk.pop();
	}

	tabHSuspencion::iterator it = suspended_requests.begin();
	while (it != suspended_requests.end()) {
		if ((*it).sr->getID() == id)
		{
			found = true;
			break;
		}
		it++;
	}

	if(found)
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

	Store_Request * str = new Store_Request(id, publication_id, Date(y1, m1, d1), Date(y2, m2, d2), qnt, unitary_price, *it3);
	store_requests.push(str);
}

//DONE
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

	BSTItrIn<Production_Request> it(production_requests);
	while (!it.isAtEnd())
	{
		if(it.retrieve().getID() == id)
			throw ExistingID<int>(id);
		it.advance();
	}


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

	// set request date

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

	production_requests.insert(Production_Request(id, publication_id,  Date(y1, m1, d1), Date(y2, m2, d2), qnt));
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

	vector<int> qnts;

	BSTItrIn<Production_Request> it(production_requests);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getPublicationID() == id)
			qnts.push_back(it.retrieve().getQuantity());
		it.advance();
	}

	for (i = 0; i < qnts.size(); i++)
	{
		production_requests.remove(Production_Request(-1, id, Date(1, 1, 1), Date(1, 1, 1), qnts.at(i)));
	}

	priority_queue<Store_Request *> requests_store = store_requests, aux;

	//eliminates publication from store requests
	for (i = 0; i < store_requests.size(); i++)
	{
		if (requests_store.top()->getPublicationID() != id)
		{
			aux.push(requests_store.top());
		}
		requests_store.pop();
	}
	store_requests = aux;
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

	priority_queue<Store_Request *> requests_store = store_requests, aux;

	//eliminates store from store requests
	for (i = 0; i < store_requests.size(); i++)
	{
		if (requests_store.top()->getStore()->getID() != id)
		{
			aux.push(requests_store.top());
		}
		requests_store.pop();
	}
	store_requests = aux;
}

void Headquarters::suspendStoreRequest() // Pedir ao utilizador
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

	priority_queue<Store_Request *> requests_store = store_requests,auxiliar;

	unsigned int i = 0;
	//searches for store request
	for (; i < store_requests.size(); i++)
	{
		if (requests_store.top()->getID() == id)
		{
			found = true;

			break;
		}
		requests_store.pop();
	}

	if (!found)
		throw IDNotFound<int>(id);

	int y, m, d;

	//set new year
	cout << "\n\nSuspencion date:\n\nYear? ";

	cin >> y;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid year ";
		cin >> y;
	}

	//set new month
	cout << "Month? ";
	cin >> m;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid month ";
		cin >> m;
	}

	//set day
	cout << "Day? ";
	cin >> d;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid day ";
		cin >> d;
	}

	requests_store = store_requests;

	//eliminates store request from vector
	for (unsigned int j = 0; j < store_requests.size(); j++)
	{
		if (j != i)
			auxiliar.push(requests_store.top());
		else
		{
			Suspended_Request req;
			req.sr = requests_store.top();
			req.d = Date(y, m, d);

			suspended_requests.insert(req);
		}
		requests_store.pop();
	}
	store_requests = auxiliar;
}

void Headquarters::reinstateStoreRequest()
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

	tabHSuspencion::iterator it = suspended_requests.begin();
	while (it != suspended_requests.end()) {
		if ((*it).sr->getID() == id)
		{
			found = true;
			break;
		}
		it++;
	}

	if (!found)
		throw IDNotFound<int>(id);

	store_requests.push((*it).sr);
	suspended_requests.erase(it);
}

void Headquarters::removeStoreRequest()
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

	tabHSuspencion::iterator it = suspended_requests.begin();
	while (it != suspended_requests.end()) {
		if ((*it).sr->getID() == id)
		{
			found = true;
			break;
		}
		it++;
	}

	if (!found)
		throw IDNotFound<int>(id);

	suspended_requests.erase(it);
}

//DONE
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

	BSTItrIn<Production_Request> it(production_requests);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getPublicationID() == id)
		{
			production_requests.remove(Production_Request(-1, id, Date(1, 1, 1), Date(1, 1, 1), it.retrieve().getQuantity()));
			found = true;
			break;
		}
		it.advance();
	}

	if(!found)
		throw IDNotFound<int>(id);
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

void Headquarters::satisfyStoreRequests()
{
	bool found = false;

	size_t i = 0;
	priority_queue<Store_Request *> store_request = store_requests, aux;

	for (; i < store_requests.size(); i++)
	{
		for (size_t j = 0; j < publications.size(); j++)
		{
			if (publications.at(j)->getID() == store_request.top()->getPublicationID())
			{
				if (hq_stock.at(j) >= store_request.top()->getQuantity())
				{
					hq_stock.at(j) -= store_request.top()->getQuantity();
					for (size_t k = 0; k < stores.size(); k++)
					{
						if (stores.at(k)->getID() == store_requests.top()->getStore()->getID())
						{
							stores.at(k)->addStock(store_requests.top()->getPublicationID(), store_requests.top()->getQuantity());
							found = true;
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
		store_request.pop();
	}

	store_request = store_requests;

	for (size_t a = 0; a < store_requests.size(); a++) // deletes satisfied request
	{
		if ( a != i)
			aux.push(store_request.top());
		store_request.pop();
	}
	store_requests = aux;

}

void Headquarters::produce()
{
	Production_Request p = production_requests.findMax();
	production_requests.remove(p);


	unsigned int i;
	for (i = 0; i < publications.size(); i++)
	{
		if (p.getPublicationID() == publications.at(i)->getID())
		{
			break;
		}
	}

	hq_stock.at(i) += p.getQuantity();
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

priority_queue<Store_Request *> Headquarters::getStore_requests() const {
	return store_requests;
}

tabHSuspencion Headquarters::get_suspended_requests() const{
	return this->suspended_requests;
}

//DONE
BST<Production_Request> Headquarters::getProduction_requests() const {
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


//DONE
void Headquarters::show_specific_production_request() const{
	int id;

	//get id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	bool found = false;

	for (unsigned int i = 0; i < publications.size(); i++)
	{
		if (publications.at(i)->getID() == id)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		throw IDNotFound<int>(id);
	}

	BSTItrIn<Production_Request> it(production_requests);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getPublicationID() == id)
		{
			it.retrieve().show();
			return;
		}
		it.advance();
	}
	cout << "Production Request not found with the given publication ID.\n";
}

void Headquarters::change_limite_date(){

	int id;

	//get id
	cout << "ID? ";
	cin >> id;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Insert a valid ID ";
		cin >> id;
	}

	bool found = false;

	BSTItrIn<Production_Request> it(production_requests);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getID() == id)
		{
			found = true;
			break;
		}
		it.advance();
	}

	if (!found)
	{
		throw IDNotFound<int>(id);
	}
	else
	{
		it.retrieve().show();
		int y,m,d;

		//set new year
		cout << "\n\nNew limit date:\n\nYear? ";

		cin >> y;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid year ";
			cin >> y;
		}

		//set new month
		cout << "Month? ";
		cin >> m;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid month ";
			cin >> m;
		}

		//set day
		cout << "Day? ";
		cin >> d;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid day ";
			cin >> d;
		}


		Production_Request p = it.retrieve();
		production_requests.remove(it.retrieve());
		p.set_Deadline(y, m, d);
		production_requests.insert(p);
	}
}
