#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include "Publication.h"


/**
 * @brief Class Journal - creates the object Journal - type of Publication
 */
class Journal : public Publication
{
public:
	/**
	 * @brief Journal Default constructor
	 *
	 * @param id unique way to identify all the journals
	 * @param desc description of the journal
	 * @param col collecting of the journal
	 * @param vol volume
	 * @param n number
	 * @param y year when the journal was published
	 */
	Journal(int id, std::string desc, std::string col, int vol, int n, int y);

	/**
	 * @brief Displays the information of the journal (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief Gets the volume of the journal
	 *
	 * @return Respective volume
	 */
	int getVolume() const; 

	/**
	 * @brief Gets the number of the journal
	 *
	 * @return Respective number
	 */
	int getNumber() const;

	/**
	 * @brief Gets the year of the journal
	 *
	 * @return Respective year
	 */
	int getYear() const;

	/**
	 * @brief Gets the output to right in the file
	 *
	 * @param type integer type of the publication, 0 if Book and 1 if Journal
	 *
	 * @return the string to be written into the file
	 */
	std::string getOutPut(int type);

	/**
	 * @brief Gets the type of the Journal
	 *
	 * @return type of the Publication (Book or Journal)
	 */
	int getType() const;

private:
	int volume;	///< volume of the journal
	int number;	///< number of the journal
	int year;	///< year of the journal
};

#endif
