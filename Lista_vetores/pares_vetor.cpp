#include <iostream>
using namespace std;

int main(){
    int vetor[10];
    int pares = 0;
    for(int i = 0; i < 10; i++){
        cout<<"Digite um inteiro: "<<endl;
        cin>>vetor[i];
        if (vetor[i] % 2 == 0){
            pares ++;
        }
    }
    cout<<"Existem "<<pares<<" numeros pares"<<endl;
    
}