#ifndef __DAYTWOPARTTWO_H__
#define __DAYTWOPARTTWO_H__

#include <vector>
#include <string>
using namespace std;

class DayTwo {
    public:
        DayTwo();
        ~DayTwo();
        void addLine(string toAdd);
        void printKey(int line);
        void printPassword(int line);
        int findNum();
        int getStart(int line);
        int getEnd(int line);
        int numFound(string password, char toFind);
        int size();
    private:
        vector<string> numStart;
        vector<string> numEnd;
        vector<string> rules;
        vector<string> pass;
        int len;
};

#endif