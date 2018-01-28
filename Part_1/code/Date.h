#ifndef DATE_H
#define DATE_H


/**
 * @brief Class Date - Year / month / day
 */
class Date
{
public:
	/**
	 * @brief default constructor
	 *
	 * @param y is the year of the Date
	 * @param m is the month of the Date
	 * @param d is the day of the Date
	 */
	Date(unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief sets the Year of the Date
	 *
	 * @param y is the "new" year to be changed on the respective Date
	 *
	 * @return void
	 */
	void setYear(unsigned int y);

	/**
	 * @brief sets the Month of the Date
	 *
	 * @param m is the "new" month to be changed on the respective Date
	 *
	 * @return void
	 */
	void setMonth(unsigned int m);

	/**
	 * @brief sets the Day of the Date
	 *
	 * @param d is the "new" day to be changed on the respective Date
	 *
	 * @return void
	 */
	void setDay(unsigned int d);

	/**
	 * @brief sets the Date
	 *
	 * @param y is the "new" year to be changed on the respective Date
	 * @param m is the "new" month to be changed on the respective Date
	 * @param d is the "new" day to be changed on the respective Date
	 *
	 * @return void
	 */
	void setDate(unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief gets the Year of the Date
	 *
	 * @return the respective Year
	 */
	unsigned int getYear() const;

	/**
	 * @brief gets the Month of the Date
	 *
	 * @return the respective Month
	 */
	unsigned int getMonth() const;

	/**
	 * @brief gets the Day of the Date
	 *
	 * @return the respective Day
	 */
	unsigned int getDay() const;

	/**
	 * @brief shows the date on the screen in format "yyyy/mm/dd"
	 *
	 * @return void
	 */
	void show();

	/**
	 * @brief operator < for the Date
	 *
	 * @param the Date d2 to the compared
	 *
	 * @return true if the "Date < d2" and false otherwise
	 */
	bool operator < (const Date & d2) const;

	/**
	 * @brief operator == for the Date
	 *
	 * @param the Date d2 to the compared
	 *
	 * @return true if the Dates are equal and false otherwise
	 */
	bool operator == (const Date & d2) const;

private:
	unsigned int year; 														///< Year of the Date
	unsigned int month;														///< Month of the Date
	unsigned int day;														///< Day of the Date
	bool monthDayCheck(unsigned int y, unsigned int m, unsigned int d);		///< returns true if Date is valid and false otherwise
	bool anobissexto(unsigned int y);										///< returns true is Date is leap year and false otherwise
};


/**
 * @brief Class InvalidDate - is a Template<Class T> exception
 */
// InvalidDate exception
template <class T>
class InvalidDate {
public:
	T y, m, d;
	InvalidDate(T y, T m, T d) {
		this->y = y;
		this->m = m;
		this->d = d;
	}
};

#endif
