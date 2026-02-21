# include <iostream>
// # include <cstdlib>
# include <limits>
// # include <iomanip>
// # include <cmath>
// # include <climits>

int main(){
    double a = std::numeric_limits<double>::quiet_NaN();
    printf("a: %f\n", a);
}