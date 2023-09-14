#include <iostream>
using namespace std;

int main(){
    int vetor[7];
    for (int i = 0; i <7; i++){
        cout<<"Digite um inteiro: "<<endl;
        cin>>vetor[i];
    }
    for (int i = 6; i > -1; i--){
        cout<<"O vetor e: "<<vetor[i]<<endl;
    }
}