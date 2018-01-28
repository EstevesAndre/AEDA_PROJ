#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "Date.h"

/**
 * @brief Class Store_Request to save the requests of the stores to be completed by Headquarters
 */
class Store_Request
{
public:
	/**
	 * @brief default constructor of the Store_Request
	 *
	 * @param ID is the unique way to identify the different store requests
	 * @param pub_id is the identification for the publication (book or journal)
	 * @param d1 is the request Date of the order
	 * @param d2 is the limit delivery date of the request
	 * @param q is the quantity of the order
	 * @param price is the value of each publication(book or journal)
	 * @param s_id is the store id that did the request
	 */
	Store_Request(int ID, int pub_id, Date d1, Date d2, int q, float price, int s_id);

	/**
	 * @brief displays the information of the store request
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief gets the ID (identification) of the store request
	 *
	 * @return the respective ID
	 */
	int getID() const;

	/**
	 * @brief gets the publication id
	 *
	 * @return the respective id
	 */
	int getPublicationID() const;

	/**
	 * @brief gets the request date of the store request
	 *
	 * @return the request date
	 */
	Date getRequestDate() const;

	/**
	 * @brief gets the delivery date of the store request
	 *
	 * @return the delivery date
	 */
	Date getDeliveryDate() const;

	/**
	 * @brief gets the quantity of the request
	 *
	 * @return the qnt param (quantity of the request)
	 */
	int getQuantity() const;

	/**
	 * @brief gets the unit price of the publication (book or journal)
	 *
	 * @return the unit price
	 */
	float getUnitaryPrice() const;

	/**
	 * @brief gets the store ID that did the request
	 *
	 * @return the respective store ID
	 */
	int getStoreID() const;

	/**
	 * @brief operator == for the Store_Request
	 *
	 * @param the Store_Request sr2 to the compared
	 *
	 * @return true if the Store_Requests are equal and false otherwise
	 */
	bool operator == (Store_Request & sr2) const;

private:
	int ID;					///< ID of the request
	int publication_id;		///< the publication id (book id or journal id)
	Date request_date;		///< request date of the request
	Date delivery_date;		///< deadline of the request
	int qnt;				///< quantity of the publication (book or journal)
	float unitary_price;	///< unit price for each publication (book or journal)
	int store_id;			///< store id that did the order
};

#endif
