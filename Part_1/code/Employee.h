#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"


/**
 * @brief declaration of the class Store to the program know that exists a class Store
 */
class Store;

/**
 * @brief Class Store that creates an object (Store)
 */
class Employee 
{
public:
	/**
	 * @brief default constructor of the class Employee
	 *
	 * @param ID is the unique way to identify each employee
	 * @param name - is the name of the employee
	 * @param y is the year of the birth
	 * @param m is the month of the birth
	 * @param d is the day of the birth
	 */
	Employee(int ID, std::string name, unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief displays the information of the Employee (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the ID of the employee
	 *
	 * @return the respective ID
	 */
	int getID() const;

	/**
	 * @brief gets the ID of the Store
	 *
	 * @return 0 if there's no store attributed to the employee
	 * @return otherwise is there's a store attributed to the employee
	 */
	int getID_store() const;

	/**
	 * @brief sets the ID of the store
	 *
	 * @param val is the ID to set the param ID_store
	 *
	 * @return void
	 */
	void setID_store(int val);

	/**
	 * @brief gets the name of the employee
	 *
	 * @return the respective string of the employee's name
	 */
	std::string getName() const;

	/**
	 * @brief gets the Date of birth of the employee
	 *
	 * @return the Date (class)
	 */
	Date getDate() const;

	/**
	 * @brief gets the Workplace(Class store)
	 *
	 * @return the Store associated to this employee, NULL if there's no Store attributed
	 */
	Store * getWorkplace() const;

	/**
	 * @brief sets the Store(class) to the employee
	 *
	 * @param st is the store to be set to the employee
	 *
	 * @return void
	 */
	void setWorkplace(Store * st);

	/**
	 * @brief operator == for the employee
	 *
	 * @param the Employee e2 to the compared
	 *
	 * @return true if the Employees are equal and false otherwise
	 */
	bool operator == (Employee & e2) const;

private:
	int ID;				///< ID of the employee
	int ID_store;		///< ID_store of the employee (0 if not set)
	std::string name;	///< Name of the employee
	Date date_birth;	///< Date date of birth
	Store * workplace;	///< Store attributed to the employee (NULL if not attributed)
};

#endif
