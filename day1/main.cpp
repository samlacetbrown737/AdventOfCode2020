#include <iostream>
#include <fstream>
#include <vector>
#include "day1part1.h"

using namespace std;
int main(int argc, char *argv[]) {
    DayOne *list = new DayOne;

    vector<int> ints;
    if(argc == 2) {
        ifstream intList;
        intList.open(argv[1]);
        if(!intList.is_open()) {
            cerr << "Error: could not open file " << argv[1] << endl;
            return 0;
        }
        string line;
        while(getline(intList, line)) {
            list->addInt(stoi(line));
        }
        intList.close();
        list->printAll();
        cout << "Answer: " << endl;
        cout << list->findMatch(2020) << endl;
    }
}