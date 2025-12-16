// files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    {
        std::ifstream ifs("file.txt");
        if (!ifs.is_open()) {
            return -1;
        }
        int a,b;
        ifs >> a;
        //cout << ifs.tellg();
        ifs >> b;
        cout << ifs.tellg()<<" "<<b;
    }
    
}


