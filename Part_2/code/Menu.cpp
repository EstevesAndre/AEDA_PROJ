#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Headquarters.h"

using namespace std;

// menu 1 visualization
// PUBLICATIONS
void menu1(Headquarters &hq) 
{
	int option;
	bool repeat = true;

	cout << "------------------------------" << endl;
	cout << "--------|PUBLICATIONS|--------" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Show Publications" << endl;
	cout << "2 - Add Publication" << endl;
	cout << "3 - Remove Publication" << endl;
	cout << "4 - Back to Main Menu" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				hq.showPublications();
				system("pause");
				repeat = false;
				break;
			}
			case 2:
			{
				try
				{
					hq.addPublication();
					cout << "  <<< Created >>>\n";
					system("pause");
				}
				catch (ExistingID<int> &e)
				{
					cout << "Existing ID: A Publication with ID: " << e.ID << " already exists." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 3:
			{
				try
				{
					hq.deletePublication();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Publication found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 4:
			{
				repeat = false;
				break;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;

			}
			}
		}
	}
}

// menu 2 visualization
// EMPLOYEES
void menu2(Headquarters &hq)
{
	int option;
	bool repeat = true;

	cout << "------------------------------" << endl;
	cout << "----------|EMPLOYEES|---------" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Show Employees" << endl;
	cout << "2 - Add Employee" << endl;
	cout << "3 - Remove Employee" << endl;
	cout << "4 - Attribute Store to Employee" << endl;
	cout << "5 - Back to Main Menu" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				hq.showEmployees();
				system("pause");
				repeat = false;
				break;
			}
			case 2:
			{
				try
				{
					hq.addEmployee();
					cout << "  <<< Created >>>\n";
					system("pause");
				}
				catch (ExistingID<int> &e)
				{
					cout << "Existing ID: An Employee with ID: " << e.ID << " already exists." << endl;
					system("pause");
				}
				catch (InvalidDate<unsigned int> &e)
				{
					cout << "Invalid Date: Invalid birth date: " << e.y << "/" << e.m << "/" << e.d << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 3:
			{
				try
				{
					hq.deleteEmployee();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Employee found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 4:
			{
				try
				{
					hq.attributeStore();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No object found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 5:
			{
				repeat = false;
				break;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;

			}
			}
		}
	}
}

// menu 3 visualization
// STORES
void menu3(Headquarters &hq)
{
	int option;
	bool repeat = true;

	cout << "------------------------------" << endl;
	cout << "-----------|STORES|-----------" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Show Stores" << endl;
	cout << "2 - Add Store" << endl;
	cout << "3 - Remove Store" << endl;
	cout << "4 - Set publications to the Store" << endl;
	cout << "5 - Attribute Store to Employee" << endl;
	cout << "6 - Back to Main Menu" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				hq.showStores();
				system("pause");
				repeat = false;
				break;
			}
			case 2:
			{
				try
				{
					hq.addStore();
					cout << "  <<< Created >>>\n";
					system("pause");
				}
				catch (ExistingID<int> &e)
				{
					cout << "Existing ID: A Store with ID: " << e.ID << " already exists." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 3:
			{
				try
				{
					hq.deleteStore();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Store found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 4:
			{
				try
				{
					hq.set_publication_to_store();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No object found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 5:
			{
				try
				{
					hq.attributeStore();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No object found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 6:
			{
				repeat = false;
				break;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;

			}
			}
		}
	}
}

// menu 4 visualization
// STORES REQUESTES
void menu4(Headquarters &hq)
{
	int option;
	bool repeat = true;

	cout << "------------------------------" << endl;
	cout << "-------|STORE REQUESTS|-------" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Show Store Requests" << endl;
	cout << "2 - Show Urgent Store Requests" << endl;
	cout << "3 - Show Suspended Store Requests" << endl;
	cout << "4 - Add Store Request" << endl;
	cout << "5 - Suspend Store Request" << endl;
	cout << "6 - Reinstate Suspended Store Request" << endl;
	cout << "7 - Remove Suspended Store Request" << endl;
	cout << "8 - Satisfy Store Requests" << endl;
	cout << "9 - Back to Main Menu" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				hq.showStoreRequests();
				system("pause");
				repeat = false;
				break;
			}
			case 2:
			{
				hq.showStoreRequestsBelowX();
				system("pause");
				repeat = false;
				break;
			}
			case 3:
			{
				hq.showSuspendedRequests();
				system("pause");
				repeat = false;
				break;
			}
			case 4:
			{
				try
				{
					hq.addStoreRequest();
					cout << "  <<< Created >>>\n";
					system("pause");
				}
				catch (ExistingID<int> &e)
				{
					cout << "Existing ID: A Store Request with ID: " << e.ID << " already exists." << endl;
					system("pause");
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Store found with ID: " << e.ID << endl;
					system("pause");
				}
				catch (InvalidDate<unsigned int> &e)
				{
					cout << "Invalid Date: Invalid inserted date: " << e.y << "/" << e.m << "/" << e.d << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 5:
			{
				try
				{
					hq.suspendStoreRequest();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Store Request found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (InvalidDate<unsigned int> &e)
				{
					cout << "Invalid Date: Invalid inserted date: " << e.y << "/" << e.m << "/" << e.d << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 6:
			{
				try
				{
					hq.reinstateStoreRequest();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Store Request found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 7:
			{
				try
				{
					hq.removeStoreRequest();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Store Request found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 8:
			{
				hq.satisfyStoreRequests();
				repeat = false;
				break;
			}
			case 9:
			{
				repeat = false;
				break;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;

			}
			}
		}
	}
}

// menu 5 visualization
// PRODUCTION REQUESTS
void menu5(Headquarters &hq)
{
	int option;
	bool repeat = true;

	cout << "------------------------------" << endl;
	cout << "-----|PRODUCTION REQUESTS|----" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Show Production Requests" << endl;
	cout << "2 - Show Specific Publication Production Requests" << endl;
	cout << "3 - Add Production Request" << endl;
	cout << "4 - Remove Production Request" << endl;
	cout << "5 - Change Production Request Deadline" << endl;
	cout << "6 - Advance Production" << endl;
	cout << "7 - Back to Main Menu" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				hq.showProductionRequests();
				system("pause");
				repeat = false;
				break;
			}
			case 2:
			{
				try
				{
					hq.show_specific_production_request();
					system("pause");
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Publication found with ID: " << e.ID << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 3:
			{
				try
				{
					hq.addProductionRequest();
					cout << "  <<< Created >>>\n";
					system("pause");
				}
				catch (ExistingID<int> &e)
				{
					cout << "Existing ID: A Prduction Request with ID: " << e.ID << " already exists." << endl;
					system("pause");
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Publication found with ID: " << e.ID << endl;
					system("pause");
				}
				catch (InvalidDate<unsigned int> &e)
				{
					cout << "Invalid Date: Invalid inserted date: " << e.y << "/" << e.m << "/" << e.d << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 4:
			{
				try
				{
					hq.deleteProductionRequest();
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Production Request found with ID: " << e.ID << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 5:
			{
				try
				{
					hq.change_limite_date();
					system("pause");
				}
				catch (IDNotFound<int> &e)
				{
					cout << "ID Not Found: No Production Request found with ID: " << e.ID << endl;
					system("pause");
				}
				catch (InvalidDate<unsigned int> &e)
				{
					cout << "Invalid Date: Invalid inserted date: " << e.y << "/" << e.m << "/" << e.d << "." << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Unknown exception." << endl;
					system("pause");
				}
				repeat = false;
				break;
			}
			case 6:
			{
				hq.produce();
				repeat = false;
				break;
			}
			case 7:
			{
				repeat = false;
				break;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;

			}
			}
		}
	}
}

// MAIN MENU
bool mainMenu(Headquarters &hq)
{
	int option;
	bool repeat = true;

	// main menu
	cout << "------------------------------" << endl;
	cout << "------------|MENU|------------" << endl;
	cout << "------------------------------" << endl;
	cout << "1 - Publications" << endl;
	cout << "2 - Employees" << endl;
	cout << "3 - Stores" << endl;
	cout << "4 - Store Requests" << endl;
	cout << "5 - Production Requests" << endl;
	cout << "6 - Exit" << endl;

	while (repeat)
	{
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Insert a valid menu option." << endl;
			continue;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (option)
			{
			case 1:
			{
				//Limpar_ecra();
				menu1(hq);
				//Limpar_ecra();
				repeat = false;
				return true;
			}
			case 2:
			{
				//Limpar_ecra();
				menu2(hq);
				//Limpar_ecra();
				repeat = false;
				return true;
			}
			case 3:
			{
				//Limpar_ecra();
				menu3(hq);
				//Limpar_ecra();
				repeat = false;
				return true;
			}
			case 4:
			{
				//Limpar_ecra();
				menu4(hq);
				//Limpar_ecra();
				repeat = false;
				return true;
			}
			case 5:
			{
				//Limpar_ecra();
				menu5(hq);
				//Limpar_ecra();
				repeat = false;
				return true;
			}
			case 6:
			{
				return false;
			}
			default:
			{
				cout << "Insert a valid menu option." << endl;
			}
			}
		}
	}
	return true;
}
