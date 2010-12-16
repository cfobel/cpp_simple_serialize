#include<iostream>
#include<fstream>
#include<vector>
#include<stdint.h>

using namespace std;


int main(int argc, char** argv) {
    vector<uint16_t> values(10);

    for(int i = 0; i < values.size(); i++) {
        values[i] = i;
    }

    ofstream output;
    output.open("example.txt", ios::out | ios::binary);
    for(int i = 0; i < values.size(); i++) {
        output << " " << values[i];
    }
    output << endl;
    output.close();

    for(int i = 0; i < values.size(); i++) {
        values[i] = 0;
    }

    ifstream input;
    input.open("example.txt", ios::in | ios::binary);
    for(int i = 0; i < values.size(); i++) {
        input >> values[i];
    }
    input.close();

    for(int i = 0; i < values.size(); i++) {
        cout << " " << values[i];
    }
    cout << endl;

    return 0;
}
