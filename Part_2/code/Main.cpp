#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Menu.h"
#include "Headquarters.h"
#include "Publication.h"
#include "Employee.h"
#include "Store.h"
#include "Store_Request.h"
#include "Production_Request.h"
#include "Book.h"
#include "Journal.h"

// VERIFICAR OS PATHS PARA A ABERTURA DOS FICHEIROS

using namespace std;

void tiraEspaco_i_f(string &str, unsigned int tmh);

int main() {

	Headquarters company;

	company.start_files();

	// call main menu
	while (mainMenu(company));

	string val;
	cout << "\n\n Deseja guardar as alteracoes ? \n -- > ";
	getline(cin, val);

	if (val == "yes" || val == "YES" || val == "Yes" || val == "y" || val == "Y") {

		ofstream ficheirotxt1;
		ficheirotxt1.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Publications_books.txt", ios::trunc);
		int qua = company.count_types(0);
		int aux = 0;
		for (unsigned int i = 0; i < company.getPublications().size(); i++) {
			if (company.getPublications().at(i)->getType() == 0) {
				aux++;
				ficheirotxt1 << company.getPublications().at(i)->getOutPut(0);
				if (aux != qua)
					ficheirotxt1 << endl;
			}
		}

		ficheirotxt1.close();

		ofstream ficheirotxt2;
		ficheirotxt2.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Publications_journals.txt", ios::trunc);
		qua = company.count_types(1);
		aux = 0;
		for (unsigned int i = 0; i < company.getPublications().size(); i++) {
			if (company.getPublications().at(i)->getType() == 1) {
				aux++;
				ficheirotxt2 << company.getPublications().at(i)->getOutPut(1);
				if (aux != qua)
					ficheirotxt2 << endl;
			}
		}
		ficheirotxt2.close();

		ofstream ficheirotxt3;
		ficheirotxt3.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Employees.txt");
		for (unsigned int i = 0; i < company.getEmployees().size(); i++) {
			ficheirotxt3 << company.getEmployees().at(i)->getName() << " ; " << company.getEmployees().at(i)->getID() << " ";
			ficheirotxt3 << company.getEmployees().at(i)->getDate().getYear() << " " << company.getEmployees().at(i)->getDate().getMonth();
			ficheirotxt3 << " " << company.getEmployees().at(i)->getDate().getDay() << " " << company.getEmployees().at(i)->getID_store();
			if (i != company.getEmployees().size() - 1)
				ficheirotxt3 << endl;
		}
		ficheirotxt3.close();

		ofstream ficheirotxt4;
		ficheirotxt4.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Stores.txt");
		for (unsigned int i = 0; i < company.getStores().size(); i++) {
			ficheirotxt4 << company.getStores().at(i)->getCity() << " ; " << company.getStores().at(i)->getID() << " ";
			ficheirotxt4 << company.getStores().at(i)->getPhoneNumber() << " " << company.getStores().at(i)->getID_employee();
			if (i != company.getStores().size() - 1)
				ficheirotxt4 << endl;
		}
		ficheirotxt4.close();

		ofstream ficheirotxt5;
		ficheirotxt5.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Stores_Requests.txt");

		priority_queue<Store_Request *> requests = company.getStore_requests();

		for (unsigned int i = 0; i < company.getStore_requests().size(); i++) {
			ficheirotxt5 << requests.top()->getID() << " " << requests.top()->getPublicationID();
			ficheirotxt5 << " " << requests.top()->getRequestDate().getYear() << " " << requests.top()->getRequestDate().getMonth();
			ficheirotxt5 << " " << requests.top()->getRequestDate().getDay() << " " << requests.top()->getDeliveryDate().getYear();
			ficheirotxt5 << " " << requests.top()->getDeliveryDate().getMonth() << " " << requests.top()->getDeliveryDate().getDay();
			ficheirotxt5 << " " << requests.top()->getQuantity() << " " << requests.top()->getUnitaryPrice();
			ficheirotxt5 << " " << requests.top()->getStore()->getID();
			if (i != company.getStore_requests().size() - 1)
				ficheirotxt5 << endl;
			requests.pop();
		}
		ficheirotxt5.close();

		ofstream ficheirotxt6;
		ficheirotxt6.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Production_Requests.txt");


		BST<Production_Request> prod_reque = company.getProduction_requests();
		while (!prod_reque.isEmpty())
		{
			ficheirotxt6 << prod_reque.findMax().getID() << " " << prod_reque.findMax().getPublicationID()<< " ";
			ficheirotxt6 << prod_reque.findMax().getRequestDate().getYear() << " " << prod_reque.findMax().getRequestDate().getMonth();
			ficheirotxt6 << " " << prod_reque.findMax().getRequestDate().getDay() << " " << prod_reque.findMax().getDeadline().getYear();
			ficheirotxt6  << " " << prod_reque.findMax().getDeadline().getMonth() << " " << prod_reque.findMax().getDeadline().getDay() << " ";
			ficheirotxt6 << prod_reque.findMax().getQuantity();

			prod_reque.remove(prod_reque.findMax());
			if (!prod_reque.isEmpty())
				ficheirotxt6 << endl;

		}
		ficheirotxt6.close();

		ofstream ficheirotxt7;
		ficheirotxt7.open("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Suspended_Requests.txt");

		tabHSuspencion::const_iterator iter = company.get_suspended_requests().begin();

		while (iter != company.get_suspended_requests().end()) {
			ficheirotxt7 << iter->sr->getID() << " " << iter->sr->getPublicationID();
			ficheirotxt7 << " " << iter->sr->getRequestDate().getYear() << " " << iter->sr->getRequestDate().getMonth();
			ficheirotxt7 << " " << iter->sr->getRequestDate().getDay() << " " << iter->sr->getDeliveryDate().getYear();
			ficheirotxt7 << " " << iter->sr->getDeliveryDate().getMonth() << " " << iter->sr->getDeliveryDate().getDay();
			ficheirotxt7 << " " << iter->sr->getQuantity() << " " << iter->sr->getUnitaryPrice();
			ficheirotxt7 << " " << iter->sr->getStore()->getID();
			ficheirotxt7 << " " << iter->d.getDay() << " " << iter->d.getMonth() << " " << iter->d.getYear();
			iter++;
			if ( iter != company.get_suspended_requests().end())
				ficheirotxt7 << endl;
		}
		ficheirotxt7.close();

		cout << "\n--------------" << endl;
		cout << "---Guardado---" << endl;
		cout << "--------------\n" << endl;
	}
	else {
		cout << "\n-------------------" << endl;
		cout << "---Nao guardado!---" << endl;
		cout << "-------------------\n" << endl;
	}


	return 0;
}

