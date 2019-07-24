#pragma once
#include <iostream>
#include <string>
#include "Date.h"
class Book
{
private:
	std::string ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	int quantity;
	Date published;
	Date added;
	double wholeSaleCost;
	double retailPrice;
	//Date added


public:
	//Constructor
	Book() {

	};
	Book(std::string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice);
	Book(const Book &orig);
	Book(std::string toParse);
	// Destructor
	~Book();

	// Accessor or getters
	std::string getISBN() const { return ISBN; };
	std::string getTitle() const { return title; }
	std::string getAuthor() const { return author; }
	int getwholeSaleCost() const { return wholeSaleCost; }
	double getRetailPrice() const { return retailPrice; }
	


	

	//mutators or setters
	void setISBN(std::string m);
	void setTitle(std::string t);
	void setRetailPrice(double price);
	void setAuthor(std::string auth);
	void setPublisher(std::string pub);

	


	//operating overloading
//    example
//    friend book operator+(car &left, car&right);


};




