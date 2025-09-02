#include <bits/stdc++.h>
using namespace std;

int main()
{
    class employee
    {
    public:
        string name;
        int age;
        int salary;
    };

    map<int, employee> em;

    employee e1 = {"Danial", 26, 4000};
    employee e2 = {"Faysal", 22, 5000};
    employee e3 = {"ElDel", 23, 6000};

    em.insert({1, e1});
    em.insert({2, e2});
    em.insert({3, e3});

    int search;
    cout << "Enter employee ID to search: ";
    cin >> search;

    // Option 1: Using find()
    auto it = em.find(search);
    if (it != em.end())
    {
        cout << "Salary: " << it->second.salary << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
    }

    // Option 2: Using [] (only works if you want to assume the ID exists)
    cout << "Salary: " << em[search].salary << endl; // Warning: creates default employee if not found

    vector<employee> v;
    for (auto &p : em)
    {
        v.push_back(p.second);
    }

    sort(v.begin(), v.end(), [](const employee &a, const employee &b)
         { return a.age < b.age; });

    for (auto &e : v)
    {
        cout << e.name << " " << e.age << " " << e.salary << endl;
    }

    return 0;
}
