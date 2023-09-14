#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double reais[20];
    double quadrados[20];
    for(int i = 0; i<20; i++){
        cout<<"Digite um numero real: "<<endl;
        cin>>reais[i];
        quadrados[i] = pow(reais[i], 2);
    }

    for(int i = 0; i<20; i++){
        cout<<"O valor dos numeros reais e: "<<reais[i]<<endl;
        cout<<"Elevado ao quadrado fica: "<<quadrados[i]<<endl;
    }
}