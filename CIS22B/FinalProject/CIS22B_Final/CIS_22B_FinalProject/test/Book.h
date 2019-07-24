//#pragma once
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
	Book();
	Book(std::string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice, Date publishedIn, Date addedIn);
	Book(const Book &orig);
	Book(std::string toParse);
	// Destructor
	~Book();

	// Accessor or getters
	inline std::string getISBN() const { return ISBN; };
	inline std::string getTitle() const { return title; }
	inline std::string getAuthor() const { return author; }
	inline std::string getPublisher() const { return publisher; }
	inline double getwholeSaleCost() const { return wholeSaleCost; }
	inline double getRetailPrice() const { return retailPrice; }
	inline int getQuantity() const {return quantity;}
	inline Date getPublished() const {return published;}
	inline Date getAdded() const {return added;}
	inline std::string toString(){	if(ISBN.size() != 0)
																		return (ISBN + "|" + title + "|" + author + "|" + publisher + "|" + std::to_string(quantity) + "|"+ std::to_string(retailPrice) + "|"+ std::to_string(wholeSaleCost) + "|"
																			+ (published.getDay() < 10 ? "0":"") + std::to_string(published.getDay())
																			+ (published.getMonth() < 10 ? "0" : "") + std::to_string(published.getMonth())
																			+ (published.getYear() < 10 ? "000" : (published.getYear() < 100 ? "00": (published.getYear() < 1000 ? "0" : ""))) + std::to_string(published.getYear()) + "|"
																			+ (added.getDay() < 10 ? "0":"") + std::to_string(added.getDay())
																			+ (added.getMonth() < 10 ? "0" : "") + std::to_string(added.getMonth())
																			+ (added.getYear() < 10 ? "000" : (added.getYear() < 100 ? "00": (added.getYear() < 1000 ? "0" : ""))) + std::to_string(added.getYear()));
																		return "";
																			};



	//mutators or setters
	void setISBN(std::string m);
	void setTitle(std::string t);
	void setRetailPrice(double price);
	void setWholesale(double price);
	void setAuthor(std::string auth);
	void setPublisher(std::string pub);
	void setQuantity(int pub);
	void setQuantity(int pub);
	void setQuantity(int pub);


	//operating overloading
//    example
//    friend book operator+(car &left, car&right);


};
