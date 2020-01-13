// Written by Vladimir Kataev
#include <iostream>
#include <string>
#include "Car.h"
//#pragma once
Car::Car(std::string input) {
	std::string var[8];
	int split;
	for (int i = 0; i < 7; i++) {
		split = input.find('|');
		var[i] = input.substr(0, split);
		input = input.substr(split + 1);
	}
	var[7] = input;

	setManufacturer(var[0]);
	setModel(var[1]);
	setYear(stoi(var[2]));
	setPrice(stoi(var[3]));
	setMileage(stod(var[4]));
	setSeats(stoi(var[5]));
	setHorsePower(stod(var[6]));
	setDriveTrain(var[7]);
}

Car::Car(std::string man, std::string mod, int y, int p, int seats, int mileage, int hp, driveTrain drive)
{
	manufacturer = man;
	model = mod;
	year = y;
	price = p;
	seatingCap = seats;
	combMile = mileage;
	horsePower = hp;
	mode = drive;
}

Car::Car() {
	year = 0;
	price = 0;
	seatingCap = 0;
	combMile = 0;
	horsePower = 0;
	driveTrain mode;
}

std::string Car::getKey() { std::string tmp;
	tmp += this->getManufacturer();
	tmp += this->getModel();
	tmp += std::to_string(this->getYear());
	return tmp;
}

/*
std::string Car::formattedOutput()
{
	std::string s = "Manufacturer:  " + this->getManufacturer() + "\nModel:  " + this->getModel() + "\nYear:  " + this->getYear()
					+ "\nPrice:  " + std::to_string(this->getPrice()) + "\nSeating Capacity:  " + std::to_string(this->getSeats())
					+ "\nCombined Mileage:  " + std::to_string(this->getMileage()) + "\nEngine Horsepower:  " + std::to_string(this->getHorsePower())
					+ "\nDrivetrain Mode:  " + ;
}
*/

void Car::setManufacturer(std::string manu) {
	manufacturer = manu;
}

std::string Car::getManufacturer() {
	return manufacturer;
}

void Car::setModel(std::string mod) {
	model = mod;
}

std::string Car::getModel() {
	return model;
}

void Car::setYear(int yr) {
	year = yr;
}
int Car::getYear() {
	return year;
}

void Car::setPrice(int pr) {
	price = pr;
}

int Car::getPrice() {
	return price;
}

void Car::setMileage(int mileage) {
	combMile = mileage;
}

driveTrain Car::getDriveTrain(){
	return mode;
}

std::string Car::getDriveTrainString() {
	if (mode == AWD) return "AWD";
	else if (mode == FWD) return "FWD";
	return "RWD";
}

int Car::getMileage() {
	return combMile;
}

void Car::setSeats(int seat) {
	seatingCap = seat;
}

int Car::getSeats() {
	return seatingCap;
}

void Car::setHorsePower(int pwr) {
	horsePower = pwr;
}

int Car::getHorsePower() {
	return horsePower;
}

void Car::setDriveTrain(std::string md) {
	if (md == "AWD") {
		mode = driveTrain::AWD;
	}
	else if (md == "FWD") {
		mode = driveTrain::FWD;
	}
	else if (md == "RWD") {
		mode = driveTrain::RWD;
	}
}

void Car::setComparisonMode(int attr) {
	comparingMakeModel = false;
	comparingPrice = false;
	comparingHP = false;
	comparingYear = false;
	if (attr == 0) comparingMakeModel = true;
	else if (attr == 1) comparingPrice = true;
	else if (attr == 2) comparingHP = true;
	else comparingYear = true;
}

std::ostream & operator << (std::ostream & output, Car right) {
	output << right.getYear() << " " << right.getManufacturer() << " " + right.getModel() << " with "
		<< right.horsePower << "HP and " << right.getMileage() << "MPG average for $" << right.getPrice();
	return output;
}

bool operator == (Car & left, Car & right) {
	return left.manufacturer == right.manufacturer && left.model == right.model && left.year == right.year;
}
bool operator < (Car & left, Car & right) {
	if (left.comparingMakeModel) {
		std::string tmp1 = left.manufacturer + left.model;
		std::string tmp2 = right.manufacturer + right.model;
		return tmp1 < tmp2;
	}
	else if (left.comparingPrice) return left.price < right.price;
	else if (left.comparingHP) return left.horsePower < right.horsePower;
	else return left.year < right.year;
}




bool operator > (Car & left, Car & right) {
	if (left.comparingMakeModel) {
		std::string tmp1 = left.manufacturer + left.model;
		std::string tmp2 = right.manufacturer + right.model;
		return tmp1 > tmp2;
	}
	else if (left.comparingPrice) return left.price > right.price;
	else if (left.comparingHP) return left.horsePower > right.horsePower;
	else return left.year > right.year;
}


bool operator != (Car & left, Car & right) {
	return !(left == right);
}

bool operator >= (Car & left, Car & right) {
	return left > right || left == right;
}

bool operator <= (Car & left, Car & right) {
	return left < right || left == right;
}



Car& Car::operator=(Car & right) {
	manufacturer = right.getManufacturer();
	model = right.getModel();
	year = right.getYear();
	price = right.getPrice();
	seatingCap = right.getSeats();
	combMile = right.getMileage();
	horsePower = right.getHorsePower();
	setDriveTrain(right.getDriveTrainString());
	return *this;
}

/*
Car& Car::Car(Car & copy) {
	model = copy.getModel();
	year = copy.getYear();
	price = copy.getPrice();
	seatingCap = copy.getSeats();
	combMile = copy.getMileage();
	horsePower = copy.getHorsePower();
	setDriveTrain(copy.getDriveTrainString());
	return *this;
}

*/
Car::~Car() {} //nothing declared within

std::string Car::toString() {
	std::string value;
	if (comparingPrice) {
		value = "$" + std::to_string(price);
	}
	else if (comparingHP) {
		value = "HP: " + std::to_string(horsePower);
	}
	else {
		value = "Y: " + std::to_string(year);
	}
	return "{" + manufacturer + " " + model + " " + value + "}";
}

std::string operator+(std::string left, Car& right) {
	left += right.toString();
	return left;
}
