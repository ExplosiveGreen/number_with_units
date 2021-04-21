#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>



using namespace std;

namespace ariel{
    class NumberWithUnits{

        public:
        NumberWithUnits(double a, string f){
        }
        static void read_units(ifstream& file);
        NumberWithUnits operator+(const NumberWithUnits& b) const;
        NumberWithUnits& operator+=(const NumberWithUnits& b);
        NumberWithUnits operator+() const;
        NumberWithUnits operator-(const NumberWithUnits& b);
        NumberWithUnits& operator-=(const NumberWithUnits& b);
        NumberWithUnits operator-() const;

        friend bool operator>(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator>=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator<(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator<=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator==(const NumberWithUnits& b1, const NumberWithUnits& b2);
        friend bool operator!=(const NumberWithUnits& b1, const NumberWithUnits& b2);
        
         NumberWithUnits& operator++();
         NumberWithUnits operator++(int dd);
        NumberWithUnits& operator--();
        NumberWithUnits operator--(int dd);

         friend  NumberWithUnits operator* (double b1,const NumberWithUnits& b2);
        
         friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& b);
         friend std::istream& operator>> (std::istream& input , NumberWithUnits& b);
        




    };
}