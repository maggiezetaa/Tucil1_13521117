#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "function.cpp"
using namespace std;

char operation[4];
double value[4];
//*****************************************************************Program Utama********************************************************************
int main(int argc, char const *argv[]){
    bool exit = false;
    while(!exit)
    {   int input;
        int start;
        cout << "****Tekan 1 untuk bermain, atau 2 keluar dari 24Game Solver ini ****" << endl;
        cout << "1.Solve" << endl;
        cout << "2.Keluar" << endl;
        cin >> start;
        if(start == 1)
        {
            cout << "Pilih jenis Input: " << endl;
            cout << "1. Random " << endl;cout << "2. Input user" << endl;cin >> input;
            srand(time(0));
            if(input == 1){
                for(int i = 0; i < 4; i++){
                    value[i] = (rand()%12) + 1;}}
            else if(input == 2){inputUser(value);}    
            int output;cout << "output" << endl;cout << "1.Terminal" << endl; cout << "2.Text" << endl;
            cin >> output;
            clock_t startTime = clock();
            ofstream myFile;
            if(output == 2){
                string namaFile;string file;cout << " file : " << endl;cin >> namaFile;
                file = "../test/" + namaFile;
                myFile.open(file);}
            operation[0] = '+';operation[1] = '-';operation[2] = '*';operation[3] = '/';
            selectionSort(value,4);
            int count = 0;int hasil = 24; 
            if(value[0] != value[1] && value[0] != value[2] && value[0] != value[3] && value[1]!=value[2] && value[1]!=value[3] && value[2]!=value[3]){
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        for(int k = 0; k < 4; k++){
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] << value[3] << ")" << endl;}
                                else if (output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << value[3] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << value[3] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << value[2] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << value[2] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << value[2] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << value[2] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << value[3] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << value[3] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << value[1] << endl;}}
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << value[1] << endl;}}
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] << value[1] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] << value[1] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] << value[2] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] << value[2] << endl; }}
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] << value[2] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << value[2] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << value[2] << "))" << endl;}}
                            //Permutasi 6
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" << operation[k] << value[1] << endl; }}
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] << value[1] << endl;}}
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] << value[1] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] << value[1] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" << operation[k] << value[3] << endl; }}
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] << value[3] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] << value[3] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] << value[2] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] << value[2] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] << value[2] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] << value[2] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] << value[3] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]<< value[3] << endl; }}
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << value[3] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << value[3] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0){
                                count++;                        
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << value[0] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << value[0] << endl; }}
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << value[0] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << value[0] << endl;}}
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << value[0] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << value[0] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] << value[0] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] << value[0] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] << value[0] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] << value[0] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" << operation[k] << value[0] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" << operation[k] << value[0] << endl; }}
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] << value[0] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] << value[0] << endl;}}
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] << value[0] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] << value[0] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << value[0] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << value[0] << ")" << endl;} }
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] << value[0] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] << value[0] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" << operation[k] << value[2] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" << operation[k] << value[2] << endl; }}
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" << operation[k] << value[2] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" << operation[k] << value[2] << endl;}}
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" << operation[k] << value[2] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" << operation[k] << value[2] << ")" << endl;}}
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  << operation[k] << value[2] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  << operation[k] << value[2] << "))" << endl;}}
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] << value[3] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] << value[3] << endl; }}
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  << operation[k] << value[3] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  << operation[k] << value[3] << "))" << endl;}
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] << value[1] << endl; }}
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] << value[1] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] << value[1] << endl;}}
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] << value[1] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] << value[1] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] << value[1] << "))" << endl;}
                                else if(output == 2){
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] << value[1] << "))" << endl;} }
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" << operation[k] << value[3] << endl; }
                                else if(output == 2){
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" << operation[k] << value[3] << endl; }}
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" << operation[k] << value[3] << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" << operation[k] << value[3] << endl;}}
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0){
                                count++;
                                if(output == 1){
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0){
                                count++;
                                if(output == 1){
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" << operation[k] << value[3] << ")" << endl;}
                                else if(output == 2){
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" << operation[k] << value[3] << ")" << endl;}}
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                            }
                            //Permutasi 16
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 17
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[0],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[0],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }                      
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[0],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[0],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[0],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 18
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[1],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[1],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))"  
                                    << operation[k] << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[1],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[1],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[1],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                            
                            }
                            //Permutasi 19
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }  
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)  
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 20
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[1] << ")" << endl;
                                }     
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                            }
                            //Permutasi 21
                            if(evaluate((evaluate(evaluate(value[3],value[1],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[1],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[1],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {   
                                    cout << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[1],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[1],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[0] << "))" << endl;
                                }           
                            }

                            //Permutasi 22
                            if(evaluate((evaluate(evaluate(value[3],value[1],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[1],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[1],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[1],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[1],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }

                            //Permutasi 23
                            if(evaluate((evaluate(evaluate(value[3],value[2],operation[i]),value[1],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }

                            if(evaluate(evaluate(value[3],evaluate(value[2],value[1],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[2],operation[i]),evaluate(value[1],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[2],value[1],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }  
                            }
                            if(evaluate(value[3],evaluate(value[2],evaluate(value[1],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 24
                            if(evaluate((evaluate(evaluate(value[3],value[2],operation[i]),value[0],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[2],value[0],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[2],operation[i]),evaluate(value[0],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[2],value[0],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[2],evaluate(value[0],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                        

                        }
                    }
                }
            }

            //Jika v[0]=v[1]=v[2]=v[3]
            if(value[0]==value[1] && value[2] == value[1] && value[3] == value[1])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                        }
                    }
                }
            }
            //value[0] = value[1] dan value[2] = value[3]
            else if((value[0]==value[1] && value[2] == value[3]) || (value[0]==value[2] && value[1] == value[3]) || (value[0]==value[3] && value[1] == value[2])){
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 4
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }
                                
                            }

                            if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 14
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 17
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[0],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[0],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }                      
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[0],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[0],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[0],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }

                        }
                    }
                }
            }
            //Mengcover jika value[0] == value[1]
            else if((value[0] == value[1]) && (value[2] != value[0]) && (value[3] != value[1]))
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }

                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 4
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }
                                
                            }

                            if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 5
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {

                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 6
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }

                                else if(output == 2)

                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[1] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 14
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 18
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[1],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[1],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))"  
                                    << operation[k] << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[1],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[1],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[1],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                            
                            }
                            //Permutasi 19
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }  
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)  
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 20
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[1] << ")" << endl;
                                }     
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                            }
                            //Permutasi 24
                            if(evaluate((evaluate(evaluate(value[3],value[2],operation[i]),value[0],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[2],value[0],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[2],operation[i]),evaluate(value[0],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[2],value[0],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[2],evaluate(value[0],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                        

                        }
                    }
                }
            }
            //cover jika v[0]=v[1]=v[2]
            else if(value[0]==value[1] && value[2]==value[1] && value[3] != value[1])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }
                            //Permutasi 5
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {

                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 19
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }  
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)  
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }

                        }
                    }
                }
            }
    //cover 1,2,4
            else if(value[0] == value[1] && value[3] == value[1] && value[2] != value[1])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }

                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }

                        }
                    }
                }
            
            }
            //mengcover v[0] = v[2] = v[3]
            else if(value[0] == value[2] && value[3] == value[2] && value[1] != value[2])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 7
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 9
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]
                                    << value[3] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }

                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 10
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;                        if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << 
                                    operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                        }
                    }
                }

            }
            //mengcover jika value[0] = value[3]
            else if(value[0] == value[2] && value[1] != value[0] && value[3] != value[0])
            {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        //Permutasi 1
                        if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                        hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                operation[k] << value[3] << endl; 
                            }
                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                operation[k] << value[3] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                        hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                operation[k] << value[3] << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                operation[k] << value[3] << endl;
                            }  
                        }
                        if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                << value[3] << ")" << endl;
                            }
                            else if (output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[3] << ")" << endl;
                            }
                        }
                        if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                value[3] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                value[3] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                value[3] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                value[3] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 2
                        if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                        hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                value[2] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                value[2] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                value[2] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                value[2] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                value[2] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                value[2] << "))" << endl;
                            } 
                        }

                        //Permutasi 3
                        if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                value[3] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                value[3] << endl; 
                            }    
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                value[3] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                << value[3] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                << value[3] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                << value[3] << ")" << endl;
                            }   
                        }
                        if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                << value[3] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                value[3] << ")" << endl;
                            }
                        }
                        if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                value[3] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                value[3] << "))" << endl;
                            }   
                        }
                        //Permutasi 4
                        if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                value[1] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                value[1] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                value[1] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                value[1] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                value[1] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                value[1] << ")" << endl;
                            }
                            
                        }

                        if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                << value[1] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                << value[1] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                << value[1] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                << value[1] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 5
                        if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                        {

                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                << value[2] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                << value[2] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[3],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                << value[2] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                << value[2] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(evaluate(value[3],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                value[2] << ")" << endl;
                            }

                        }
                        if(evaluate(value[0],evaluate(value[3],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << 
                                value[2] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] 
                                << value[2] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 6
                        if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << endl; 
                            }
                            
                            else if(output == 2)
                            {
                                myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << endl; 
                            }
                        }
                        if(evaluate(evaluate(value[0],evaluate(value[3],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" 
                                << operation[k] << value[1] << endl;
                            }

                            else if(output == 2)

                            {
                                myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << 
                                operation[k] << value[1] << endl;
                            }
                        }
                        if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                operation[k] << value[1] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                operation[k] << value[1] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[0],evaluate(evaluate(value[3],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                value[1] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                value[1] << ")" << endl;
                            }   
                        }
                        if(evaluate(value[0],evaluate(value[3],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                << value[1] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                << value[1] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 7
                        if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[3] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[3] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                << value[3] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                << operation[k] << value[3] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[3] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[3] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)

                            {
                                cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                << value[3] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                << value[3] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                << value[3] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                << value[3] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 8
                        if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {

                                cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                << value[2] << endl; 
                            }

                            else if(output == 2)
                            {
                                myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                << value[2] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[1],evaluate(value[0],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                << value[2] << endl;
                            }
                            
                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                << value[2] << endl;
                            }
                        }
                        if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                << value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                << value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(evaluate(value[0],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                << value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                << value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(value[0],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 
                                << value[2] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 

                                << value[2] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 12
                        if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                << value[2] << endl; 
                            }
                            
                            else if(output == 2)
                            {
                                myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                << operation[k] << value[2] << endl; 
                            }
                        }
                        if(evaluate(evaluate(value[1],evaluate(value[3],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                << operation[k] << value[2] << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                << operation[k] << value[2] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                << operation[k] << value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                << operation[k] << value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(evaluate(value[3],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                << operation[k] << value[2] << ")" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                << operation[k] << value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[1],evaluate(value[3],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                << operation[k] << value[2] << "))" << endl;
                            }

                            else if(output == 2)
                            {
                                myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                << operation[k] << value[2] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 19
                        if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                << operation[k] << value[2] << endl; 
                            }
                            else if(output == 2)
                            {
                                myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                << operation[k] << value[2] << endl; 
                            }  
                        }
                        if(evaluate(evaluate(value[3],evaluate(value[0],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                << operation[k] << value[2] << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                << operation[k] << value[2] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                << operation[k] << value[2] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                << operation[k] << value[2] << ")" << endl;
                            }
                        
                        }
                        if(evaluate(value[3],evaluate(evaluate(value[0],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)  
                            {
                                cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                << operation[k] << value[2] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                << operation[k] << value[2] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[3],evaluate(value[0],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                << operation[k] << value[2] << "))" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                << operation[k] << value[2] << "))" << endl;
                            }
                            
                        }
                        //Permutasi 20
                        if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << endl; 
                            }
                            else if(output == 2)
                            {
                                myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << endl; 
                            }
                        }
                        if(evaluate(evaluate(value[3],evaluate(value[0],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                << operation[k] << value[1] << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                << operation[k] << value[1] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[1] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[1] << ")" << endl;
                            }     
                        }
                        if(evaluate(value[3],evaluate(evaluate(value[0],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" 
                                << operation[k] << value[1] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[3],evaluate(value[0],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                << operation[k] << value[1] << "))" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  
                                << operation[k] << value[1] << "))" << endl;
                            }
                        }
                        //Permutasi 21
                        if(evaluate((evaluate(evaluate(value[3],value[1],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[0] << endl; 
                            }
                            else if(output == 2)
                            {
                                myFile << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                << operation[k] << value[0] << endl; 
                            }
                            
                        }
                        if(evaluate(evaluate(value[3],evaluate(value[1],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                << operation[k] << value[0] << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                << operation[k] << value[0] << endl;
                            }
                            
                        }
                        if(evaluate(evaluate(value[3],value[1],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0)
                        {
                            count++;
                            if(output == 1)
                            {   
                                cout << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[0] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                << operation[k] << value[0] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[3],evaluate(evaluate(value[1],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                << operation[k] << value[0] << ")" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                << operation[k] << value[0] << ")" << endl;
                            }
                            
                        }
                        if(evaluate(value[3],evaluate(value[1],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                        {
                            count++;
                            if(output == 1)
                            {
                                cout << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                << operation[k] << value[0] << "))" << endl;
                            }
                            else if(output == 2)
                            {
                                myFile << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                << operation[k] << value[0] << "))" << endl;
                            }           
                        }

                        }
                    }
                }
            }
            //Jika value[0] = value[3]
            else if(value[0] == value[3] && value[1] != value[0] && value[2] != value[0])
            {for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }

                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 4
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }
                                
                            }

                            if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 5
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {

                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 6
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }

                                else if(output == 2)

                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[1] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 7
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 8
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {

                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 

                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 9
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]
                                    << value[3] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }

                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 14
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 15
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }                        
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                            }
                        }
                    }
                }
            }
            else if(value[1] == value[2] && value[0] != value[1] && value[3] != value[1])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }
                            //Permutasi 6
                            if(evaluate((evaluate(evaluate(value[0],value[3],operation[i]),value[2],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[3],value[2],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[1] << endl;
                                }

                                else if(output == 2)

                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[1] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[0],value[3],operation[i]),evaluate(value[2],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << 
                                    operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[3],value[2],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[1] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(value[3],evaluate(value[2],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 7
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 8
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {

                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 

                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 9
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]
                                    << value[3] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }

                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 10
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;                        if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << 
                                    operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 11
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 12
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 19
                            if(evaluate((evaluate(evaluate(value[3],value[0],operation[i]),value[1],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }  
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[0],value[1],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[0],operation[i]),evaluate(value[1],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[0],value[1],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)  
                                {
                                    cout << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[0],evaluate(value[1],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 21
                            if(evaluate((evaluate(evaluate(value[3],value[1],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[1],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[1],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {   
                                    cout << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[1],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[1],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  
                                    << operation[k] << value[0] << "))" << endl;
                                }           
                            }

                            //Permutasi 22
                            if(evaluate((evaluate(evaluate(value[3],value[1],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[3] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[3],evaluate(value[1],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[3],value[1],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[3] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(evaluate(value[1],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[3],evaluate(value[1],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[3] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }

                        }
                    }
                }
            
            }
            //value[1] dan value[3] sama 
            else if(value[1] == value[3] && value[2] != value[1] && value[3] != value[1])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 2
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[3],operation[j])),value[2],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" << operation[k] << 
                                    value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  << operation[k] << 
                                    value[2] << "))" << endl;
                                } 
                            }

                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 7
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 8
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[3],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {

                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[3],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[2] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[3],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[3],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[3],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  << operation[k] 

                                    << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 9
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]
                                    << value[3] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }

                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 10
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;                        if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << 
                                    operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 11
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[2],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[2],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[2],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[2],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[2],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 12
                            if(evaluate((evaluate(evaluate(value[1],value[3],operation[i]),value[0],operation[j])),value[2],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[2] << endl; 
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[3],value[0],operation[j]),operation[i]),value[2],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[2] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[3],operation[i]),evaluate(value[0],value[2],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[3],value[0],operation[j]),value[2],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[2] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[3],evaluate(value[0],value[2],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[2] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 15
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }                        
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                            }
                            //Permutasi 16
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                
                            }
                        }
                    }
                }
            
            }
    //Cover jika value[2] = value[3]
            else if(value[2] == value[3] && value[0] != value[2] && value[1] != value[2])
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            //Permutasi 1
                            if(evaluate((evaluate(evaluate(value[0],value[1],operation[i]),value[2],operation[j])),value[3],operation[k])-
                            hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[1] << ")" << operation[j] << value[2] << ")" << 
                                    operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[1],value[2],operation[j]),operation[i]),value[3],operation[k])-
                            hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[1] << operation[j] << value[2] << "))" << 
                                    operation[k] << value[3] << endl;
                                }  
                            }
                            if(evaluate(evaluate(value[0],value[1],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if (output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[1] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[1],value[2],operation[j]),value[3],operation[k]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[1] << operation[j] << value[2] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[1],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[1] << operation[j] << "(" << value[2]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }
                                
                            }

                            //Permutasi 3
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << endl; 
                                }    
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] << 
                                    value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[1] << operation[k] 
                                    << value[3] << ")" << endl;
                                }   
                            }
                            if(evaluate(value[0],evaluate(evaluate(value[2],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[1] << ")" << operation[k] << 
                                    value[3] << ")" << endl;
                                }
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[1]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }   
                            }
                            //Permutasi 4
                            if(evaluate((evaluate(evaluate(value[0],value[2],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[0] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],evaluate(value[2],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] << 
                                    value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[0],value[2],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[0] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << operation[k] << 
                                    value[1] << ")" << endl;
                                }
                                
                            }

                            if(evaluate(value[0],evaluate(evaluate(value[2],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[0],evaluate(value[2],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[0] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 7
                            if(evaluate((evaluate(evaluate(value[1],value[0],operation[i]),value[2],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[0] << ")" << operation[j] << value[2] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[0],value[2],operation[j]),operation[i]),value[3],operation[k])-hasil==0)

                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[0] << operation[j] << value[2] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[0],operation[i]),evaluate(value[2],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[0] << ")" << operation[j] << "(" << value[2] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[0],value[2],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[0] << operation[j] << value[2] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[0],evaluate(value[2],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[0] << operation[j] << "(" << value[2]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 9
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[0] << ")" << operation[k]
                                    << value[3] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[0] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                
                            }

                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[0] << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[0] << ")" << operation[k] 
                                    << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)

                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] << 
                                    value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[0]  << operation[k] 
                                    << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 10
                            if(evaluate((evaluate(evaluate(value[1],value[2],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;                        if(output == 1)
                                {
                                    cout << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[1] << operation[i] << value[2] << ")" << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[1],evaluate(value[2],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << operation[k] 
                                    << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << "(" << value[2] << operation[j] << value[3] << "))" << 
                                    operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[1],value[2],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                                
                                else if(output == 2)
                                {
                                    myFile << "(" << value[1] << operation[i] << value[2] << ")" << operation[j] << "(" << value[3] << 
                                    operation[k] << value[0] << ")" << endl;
                                }
                            }
                            if(evaluate(value[1],evaluate(evaluate(value[2],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" << operation[k] 
                                    << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "((" << value[2] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[1],evaluate(value[2],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[1] << operation[i] << "(" << value[2] << operation[j] << "(" << value[3]  << operation[k] 
                                    << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 13
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[1],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[1] << ")" << operation[k] 
                                    << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[1],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[1] << "))" << operation[k] 
                                    << value[3] << endl;
                                }
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[1],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[1],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[1],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 14
                            if(evaluate((evaluate(evaluate(value[2],value[0],operation[i]),value[3],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[0] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[0],value[3],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[0] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[0],operation[i]),evaluate(value[3],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[0] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[0],value[3],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[0] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[0],evaluate(value[3],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[0] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 15
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[0],operation[j])),value[3],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[0],operation[j]),operation[i]),value[3],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[3] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[0],value[3],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[3] << ")" << endl;
                                }                        
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[0],operation[j]),value[3],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[3] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[0],value[3],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[3] << "))" << endl;
                                }
                            }
                            //Permutasi 16
                            if(evaluate((evaluate(evaluate(value[2],value[1],operation[i]),value[3],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }

                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[1] << ")" << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[1],value[3],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[1] << operation[j] << value[3] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[1],operation[i]),evaluate(value[3],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[1] << ")" << operation[j] << "(" << value[3] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[1],value[3],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[1] << operation[j] << value[3] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[1],evaluate(value[3],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[1] << operation[j] << "(" << value[3]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 17
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[0],operation[j])),value[1],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << endl; 
                                }
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[0],operation[j]),operation[i]),value[1],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[0] << "))" 
                                    << operation[k] << value[1] << endl;
                                }                      
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[0],value[1],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[0] 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                            
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[0],operation[j]),value[1],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[0] << ")" 
                                    << operation[k] << value[1] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[0],value[1],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[0]  
                                    << operation[k] << value[1] << "))" << endl;
                                }
                                
                            }
                            //Permutasi 18
                            if(evaluate((evaluate(evaluate(value[2],value[3],operation[i]),value[1],operation[j])),value[0],operation[k])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                else if(output == 2)
                                {
                                    myFile << "((" << value[2] << operation[i] << value[3] << ")" << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << endl; 
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],evaluate(value[3],value[1],operation[j]),operation[i]),value[0],operation[k])-hasil==0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))"  
                                    << operation[k] << value[0] << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << "(" << value[3] << operation[j] << value[1] << "))" 
                                    << operation[k] << value[0] << endl;
                                }
                                
                            }
                            if(evaluate(evaluate(value[2],value[3],operation[i]),evaluate(value[1],value[0],operation[k]),operation[j])-hasil == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }

                                else if(output == 2)
                                {
                                    myFile << "(" << value[2] << operation[i] << value[3] << ")" << operation[j] << "(" << value[1] 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(evaluate(value[3],value[1],operation[j]),value[0],operation[k]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "((" << value[3] << operation[j] << value[1] << ")" 
                                    << operation[k] << value[0] << ")" << endl;
                                }
                                
                            }
                            if(evaluate(value[2],evaluate(value[3],evaluate(value[1],value[0],operation[k]),operation[j]),operation[i])-24 == 0)
                            {
                                count++;
                                if(output == 1)
                                {
                                    cout << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                                else if(output == 2)
                                {
                                    myFile << value[2] << operation[i] << "(" << value[3] << operation[j] << "(" << value[1]  
                                    << operation[k] << value[0] << "))" << endl;
                                }
                            
                            }

                        }
                    }
                }
            
            }
            //12.Menangani output-output jumlah solusi dan waktu
            if (count == 0) 
            {
                if(output == 1)
                {
                    cout << "Maaf tidak ditemukan solusi" << endl;
                    myFile << "Waktu eksekusi program : " << endl;
                    cout << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;
                }
                else if(output == 2)
                {
                    myFile << "Maaf tidak ditemukan solusi" << endl;
                    myFile << "Waktu eksekusi program : " << endl;
                    myFile << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;
                }
            }
            else
            {
                if(output == 1)
                {
                    cout <<"Banyaknya solusi sebanyak : " << count << endl;
                    cout << "Waktu eksekusi program : " << endl;
                    cout << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;
                }

                else if(output == 2)
                {
                    myFile <<"Banyaknya solusi sebanyak : " << count << endl;
                    myFile << "Waktu eksekusi program : " << (double)(clock() - startTime)/CLOCKS_PER_SEC << " second" << endl;
                    myFile.close();
                    
                }
            }
            }
        else if(start == 2)
        {
            exit = true;
        }
    }

    cout << "Terima kasih telah menggunakan 24GameSolver" << endl;
    return 0;
}
}