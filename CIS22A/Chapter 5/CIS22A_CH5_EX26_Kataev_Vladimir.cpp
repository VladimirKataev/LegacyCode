/*Written By Vladimir Kataev*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

double getPosDoubleResponse(string);

int main(){
        int months = getPosDoubleResponse("How many months ago was your account established");
        double interest = getPosDoubleResponse("What is the interest rate of your account");
        interest /= 100; interest += 1; //To be used in actual maths, turning 17% interest to 1.17
        double balance = getPosDoubleResponse("What was the starting balance");
        double in, out;
	ofstream writer;
	writer.open("report.txt");


        for(int a = 0; a < months; a++){
                cout << "--------- Month " << a << endl;
                writer << "--------- Month " << a << endl;
                in = getPosDoubleResponse("What deposits did you make");
                out = getPosDoubleResponse("What withdrawals did you make");
                balance += in - out;
		writer << "IN:" << in << " OUT:" << out << endl;
                if(balance < 0){
                        cout << "Out of money, account closed\n";
                        writer << "Out of money, account closed\n";
			writer.close();
                        return 0;
                }
                balance *= ((interest - 1)/12)+1;
                cout << "Your balance is " << balance<<endl;
                writer << "Your balance is " << balance<<endl;
        }



}


double getPosDoubleResponse(string prompt){ // As function prints end after cin, no \n needed
        double response = 0;
        do{
                if(response < 0)
                        cout << "Enter a Positive Number\n";
                cout << prompt << ":";
                cin >> response;
        }while(response < 0);
        return response;
}

/*
How many months ago was your account established:2
What is the interest rate of your account:100
What was the starting balance:20
--------- Month 0
What deposits did you make:0
What withdrawals did you make:0
Your balance is 21.6667
--------- Month 1
What deposits did you make:20
What withdrawals did you make:10
Your balance is 34.3056

*/
