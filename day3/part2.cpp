//compile with 'g++ -o day3 part2.cpp'
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
        int one = hits(1, 1, length, width, trees);
        int two = hits(3, 1, length, width, trees);
        int three = hits(5, 1, length, width, trees);
        int four = hits(7, 1, length, width, trees);
        int five = hits(1, 2, length, width, trees);
        long long answer = one * two  * three * four;
        cout << "1: " << one << endl;
        cout << "2: " << two << endl;
        cout << "3: " << three << endl;
        cout << "4: " << four << endl;
        cout << "5: " << five << endl;
        cout << "Answer: " << answer * five << endl;
    }
}