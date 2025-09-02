#include <iostream>
#include <map>
using namespace std;

int main() {
    
    // create a map named student
    map <int, string> student {{1, "AUST"}, {2, "CSE"}, {3, "EEE"}, {4, "ME"}, {5, "IPE"}};

    // create a map iterator
    map <int, string>::iterator iter;
    
    // display initial map values
    cout << "Initial Values:" << endl;
    for(iter = student.begin(); iter != student.end(); ++iter) {
        cout <<iter->first<<" "<< iter->second << ", ";
    }
    
    cout << endl;
    //cout << student[7] << endl;
    cout << student.at(2);
    //cout << student.at(7);
    cout << endl;
    
    // Updating value
    student[0] = "Happy";
    student.at(1) = "By";
    
    // remove a range of elements
    student.erase(student.find(2),student.find(5));

    // display final map values
    cout << "\nFinal Values:" << endl;

    for(iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->second << ", ";
    }
    
    return 0;
}