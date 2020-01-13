#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char** argv){
	ofstream writer;
	string filename;
	for(int i = 1; i <= 18; i++){	//for every relevant file
		filename = "CIS22A_CH5_ASSIGNMENT";
		filename += to_string(i);
		filename += "_Kataev_Vladimir.cpp";
		writer.open(filename.c_str());
		if(!writer){
			cout << "error getting " << filename << endl;
			break;
		}
		writer << "/"<<"*"<< "\tWritten By Vladimir Kataev\n";
		writer << "Does the specified assignment\n*/\n";
		writer << "#include<iostream>			\n";
		writer << "#include<fstream>			\n";
		writer << "#include<string>			\n";
		writer << "using namespace std;			\n";
		writer << "int main(){				\n";
		writer << "\t					\n";
		writer << "\treturn 0;				\n";
		writer << "}	\n";


		writer.close();
	}



	return 0;
}
