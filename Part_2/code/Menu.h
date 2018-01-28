#pragma once
/*
#ifdef _WIN32
#define Limpar_ecra() system("cls");

#else
#define Limpar_ecra() system("clear");
#endif
*/
#include <iostream>
#include "Headquarters.h"

/**
 * @brief mainMenu of the project
 *
 * @param hq object of the company class
 *
 * @return true if is the user press 6 (Close) and false otherwise
 */
bool mainMenu(Headquarters &hq);

/**
 * @brief menu1 - Publications menu
 *
 * @param hq object of the company class
 *
 * @return void
 */
void menu1(Headquarters &hq);

/**
 * @brief menu1 - Employees menu
 *
 * @param hq object of the company class
 *
 * @return void
 */
void menu2(Headquarters &hq);

/**
 * @brief menu1 - Stores menu
 *
 * @param hq object of the company class
 *
 * @return void
 */
void menu3(Headquarters &hq);

/**
 * @brief menu1 - Stores Requests menu
 *
 * @param hq object of the company class
 *
 * @return void
 */
void menu4(Headquarters &hq);


/**
 * @brief menu1 - Production Requests menu
 *
 * @param hq object of the company class
 *
 * @return void
 */
void menu5(Headquarters &hq);
