#include <iostream>
using namespace std;

int main() {
    int scale = 10;       // 1 decimal place
    int a = 1;            // represents 0.1
    int b = 2;            // represents 0.2
    int c = a + b;        // integer addition

    cout << "Fixed-point sum = " << (double)c / scale << endl;
    return 0;
}
