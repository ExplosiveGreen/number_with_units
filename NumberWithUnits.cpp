#include "NumberWithUnits.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>



using namespace std;

namespace ariel{


     void NumberWithUnits::read_units(ifstream& infile){}
        NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& b) const{
            return NumberWithUnits{1, "km"};
        }
        NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& b){
            return *this;
        }
        NumberWithUnits NumberWithUnits::operator+() const{
            return NumberWithUnits{1, "km"};
                    }
        NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& b){
            return NumberWithUnits{1, "km"};
                    }
        NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& b){
            return *this;
        }
        NumberWithUnits NumberWithUnits::operator-() const{
            return NumberWithUnits{1, "km"};
                    }

        bool operator>(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        bool operator>=(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        bool operator<(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        bool operator<=(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        bool operator==(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        bool operator!=(const NumberWithUnits& b1, const NumberWithUnits& b2){
            return true;
        }
        
         NumberWithUnits& NumberWithUnits::operator++(){
            return *this;
            }
         NumberWithUnits NumberWithUnits::operator++(int dd){
            return NumberWithUnits{1, "km"};
                        }
        NumberWithUnits& NumberWithUnits::operator--(){
            return *this;
        }
          NumberWithUnits NumberWithUnits::operator--(int dd){
            return NumberWithUnits{1, "km"};
                        }

           NumberWithUnits operator* (double b1,const NumberWithUnits& b2){
                       return NumberWithUnits{1, "km"};
        }
        
          std::ostream& operator<< (std::ostream& output, const NumberWithUnits& b){
            return output;
        }
          std::istream& operator>> (std::istream& input , NumberWithUnits& b){
            return input;
        }
}