void tiraEspaco_i_f(string &str, unsigned int tmh) {
	while ((str.at(0) == ' ') || (str.at(tmh - 1) == ' ')) {
		if (str.at(0) == ' ') {
			str.erase(str.begin() + 0);
			tmh--;
		}
		else if (str.at(tmh - 1) == ' ') {
			str.erase(str.begin() + tmh - 1);
			tmh--;
		}
	}
}

void Headquarters::start_files() {

	string line;

	///////////////////////
	// FILE PUBLICATIONS //
	/////////////////////// 
	// ID; DESCRIPTOIN; COLLECTION
	// Publication(int id, string desc, string col);

	ifstream file_publications_books("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Publications_books.txt");
	if (!file_publications_books.fail()){
		while (!file_publications_books.eof()) // To get you all the lines.
		{
			getline(file_publications_books, line);

			int contador = 0, aux = 0;
			string s_id, description, collection;

			for (unsigned int i = 0; i < line.size(); i++) {
				if ((line.at(i) == ';') && (contador == 0)) {
					s_id = line.substr(0, i);
					aux = i;
					contador++;
				}
				else if ((line.at(i) == ';') && (contador == 1)) {
					description = line.substr(aux + 1, i - aux - 1);
					aux = i;
					contador++;
					collection = line.substr(aux + 1, line.size() - aux - 1);
				}

			}

			tiraEspaco_i_f(description, description.size());
			tiraEspaco_i_f(collection, collection.size());

			stringstream val(s_id);
			int id;
			val >> id;

			Publication *pub = new Book(id, description, collection);
			publications.push_back(pub);
			hq_stock.push_back(0);
		}

		file_publications_books.close();
	}


	///////////////////////
	// FILE PUBLICATIONS //
	///////////////////////

	ifstream file_publications_journals("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Publications_journals.txt");
	if (!file_publications_journals.fail()){
		while (!file_publications_journals.eof()) // To get you all the lines.
		{
			getline(file_publications_journals, line);

			int contador = 0, aux = 0;
			string s_id, description, collection, s_vals;

			for (unsigned int i = 0; i < line.size(); i++) {
				if ((line.at(i) == ';') && (contador == 0)) {
					s_id = line.substr(0, i);
					aux = i;
					contador++;
				}
				else if ((line.at(i) == ';') && (contador == 1)) {
					description = line.substr(aux + 1, i - aux - 1);
					aux = i;
					contador++;
				}
				else if ((line.at(i) == ';') && (contador == 2)) {
					collection = line.substr(aux + 1, i - aux - 1);
					aux = i;
					s_vals = line.substr(aux + 1, line.size() - aux - 1);
				}

			}

			tiraEspaco_i_f(description, description.size());
			tiraEspaco_i_f(collection, collection.size());

			stringstream val(s_id);
			int id;
			val >> id;

			stringstream val2(s_vals);
			int volume, number, year;
			val2 >> volume;
			val2 >> number;
			val2 >> year;

			Publication *pub = new Journal(id, description, collection, volume, number, year);
			publications.push_back(pub);
			hq_stock.push_back(0);
		}

		file_publications_journals.close();
	}


	////////////////////
	// FILE EMPLOYEES //
	////////////////////
	// NAME; ID Y M D
	//Employee(int ID, string name, unsigned int y, unsigned int m, unsigned int d);

	ifstream file_employees("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Employees.txt");

	if (!file_employees.fail()){
		while (!file_employees.eof()) // To get you all the lines.
		{
			getline(file_employees, line);
			string s_name;
			int place_;
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ';') {
					s_name = line.substr(0, i);
					place_ = i;
				}
			}
			tiraEspaco_i_f(s_name, s_name.size());

			string valores = line.substr(place_ + 1, line.size() - place_); // contem o ID Y M D
			stringstream aux(valores);
			int id;
			unsigned int year, month, day, id_store;
			aux >> id;
			aux >> year;
			aux >> month;
			aux >> day;
			aux >> id_store;

			Employee *emp = new Employee(id, s_name, year, month, day);

			if (id_store != 0)
				emp->setID_store(id_store);

			employees.push_back(emp);
		}

		file_employees.close();
	}
	/////////////////
	// FILE STORES //
	/////////////////
	// CITY; ID PHONE_NUMBER
	// Store(int id, string city, unsigned long pn);

	ifstream file_stores("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Stores.txt");
	if(!file_stores.fail()){
		while (!file_stores.eof()) // To get you all the lines.
		{
			getline(file_stores, line);
			string s_city;
			int place_;
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ';') {
					s_city = line.substr(0, i);
					place_ = i;
				}
			}
			tiraEspaco_i_f(s_city, s_city.size());

			string valores = line.substr(place_ + 1, line.size() - place_); // contem o ID e PHONE_NUMBER
			stringstream aux(valores);
			int id, phone_number, id_employee;
			aux >> id;
			aux >> phone_number;
			aux >> id_employee;

			Store *loja = new Store(id, s_city, phone_number);
			loja->setID_employee(id_employee);
			stores.push_back(loja);
		}

		file_stores.close();
	}
	for (unsigned int k = 0; k < this->getStores().size(); k++) {
		if (this->getStores().at(k)->getID_employee() != 0) {
			for (unsigned int j = 0; j < this->getEmployees().size(); j++) {
				if (this->getStores().at(k)->getID_employee() == this->getEmployees().at(j)->getID()) {
					this->stores.at(k)->setWorker(this->getEmployees().at(j));
					this->employees.at(j)->setWorkplace(getStores().at(k));
				}
			}
		}
	}


	//////////////////////////
	// FILE STORES REQUESTS //
	//////////////////////////
	// ID  | (y,m,d)Date request_date |  (y,m,d)Date delivery_date | qnt | unitary_price | store_id
	// Store_Request(int ID, Date d1, Date d2, int q, float price, int s_id);

	ifstream file_stores_requests("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Stores_Requests.txt");

	if	(!file_stores_requests.fail()){
		while (!file_stores_requests.eof()) // To get you all the lines.
		{
			getline(file_stores_requests, line);
			stringstream valores(line);
			int id, store_id, quantidade, pub_id;
			float unitary_price;
			unsigned int y_r, m_r, d_r, y_d, m_d, d_d;
			valores >> id;
			valores >> pub_id;
			valores >> y_r;
			valores >> m_r;
			valores >> d_r;
			valores >> y_d;
			valores >> m_d;
			valores >> d_d;
			valores >> quantidade;
			valores >> unitary_price;
			valores >> store_id;

			for (unsigned int i = 0; i < stores.size(); i++)
			{
				if (stores.at(i)->getID() == store_id)
				{
					Store_Request *pedido_loja = new Store_Request(id, pub_id, Date(y_r, m_r, d_r), Date(y_d, m_d, d_d), quantidade, unitary_price, stores.at(i));
					store_requests.push(pedido_loja);
					break;
				}
			}

		}

		file_stores_requests.close();
	}

	//////////////////////////////
	// FILE PRODUCTION REQUESTS //
	//////////////////////////////
	// ID PUBLICATION_ID (y m d)DATE1 (y m d)DATE2 QUANTIDADE
	// Production_Request(int id, int p_id, Date d1, Date d2, int q);

	//DONE//

	ifstream file_production_requests("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Production_Requests.txt");
	if (!file_production_requests.fail()){
		while (!file_production_requests.eof()) // To get you all the lines.
		{
			getline(file_production_requests, line);
			stringstream valores(line);
			int id, publication_id, quantidade;
			unsigned int y_r, m_r, d_r, y_d, m_d, d_d;
			valores >> id;
			valores >> publication_id;
			valores >> y_r;
			valores >> m_r;
			valores >> d_r;
			valores >> y_d;
			valores >> m_d;
			valores >> d_d;
			valores >> quantidade;

			Production_Request pedido_prod = Production_Request(id, publication_id, Date(y_r, m_r, d_r), Date(y_d, m_d, d_d), quantidade);

			production_requests.insert(pedido_prod);

		}

		file_production_requests.close();
	}

	ifstream file_suspended_requests("D:\\FEUP\\MIEIC\\2º ano\\AEDA\\Projeto_Eclipse\\Projeto\\src\\Suspended_Requests.txt");
	if (!file_suspended_requests.fail()){
		while(!file_suspended_requests.eof())
		{
			getline(file_suspended_requests,line);
			if (line.size() == 0)
				break;
			stringstream valores(line);
			int id, store_id, quantidade, pub_id;
			float unitary_price;
			unsigned int y_r, m_r, d_r, y_d, m_d, d_d;
			valores >> id;
			valores >> pub_id;
			valores >> y_r;
			valores >> m_r;
			valores >> d_r;
			valores >> y_d;
			valores >> m_d;
			valores >> d_d;
			valores >> quantidade;
			valores >> unitary_price;
			valores >> store_id;
			int y_s,m_s,d_s;
			valores >> d_s;
			valores >> m_s;
			valores >> y_s;
			for (unsigned int i = 0; i < stores.size(); i++)
			{
				if (stores.at(i)->getID() == store_id)
				{
					Suspended_Request susp;
					susp.sr = new Store_Request(id, pub_id, Date(y_r, m_r, d_r), Date(y_d, m_d, d_d), quantidade, unitary_price, stores.at(i));
					susp.d = Date(y_s,m_s,d_s);
					suspended_requests.insert(susp);
					break;
				}
			}
		}

		file_suspended_requests.close();
	}
}
