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
	 * @brief Default constructor of the publication
	 *
	 * @param id unique way to identify the publication
	 * @param desc description of the publication
	 * @param col collecting of the publication
	 */
	Publication(int id, std::string desc, std::string col);

	/**
	 * @brief Displays the information of the Publication
	 *
	 * @Virtual because publications is an abstract class and the show() function is initialized in book and journal classes
	 *
	 * @return void
	 */
	virtual void show();

	/**
	 * @brief Gets the ID of Publication
	 *
	 * @return Respective ID
	 */
	int getID() const;

	/**
	 * @brief Gets the description of the Publication
	 *
	 * @return Description of the Publication in a string
	 */
	std::string getDescripiton() const;

	/**
	 * @brief Gets the collection of the Publication
	 *
	 * @return Collection of the Publication in a string
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
	 * @brief Get the type of the publication 0 if Book or 1 if Journal
	 *
	 * @return type (integer)
	 */
	virtual int getType() const { return 0; }

	/**
	 * @brief Gets the output to right in the file
	 *
	 * @param type is the integer type of the publication, 0 if Book and 1 if Journal
	 *
	 * @return string to write to the file
	 */
	virtual std::string getOutPut(int type);

protected:
	int ID; 					///< ID of the publication (book or journal)
	std::string description;	///< description of the publication
	std::string colection;		///< collection of the publication
};

#endif
