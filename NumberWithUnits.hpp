#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#define TOLARENCE 0.00001
using namespace std;
namespace ariel{
    
    class NumberWithUnits{
    private:
        double num = 0;
        string unit = "";
    public:
        NumberWithUnits(){}
        NumberWithUnits(const double& number, const string& units);
        ~NumberWithUnits() = default;
        static void read_units(ifstream& stream);
        static double converter(const string& from, const string& to);
        bool operator!() const {
            return num == 0;
        }
        const NumberWithUnits operator-() const {
            return NumberWithUnits{-num, unit};
        }
        const NumberWithUnits operator+() const {
            return NumberWithUnits(+num, unit);
        }
        NumberWithUnits& operator+=(const NumberWithUnits& b);
        NumberWithUnits& operator-=(const NumberWithUnits& b);
        NumberWithUnits& operator*=(const NumberWithUnits& b);
        friend const NumberWithUnits operator*(const NumberWithUnits& b, const double& mul) {
            return NumberWithUnits(b.num * mul, b.unit);
        }
        friend const NumberWithUnits operator*(const double& mul, const NumberWithUnits& b) {
            return NumberWithUnits(b.num * mul, b.unit);
        }
        friend NumberWithUnits operator+(const NumberWithUnits& b1, const NumberWithUnits& b2) ;
        friend NumberWithUnits operator-(const NumberWithUnits& b1, const NumberWithUnits& b2) ;
        friend bool operator==(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator!=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator<=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator>=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator<(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator>(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend std::ostream& operator<< (ostream& output, const NumberWithUnits& b);
        friend std::istream& operator>> (istream& input, NumberWithUnits& b);
        NumberWithUnits& operator++() {
            num++;
            return *this;
        }
        NumberWithUnits& operator--() {
            num--;
            return *this;
        }
        NumberWithUnits operator++(int dd) {
            NumberWithUnits copy = *this;
            num++;
            return copy;
        }
        NumberWithUnits operator--(int dd) {
            NumberWithUnits copy = *this;
            num--;
            return copy;
        }
    };
}