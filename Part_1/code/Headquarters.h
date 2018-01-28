#ifndef HEADQUARTERS_H
#define HEADQUARTERS_H

#include <vector>
#include "Publication.h"
#include "Employee.h"
#include "Store.h"
#include "Store_Request.h"
#include "Production_Request.h"


#ifdef _WIN32
#define Limpar_ecra() system("cls");

#else
#define Limpar_ecra() system("clear");
#endif

/**
 * @brief Class Headquarters the main class that contains everything (support where the company works)
 */
class Headquarters
{
public:
	/**
	 * @brief default construction
	 */
	Headquarters();

	/**
	 * @brief reads the information from the files and put this on the respective vectors (publications, employees, stores, store_requests, production_requests, hq_stock)
	 *
	 * @return void;
	 */
	void start_files();

	/**
	 * @brief displays the publications of the Headquarters
	 *
	 * @return void
	 */
	void showPublications() const;
	/**
	 * @brief displays the employees of the Headquarters
	 *
	 * @return void
	 */
	void showEmployees() const;

	/**
	 * @brief displays the stores of the Headquarters
	 *
	 * @return void
	 */
	void showStores() const;

	/**
	 * @brief displays the store_requests of the Headquarters
	 *
	 * @return void
	 */
	void showStoreRequests() const;

	/**
	 * @brief displays the production_requests of the Headquarters
	 *
	 * @return void
	 */
	void showProductionRequests() const;

	/**
	 * @brief add Publication
	 *
	 * the user is the one who needs to give all the parameters for create a new Publication
	 *
	 * @return void
	 */
	void addPublication();

	/**
	 * @brief add Employee
	 *
	 * the user is the one who needs to give all the parameters for create a new Employee
	 *
	 * @return void
	 */
	void addEmployee();

	/**
	 * @brief add Store
	 *
	 * the user is the one who needs to give all the parameters for create a new Store
	 *
	 * @return void
	 */
	void addStore();

	/**
	 * @brief sets the publication to the store
	 *
	 * @return void
	 */
	void set_publication_to_store();

	/**
	 * @brief sets the publication to the store
	 *
	 * @param store_id is the store where will be added the publication( book or journal)
	 * @param store_request_id is the identification of the request to know which publication will be added to the vector publications of the store
	 *
	 * @return true if can add publication to store and false otherwise
	 */
	bool verifica_set_publications (int store_id, int store_request_id);

	/**
	 * @brief add StoreRequest
	 *
	 * the user is the one who needs to give all the parameters for create a new StoreRequest
	 *
	 * @return void
	 */
	void addStoreRequest();

	/**
	 * @brief add ProductionRequest
	 *
	 * the user is the one who needs to give all the parameters for create a new ProductionRequest
	 *
	 * @return void
	 */
	void addProductionRequest();

	/**
	 * @brief deletes publication
	 *
	 * the user is the one who needs to give the publication id that is gonna be deleted
	 *
	 * @return void
	 */
	void deletePublication();

	/**
	 * @brief deletes Publication
	 *
	 * the user is the one who needs to give the Publication ID that is gonna be deleted
	 *
	 * @return void
	 */
	void deleteEmployee();

	/**
	 * @brief deletes Store
	 *
	 * the user is the one who needs to give the Store ID that is gonna be deleted
	 *
	 * @return void
	 */
	void deleteStore();

	/**
	 * @brief deletes StoreRequest
	 *
	 * the user is the one who needs to give the StoreRequest ID that is gonna be deleted
	 *
	 * @return void
	 */
	void deleteStoreRequest();

	/**
	 * @brief deletes ProductionRequest
	 *
	 * the user is the one who needs to give the ProductionRequest ID that is gonna be deleted
	 *
	 * @return void
	 */
	void deleteProductionRequest();

	/**
	 * @brief attributes a Store to a Employee
	 *
	 * the user is the one who need to give the Store ID and the Employee ID to attribute the Store
	 *
	 * @return void
	 */
	void attributeStore();

	/**
	 * @brief
	 *
	 * @param priority
	 *
	 * @return void
	 */
	void satisfyStoreRequests(bool priority);

	/**
	 * @brief
	 *
	 * @param priority
	 *
	 * @return void
	 */
	void produce(bool priority);

	/**
	 * @brief count types of the publications in a vector
	 *
	 * @param ind is the indice of the publication type (book or journal)
	 *
	 * return the count
	 */
	int count_types(int ind) const;

	/**
	 * @brief gets the Publications (book and journals)
	 *
	 * @return the vector of Publication*
	 */
	std::vector<Publication *> getPublications() const;

	/**
	 * @brief gets the Employees
	 *
	 * @return the vector of Employee*
	 */
	std::vector<Employee *> getEmployees() const;

	/**
	 * @brief gets the Stores
	 *
	 * @return the vector of Store*
	 */
	std::vector<Store *> getStores() const;

	/**
	 * @brief gets the Store_requests
	 *
	 * @return the vector of Store_Request
	 */
	std::vector<Store_Request *> getStore_requests() const;

	/**
	 * @brief gets the Production_requests
	 *
	 * @return the vector of Production_Request
	 */
	std::vector<Production_Request *> getProduction_requests() const;

private:
	std::vector<Publication *> publications;					///< vector publications of Publication(book and journal)
	std::vector<Employee *> employees;							///< vector employees of Employee
	std::vector<Store *> stores;								///< vector stores of Store
	std::vector<Store_Request *> store_requests;				///< vector store_requests of Store_Request
	std::vector<Production_Request *> production_requests;		///< vector production_requests of Production_Request
	std::vector<int> hq_stock;									///< vector hq_stock of the amount of each publication
};


// ExistingID exception

/**
 * @brief Class ExistingID - is a Template<Class T> exception
 */
template <class T>
class ExistingID {
public:
	T ID;
	ExistingID(T id) {
		ID = id;
	}
};


// IDNotFound exception

/**
 * @brief Class IDNotFound - is a Template<Class T> exception
 */
template <class T>
class IDNotFound {
public:
	T ID;
	IDNotFound(T id) {
		ID = id;
	}
};

#endif
