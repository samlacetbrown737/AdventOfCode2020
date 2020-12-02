#include <iostream>
#include <fstream>
#include <vector>
#include "daytwopart2.h"

using namespace std;
int main(int argc, char *argv[]) {
    DayTwo *list = new DayTwo;

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
            list->addLine(line);
        }
        intList.close();
        cout << "Answer: " << endl;
        cout << list->findNum() << endl;
    }
}