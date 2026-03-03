#include <iostream> 
#include <string>

using namespace std; 

int a , b; //a 1 = the number of white // b = lenght of strip // 0 is black strip

void print(string s , int cnt , bool ok) {
    //cout << s << " " << cnt << "\n";

    if (cnt > a) ok = false;
    if (cnt == a) ok = true;

    if (s.length() == b) {
        if (ok) {
            cout << s << "\n";
        }
        return;
    }
    
    print(s+"0" , cnt , ok);
    print(s+"1" , cnt+1 , ok);

}

int main() {
    cin >> a >> b;
    print("" , 0 , false);

}
