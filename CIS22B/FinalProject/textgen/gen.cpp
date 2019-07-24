#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream output("out.txt");
	string tmp;

	if(!output){
		cout << "issues";
		return 1;
	}
	for(int m = 0; m < 2; m++){
		cout << "enter ISBN:";getline( cin, tmp);
		output <<tmp << "|";
                cout << "enter Title:"; getline(cin, tmp);
                output <<tmp << "|";
                cout << "enter Author:"; getline(cin, tmp);
                output <<tmp << "|";
								cout << "enter Publisher:"; getline(cin, tmp);
                output <<tmp << "|";
                cout << "enter Quantity:"; getline(cin, tmp);
                output <<tmp << "|";
                cout << "enter Wholesale cost:"; getline(cin, tmp);
                output <<tmp << "|";
                cout << "enter Retail Price:"; getline(cin, tmp);
                output <<tmp << "|";
								cout << "enter Published:"; getline(cin, tmp);
                output <<tmp << "|";
                cout << "enter Date added:"; getline(cin, tmp);

                output <<tmp;
		output << endl;
	}


	output.close();
	return 0;
}
