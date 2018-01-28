#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>

/**
 * @brief Class Publication, abstract, Class parent of Book and Journal
 */
class Publication
{
public:
	/**
	 * @brief default constructor of the publication
	 *
	 * @param id is the unique way to identify the publication
	 * @param desc is the description of the publication
	 * @param col is the collecting of the publication
	 */
	Publication(int id, std::string desc, std::string col);

	/**
	 * @brief displays the information of the publication
	 *
	 * @Virtual because publications is an abstract class and the show() function is initialized in book and journal classes
	 *
	 * @return void
	 */
	virtual void show();

	/**
	 * @brief gets the ID of the publication
	 *
	 * @return the respective ID
	 */
	int getID() const;

	/**
	 * @brief gets the description of the publication
	 *
	 * @return the description in a string
	 */
	std::string getDescripiton() const;

	/**
	 * @brief gets the collection of the publication
	 *
	 * @return the collection in a string
	 */
	std::string getColection() const;

	/**
	 * @brief operator == for the publication
	 *
	 * @param the Publication p2 to the compared
	 *
	 * @return true if the Publications are equal and false otherwise
	 */
	bool operator == (const Publication & p2) const;

	/**
	 * @brief get the type of the publication (Book or Publication type)
	 *
	 * @return the type (int)
	 */
	virtual int getType() const { return 0; }

	/**
	 * @brief gets the output to right in the file
	 *
	 * @param type is the int type of the publication(book or journal)
	 *
	 * @return the string to write to the file
	 */
	virtual std::string getOutPut(int type);

protected:
	int ID; 					///< ID of the publication (book or journal)
	std::string description;	///< description of the publication
	std::string colection;		///< collection of the publication
};

#endif
