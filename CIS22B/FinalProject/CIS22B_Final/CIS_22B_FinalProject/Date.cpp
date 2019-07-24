#include"Date.h"
/*class Date{
	public:
		int year, month, day;
                int getYear(), getMonth(), getDay();
                void setYear(int ), setMonth(int ), setDay(int), reset(int, int, int);
                Date(int, int, int);
                Date();
                bool friend operator>(Date const &, Date const &);
                bool friend operator<(Date const &, Date const &);
                bool friend operator==(Date const &, Date const &);
                bool friend operator!=(Date const &, Date const &);


};*/
Date::Date(){
	int year = 0;
	int month = 0;
	int day = 0;
};


Date::Date(int a, int b, int c){
	day = a;
	month = b;
	year = c;
};




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

int Date::getYear(){return year;};
int Date::getDay(){return day;};
int Date::getMonth(){return month;};


void Date::setYear(int a){year = a;};
void Date::setMonth(int a){month = a;};
void Date::setDay(int a){day = a;};
