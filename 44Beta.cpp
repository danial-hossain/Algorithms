#include <bits/stdc++.h>
using namespace std;

int main() {
 

    int t; 
    cin >> t;
    string rest;
    getline(cin, rest);

    while (t--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string batch;
        int key;
        char colon;

        ss >> batch >> key >> colon; 

        int originalKey = key;                   
        int shift = (key % 26 + 26) % 26;            

        string message;
        getline(ss, message);
        if (!message.empty() && message[0] == ' ') 
            message = message.substr(1);             

        
        for (char &c : message) {
            if (isupper(c)) 
                c = 'A' + (c - 'A' + 26 - shift) % 26;
            else if (islower(c)) 
                c = 'a' + (c - 'a' + 26 - shift) % 26;
        }

        cout << batch << " " << originalKey << ": " << message << "\n";
    }
}
