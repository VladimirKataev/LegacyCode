#include "Book.h"

#include "Date.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


Book* readFile(string fileName){  //----MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED
  Book* ans = new Book[128];
  int tmp = 0;
  ifstream reader;
  reader.open(fileName);
  string parseText = "";
  while(getline(reader, parseText)){
    ans[tmp++] = Book(parseText);
  }
  reader.close();
  return ans;



}

void writeFile(string fileName, Book* data){
  ofstream writer;
  writer.open(fileName);
  for(int a = 0; a < 128; a++)
    writer << data[a].toString() << endl;
  writer.close();
 delete [] data;
};

int main(){
//  Book a("1234567890123|Metro 2033|Dmitry G|4A Games|30000|5.49|14.99|13102007|06082033");
  Book* inv = readFile("DATA.txt");

  for(int a = 0; a < 128; a++){
    cout << inv[a].toString() << endl;
  }

  writeFile("proof.txt", inv);
  //delete(inv);
  return 0;
}


//------------REMNANTS OF DEBUGGING, MOSTLY NOSTALGIA
/*
cout << a.getISBN() << endl <<
a.getTitle() << endl <<
a.getAuthor() << endl <<
a.getPublisher() << endl <<
  to_string(a.getQuantity()) << endl <<
    to_string(a.getRetailPrice()) << endl <<
      to_string(a.getwholeSaleCost()) << endl <<
        a.getPublished().toString() << endl <<
          a.getAdded().toString() << endl;
        */
