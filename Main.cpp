#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h> 
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

void get_file(string& str){
    cout << "insert input file name, enter nothing for filename.txt (default): ";
    if(getline(cin, str))
    {
        if(str.empty())
        {
            str = "filename.txt";
        }
    }
    else
    {
        cout << "Input failed - no more input?" << endl;
    }
}
void randomChoise(){
    srand (time(0));
    const vector<string>units={"km","m","cm","kg","g","ton","hour","min","sec","USD","ILS"};
    const vector<string>operats={"+","-","==","!=","<=",">=","<",">","+=","-=","*=","++","--","<<","*"};
    string operat;
    for (int i=0;i<20;i++){
     int b=rand() % 15;
     operat=operats.at(b);
     double c=rand()/1000.0;
     double d=rand()/1000.0;
     if(b<14){
       int a1= rand() % 11;
       int b1= rand() % 11;
       NumberWithUnits a{c,units.at(a1)};
       NumberWithUnits b{d,units.at(b1)};  
       if(operat == "+"){
        cout << a << operat << b << '=' << a+b << endl;
    }
    else if(operat == "-"){
        cout << a << operat << b << '=' << a-b << endl;
    }
    else if(operat == "=="){
        cout << a << operat << b << '=' << (a==b) << endl;
    }
    else if(operat == "!="){
        cout << a << operat << b << '=' << (a!=b) << endl;
    }
    else if(operat == "<="){
        cout << a << operat << b << '=' << (a<=b) << endl;
    }
    else if(operat == ">="){
        cout << a << operat << b << '=' << (a>=b) << endl;
    }
    else if(operat == "<"){
        cout << a << operat << b << '=' << (a<b) << endl;
    }
    else if(operat == ">"){
        cout << a << operat << b << '=' << (a>b) << endl;
    }
    else if(operat == "+="){
        cout << a << operat << b << '=' << (a+=b) << endl;
    }
    else if(operat == "-="){
        cout << a << operat << b << '=' << (a-=b) << endl;
    }
    else if(operat == "*="){
        cout << a << operat << b << '=' << (a*=b) << endl;
    }
    else if(operat == "++"){
        cout << a << operat << '=' << a++ << ' ' << b << '=' << b++ << endl;
    }
    else if(operat == "--"){
        cout << a << operat << '=' << a-- << ' ' << b << '=' << b-- << endl;
    }
    else if(operat == "<<"){
        cout << "first: " << a << " second: " << b << endl;
    }
     }
      else{
           int a1= rand() % 11;
       NumberWithUnits b1{c,units.at(a1)};
         cout << a << operat << d<<"=" << a*d<< endl;
      }
     
    }
    
}
int main() {
    string file;
    get_file(file);
    
    ifstream units{file};
    while(units.fail()){
        cout << "reading from " << file << " failed." << endl;
        get_file(file);
        units.open(file);
    }
    NumberWithUnits::read_units(units);
    NumberWithUnits a;
    NumberWithUnits b;
    string operat;
    cout << "file found! " << endl;
    while(true){
    cout << "choose an operator: (+,-,==,!=,<=,>=,<,>,+=,-=,*=,++,--,<<,*,exit)" << endl;
    cin >> operat;
    if(operat == "+"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << a+b << endl;
    }
    else if(operat == "-"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << a-b << endl;
    }
        else if(operat == "*"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "Enter double ";
     double d;
    cin >> d;
        cout << a << operat << d << '=' << a*d << endl;
    }
    else if(operat == "=="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a==b) << endl;
    }
    else if(operat == "!="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a!=b) << endl;
    }
    else if(operat == "<="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a<=b) << endl;
    }
    else if(operat == ">="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a>=b) << endl;
    }
    else if(operat == "<"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a<b) << endl;
    }
    else if(operat == ">"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a>b) << endl;
    }
    else if(operat == "+="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a+=b) << endl;
    }
    else if(operat == "-="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a-=b) << endl;
    }
    else if(operat == "*="){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << b << '=' << (a*=b) << endl;
    }
    else if(operat == "++"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << '=' << a++ << ' ' << b << '=' << b++ << endl;
    }
    else if(operat == "--"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << a << operat << '=' << a-- << ' ' << b << '=' << b-- << endl;
    }
    else if(operat == "<<"){
            cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
        cout << "first: " << a << " second: " << b << endl;
    }
    else if(operat=="exit"){
        break;
    }
    }
    return 0;
}
