#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include "daytwopart2.h"
using namespace std;

DayTwo::DayTwo() {

}

DayTwo::~DayTwo() {

}

void DayTwo::addLine(string toAdd) {
    istringstream iss(toAdd);
    vector<string> rule{istream_iterator<string>{iss},
        istream_iterator<string>{}
    };
    if(isdigit(rule[0].substr(1,1)[0])) {
        numStart.push_back(rule[0].substr(0,2));
        if(isdigit(rule[0].substr(4,1)[0])) {
            numEnd.push_back(rule[0].substr(3,2));
        } else {
            numEnd.push_back(rule[0].substr(3,1));
        }
    } else {
        numStart.push_back(rule[0].substr(0,1));
        if(isdigit(rule[0].substr(3,1)[0])) {
            numEnd.push_back(rule[0].substr(2,2));
        } else {
            numEnd.push_back(rule[0].substr(2,1));
        }
    }
    rules.push_back(rule[1].substr(0,1));
    pass.push_back(rule[2]);
    len++;
}

void DayTwo::printKey(int line) {
    cout << "between " << numStart[line] << " to " << numEnd[line] << " of " << rules[line] << endl;
}

void DayTwo::printPassword(int line) {
    cout << "password " << pass[line] << endl;
}

int DayTwo::getStart(int line) {
    return stoi(numStart[line]) - 1;
}

int DayTwo::getEnd(int line) {
    return stoi(numEnd[line]) - 1;
}

int DayTwo::numFound(string password, char toFind) {
    int count = 0;
    for(int i = 0; i < password.size(); i++) {
        if(password[i] == toFind) {
            count++;
        }
    }
    return count;
}

int DayTwo::findNum() {
    int match = 0;
    for(int i = 0; i < len; i++) {
        int first = getStart(i);
        int second = getEnd(i);
        if(pass[i][first] == rules[i][0] xor pass[i][second] == rules[i][0]) {
            match++;
        }
    }
    return match;
}

int DayTwo::size() {
    return len;
}
