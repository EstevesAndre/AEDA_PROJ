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
	 * @brief Book default constructor
	 *
	 * @param id is the unique way to identify all the books
	 * @param desc is the description of the book
	 * @param col is the collecting of the book
	 */
	Book(int id, std::string desc, std::string col);

	/**
	 * @brief displays the information of the book (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the output to right in the file
	 *
	 * @param type is the int type of the publication(book or journal)
	 *
	 * @return the string to write to the file
	 */
	std::string getOutPut(int type) ;

	/**
	 * @brief getType of the book
	 *
	 * @return the int type of the publication (book or journal)
	 */
	int getType() const;
};

#endif
