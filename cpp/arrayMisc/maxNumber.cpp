/*

 Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.

*/


#include <iostream>
#include <cstdlib>

using namespace std;

/* bitwise abs()
int absbit32(int x, int y){
     int sub = x - y;
     int mask = (sub >> 31);
     return (sub ^ mask) - mask;        
}
*/

int max(int x, int y){
     return (x + y + abs(x-y))/2;        
}
  
int min(int x, int y){
     return (x + y - abs(x-y))/2;
}

int main() {
    int n1, n2;

    cout << "Enter number: ";
    cin >> n1;
    cout << "Enter another number: ";
    cin >> n2;

    cout << "Max: " << max(n1, n2) << endl;
    cout << "Min: " << min(n1, n2) << endl;

}

