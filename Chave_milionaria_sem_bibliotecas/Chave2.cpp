#include <iostream>

using namespace std;

void BubbleSort(int arr[], int size) {                               // Algoritmo para organizar os numeros por ordem crescente
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

int main() {
    const int Max_Nums = 5;
    const int Max_Stars = 2;
    int numbers[Max_Nums];                                           // Criação de array cujo tamanho é a nossa variavel antes defenida
    int stars[Max_Stars];                                            // Criação de array cujo tamanho é a nossa variavel antes defenida
    
    srand(time(NULL));
    
    char keep_generating;
    do {
        system("clear");                                             // Limpa a tela 
        
        
        for (int x = 0; x < Max_Nums; ++x) {                         // Gera numeros
            bool repeated_number;
            int new_number;
            
            do {
                new_number = rand() % 50 + 1;                           
                repeated_number = false;
                
                
                for (int y = 0; y < x; ++y) {                        // Verifica se o numero ja foi gerado
                    if (numbers[y] == new_number) {                  // Verifica se o novo numero é igual a um dos numeros do array entao é repetido
                        repeated_number = true;
                        break;
                    }
                }
            } while (repeated_number);                               // Volta a executar o loop até achar um numero ainda n gerado 
            
            numbers[x] = new_number;                                 // armazena o novo numero na posicao i
        }
        
        BubbleSort(numbers, Max_Nums);                               // Ordena os numeros por ordem crescente
        
        
        for (int x = 0; x < Max_Stars; ++x) {                        // Gera as estrelas 
            bool repeated_star;
            int new_star;
            
            do {
                new_star = rand() % 12 + 1;
                repeated_star = false;
                
                
                for (int y = 0; y < x; ++y) {                        // Verifica se a estrela ja foi gerada 
                    if (stars[y] == new_star) {                      // Verifica se a estrela é igual a uma das outras estrelas ja presentes no array
                        repeated_star = true;
                        break;
                    }
                }
            } while (repeated_star);
            
            stars[x] = new_star;                                    // armazena o novo numero na posicao i
        }
        
        BubbleSort(stars, Max_Stars);                               // Ordena os numeros por ordem crescente
        
        
        cout << "Números: ";
        for (int z = 0; z < Max_Nums; ++z) {
            cout << numbers[z] << " ";
        }
        cout << endl;
        
        cout << "Estrelas: ";
        for (int k = 0; k < Max_Stars; ++k) {
            cout << stars[k] << " ";
        }
        cout << endl;
        
        cout << "Deseja gerar outro conjunto? (S/N): ";
        cin >> keep_generating;
    } while (keep_generating == 'S' || keep_generating == 's');
    
    return 0;
}


