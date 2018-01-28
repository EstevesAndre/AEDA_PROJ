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
	 * @brief Journal default constructor
	 *
	 * @param id is the unique way to identify all the journals
	 * @param desc is the description of the journal
	 * @param col is the collecting of the journal
	 * @param vol is the volume
	 * @param n is the number
	 * @param y is the year when the journal was published
	 */
	Journal(int id, std::string desc, std::string col, int vol, int n, int y);

	/**
	 * @brief displays the information of the journal (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the volume of the journal
	 *
	 * @return the respective volume
	 */
	int getVolume() const; 

	/**
	 * @brief gets the number of the journal
	 *
	 * @return the respective number
	 */
	int getNumber() const;

	/**
	 * @brief gets the year of the journal
	 *
	 * @return the respective year
	 */
	int getYear() const;

	/**
	 * @brief gets the output to right in the file
	 *
	 * @param type is the int type of the publication(book or journal)
	 *
	 * @return the string to write to the file
	 */
	std::string getOutPut(int type);

	/**
	 * @brief getType of the journal
	 *
	 * @return the int type of the publication (book or journal)
	 */
	int getType() const;

private:
	int volume;	///< volume of the journal
	int number;	///< number of the journal
	int year;	///< year of the journal
};

#endif
