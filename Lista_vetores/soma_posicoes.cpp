#include <iostream>
using namespace std;

int main(){
    int vetor[8];
    int x, y;
    for(int i = 0; i < 8; i++){
        cout<<"Digite um inteiro: "<<endl;
        cin>>vetor[i];
    }
    cout<<"Digite a primeira posicao a ser somada: "<<endl;
    cin>>x;
    cout<<"Digite a segunda posicao a ser somada: "<<endl;
    cin>>y;
    cout<<"A soma e: "<<vetor[x] + vetor[y]<<endl;

}