#ifndef PRODUCTION_REQUEST_H
#define PRODUCTION_REQUEST_H

#include "Date.h"

/**
 * @brief Class Production_Request to be done by Headquarters
 */
class Production_Request
{
public:
	/**
	 * @brief default constructor of the object
	 *
	 * @param id is the unique way to identify the production request
	 * @param p_id is the id of the publication (book or journal)
	 * @param d1 is the request date of the order
	 * @param d2 is the deadline of the request
	 * @param q is the quantity of the request, publication (book or journal)
	 */
	Production_Request(int id, int p_id, Date d1, Date d2, int q);

	/**
	 * @brief displays the information of the production request (his parameters)
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the ID of the production request
	 *
	 * @return the respective ID
	 */
	int getID() const;

	/**
	 * @brief the publication ID of the publication request
	 *
	 * @return the respective publication ID
	 */
	int getPublicationID() const;

	/**
	 * @brief gets the request date of the publication order
	 *
	 * @return the request date
	 */
	Date getRequestDate() const;

	/**
	 * @brief gets the deadline of the publication request
	 *
	 * @return the delivery date
	 */
	Date getDeadline() const;

	/**
	 * @brief gets the quantity of the publication order
	 *
	 * @return the respective quantity
	 */
	int getQuantity() const;

	/**
	 * @brief operator == for the Production_Request
	 *
	 * @param the Production_Request pr2 to the compared
	 *
	 * @return true if the Production_Requests are equal and false otherwise
	 */
	bool operator == (Production_Request & pr2) const;

private:
	int ID; 				///< ID of the request
	int publication_id;		///< publication ID  (Book id or journal id)
	Date request_date;		///< request date of the order
	Date deadline;			///< delivery date of the request
	int qnt;				///< quantity of the request
};

#endif
