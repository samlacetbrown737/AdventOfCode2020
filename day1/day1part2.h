#ifndef __DAYONEPARTONE_H__
#define __DAYONEPARTONE_H__

#include <vector>
using namespace std;

class DayOne {
    public:
        DayOne();
        ~DayOne();
        void addInt(int toAdd);
        void printAll();
        int findMatch(int goal);
        int size();
    private:
        vector<int> ints;
        int len;
};

#endif