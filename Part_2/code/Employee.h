#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"


/**
 * @brief declaration of the class Store to the program know that exists a class Store
 */
class Store;

/**
 * @brief Class Employee that creates an object (Employee)
 */
class Employee 
{
public:
	/**
	 * @brief Default constructor of the class Employee
	 *
	 * @param ID unique way to identify each employee
	 * @param name name of the employee
	 * @param y year of the birth
	 * @param m month of the birth
	 * @param d day of the birth
	 */
	Employee(int ID, std::string name, unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief Displays the information of the Employee (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief Gets the ID of the employee
	 *
	 * @return Respective ID
	 */
	int getID() const;

	/**
	 * @brief Gets the ID of the Store
	 *
	 * @return 0 if there's no store attributed to the employee
	 * @return otherwise is there's a store attributed to the employee
	 */
	int getID_store() const;

	/**
	 * @brief Sets the ID of the store
	 *
	 * @param val ID to set the param ID_store
	 *
	 * @return void
	 */
	void setID_store(int val);

	/**
	 * @brief Gets the name of the employee
	 *
	 * @return Respective string of the employee's name
	 */
	std::string getName() const;

	/**
	 * @brief Gets the Date of birth of the employee
	 *
	 * @return Date(class) of the employee's birth
	 */
	Date getDate() const;

	/**
	 * @brief Gets the Workplace(Class store)
	 *
	 * @return Respective Store associated to this employee, NULL if there's no Store attributed
	 */
	Store * getWorkplace() const;

	/**
	 * @brief Sets the Store(class) to the employee
	 *
	 * @param st store to be set to the employee
	 *
	 * Gives an exception if the the Store doesn't exists or if the Store has already an employee associated
	 *
	 * @return void
	 */
	void setWorkplace(Store * st);

	/**
	 * @brief Operator == for the employee
	 *
	 * @param e2 Employee e2 to the compared
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
