//Written by Vladimir Kataev
#pragma once

#include <iostream>
#include <string>

enum driveTrain { NULLDRIVE = -1, AWD = 0, FWD, RWD };

class Car {
private:
	std::string manufacturer, model;
	int year, price, seatingCap, combMile, horsePower;
	driveTrain mode;
	bool comparingMakeModel = true;
	bool comparingPrice = false;
	bool comparingHP = false;
	bool comparingYear = false;


public:
	// One string constructor
	//Pre: input - A one-line constructor, as used in data file
	//Post:    Car object exists accordingly
	//Return:nope
	Car(std::string input);

	/*
	Param:	car attributes in order of class declaration
	Post:	car object with given attributes is created
	*/
	Car(std::string, std::string, int, int, int, int, int, driveTrain);

	// Copy Contructor
	//Pre: copy- a car to be copied
	//Post: Car object exists
	//Return:nope
	//Car(Car& copy);

	// empty constructor
	//Pre:Nope
	//Post:Car Object exists
	//Return: nope
	Car();

	// getter for hash key
	//Pre:none
	//Post:none
	//Return:key = manufacturer + model + year
	std::string getKey();

	/*
	Return:	string of formatted car attributes
	*/
	std::string formattedOutput();

	// getter for manufacturer
	//Pre:nope
	//Post:nope
	//Return: manufacturer
	std::string getManufacturer();

	// getter for model
	//Pre:nope
	//Post:nope
	//Return:model
	std::string getModel();

	// getter for year
	//Pre:nope
	//Post:nope
	//Return:year
	int getYear();

	// getter of price
	//Pre:nope
	//Post:nope
	//Return:price
	int getPrice();

	// getter of seats
	//Pre:nope
	//Post:nope
	//Return:seats
	int getSeats();

	// getter of mileage
	//Pre:nope
	//Post:nope
	//Return:mileage
	int getMileage();

	// getter of horsepower
	//Pre:nope
	//Post:nope
	//Return:nope
	int getHorsePower();


	// getter of drivetrain
	//Pre:nope
	//Post:nope
	//Return:driveTrain
	driveTrain getDriveTrain();


	// getter of drivetrain
	//Pre:nope
	//Post:nope
	//Return:driveTrain string
	std::string getDriveTrainString();


	// setter of manufacturer
	//Pre:manu - manufacturer
	//Post:manufacturer
	//Return:nope
	void setManufacturer(std::string manu);

	// setter of model
	//Pre:mod - model
	//Post:model
	//Return: nope
	void setModel(std::string mod);

	// setter of year
	//Pre:yr - year
	//Post: year
	//Return:nope
	void setYear(int yr);

	// setter of price
	//Pre:pr - price
	//Post:price
	//Return:nope
	void setPrice(int pr);

	// setter of seats
	//Pre: seat - seats
	//Post:seats
	//Return:nope
	void setSeats(int seat);

	// setter of mileage
	//Pre:mileage - combMile
	//Post:combMile
	//Return:nope
	void setMileage(int mileage);

	// setter of horsepower
	//Pre:pwr - horsePower
	//Post:horsePower
	//Return:nope
	void setHorsePower(int pwr);

	// setter of drivetrain
	//Pre:mode - drivetrain (AWD, FWD, RWD)
	//Post: driveTrain
	//Return:nope
	void setDriveTrain(std::string mode);

	// Sets comparison mode
	//Pre: attr: which attribute to compare by (0 for makeModel, 1 for price, 2 for horsepower, 3 for model year)
	//Post: changes internal booleans
	//Return: nope
	void setComparisonMode(int attr);

	// appends to stream a car toString
	//Pre: output- the stream being appended, right - the car being toStringed
	//Post: nope
	//Return: output stream
	friend std::ostream& operator << (std::ostream& output, Car right);

	//Comparison operators, comparing cars depending on internal booleans
	//Pre: 2 cars existing
	//Post: nope
	//Return: boolean on comparison
	bool friend operator > (Car& left, Car& right);
	bool friend operator >= (Car& left, Car& right);
	bool friend operator <= (Car& left, Car& right);
	bool friend operator < (Car& left, Car& right);
	bool friend operator == (Car& left, Car& right);
	bool friend operator != (Car& left, Car& right);

	// Assignment Operator
	//Pre: Object on right exists
	//Post:Object on left assigned
	//Return:Car object identical to right (except comparison mode)
	Car& operator=(Car& right);

	// Destructor
	//Pre: Object exists
	//Post:Object doesn't exist
	//Return: Nope
	~Car();

	// String append operator
	//Pre: Object on right & left exists
	//Post:Object on left assigned
	//Return:Concatenate string
	std::string friend operator+(std::string left, Car& right);

	// getter for human-readable string
	//Pre:nope
	//Post:nope
	//Return: make model year
	std::string toString();
};
