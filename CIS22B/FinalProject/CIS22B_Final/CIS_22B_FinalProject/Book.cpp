#include <stdio.h>
#include "Book.h"



Book::Book(std::string ISB, std::string Ti, std::string Au, std::string Publish, int quant, double wholeSale, double retail)
{
	ISBN = ISB;
	title = Ti;
	author = Au;
	publisher = Publish;
	quantity = quant;
	wholeSaleCost = wholeSale;
	retailPrice = retail;
	std::cout << "Constructor for object " << title << " with full initialization list called ..." << std::endl;
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
	std::cout << "Copy constuctor for object " << this->title << " with partial initialization list called ..." << std::endl;
}

Book::~Book()
{

}
Book::Book(std::string toParse){
	char toEnter[20];
	int parseChar = 0; //pointing at first of ISBN
	int stop = 0;
	while(toParse[parseChar-stop] != '|'){
		toEnter[parseChar] = toParse[parseChar-stop];
		parseChar++;
	}
	toEnter[parseChar] = '\0';
	toEnter.copy(ISBN, parseChar-stop);
	parseChar++; //pointing at first char of title
	stop = parseChar;


	while(toParse[parseChar] != '|'){
		toEnter[parseChar] = toParse[parseChar-stop];
		parseChar++;
	}
	title.copy(toEnter);

}

//std::string Book::set

// Accessor or getters
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
