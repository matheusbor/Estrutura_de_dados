#include <iostream>
#include <stdlib.h>

using namespace std;

struct aluno {
    int idade;
    string nome;
    aluno* proximo;
};

void adicionarAluno(aluno*& lista, int idade, string& nome) {
    aluno* novoAluno = new aluno;
    novoAluno->idade = idade;
    novoAluno->nome = nome;
    novoAluno->proximo = lista;
    lista = novoAluno;
}

void exibirAlunos(aluno* lista) {
    aluno* auxiliar = lista;
    while (auxiliar != NULL) {
        cout << "Idade: " << auxiliar->idade << ", Nome: " << auxiliar->nome << endl;
        auxiliar = auxiliar->proximo;
    }
}

void trocarAlunos(aluno* a, aluno* b) {
    if (a == nullptr || b == nullptr) {
        return;
    }
    aluno temp = *a;
    *a = *b;
    *b = temp;

    aluno* tempProximo = a->proximo;
    a->proximo = b->proximo;
    b->proximo = tempProximo;
}

void ordenarAlunos(aluno*& lista) {
    aluno* inicio = lista;

    while (inicio != nullptr) {
        aluno* minimo = inicio;
        aluno* atual = inicio->proximo;

        while (atual != nullptr) {
            if (atual->idade < minimo->idade) {
                minimo = atual;
            }
            atual = atual->proximo;
        }

        if (minimo != inicio) {
            trocarAlunos(inicio, minimo);
        }

        inicio = inicio->proximo;
    }
}

void removerAluno(aluno*& lista, string& nome) {
    aluno* atual = lista;
    aluno* anterior = nullptr;

    while (atual != nullptr && atual->nome != nome) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != nullptr) {
        if (anterior != nullptr) {
            anterior->proximo = atual->proximo;
        } else {
            lista = atual->proximo;
        }

        delete atual;
    }
}

void buscarAluno(aluno* lista, string& nome) {
    aluno* atual = lista;

    while (atual != nullptr && atual->nome != nome) {
        atual = atual->proximo;
    }

    if (atual != nullptr) {
        cout << "Aluno encontrado:" << endl;
        cout << "Idade: " << atual->idade << ", Nome: " << atual->nome << endl;
    } else {
        cout << "Aluno não encontrado." << endl;
    }
}


int main() {
    aluno* lista = nullptr;
    string nome;

    char continuar;
    do {
        string nome;
        int idade;

        cout << "Informe o nome do aluno: ";
        getline(cin, nome);

        cout << "Informe a idade do aluno: ";
        cin >> idade;

        adicionarAluno(lista, idade, nome);

        cout << "Deseja cadastrar outro aluno? (S/N): ";
        cin >> continuar;
        cin.ignore();

    } while (continuar == 'S' || continuar == 's');

    cout << "\nLista de alunos cadastrados (antes da ordenacao):" << endl;
    exibirAlunos(lista);

    cout<<"Deseja remover algum aluno? (S/N): "<<endl;
    cin>>continuar;
    cin.ignore();

    if(continuar == 'S' || continuar == 's'){
        cout<<"Digite o nome do aluno: "<<endl;
        getline(cin, nome);
        removerAluno(lista, nome);
    }
    exibirAlunos(lista);

    cout<<"Deseja buscar algum aluno? (S/N): "<<endl;
    cin>>continuar;
    cin.ignore();

    if(continuar == 'S' || continuar == 's'){
        cout<<"Digite o nome do aluno: "<<endl;
        getline(cin, nome);
        buscarAluno(lista, nome);
    }

    cout<<"\n Lista ordenada: "<<endl;

    ordenarAlunos(lista);

    exibirAlunos(lista);

    aluno* atual = lista;
    while (atual != nullptr) {
        aluno* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    return 0;
}