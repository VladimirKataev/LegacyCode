#include <iostream>
#include <iomanip>
#include "Book.h"
#include <string>

using namespace std;




int main() {


	Book Becoming("9781524763138", "Becoming", "Michelle Obama", "Crown Publishing Group", 5, 15.00, 19.50);
	Book WhereTheCrawdadsSing("9780735219090", "Where the Crawdads Sing", "Delia Owens", "Penguin Publishing Group", 5, 10.00, 15.60);
	Book YouAreMyHappy("9780062931030", "You Are My Happy", "Hoda Kotb, Suzie Mason(Illustrator)", "HarperCollins Publishers", 5, 10.56, 17.09);
	Book TheUmbrellaAcademy("9781593079789", "The Umbrella Academy, Volume 1: Apocalypse Suite", "Gerard Way, Gabriel Ba (Artist)", "Dark Horse Comics", 5, 9.50, 11.90);
	Book TheMeullerReport("9781510750166", "The Meuller Report", "Robert S. Mueller III", "Skyhorse", 5, 10.56, 17.09);



	Book arr[5] = { Becoming, WhereTheCrawdadsSing, YouAreMyHappy, TheUmbrellaAcademy, TheMeullerReport };

      


		double total = 0.00;
		double price;
		char selection;
		const double tax = 1.087;
		int fCount = 0;
		int sCount = 0;
		int xCount = 0;
		double tax_included_price = 0;
		double totalTax = 0.0;

		do
		{
			DisplayMenu();
			price = 0;
			cout << "Make your selection : ";
			cin >> selection;
			switch (toupper(selection))
			{
			case 1:
				price = ;
				fCount += 1;
				break;
			case 2:
				price = ;
				sCount += 1;
				break;
			case 3:
				price = ;
				xCount += 1;
				break;
			case 'T':
				break;
			default:
				cout << "Illegal selection, try again." << endl;
			}
			total += price;
			totalTax = total * .087;
			tax_included_price = total * tax;
		} while (selection != 'T' && selection != 't');

		cout << "The sub total is $" << fixed << setprecision(2) << total << endl;
		cout << "The total tax is $" << fixed << setprecision(2) << totalTax << endl;
		cout << "The total is $" << fixed << setprecision(2) << tax_included_price << endl;
		return 0;
	





}void DisplayMenu(arr)
{
	cout << endl;   // blank line before start of menu
	for( int item; item < 5; item++)
	{ 
		cout << item << "=" << arr[5] <<  "$" << arr[5] << endl;
	}

	cout << "F = falafel  $5.15" << endl;
	cout << "S = soda     $2.24" << endl;
	cout << "X = extras   $1.57" << endl;
	cout << "T = total" << endl;
}