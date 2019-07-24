#include"Date.h"
#include<string>
//#include<iostream>
//using namespace std;

Date::Date(){
	int year = 0;
	int month = 0;
	int day = 0;
};
Date::Date(const Date &orig){
	this->day = orig.day;
	this->month = orig.month;
	this->year = orig.year;
};

Date::Date(int a, int b, int c){
	day = a;
	month = b;
	year = c;
};

Date::Date(std::string in){
	//cout << "got " << in << std::endl;
	day = std::stoi(in.substr(0,2));
	month = std::stoi(in.substr(2,2));
	year = std::stoi(in.substr(4,4));
}


bool Date::operator>(const Date &r){
	if(this->year > r.year){return true;}else if(r.year > this->year){return false;}
	if(this->month > r.month){return true;}else if(r.month > this->month){return false;}
	if(this->day > r.day){return true;}else if(r.day > this->day){return false;}
	return false;
};
bool Date::operator==(const Date &r){
	if(this->year == r.year && this->month == r.month && this->day == r.day)
		return true;
	return false;
};
bool Date::operator<(const Date &r){
        if(this->year < r.year){return true;}else if(r.year < this->year){return false;}
        if(this->month < r.month){return true;}else if(r.month < this->month){return false;}
        if(this->day < r.day){return true;}
        return false;


};
bool Date::operator!=(const Date &r){
        if(this->year == r.year && this->month == r.month && this->day == r.day)
                return false;
        return true;
};

std::string Date::toString(){
	std::string ans = "";
	if(day <10) ans += "0";
	ans += day;
	if(month <10) ans += "0";
	ans += month;
	if (year < 10 ) ans += "000";
	else if (year < 100 ) ans += "00";
	else if (year < 1000 ) ans += "0";
	ans += year;
	return ans;

//	return (day < 10 ? "0":"") + day + (month < 10 ? "0" : "") + month + (year < 10 ? "000" : (year < 100 ? "00": (year < 1000 ? "0"))) + year;

};

int Date::getYear(){return year;};
int Date::getDay(){return day;};
int Date::getMonth(){return month;};


void Date::setYear(int a){year = a;};
void Date::setMonth(int a){month = a;};
void Date::setDay(int a){day = a;};
