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
	 * @brief Default constructor
	 *
	 * @param id unique way to identify the different stores
	 * @param city place where the store is situated
	 * @param pn phone number of the store
	 */
	Store(int id, std::string city, unsigned long pn);

	/**
	 * @brief Displays the information of the Store (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief Gets the ID of the Store
	 *
	 * @return Respective ID
	 */
	int getID() const;

	/**
	 * @brief Gets the City of the Store
	 *
	 * @return Parameter(string) city
	 */
	std::string getCity() const;

	/**
	 * @brief Gets the Employee of the Store
	 *
	 * @return Employee of the respective Store, NULL if no attributed
	 */
	Employee getWorker() const;


	/**
	 * @brief Gets the phone number of the store
	 *
	 * @return Respective phone number (parameter phone_number)
	 */
	unsigned long getPhoneNumber() const;

	/**
	 * @brief Sets the worker of the Store
	 *
	 * @param worker Employee to be set to the Store
	 *
	 * @return void
	 */
	void setWorker(Employee * worker);

	/**
	 * @brief Gets the Employee ID
	 *
	 * if Employee ID is 0, then there is no Employee attributed
	 *
	 * @return Respective Employee ID
	 */
	int getID_employee() const;


	/**
	 * @brief Gets the vector of publications (books and journals)
	 *
	 * @return Respective vector
	 */
	std::vector<Publication * > get_publications_store();

	/**
	 * @brief Gets the vector of stock of publications (books and journals)
	 *
	 * @return Respective vector
	 */
	std::vector<int> get_stock();

	/**
	 * @brief Sets the Employee ID
	 *
	 * @param val ID to be set to the Employee
	 *
	 * @return void
	 */
	void setID_employee(int val);

	/**
	 * @brief Add a Publication (Book or Journal) to the Store
	 *
	 * @param publication book or journal to be added
	 * @param stock_min minimum stock of the publication, 0 if Book and 1 if Journal
	 *
	 * @return void
	 */
	void addPublication(Publication * publication, int stock_min);

	/**
	 * @brief Add stock to the Publication (Book or Journal)
	 *
	 * @param publication_id ID of the publication (book or journal) of the Store to be added the respective amount
	 * @param amount value of the books or journals to be added on the stock of the respective publication
	 *
	 * @return void
	 */
	void addStock(int publication_id, int amount);

	/**
	 * @brief Removes a Publication of the Store
	 *
	 * @param id Publication ID that is to be removed
	 *
	 * @return void
	 */
	void removePublication(int id);

	/**
	 * @brief operator == for the Store
	 *
	 * @param s2 Store s2 to the compared
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
