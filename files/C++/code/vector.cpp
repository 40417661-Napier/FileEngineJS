#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string input;
    int inputAsInt, accum = 0;
    vector<int> mydata;
    while(true) {
        cout << "Enter a value (N to quit) : " << endl;
        cin >> input;
        if (input == "N") {
            break;
        }
        inputAsInt = atoi(input.c_str());
        mydata.push_back(inputAsInt);
    }

    cout << "size of vector is : " << mydata.size() << endl;

    // method one for iterating over an array
    for (unsigned int i = 0; i < mydata.size(); i++) {
        accum += mydata[i];
    }
    cout << "total value is : " << accum << endl;

    // method two for iterating over an
    accum = 0;
    for (unsigned int i = 0; i < mydata.size(); i++) {
        accum += mydata.at(i);
    }
    cout << "total value is : " << accum << endl;

    // method three for iterating over an array
    accum = 0;
    vector<int>::iterator Iter;
    for (Iter = mydata.begin(); Iter != mydata.end(); Iter++) {
        accum += *Iter;
    }
    cout << "total value is : " << accum << endl;

    // method four for iterating over an array
    accum = 0;
    for (auto a : mydata) {
        accum += a;
    }
    cout << "total value is : " << accum << endl;

    return 0;
}
