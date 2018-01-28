#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "Employee.h"
#include "Publication.h"

/**
 * @brief Class Store - creates an object Store
 */
class Store
{
public:
	/**
	 * @brief default constructor
	 *
	 * @param id is the unique way to identify the different stores
	 * @param city is the place where the store is situated
	 * @param pn is the phone number of the store
	 */
	Store(int id, std::string city, unsigned long pn);

	/**
	 * @brief displays the information of the Store (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the ID of the Store
	 *
	 * @return the respective ID
	 */
	int getID() const;

	/**
	 * @brief gets the City of the Store
	 *
	 * @return the parameter(string) city
	 */
	std::string getCity() const;

	/**
	 * @brief gets the Employee of the Store
	 *
	 * @return the Employee of the respective Store, NULL if no attributed
	 */
	Employee getWorker() const;

	/**
	 * @brief gets the phone number of the store
	 *
	 * @return the respective phone number (parameter phone_number)
	 */
	unsigned long getPhoneNumber() const;

	/**
	 * @brief sets the worker of the Store
	 *
	 * @param worker is the Employee to be set to the Store
	 *
	 * @return void
	 */
	void setWorker(Employee * worker);

	/**
	 * @brief gets the Employee ID
	 *
	 * if Employee ID is 0, then there is no Employee attributed
	 *
	 * @return the respective Employee ID
	 */
	int getID_employee() const;

	/**
	 * @brief gets the vector of publications (books and journals)
	 *
	 * @return the respective vector
	 */
	std::vector<Publication * > get_publications_store();

	/**
	 * @brief sets the Employee ID
	 *
	 * @param val is the ID to be set to the Employee
	 *
	 * @return void
	 */
	void setID_employee(int val);

	/**
	 * @brief add a publication(book or journal) to the Store
	 *
	 * @param publication is the book or journal to be added
	 * @param stock_min is the minimum stock of the publication (journal or book), 0 if not journal
	 *
	 * @return void
	 */
	void addPublication(Publication * publication, int stock_min);

	/**
	 * @brief add stock to the publication (book or journal)
	 *
	 * @param publication_id is the ID of the publication (book or journal) of the Store to be added the respective amount
	 * @param amount is the value of the books or journals to be added on the stock of the respective publication
	 *
	 * @return void
	 */
	void addStock(int publication_id, int amount);

	/**
	 * @brief removes a publication of the Store
	 *
	 * @param id is the publication ID that is to be removed
	 *
	 * @return void
	 */
	void removePublication(int id);

	/**
	 * @brief operator == for the Store
	 *
	 * @param the Store s2 to the compared
	 *
	 * @return true if the Stores are equal and false otherwise
	 */
	bool operator == (Store & s2) const;

private:
	int ID;										///< ID of the Store
	std::string city;							///< City of the Store
	int ID_employee;							///< ID of the Employee attributed to the Store (0 if not attributed)
	Employee * worker;							///< Employee of the Store ( NULL if not attributed)
	unsigned long phone_number;					///< phone number of the Store
	std::vector<Publication *> publications;	///< vector of Publication (class) are the books and journals of the Store
	std::vector<int> stock;						///< Stock of each Publication of the Store
	std::vector<int> minimun_stock;				///< minimum Stock of each Publication of the Store
};

#endif
