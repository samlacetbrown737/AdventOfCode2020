#include <iostream>
#include <vector>
#include "day1part1.h"
using namespace std;

DayOne::DayOne() {
    ints.push_back(0);
}

DayOne::~DayOne() {

}

void DayOne::addInt(int toAdd) {
    ints.push_back(toAdd);
    len++;
}

void DayOne::printAll() {
    cout << "Full list: " << endl;
    for (vector<int>::const_iterator i = ints.begin(); i != ints.end(); i++) {
            cout << *i << endl;
    }
}

int DayOne::size() {
    return len;
}

int DayOne::findMatch(int goal) {
    for(int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(ints[i]+ints[j] == goal) {
                cout << "a: " << ints[i] << endl;
                cout << "b: " << ints[j] << endl;
                return ints[i]*ints[j];
            }
        }
    }
    return 0;
}