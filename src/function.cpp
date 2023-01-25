#include <iostream>
using namespace std;
void selectionSort(double arr[],int n)  //n disini bersumber dari jumlah anggota array, jika di case ini  n yang akan digunakan adalah  4
{for(int i = 0;i < n;i++){
    int min = i;
    for(int j = i+1;j < n;j++)
        if (arr[j] < arr[min])
            min = j;
        swap(arr[i],arr[min]);}}
double evaluate(double value1, double value2, char operasi){
    if(operasi == '+'){
        return value1+value2;}
    else if(operasi == '-'){
        return value1-value2;}
    else if(operasi == '*'){
        return value1*value2;}
    else if(operasi == '/'){
        return value1/value2;}}
void inputUser(double value[])
{
    for(int i = 0; i < 4; i ++){
        string sementara;
        cout << "Masukkan input anda : " << endl;
        cin >> sementara;
        if(sementara == "As")
        {
            value[i] = 1;}
        else if(sementara == "J")
        {value[i] = 11;}
        else if(sementara == "Q"){
            value[i] = 12;}
        else if(sementara == "K"){
            value[i] = 13;}
        else if(sementara == "2"){
            value[i] = 2;}
        else if(sementara == "3"){
            value[i] = 3;}
        else if(sementara == "4"){
                value[i] = 4;}
        else if(sementara == "5"){
            value[i] = 5;}
        else if(sementara == "6"){
            value[i] = 6;}
        else if(sementara == "7"){
            value[i] = 7;}
        else if(sementara == "8"){
            value[i] = 8;}
        else if(sementara == "9"){
            value[i] = 9;}
        else if(sementara == "10"){
            value[i] = 10;}
        else{
        while(sementara != "As" && sementara != "2" && sementara != "3" && sementara != "4" && sementara != "5" && sementara != "6" && 
        sementara != "7" && sementara != "8" && sementara != "9" && sementara != "10" && sementara != "J" && sementara != "Q" && sementara != "K"){
            cout << "input anda salah, Mohon input ulang Jawaban anda" << endl;
            cin >> sementara;}
            if(sementara == "As"){
                value[i] = 1;}
            else if(sementara == "J"){
                value[i] = 11;}
            else if(sementara == "Q"){
                value[i] = 12;}
            else if(sementara == "K"){
                value[i] = 13;}
            else if(sementara == "2"){
                value[i] = 2;}
            else if(sementara == "3"){
                value[i] = 3;}
            else if(sementara == "4"){
                value[i] = 4;}
            else if(sementara == "5"){
                value[i] = 5;}
            else if(sementara == "6"){
                value[i] = 6;}
            else if(sementara == "7"){
                value[i] = 7;}
            else if(sementara == "8"){
                value[i] = 8;}
            else if(sementara == "9"){
                value[i] = 9;}
            else if(sementara == "10"){
                value[i] = 10;}}}}
