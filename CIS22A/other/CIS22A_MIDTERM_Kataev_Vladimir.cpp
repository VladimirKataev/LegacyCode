/*
	Written by Vladimir Kataev
	Program acts as a cashier
*/
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){

        //------Constant screen record
        ofstream writer;
        writer.open("output.txt");
        if(!writer){
                cout << "File issues\n";
                return 1;//Actual error occured
	}


	//-------Disp menu
	cout <<	"Welcome to De Anza Food Court.\nThe options are:\n"<<
		"1:De Anza Burger ($5.25)\n"<<
		"2:Bacon Cheese Burger ($5.75)\n"<<
		"3:Mushroom Swiss Burger ($5.95)\n"<<
		"4:Western Burger ($5.95)\n"<<
		"5:Don Cali Burger ($5.95)\n";
	/*writer << 	"Welcome to De Anza Food Court.\nThe options are:\n"<<
	                "1:De Anza Burger ($5.25)\n"<<
	                "2:Bacon Cheese Burger ($5.75)\n"<<
	                "3:Mushroom Swiss Burger ($5.95)\n"<<
        	        "4:Western Burger ($5.95)\n"<<
                	"5:Don Cali Burger ($5.95)\n";
	*/
	int choice = -1; // set to -1 for now
			// 0 for pay condition, 1-5 for purchase
	int 	quantity1=-0,
		quantity2=-0,
		quantity3=-0,
		quantity4=-0,
		quantity5=-0;// Correspond  a for choice 1, so on

	//-------Acquire choices
	while(choice != 0){
		cout << "\nEnter your choice(s), or use 0 to enter Billing phase:";
		//writer << "\nEnter your choice(s), or use 0 to enter Billing phase:";
		cin >> choice;
		//writer << choice<<endl;
		switch(choice){
                        case 0:
				break;
			case 1:
				do{
					cout << "Number to order:"; cin >> quantity1;
					//writer << "Number to order:"; writer <<  quantity1;
				}
				while(!(0 <= quantity1));//no upper bound in America
				break;
                        case 2:
                                do{
                                        cout << "Number to order:"; cin >> quantity2;
                                        //writer << "Number to order:"; writer <<quantity2;
                                }
                                while(!(0 <= quantity2));//no upper bound in America
                                break;
                        case 3:
                                do{
                                        cout << "Number to order:"; cin >> quantity3;
                                        //writer << "Number to order:"; writer << quantity3;
                                }
                                while(!(0 <= quantity3));//no upper bound in America
                                break;
                        case 4:
                                do{
                                        cout << "Number to order:"; cin >> quantity4;
                                        //writer << "Number to order:"; writer << quantity4;

                                }
                                while(!(0 <= quantity4));//no upper bound in America
                                break;
                        case 5:
                                do{
                                        cout << "Number to order:"; cin >> quantity5;
                                        //writer << "Number to order:"; writer << quantity5;

                                }
                                while(!(0 <= quantity5));//no upper bound in America
                                break;
                        default:
				cout << "Invalid response\n";
				//writer << "Invalid response\n";
		}
	}
	bool staff;
	int tmp;
	do{
		cout << "Are you Staff? (0 for no, 1 for yes):";cin >> tmp;
		//writer << "Are you Staff? (0 for no, 1 for yes):";writer << tmp;
	}while(!(tmp == 0 || tmp == 1));
	(tmp == 1)? staff = true:staff = false;

	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "The orders were:\n";
	writer << "The orders were:\n";
	double totalPreTax = 0.0;
	if(quantity1 != 0){
		cout << "De Anza Burger X"<<quantity1<<"\t$"<< 5.25*quantity1<< "\n";
		writer << "De Anza Burger X"<<quantity1<<"\t$"<< 5.25*quantity1<< "\n";
		totalPreTax += 5.25*quantity1;
	}
	if(quantity2 != 0){
                cout << "Bacon Cheese Burger X"<<quantity2<<"\t$"<< 5.75*quantity2<< "\n";
                writer << "Bacon Cheese Burger X"<<quantity2<<"\t$"<< 5.75*quantity2<< "\n";
		totalPreTax += 5.75*quantity2;
        }
        if(quantity3 != 0){
		totalPreTax += 5.95*quantity3;
                cout << "Mushroom Swiss Burger X"<<quantity3<<"\t$"<< 5.95*quantity3<< "\n";
                writer << "Mushroom Swiss Burger X"<<quantity3<<"\t$"<< 5.95*quantity3<< "\n";
	}
        if(quantity4 != 0){
		totalPreTax += 5.95*quantity4;
                cout << "Western Burger X"<<quantity4<<"\t$"<< 5.95*quantity4<< "\n";
                writer << "Western Burger X"<<quantity4<<"\t$"<< 5.95*quantity4<< "\n";
        }
        if(quantity5 != 0){
		totalPreTax += 5.95*quantity5;
                cout << "Don Cali Burger X"<<quantity5<<"\t$"<< 5.95*quantity5<< "\n";
                writer << "Don Cali Burger X"<<quantity5<<"\t$"<< 5.95*quantity5<< "\n";
        }
	if(staff){
		cout << "Tax of 9%:$"<< totalPreTax*0.09 << endl;
		writer << "Tax of 9%:$"<< totalPreTax*0.09<<endl;
	}
	cout << "Pretax:$"<<totalPreTax <<"\nPost tax:$";
	writer << "Pretax:$"<<totalPreTax <<"\nPost tax:$";
	(staff)?cout << totalPreTax*1.09:cout << totalPreTax;
	(staff)?writer << totalPreTax*1.09:writer << totalPreTax;
	cout << endl;
	writer << endl;
	writer.close();
	return 0;
}
/*
Welcome to De Anza Food Court.
The options are:
1:De Anza Burger ($5.25)
2:Bacon Cheese Burger ($5.75)
3:Mushroom Swiss Burger ($5.95)
4:Western Burger ($5.95)
5:Don Cali Burger ($5.95)

Enter your choice(s), or use 0 to enter Billing phase:2
Number to order:2

Enter your choice(s), or use 0 to enter Billing phase:0
Are you Staff? (0 for no, 1 for yes):1
The orders were:
Bacon Cheese Burger X2	$11.50
Tax of 9%:$1.03
Pretax:$11.50
Post tax:$12.54



Welcome to De Anza Food Court.
The options are:
1:De Anza Burger ($5.25)
2:Bacon Cheese Burger ($5.75)
3:Mushroom Swiss Burger ($5.95)
4:Western Burger ($5.95)
5:Don Cali Burger ($5.95)

Enter your choice(s), or use 0 to enter Billing phase:-2
Invalid response

Enter your choice(s), or use 0 to enter Billing phase:9
Invalid response

Enter your choice(s), or use 0 to enter Billing phase:3
Number to order:-2
Number to order:-666
Number to order:34

Enter your choice(s), or use 0 to enter Billing phase:1
Number to order:1

Enter your choice(s), or use 0 to enter Billing phase:2
Number to order:2

Enter your choice(s), or use 0 to enter Billing phase:4
Number to order:4

Enter your choice(s), or use 0 to enter Billing phase:5
Number to order:5

Enter your choice(s), or use 0 to enter Billing phase:0
Are you Staff? (0 for no, 1 for yes):0
The orders were:
De Anza Burger X1	$5.25
Bacon Cheese Burger X2	$11.50
Mushroom Swiss Burger X34	$202.30
Western Burger X4	$23.80
Don Cali Burger X5	$29.75
Pretax:$272.60
Post tax:$272.60

*/
