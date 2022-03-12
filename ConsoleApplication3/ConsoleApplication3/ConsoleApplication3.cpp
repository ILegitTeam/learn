#include <iostream>

using namespace std;

int firstSimpleNum(int fnum, int lnum) {
    int simpleNum = 0;
        for (int i = fnum; i < lnum; i++) {
            bool isSimple = true;
            for (int j = 2; j < lnum; j++) {
                if (i == j) { j++; }
                if (i % j == 0) { isSimple = false; }
            }
            if (isSimple) { simpleNum = i; break; }
        }
        return simpleNum;
}
int simpleNumCount(int fnum, int lnum) {
    int sizeOfBuffer = lnum / 4;
    int* buffer = new int[sizeOfBuffer];
    buffer[0] = firstSimpleNum(fnum, lnum);
    int count = 1;
    bool isSimple;
    for (int i = fnum; i < lnum; i++) {
        isSimple = true;
        for (int j = 0; j < sizeOfBuffer; j++) {
            if (i % buffer[j] == 0 && buffer[j] > 0) { isSimple = false; }
       }
        if (isSimple) { buffer[count] = i; count++; }
    }

    return count;
}
int main()
{
    cout << simpleNumCount(2, 100000);
}