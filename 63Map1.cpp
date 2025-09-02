#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, string> student;
    map<int, string> student1 {{1,"Fahim"}, {2,"Silvi"}, {3,"Rakib"}};
    // use [] operator to add elements
    student[1] = "Afifa";
    student[2] = "Arpon";
    // use insert() method to add elements
    student.insert(make_pair(3, "Sakib"));
    student.insert(make_pair(4, "Mithu"));
    map<string, int> marks;
    marks.insert({"Fahim", 85});
    marks.insert({"Silvi", 90});
    // add elements with duplicate keys
    student[5] = "Samiha";
    student[5] = "Anannya";

    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

// declare map iterator
    map<int, string>::iterator iter;
    // use iterator to display map elements
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }
    iter = student.find(2);
    cout << iter->first << " - " << iter->second << endl;
    cout << student.size() << endl;    // Output: 2
    student.clear();
    cout << student.size() << endl;    // Output: 0
    return 0;
}