#include <iostream>
#include <ctime>  // Para gerar numeros diferentes cada vez que executamos o codigo
#include <cstdlib>
#include <vector>  // Para usar vetores
#include <algorithm>  // Para usar a função std::find nos vetores

using namespace std;

int Num_50, Num_12, Another_group;

vector<int> Chaves_50;
vector<int> Chaves_12;

// Funcao que verifica se um numero é unico em um vetor 
bool Num_Unico(int num, const vector<int> &vec) { // const vector<int> &vec -> Criacao de um vetor de valor const de tipo inteiro; &vec -> Indica que a funcao aceita uma referencia ao vetor, em vez de uma copia do vetor
    return find(vec.begin(), vec.end(), num) == vec.end(); // vec designa-se como um vector em geral ou seja Chaves_12 ou Chaves_50 ou seja ele vai verificar em ambos os vetores se ja possuem os numeros gerados, senao ele mete num deles de acordo com as "regras futuras"
}

void GerarChavesEstrelas(){
    
    int Times_printed_50 = 0, Times_printed_12 = 0;
    Chaves_12.clear();
    Chaves_50.clear();

    cout << "Estrelas: ";

    while (Times_printed_12 < 2) {
        Num_12 = 1 + (rand() % 12);

        // se Num_12 nao esta presente no vetor Chaves_12
        if (Num_Unico(Num_12, Chaves_12)) {
            Chaves_12.push_back(Num_12);
            
            // esta iteragindo com o elemento do vetor Chaves_12 num indice especifico neste caso o Times_printed_12, se times_printed_12 = 0 o valor gerado sera atribuido á gaveta 0
            cout << Chaves_12[Times_printed_12] << " ";
            Times_printed_12++;
        }
    }

    cout << "\n";
    cout << "Chaves: ";

    while (Times_printed_50 < 5) {
        Num_50 = 1 + (rand() % 50);
        if (Num_Unico(Num_50, Chaves_50)) {
            Chaves_50.push_back(Num_50);
            cout << Chaves_50[Times_printed_50] << " ";
            Times_printed_50++;
        }
    }
}



int main() {
    srand(time(0));

    do {
        GerarChavesEstrelas();
        cout << endl;
        cout << "Desejas gerar mais um conjunto?\n";
        cout << "[1]-> Sim \n[2]-> Nao\n";
        cin >> Another_group;
    } while (Another_group == 1);

    if (Another_group >= 2){
        cout << "Estas foram as Chaves milionários geradas, obrigado por jogares!\n";
    }    
    
    return 0;
}


