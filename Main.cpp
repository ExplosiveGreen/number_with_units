#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
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
    cout << "insert unit (format example: 1.1 km or 1.1[km]): ";
    cin >> a;
    cout << "insert another unit (format example: 100 cm or 100[cm]): ";
    cin >> b;
    cout << "choose an operator: (+,-,==,!=,<=,>=,<,>,+=,-=,*=,++,--,<<,exit)" << endl;
    cin >> operat;
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
    else if(operat=="exit"){
        break;
    }
    }
    return 0;
}
