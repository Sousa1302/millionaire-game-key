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
    return rand() % max_value + 1;                      // O numero aleatorio estara entre 1 e o valor da variavel "max_value" (valor flexivel)
}


void Gerar_Chaves_Estrelas(){                           // Funcao cujo objetivo é gerar as chaves e estrelas 

    cout << "Estrelas: ";
    for ( int i = 0; i < 2; i++){                       // i = 0, ou seja ele vai comecar a escolher um valor dentro do array na linha 0 e depois faz o mesmo na linha 1
        int linha = i;
        int coluna = Gerador_Num(5);                    // vai escolher um intervalo de 0 a 5 (coluna) e depois esse valor escolhido sera uma estrela 
        int numero = Estrelas[linha][coluna - 1];       // vai escolher um valor especifico no array bidimensional Estrelas com base nos valores das variaveis linha e coluna -1
        cout << numero << " ";                          // Utiliza-se [coluna - 1] porque os numeros do array n começam em 0 e sim 1 , assim a coluna comeca no local correto que sera na gaveta 0
    }                                                   

    cout << endl;

    cout << "Chaves: ";
    for ( int i = 0; i < 5; i++){
        int linha = Gerador_Num(4);                     // vai escolher uma linha de 0 a 4
        int coluna =  Gerador_Num(9);                   // vai escolher um valor dentro da linha defenida anteriormente , no qual sera um valor entre os intervalos 0 a 9
        int numero = Chaves[linha - 1][coluna -1];      // subtraimos -1 a linha e coluna pq as linhas comecamos a contar do zero e as colunas igualmente, assim ele acessa os valores todos
        cout << numero << " ";
    }
    cout << endl;
}

int main(){
    while (Continuar_a_gerar == true){
    
    Iniciador_Gerador();
    Gerar_Chaves_Estrelas();
    
    cout << "Desejas gerar mais um novo conjunto? \n[1]-> YES \n[2]-> NO \n";
    cin >> Another_Group;
    
    if (Another_Group == 2){
        Continuar_a_gerar = false;
        }
    }
    return 0;
}



// FALTA IMPLEMENTAR PARA QUE O NUMERO NAO SEJA REPETIDO E A ORDENACAO DO MESMO!