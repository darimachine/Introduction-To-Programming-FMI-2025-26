```c++

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*{
        std::ifstream ifs("file.txt");
        int a, b, c;
        ifs >> a >> b >> c;
        cout << a << b << c;
    }*/


    {
        std::ofstream ofs("file.txt");
        if(!ofs.is_open()) {
            std::cout<<"Error"<<std::endl;
            return -1;
        }
        bool isPlayer1Turn = 1;
        ofs << isPlayer1Turn << endl;
        int rowSize = 8;
        int colSize = 8;
        ofs << rowSize << " " << colSize<<endl;
        char matrix[8][8] = {
            {'1','*','*','*','*','*','*','*'},
            {'*','*','.','.','.','.','.','.'},
            {'*','.','*','.','.','.','.','.'},
            {'*','.','.','*','.','.','.','.'},
            {'*','.','.','.','*','.','.','.'},
            {'*','.','.','.','.','*','.','.'},
            {'*','.','.','.','.','.','*','.'},
            {'*','.','.','.','.','.','.','*'},
        };
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                ofs << matrix[i][j];
            }
            ofs << endl;
        }
    }
    {
        int rowSize;
        int colSize;
        bool isPlayer1Turn;
        char matrix[8][8];
        std::ifstream ifs("file.txt");
        ifs >> isPlayer1Turn;
        ifs >> rowSize >> colSize;
        ifs.ignore(1024,'\n');

        for (int i = 0; i < rowSize; i++)
        {
            char buffer[1024];
            ifs.getline(buffer, 1024);
            for (int j = 0; j < colSize; j++) {
                matrix[i][j]=buffer[j];
            }
        }
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                cout << matrix[i][j]<<" ";
            }
            cout << endl;
        }
        
    }
    
    
}



```