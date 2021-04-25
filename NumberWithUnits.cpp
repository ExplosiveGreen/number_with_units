#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;
struct converter{
    unordered_map<string, unordered_map<string, double>> convert;
    unordered_set<string> units;
    int size() const{
        return units.size();
    }
    void addUnit(const string& v){
        units.insert(v);
    }
    void addConvert(const string& u, const string& v, double w)
    {
        addUnit(u);
        addUnit(v);
        convert[u][v] = w;
        convert[v][u] = 1/w;
    }
    double getConvert(const string& u, const string& v){
        if(units.find(u)!=units.end() && units.find(v)!=units.end()){
            return convert[u][v];
        }
        return -1;
    }
};

static converter g;

double NumberWithUnits::converter(const string& from, const string& to){
    stack<string> s;
    unordered_set<string> visited;
    unordered_map<string, double> con;
    con.clear();
    s.push(from);
    con[from] = 1;
    while (!s.empty())
    {
        string cur = s.top();
        s.pop();
        if(visited.find(cur)==visited.end()){
            visited.insert(cur);
            if(cur == to){
                if(g.getConvert(from, to) <= 0 && from != to){
                    g.addConvert(from, to, con[cur]);
                }
                return con[cur];
            }
            for(auto& n : g.convert[cur]){
                string v = n.first;
                if(visited.find(v)==visited.end()){
                    double w = n.second;
                    con[v] = (w * con[cur]);
                    s.push(v);
                }
            }
        }
    }
    return -1;
}
void NumberWithUnits::read_units(std::ifstream& stream){
    string line;
    double leftDouble = 0;
    double rightDouble = 0;
    string leftString;
    string rightString;
    string equation_sign;
    while(getline(stream, line)){
        std::stringstream linestream(line);
        linestream >> skipws >> leftDouble;
        linestream >> skipws >> leftString;
        linestream >> skipws >> equation_sign;
        if(equation_sign != "="){
            throw invalid_argument("bad format int line: " + line);
        }
        linestream >> skipws >> rightDouble; 
        linestream >> skipws >> rightString;
        
        g.addConvert(leftString, rightString, leftDouble / rightDouble);
        g.addConvert(rightString, leftString, rightDouble / leftDouble);
 
    }
}
NumberWithUnits::NumberWithUnits(const double& number, const string& units): num(number),unit(units){
    if((g.units.find(units)==g.units.end())){
        throw invalid_argument("unit named: ["+units+"] have not been initialized");
    }
}
NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& b) {
    double converted = NumberWithUnits::converter(this->unit, b.unit);
    if(converted < 0){
    throw invalid_argument("Units do not match - ["+b.unit+"] cannot be converted to ["+this->unit+"]");
    }
    this->num += converted * b.num;
    return *this;

}
NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& b) {
    double converted = NumberWithUnits::converter(this->unit, b.unit);
    if(converted < 0){
    throw invalid_argument("Units do not match - ["+b.unit+"] cannot be converted to ["+this->unit+"]");
    }
    this->num -= converted * b.num;
    return *this;

}
NumberWithUnits& NumberWithUnits::operator*=(const NumberWithUnits& b) {
    double converted = NumberWithUnits::converter(this->unit, b.unit);
    if(converted < 0){
    throw invalid_argument("Units do not match - ["+b.unit+"] cannot be converted to ["+this->unit+"]");
    }
    this->num *= converted * b.num;
    return *this;

}
NumberWithUnits ariel::operator+(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    double converted = NumberWithUnits::converter(b1.unit, b2.unit);
    if(converted < 0){
            throw invalid_argument("Units do not match - ["+b2.unit+"] cannot be converted to ["+b1.unit+"]");
    }
    return NumberWithUnits(b1.num + converted * b2.num, b1.unit);

}
NumberWithUnits ariel::operator-(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    return b1 + -b2;

}
bool ariel::operator==(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    double converted = NumberWithUnits::converter(b1.unit, b2.unit);
    if(converted < 0){
            throw invalid_argument("Units do not match - ["+b2.unit+"] cannot be converted to ["+b1.unit+"]");
    }
    return abs(b1.num - converted * b2.num) <= TOLARENCE;
}

bool ariel::operator!=(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    return !(b1 == b2);
}

bool ariel::operator<=(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    double converted = NumberWithUnits::converter(b1.unit, b2.unit);
    if(converted < 0){
            throw invalid_argument("Units do not match - ["+b2.unit+"] cannot be converted to ["+b1.unit+"]");
    }
    
    return b1.num < converted * b2.num || b1 == b2;
}

bool ariel::operator>=(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    double converted = NumberWithUnits::converter(b1.unit, b2.unit);
    if(converted < 0){
            throw invalid_argument("Units do not match - ["+b2.unit+"] cannot be converted to ["+b1.unit+"]");
    }
   
    return b1.num > converted * b2.num || b1 == b2;
}

bool ariel::operator<(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    return !(b1 >= b2);
    
}
bool ariel::operator>(const NumberWithUnits& b1, const NumberWithUnits& b2) {
    return !(b1 <= b2);

}
ostream& ariel::operator<< (ostream& output, const NumberWithUnits& b) {
    return (output <<  b.num << '[' << b.unit << ']');
}
istream& ariel::operator>> (istream& input, NumberWithUnits& b) {
    double num=0;
    string unit;
    string output;
    int bb=0;
    input>>num;
    input>>output;
    while(output[0]=='[' &&(output[output.size()-1]!=']'||bb!=0)){
        bb=0;
        string temp;
        input>>temp;
        output+=temp;
        for(u_long i=0;i<output.size();i++){
            if(output.at(i)=='[')
            {
                bb++;
            }
            else if(output.at(i)!=' '){
                break;
            }
        }
        for(u_long i=output.size()-1;i>=0;i--){
            if(output.at(i)==']')
            {
                bb--;
            }
            else if(output.at(i)!=' '){
                break;
            }
        }
    }
    for(u_long i=0;i<output.size();i++){
        if(!(output.at(i)==' '||output.at(i)=='\0'||output.at(i)==']'||output.at(i)=='[')){
            unit+=output.at(i);
        }
    }
    b.unit=unit;
    b.num=num;
    if(g.units.find(b.unit)==g.units.end()){
        throw invalid_argument{"unit named: ["+b.unit+"] have not been initialized"};
    }
    return input;
}

    
