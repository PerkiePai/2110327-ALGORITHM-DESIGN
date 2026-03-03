#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int digit , k;

void print(string s , int cnt , bool ok) {
    //cout << s << " " << cnt <<"\n";
    if (s.length() == digit) {
        if (ok) {
            cout << s << "\n";
        }
        return;
    }

    print(s+"0" , 0 , ok);
    if (cnt+1 == k) {
        print(s+"1" , cnt+1 , true);
    } else {
        print(s+"1" , cnt+1 , ok);
    }
    
    
}

int main() {
    cin >> digit >> k;
    print("" , 0 , false);
}

