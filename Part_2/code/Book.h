#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Publication.h"

/**
 * @brief Class Book - creates the object Book - type of Publication
 */
class Book : public Publication
{
public:
	/**
	 * @brief Book Default constructor
	 *
	 * @param id unique way to identify all the books
	 * @param desc description of the book
	 * @param col collecting of the book
	 */
	Book(int id, std::string desc, std::string col);

	/**
	 * @brief Displays the information of the book (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief Gets the output to be written to the file
	 *
	 * @param type of the publication as an int value, 0 if book and 1 if journal
	 *
	 * @return the string to write to the file
	 */
	std::string getOutPut(int type) ;

	/**
	 * @brief Gets the type of the book
	 *
	 * @return int value which is the type of the publication, 0 if book and 1 if journal
	 */
	int getType() const;
};

#endif
