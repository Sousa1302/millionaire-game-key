#include <iostream>

using namespace std;

int Num_50, Num_12, Another_Group;

bool Continuar_a_gerar = true;

int Estrelas[2][6] = {{1,2,3,4,5,6}                     // linha 0
                     ,{7,8,9,10,11,12}};                // linha 1

int Chaves[5][10] = {{1,2,3,4,5,6,7,8,9,10},
                    {11,12,13,14,15,16,17,18,19,20},
                    {21,22,23,24,25,26,27,28,29,30},
                    {31,32,33,34,35,36,37,38,39,40},
                    {41,42,43,44,45,46,47,48,49,50}};

void Iniciador_Gerador(){                               // Vai gerar um numero que vai escolher as colunas e a linha para gerar depois as chaves e estrelas
    srand(time(NULL));                                  // usado para iniciar o codigo e ter um numero aleatorio sempre diferente 
}                                                       // manda de volta um intervalo de tempo desde uma "epoca" , usado para que o numero seja sempre diferente

int Gerador_Num(int max_value){                         // O intervalo anterior utiliza-se nesta funcao 
    static int seed = 1;                                // seed Inicial ; Utiliza-se static para que o valor se mantenha durante o chamamento de outras funções 
    seed = (seed * 32719 + 3) % 32749;                  // Calculo utilizado para gerar um novo valor para a variavel seed;  32749 é um valor grande que ajuda a espalhar os bits e aumentar a aleatoriedade
    return rand() % max_value + 1;                      // O numero aleatorio estara entre 1 e o valor da variavel "max_value" (valor flexivel)                                                  
}                                                       

void BubbleSort(int arr[], int size) {                  // Algoritmo para ordenar numeros dentro de arrays
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Gerar_Chaves_Estrelas(){                           // Funcao cujo objetivo é gerar as chaves e estrelas 

    int stars[2];                                       // Arrays criados para armazenar os numeros que serao atribuidos as estrelas e as chaves
    int keys[5];

    cout << "Estrelas: ";
    bool Padroes_Estrelas_Disponiveis = false;          // Variavel usada para rastrear se ainda existem algumas estrelas disponiveis

    for ( int i = 0; i < 2; i++){                       // i = 0, ou seja ele vai comecar a escolher um valor dentro do array na linha 0 e depois faz o mesmo na linha 1
        int linha, coluna;
        Padroes_Estrelas_Disponiveis = false;           // Reinicializa a flag para as estrelas disponiveis ou seja pode voltar a usar os mesmo numeros que anteriormente
        for(int tries = 0;tries < 100;tries ++){        // Até 100 tentativas para achar uma estrela disponivel e assim nao ficar num loop infinito
            linha = Gerador_Num(2) - 1;
            coluna = Gerador_Num(6) - 1;
            if (Estrelas[linha][coluna] != 0){          // Verifica se a estrela na posicao [linha][coluna] não é igual a zero, oq significa que ela está disponivel
                Padroes_Estrelas_Disponiveis = true;    // Se uma estrela estiver disponivel é defenida como true a variavel
                break;
            }
        }                                               

        if (!Padroes_Estrelas_Disponiveis){             // Verifica se nenhuma estrela disponivel foi encontrada depois de 100 tentativas
            cout << "Não há mais estrelas disponiveis!\n";
            break;
        }

        stars[i] = Estrelas[linha][coluna];             // A estrela selecionada anteriormente é atribuida na gaveta cujo valor i tem
        Estrelas[linha][coluna] = 0;                    // depois de escolhida a estrela esta é atribuida á gaveta 0 do array ou seja nao estara disponivel para ser escolhida uma segunda vez
    }                                                   
    BubbleSort(stars, 2);

    cout << "Estrelas ordenadas: ";
    for (int i = 0; i < 2; i++) {
        cout << stars[i] << " ";
}
    
    cout << endl;

    cout << "Chaves: ";
    bool Padroes_Chaves_Disponiveis = false;            // Variavel usada para rastrear se ainda existem algumas chaves disponiveis
    for ( int i = 0; i < 5; i++){
        int linha, coluna;
        
        for (int tries = 0; tries < 100; tries ++) {    // Até 100 tentativas para achar uma chave disponivel e assim nao ficar num loop infinito
            linha = Gerador_Num(5) - 1;                 // 5 porque é o numero de linhas nos vetores bidimensionais ; -1 porque começamos a contar do 0
            coluna = Gerador_Num(10) -1;                // 10 porque é o numero de colunas nos vetores bidimensionais; -1 porque começamos a contar do 0
            if (Chaves[linha][coluna] != 0){            // Verifica se a chave na posicao [linha][coluna] não é igual a zero, oq significa que ela está disponivel
                Padroes_Chaves_Disponiveis = true;      // Se uma chave estiver disponivel é defenida como true a variavel
                break;
            }                
        }         

        if (!Padroes_Chaves_Disponiveis){               // Verifica se nenhuma chave disponivel foi encontrada depois de 100 tentativas
            cout << "Nao há mais chaves disponiveis!\n";
            break;
        }                                      

        keys[i] = Chaves[linha][coluna];                // A chave selecionada anteriormente é atribuida na gaveta cujo valor i tem
        Chaves[linha][coluna] = 0;                      // depois de escolhida a chave esta é atribuida á gaveta 0 do array ou seja nao estara disponivel para ser escolhida uma segunda vez
                              
    }
    BubbleSort(keys, 5);

    cout << "Chaves ordenadas: ";
    for (int i = 0; i < 5; i++) {
        cout << keys[i] << " ";
    }
    cout << endl;
}

int main(){
    while (Continuar_a_gerar == true){
    
    Iniciador_Gerador();
    Gerar_Chaves_Estrelas();
    
    cout << "Desejas gerar mais um novo conjunto? \n[1]-> YES \n[2]-> NO \n";
    cin >> Another_Group;
    
    if (Another_Group == 2 || Another_Group > 2){
        Continuar_a_gerar = false;
        }
    }
    return 0;
}

