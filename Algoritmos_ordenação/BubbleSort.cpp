#include <iostream>
using namespace std;

int main(){
    int elementos, auxiliar;
    bool continuar =  true;
    cout<<"Quantos elementos o vetor deve ter? "<<endl;
    cin>>elementos;

    int vetor[elementos];
    for(int i = 0; i <elementos; i++){
        cout<<"Digite um elemento pro vetor: "<<endl;
        cin>>vetor[i];
    }
    int contador = 0;
    while(continuar){
        continuar = false; //colocar antes do for pra se houver ao menos uma mudança já mudar pra true e permanecer true por todo for
        for(int j = 0; j < elementos - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                continuar = true;
                auxiliar = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = auxiliar;
                contador ++;
            }
        }
    }
    cout<<"o vetor e: ";
    for(int l = 0; l < sizeof(vetor)/4; l++){
        cout<<vetor[l]<<" ";
    }
    cout<<endl<<contador;
}