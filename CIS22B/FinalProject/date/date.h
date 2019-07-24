class Date{
	public:
		int year, month, day;
		int getYear(), getMonth(), getDay();
		void setYear(int ), setMonth(int ), setDay(int), reset(int, int, int);
		Date(int, int, int);
		Date();
		bool operator>( const Date&);/*{
		        if(this->year > r.year){return true;}else if(r.year > this->year){return false;}
		        if(this->month > r.month){return true;}else if(r.month > this->month){return false;}
		        if(this->day > r.day){return true;}else if(r.day > this->day){return false;}
        		return false;
		};*/
		bool operator<( const Date&);/*{
		        if(this->year < r.year){return true;}else if(r.year < this->year){return false;}
		        if(this->month < r.month){return true;}else if(r.month < this->month){return false;}
		        if(this->day < r.day){return true;}
		        return false;
		};*/

		bool operator==( const Date&);/*{
		        if(this->year == r.year && this->month == r.month && this->day == r.day)
                		return true;
        		return false;
		};*/
		bool operator!=( const Date&);/*[
		        if(this->year == r.year && this->month == r.month && this->day == r.day)  
           		     	return false;
        		return true;
		};*/
};
