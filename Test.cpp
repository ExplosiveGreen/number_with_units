#include "doctest.h"
#include <cmath>
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


using namespace ariel;
using namespace std;



TEST_CASE("tests"){
NumberWithUnits n1{1, "km"};
NumberWithUnits n2{100, "m"};    
CHECK((n1+n2)==NumberWithUnits{3.3, "km"});
n1+=NumberWithUnits {1, "km"};
CHECK(n1==NumberWithUnits {4, "km"});
CHECK(+n1==n1);
CHECK(n1-n2==NumberWithUnits {2.7, "km"});
n1-=NumberWithUnits {1, "km"};
CHECK(n1==NumberWithUnits {3, "km"});
CHECK(-n1==NumberWithUnits {-3, "km"});
CHECK(n1>n2);
CHECK(n2<n1);
CHECK(n1>=n2);
CHECK(n2<=n1);
CHECK(n1!=n2);
CHECK(n1++==NumberWithUnits{3, "km"});
CHECK(++n1==NumberWithUnits {5, "km"});
CHECK(n1--==NumberWithUnits {5, "km"});
CHECK(--n1==NumberWithUnits {3, "km"});
double d = 2;
CHECK(d*n1==NumberWithUnits {6, "km"});
CHECK(n2<NumberWithUnits{2, "km"});
CHECK(n2>=NumberWithUnits{0.3, "km"});
CHECK(n2>NumberWithUnits{100, "m"});
CHECK(-n2==NumberWithUnits{-300, "m"});
}