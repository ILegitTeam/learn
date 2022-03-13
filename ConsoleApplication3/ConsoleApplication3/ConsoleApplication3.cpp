#include <iostream>
#include <string>
#include <fstream>

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
    setlocale(LC_ALL, "ru");
    int fnum = 0;
    int lnum = 0;
    string infName = "in.txt";
    string outfName = "out.txt";

    ifstream fin;
    fin.open(infName);
    if (fin.is_open()) {
        cout << "Файл открыт" << endl;
        fin >> fnum;
        fin >> lnum;
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
    fin.close();

    ofstream fout;
    fout.open(outfName);
    if (fout.is_open()) {
        fout << simpleNumCount(fnum, lnum);;
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
    fout.close();
}