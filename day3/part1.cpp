//compile with 'g++ -o day3part1 part1.cpp'
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int hits(int leftInc, int topInc, int length, int width, vector<char> trees[]) {
    int hits = 0;
    int left = 0;
    int top = 0;
    char spot;
    while(top != length-1) {
        left += leftInc;
        left = (left % width);
        top += topInc;
        spot = trees[top][left];
        //cout << "(" << left << ", " << top << "): " << spot << endl;
        if(spot == '#') {
            hits++;
        }
    }
    return hits;
}

int main(int argc, char *argv[]) {
    int length = 323;
    vector<char> trees[length];
    if(argc == 2) {
        ifstream treeList;
        treeList.open(argv[1]);
        if(!treeList.is_open()) {
            cerr << "Error: could not open file " << argv[1] << endl;
            return 0;
        }
        string line;
        int lineAt = 0;
        int width;
        while(getline(treeList, line)) {
            width = 0;
            for(int i = 0; i < line.length(); i++) {
                trees[lineAt].push_back(line[i]);
                width++;
            }
            lineAt++;
        }
        treeList.close();
        cout << "Answer: " << endl;
        cout << hits(3, 1, length, width, trees) << endl;
    }
}