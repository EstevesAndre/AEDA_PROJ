#ifndef DATE_H
#define DATE_H


/**
 * @brief Class Date - Year / month / day
 */
class Date
{
public:
	/**
	 * @brief Default constructor
	 *
	 * @param y year of the Date
	 * @param m month of the Date
	 * @param d day of the Date
	 */
	Date(unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief Changes the year of the Date
	 *
	 * @param y new year to be changed on the respective Date
	 *
	 * Verifies if the year is valid and throws an exception if it is invalid
	 *
	 * @return void
	 */
	void setYear(unsigned int y);

	/**
	 * @brief Changes the month of the Date
	 *
	 * @param m new month to be changed on the respective Date
	 *
	 * Verifies if the month is valid and throws an exception if it is invalid
	 *
	 * @return void
	 */
	void setMonth(unsigned int m);

	/**
	 * @brief Changes the day of Date
	 *
	 * @param d new day to be changed on the respective Date
	 *
	 * Verifies if the day is valid and throws an exception if it is invalid
	 *
	 * @return void
	 */
	void setDay(unsigned int d);

	/**
	 * @brief Changes the Date
	 *
	 * @param y new year to be changed on the respective Date
	 * @param m new month to be changed on the respective Date
	 * @param d new day to be changed on the respective Date
	 *
	 *	Verifies if the Date introduced is valid and throws an exception if it is invalid
	 *
	 * @return void
	 */
	void setDate(unsigned int y, unsigned int m, unsigned int d);

	/**
	 * @brief Gets the year of the Date
	 *
	 * @return year of the Date
	 */
	unsigned int getYear() const;

	/**
	 * @brief Gets the month of the Date
	 *
	 * @return month of the Date
	 */
	unsigned int getMonth() const;

	/**
	 * @brief Gets the day of the Date
	 *
	 * @return day of the Date
	 */
	unsigned int getDay() const;

	/**
	 * @brief Shows the date on the screen in format "yyyy/mm/dd"
	 *
	 * @return void
	 */
	void show() const ;

	/**
	 * @brief operator < for the Date
	 *
	 * @param d2 Date d2 to the compared
	 *
	 * @return true if "Date < d2" and false otherwise
	 */
	bool operator < (const Date & d2) const;

	/**
	 * @brief operator == for the Date
	 *
	 * @param d2 Date d2 to the compared
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
