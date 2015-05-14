#include <map>
#include <string>
#include <iostream>
 
using namespace std;

int main() {
    map<string, string> phone_book;
    phone_book["Sally Smart"] = "555-9999";
    phone_book["John Doe"] = "555-1212";
    phone_book["J. Random Hacker"] = "553-1337";


    cout << phone_book["John Doe"] << endl;

    string saludo;

    saludo = "hola";

    cout << saludo << endl;

    return 0;
}