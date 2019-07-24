#include <stdio.h>
#include "Book.h"
#include<string>


Book::Book(std::string ISB, std::string Ti, std::string Au, std::string Publish, int quant, double wholeSale, double retail, Date publishedIn, Date addedIn)
{
	ISBN = ISB;
	title = Ti;
	author = Au;
	publisher = Publish;
	quantity = quant;
	wholeSaleCost = wholeSale;
	retailPrice = retail;
	added = addedIn;
	published = publishedIn;
	std::cout << "Constructor for object " << title << " with full initialization list called ..." << std::endl;
}
Book::Book(){
		//std::cout << "default cons. called" << std::endl;;
}

Book::Book(const Book &orig)
{
	this->ISBN = orig.ISBN;
	this->title = orig.title;
	this->author = orig.author;
	this->publisher = orig.publisher;
	this->quantity = orig.quantity;
	this->wholeSaleCost = orig.wholeSaleCost;
	this->retailPrice = orig.retailPrice;
	this->published = orig.published;
	this->added = orig.added;
	std::cout << "Copy constuctor for object " << this->title << " with partial initialization list called ..." << std::endl;
}

Book::~Book()
{

}
Book::Book(std::string toParse){
	std::string toTrunc = toParse;


	ISBN = toTrunc.substr(0, toTrunc.find("|"));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);
//	std::cout << toTrunc;


	title = toTrunc.substr(0, toTrunc.find("|"));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	author = toTrunc.substr(0, toTrunc.find("|"));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	publisher = toTrunc.substr(0, toTrunc.find("|"));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	quantity = std::stoi(toTrunc.substr(0, toTrunc.find("|")));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	wholeSaleCost = std::stod(toTrunc.substr(0, toTrunc.find("|")));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	retailPrice = std::stod(toTrunc.substr(0, toTrunc.find("|")));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	published = Date(toTrunc.substr(0, toTrunc.find("|")));
	toTrunc = toTrunc.substr(toTrunc.find("|")+1);

	added = Date(toTrunc);
}



//std::string Book::set

// Accessor or getters
/*
std::string Book::getISBN() const
{
	return ISBN;
};

std::string Book::getTitle() const
{
	return title;
}
std::string Book::getAuthor() const
{
	return author;
}
int Book::getwholeSaleCost() const
{
	return wholeSaleCost;
}
double Book::getRetailPrice() const
{
	return retailPrice;
}


std::string toString(){
//  Book a("1234567890123|Metro 2033|Dmitry G|4A Games|30000|5.49|14.99|13102007|06082033");
	std::string ans = ISBN + "|" + title + "|" + author + "|" + publisher + "|" + quantity + "|"+ retailPrice + "|"+ wholeSaleCost + "|"+ published.toString() + "|"+ added.toString();
}
*/
//mutators or setters
void Book::setISBN(std::string m)
{
	ISBN = m;
}
void Book::setTitle(std::string t)
{
	title = t;
}
void Book::setRetailPrice(double price)
{
	retailPrice = price;
}

void Book::setAuthor(std::string auth)
{
	author = auth;
}

void Book::setPublisher(std::string pub)
{
	publisher = pub;
}
