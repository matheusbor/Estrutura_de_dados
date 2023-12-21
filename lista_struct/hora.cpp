#include <iostream>
using namespace std;


struct hora{
    int hora;
    int minutos;
    int segundos;
};

void maior(hora horario[2]){
    int segundos1, segundos2;
  // int tamanho = (sizeof(*horario)/12);
   // cout<<"inicio maior";
    //cout<<sizeof(*horario);
    for(int i= 0; i< (sizeof(*horario)/12)*2 -1 ; i++){
        segundos1 = horario[i].hora*3600 + horario[i].minutos*60 + horario[i].segundos;
        segundos2 = horario[i+1].hora*3600 + horario[i+1].minutos*60 + horario[i+1].segundos;
       // cout<<"inicio for";
        if(segundos1 > segundos2){
            cout<<"O maior e: ";
            cout<<horario[i].hora<<"\t";

            cout<<horario[i].minutos<<"\t";

            cout<<horario[i].segundos<<endl;
        } else if(segundos1 == segundos2){
            cout<<"As horas são iguais"<<endl;
            cout<<horario[i].hora<<"\t";

            cout<<horario[i].minutos<<"\t";

            cout<<horario[i].segundos<<endl;
        }else{
            cout<<"O maior e: ";
            cout<<horario[i + 1].hora<<"\t";

            cout<<horario[i + 1].minutos<<"\t";

            cout<<horario[i + 1].segundos<<endl;

        }

    }

}
void imprime(hora horario[2]){
    for(int i=0; i<2; i++){
        cout<<horario[i].hora<<"\t";

        cout<<horario[i].minutos<<"\t";

        cout<<horario[i].segundos<<endl;
    }
}
int main(){

    hora horario[2];

    for(int i=0; i<2; i++){
        cout<<"Digite a hora: "<<endl;
        cin>>horario[i].hora;

        cout<<"Digite os minutos: "<<endl;
        cin>>horario[i].minutos;

        cout<<"Digite os segundos: "<<endl;
        cin>>horario[i].segundos;
    }

    //imprime(horario);
    //cout<<sizeof(hora);
    //cout<<sizeof(horario)/12;
    maior(horario);
    
}