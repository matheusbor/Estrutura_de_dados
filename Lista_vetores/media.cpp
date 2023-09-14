#include <iostream>
using namespace std;

int main(){
    int vetor[5];
    int media = 0;
    for(int i = 0; i <5; i++){
        cout<<"Digite um inteiro: "<<endl;
        cin>>vetor[i];
    }
    for(int i = 0; i < 5; i++){
        cout<<"O valor na posicao "<<i<<"e: "<<vetor[i]<<endl;
        media += vetor[i];
    }
    cout<<"A media e: "<<media/5;
}