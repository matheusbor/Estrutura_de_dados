#include <iostream>
using namespace std;

int main(){
    int multiplos[100];
    int controle = 0;
    //como saber quantas posicoes do vetor ja foram preenchidas? se soubesse não precisava desse controle
    for(int i = 0; controle<100; i++){
        if (i % 7 != 0){
            multiplos[controle] = i;
            controle++;
        }
    }
    cout<<"Os Nao-multiplos de 7 sao: ";
    for(int i = 0; i< 100; i++){
        cout<<multiplos[i]<<" ";
    }

    

}