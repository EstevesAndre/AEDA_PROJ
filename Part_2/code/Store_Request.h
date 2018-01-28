#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "Date.h"
#include "Store.h"

/**
 * @brief Class Store_Request to save the requests of the stores to be completed by Headquarters
 */
class Store_Request
{
public:
	/**
	 * @brief Default constructor of the Store_Request
	 *
	 * @param ID unique way to identify the different store requests
	 * @param pub_id identification for the publication (book or journal)
	 * @param d1 request Date of the order
	 * @param d2 limit delivery date of the request
	 * @param q quantity of the order
	 * @param price value of each publication(book or journal)
	 * @param s_id store id that did the request
	 */
	Store_Request(int ID, int pub_id, Date d1, Date d2, int q, float price, Store * s);

	/**
	 * @brief Displays the information of the Store_Request
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief Gets the ID (identification) of the store request
	 *
	 * @return Respective ID
	 */
	int getID() const;

	/**
	 * @brief Gets the publication id
	 *
	 * @return Respective id
	 */
	int getPublicationID() const;

	/**
	 * @brief Gets the request date of the store request
	 *
	 * @return Request date
	 */
	Date getRequestDate() const;

	/**
	 * @brief Gets the delivery date of the store request
	 *
	 * @return Delivery date
	 */
	Date getDeliveryDate() const;

	/**
	 * @brief Gets the quantity of the request
	 *
	 * @return qnt param (quantity of the request)
	 */
	int getQuantity() const;

	/**
	 * @brief Gets the unit price of the publication (book or journal)
	 *
	 * @return unit price of the request
	 */
	float getUnitaryPrice() const;

	/**
	 * @brief Gets the Store that did the request
	 *
	 * @return Respective store
	 */
	Store * getStore() const;

	/**
	 * @brief operator == for the Store_Request
	 *
	 * @param sr2 Store_Request sr2 to be compared
	 *
	 * @return true if the Store_Requests are equal and false otherwise
	 */
	bool operator == (Store_Request & sr2) const;

	/**
	 * @brief operator < for the Store_Request
	 *
	 * @param sr2 Store_Request sr2 to be compared
	 *
	 * @return true if the Store_Request publication stock is less than Store_Request sr2 publication stock
	 */
	bool operator < (Store_Request & sr2) const;

private:
	int ID;					///< ID of the request
	int publication_id;		///< the publication id (book id or journal id)
	Date request_date;		///< request date of the request
	Date delivery_date;		///< deadline of the request
	int qnt;				///< quantity of the publication (book or journal)
	float unitary_price;	///< unit price for each publication (book or journal)
	Store * store;			///< store that did the order
};

#endif
