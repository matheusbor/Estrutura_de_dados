#include <iostream>
#include <stdlib.h>

using namespace std;

struct aluno {
    int idade;
    string nome;
    aluno* proximo;
};

// Função para adicionar um novo aluno à lista
void adicionarAluno(aluno*& lista, int idade, string& nome) {
    aluno* novoAluno = new aluno;
    novoAluno->idade = idade;
    novoAluno->nome = nome;
    novoAluno->proximo = lista;
    lista = novoAluno;
}

// Função para exibir os alunos na lista
void exibirAlunos(aluno* lista) {
    aluno* auxiliar = lista;
    while (auxiliar != nullptr) {
        cout << "Idade: " << auxiliar->idade << ", Nome: " << auxiliar->nome << endl;
        
        auxiliar = auxiliar->proximo;
    }
}

// Função para trocar os dados entre dois nós
void trocarAlunos(aluno* a, aluno* b) {
    if (a == nullptr || b == nullptr) {
        return; // Verificação para evitar troca com nós nulos
    }

    // Trocar os dados
    aluno temp = *a;
    *a = *b;
    *b = temp;

    // Atualizar os ponteiros próximo
    aluno* tempProximo = a->proximo;
    a->proximo = b->proximo;
    b->proximo = tempProximo;
}


// Função para encontrar o nó com o valor mínimo a partir de um nó específico
aluno* encontrarMinimo(aluno* inicio) {
    aluno* minimo = inicio;
    aluno* atual = inicio->proximo;

    while (atual != nullptr) {
        if (atual->idade < minimo->idade) {
            minimo = atual;
        }
        atual = atual->proximo;
    }

    return minimo;
}

// Função para ordenar a lista de alunos por idade (usando Selection Sort)
void ordenarAlunosPorIdadeCrescente(aluno*& lista) {
    aluno* inicio = lista;

    while (inicio != nullptr) {
        // Encontrar o nó com a menor idade a partir do nó atual
        aluno* minimo = inicio;
        aluno* atual = inicio->proximo;

        while (atual != nullptr) {
            if (atual->idade < minimo->idade) {
                minimo = atual;
            }
            atual = atual->proximo;
        }

        // Trocar os dados entre os nós
        if (minimo != inicio) {
            trocarAlunos(inicio, minimo);
        }

        // Mover para o próximo nó
        inicio = inicio->proximo;
    }
}
void removerAluno(aluno*& lista, string& nome) {
    aluno* atual = lista;
    aluno* anterior = nullptr;

    // Procurar o aluno na lista
    while (atual != nullptr && atual->nome != nome) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Verificar se o aluno foi encontrado
    if (atual != nullptr) {
        // Remover o aluno ajustando os ponteiros
        if (anterior != nullptr) {
            anterior->proximo = atual->proximo;
        } else {
            // Se o aluno a ser removido é o primeiro da lista
            lista = atual->proximo;
        }

        // Liberar a memória do nó removido
        delete atual;
    }
}

// Função para buscar e imprimir os dados de um aluno pelo nome
void buscarAluno(aluno* lista, string& nome) {
    aluno* atual = lista;

    // Procurar o aluno na lista
    while (atual != nullptr && atual->nome != nome) {
        atual = atual->proximo;
    }

    // Verificar se o aluno foi encontrado
    if (atual != nullptr) {
        // Imprimir os dados do aluno
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
        cin.ignore(); // Limpa o buffer do teclado

    } while (continuar == 'S' || continuar == 's');

    cout << "\nLista de alunos cadastrados (antes da ordenacao):" << endl;
    exibirAlunos(lista);

    cout<<"Deseja remover algum aluno? (S/N): "<<endl;
    cin>>continuar;
    cin.ignore(); // Limpa o buffer do teclado

    if(continuar == 'S' || continuar == 's'){
        cout<<"Digite o nome do aluno: "<<endl;
        getline(cin, nome);
        removerAluno(lista, nome);
    }
    exibirAlunos(lista);

    cout<<"Deseja buscar algum aluno? (S/N): "<<endl;
    cin>>continuar;
    cin.ignore(); // Limpa o buffer do teclado

    if(continuar == 'S' || continuar == 's'){
        cout<<"Digite o nome do aluno: "<<endl;
        getline(cin, nome);
        buscarAluno(lista, nome);
    }
    
    // Ordenar a lista por idade
    ordenarAlunosPorIdadeCrescente(lista);

    exibirAlunos(lista);
    //cout << "\nLista de alunos ordenada por idade:" << endl;
   // exibirAlunos(lista);

    // Liberar a memória alocada
    aluno* atual = lista;
    while (atual != nullptr) {
        aluno* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    return 0;
}