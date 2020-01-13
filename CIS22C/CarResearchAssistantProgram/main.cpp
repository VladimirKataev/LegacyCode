#include <iostream>
#include <string>
#include "Car.h"
#include "DatabaseManager.h"

using namespace std;

class InvalidInput {};

int main(int argc, const char* argv[]) {
	int choice = -1;
	string tempChoice;
	bool repeatLoop = true;
	DatabaseManager database("carList.txt", 50);

	//cout << database.getTable().search("ToyotaSupra") << endl;
	//cout << database.getTreePrice().getRoot()->getData() << endl;

	while (choice != 0)
	{
		try {
			//MAIN MENU
			cout << '\n' << "================================================================================" << endl;
			cout << "main menu " << endl;
			cout << "--------------------------------------------------------------------------------" << '\n' << endl;
			cout << "1 - search\n2 - list data\n3 - print indented tree\n4 - edit database\n5 - program efficiency\n0 - exit program\n" << endl;
			cout << "> ";
			getline(cin, tempChoice);
			choice = stoi(tempChoice);

			switch (choice)
			{
			case 1:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > search" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;
				cout << "1 - search car model and manufacturer\n2 - advanced search\n0 - back\n" << endl;
				cout << "> ";
				getline(cin, tempChoice);
				choice = stoi(tempChoice);
				switch (choice)
				{
				case 1:
				{
					string manufacturer, model, year;
					cout << '\n' << "================================================================================" << endl;
					cout << "main menu > search > search car model and manufacturer" << endl;
					cout << "--------------------------------------------------------------------------------" << '\n' << endl;
					cout << "Manufacturer:  ";
					getline(cin, manufacturer);
					cout << "Car Model:  ";
					getline(cin, model);
					cout << "Year: ";
					getline(cin, year);
					try {
						cout << database.searchKey(manufacturer + model + year) << endl;
					}
					catch (char* s) {
						cout << s << endl;
					}
					catch (...) {
						cout << "other error" << endl;
					}

					cout << ">\npress enter to return to menu";
					getline(cin, model);
				}
				break;
				case 2:
				{
					repeatLoop = true;
					while (repeatLoop) {
						repeatLoop = false;
						string manufacturer, model;
						string stringYear, stringPrice, stringSeatingCap, stringCombMile, stringHorsePower;
						int year, price, seatingCap, combMile, horsePower;
						string stringMode;
						driveTrain mode;
						cout << '\n' << "================================================================================" << endl;
						cout << "main menu > search > advanced search" << endl;
						cout << "--------------------------------------------------------------------------------" << '\n' << endl;
						cout << "(press ENTER to bypass search criteria)\n" << endl;
						try {
							cout << "Manufacturer:  ";
							getline(cin, manufacturer);
							cout << "Model:  ";
							getline(cin, model);
							cout << "Year:  ";
							getline(cin, stringYear);
							if (stringYear == "") year = -1;
							else year = stoi(stringYear);
							cout << "Price:  ";
							getline(cin, stringPrice);
							if (stringPrice == "") price = -1;
							else price = stoi(stringPrice);
							cout << "Seating Capacity:  ";
							getline(cin, stringSeatingCap);
							if (stringSeatingCap == "") seatingCap = -1;
							else seatingCap = stoi(stringSeatingCap);
							cout << "Combined Mileage:  ";
							getline(cin, stringCombMile);
							if (stringCombMile == "") combMile = -1;
							else combMile = stoi(stringCombMile);
							cout << "Horsepower:  ";
							getline(cin, stringHorsePower);
							if (stringHorsePower == "") horsePower = -1;
							else horsePower = stoi(stringHorsePower);
							cout << "Drivetrain Mode (AWD, FWD, RWD):  ";
							getline(cin, stringMode);
							if (stringMode == "") mode = NULLDRIVE;
							else if (stringMode == "AWD") mode = AWD;
							else if (stringMode == "FWD") mode = FWD;
							else if (stringMode == "RWD") mode = RWD;
							else mode = NULLDRIVE;

							int sortState, compareMode;
							cout << "\nSort By:" << endl;
							cout << "1 - unordered\n2 - alphabetical\n3 - year\n4 - price\n5 - horsepower\n\n> ";
							getline(cin, tempChoice);
							compareMode = stoi(tempChoice);
							if (compareMode == 1) {
								compareMode = 0;
								sortState = 0;
							}
							else {
								if (compareMode == 2) compareMode = 0;
								else if (compareMode == 3) compareMode = 3;
								else if (compareMode == 4) compareMode = 1;
								else if (compareMode == 5) compareMode = 2;
								else throw "invalid data";

								cout << "\n\nSort Order:\n1 - ascending\n2 - descending\n\n> ";
								getline(cin, tempChoice);
								sortState = stoi(tempChoice);
								if (sortState == 1) sortState = 1;
								else if (sortState == 2) sortState = -1;
								else throw "invalid data";
							}
							SinglyLinkedList<Car*> * searchResults = database.search(Car(manufacturer, model, year, price, seatingCap, combMile, horsePower, mode), sortState, compareMode);
							int size = searchResults->getCount();
							cout << "\n\nSearch Results: (select to view details)\n" << endl;
							for (int i = 0; i < size; i++) {
								cout << i + 1 << " - " << searchResults->getNode(i)->getManufacturer() << " " << searchResults->getNode(i)->getModel() << endl;
							}
							cout << "\n\n0 - back to main menu\n" << endl;
							cout << "> ";
							getline(cin, tempChoice);
							//choice = stoi(tempChoice);
						}
						catch (...) {
							cout << "\nInvalid Data\n" << endl;
							cout << "try again? (y/n)\n> ";
							getline(cin, tempChoice);
							if (tempChoice == "y")
								repeatLoop = true;
						}
					}
					break;
				case 0:
					break;
				}
				}
				break;
			case 2:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > list data" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;

				break;
			case 3:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > print indented tree" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;
				cout << "Select Tree:\n1 - price\n2 - year\n" << endl;
				cout << "> ";
				getline(cin, tempChoice);
				choice = stoi(tempChoice);
				database.printIndentedTree(choice);
				break;
			case 4:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > edit database" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;
				cout << "1 - add vehicle\n2 - remove vehicle\n3 - back\n" << endl;
				cout << "> ";
				getline(cin, tempChoice);
				choice = stoi(tempChoice);
				switch (choice)
				{
				case 1:
				{
					std::string man, mod, stringDrive;
					int y, p, seats, mileage, hp;
					driveTrain drive;
					cout << '\n' << "================================================================================" << endl;
					cout << "main menu > edit database > add vehicle" << endl;
					cout << "--------------------------------------------------------------------------------" << '\n' << endl;
					cout << "Manufacturer:  "; cin >> man;
					cout << "Model:  "; cin >> mod;
					cout << "Year:  "; cin >> y;
					cout << "Price:  "; cin >> p;
					cout << "Seating Capacity:  "; cin >> seats;
					cout << "Combined Mileage:  "; cin >> mileage;
					cout << "Horsepower:  "; cin >> hp;
					cout << "Drivetrain(AWD,FWD,RWD):  "; cin >> stringDrive;
					if (stringDrive == "AWD")
						drive = AWD;
					else if (stringDrive == "FWD")
						drive = FWD;
					else if (stringDrive == "RWD")
						drive = RWD;
					else
						throw InvalidInput();

					Car * add = new Car(man, mod, y, p, seats, mileage, hp, drive);

					database.add(add);

					break;
				}
				case 2:
				{
					std::string man, mod, stringDrive;
					int y, cap, p, mile, hp;
					driveTrain drive;
					cout << '\n' << "================================================================================" << endl;
					cout << "main menu > edit database > remove vehicle" << endl;
					cout << "--------------------------------------------------------------------------------" << '\n' << endl;
					cout << "Manufacturer:  "; cin >> man;
					cout << "Model:  "; cin >> mod;
					cout << "Year:  "; cin >> y;
					cout << "Price:  "; cin >> p;
					cout << "Seating Capacity:  "; cin >> cap;
					cout << "Combined Mileage:  "; cin >> mile;
					cout << "Horsepower:  "; cin >> hp;
					cout << "Drivetrain(AWD,FWD,RWD):  "; cin >> stringDrive;
					if (stringDrive == "AWD")
						drive = AWD;
					else if (stringDrive == "FWD")
						drive = FWD;
					else if (stringDrive == "RWD")
						drive = RWD;
					else
						throw InvalidInput();

					//Car* remove = new Car(man, mod, y, p, )

					//database.remove(remove);
				}
				break;
				case 3:
					break;
				default:
					cout << "\ninvalid choice" << endl;
					break;
				}

				break;
			case 5:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > program efficiency" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;
				cout << "AVL Worst Case: Insert: 15log(n)+49    Delete: 15log(n)+51   Search: log(n)" << endl;
				cout << "HashTable Worst Case: Insert: 3n + 53  Delete:      Search: O(n)" << endl;
				break;
			case 0:
				cout << '\n' << "================================================================================" << endl;
				cout << "main menu > exit program" << endl;
				cout << "--------------------------------------------------------------------------------" << '\n' << endl;
				cout << "Are you sure you would like to exit the program? (y/n)\n" << endl;
				cout << "> ";
				getline(cin, tempChoice);
				if (tempChoice == "y" || tempChoice == "Y")
					choice = 0;
				else choice = 1;
				break;
			}
		}
		catch (...) {
			cout << "\n\nInvalid input\n" << endl;
		}
	}

	return 0;
}
