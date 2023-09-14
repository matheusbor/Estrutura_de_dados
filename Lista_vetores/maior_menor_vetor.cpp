#include <iostream>

using namespace std;

int main(){
    int vetor[10];
    int maior = 0, menor = 0;
    for ( int i = 0; i < 10; i++){
        cout<<"Digite um inteiro: "<<endl;
        cin>>vetor[i];
        if (vetor[i] > maior){
            maior = vetor[i];
        } else if(vetor[i]< menor){
            menor = vetor[i];
        }
    }
    cout<<"O maior e: "<<maior<<endl;
    cout<<"O menor e: "<<menor<<endl;
}