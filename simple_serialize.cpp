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

    // Write values vector data to file.
    ofstream output;
    output.open("example.txt", ios::out | ios::binary);
    for(int i = 0; i < values.size(); i++) {
        output << " " << values[i];
    }
    output << endl;
    output.close();

    values.clear();

    // Read values vector data from file.
    ifstream input;
    input.open("example.txt", ios::in | ios::binary);
    while(input.good()) {
        uint16_t i;
        if(input >> i) {
            values.push_back(i);
        }
    }
    input.close();

    // Write values vector data to stdout.
    for(int i = 0; i < values.size(); i++) {
        cout << " " << values[i];
    }
    cout << endl;

    return 0;
}
