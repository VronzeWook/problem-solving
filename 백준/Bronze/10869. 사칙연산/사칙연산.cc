#include <iostream>
using namespace std;
//A+B, A-B, A*B, A/B(몫), A%B(나머지)
int main(){
    cout.precision(10);
    int a, b;
    cin >> a >> b;
    cout << a+b <<endl;
    cout << a-b <<endl;
    cout << a*b <<endl;
    cout << a/b <<endl;
    cout << a%b <<endl;
    
    return 0;
}