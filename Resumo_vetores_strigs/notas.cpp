#include <iostream>
using namespace std;

float maior(float notas[10]){
    float nota_maior= -1.;
    for(int i = 0; i < 10; i++){
        if (notas[i] > nota_maior){
            nota_maior = notas[i];
        }
    }
    return nota_maior;
}

float menor(float notas[10]){
    float nota_menor = 11;
    for(int i = 0; i < 10; i++){
        if (notas[i] < nota_menor){
            nota_menor = notas[i];
        }
    }
    return nota_menor;
}

float media(float notas[10]){
    float media = 0;
    for(int i = 0; i< 10; i++){
        media+= notas[i];
    }
    media /= 10;
    return media;
}

float recuperacao(float notas[10]){
    float reprovados = 0;
    for(int i = 0; i < 10; i++){
        if (notas[i] < 6){
            reprovados ++;
        }
    }
    return reprovados;
}

float aprovados(float notas[10]){
    float aprovados = 0;
    for(int i = 0; i< 10; i++){
        if(notas[i] >= 6){
            aprovados++;
        }
    }
    return aprovados;
}
int main(){
    float notas[10];
    for(int i = 0; i<10; i++){
        cout<<"Digite uma nota: "<<endl;
        cin>>notas[i];
    }
    cout<<"A nota maior e: "<<maior(notas)<<endl;
 cout<<"A nota menor e: "<<menor(notas)<<endl;
 cout<<"A nota media e: "<<media(notas)<<endl;
 cout<<"Os de recuperacao sao: "<<recuperacao(notas)<<endl;
  cout<<"Os aprovados sao: "<<aprovados(notas)<<endl;
}