int main(){
    while (Continuar_a_gerar == true){
    
    Iniciador_Gerador();
    Gerar_Chaves_Estrelas();
    
    cout << "Desejas gerar mais um novo conjunto? \n[1]-> YES \n[2]-> NO \n";
    cin >> Another_Group;
    
    if (Another_Group == 2){
        Continuar_a_gerar = false;
        }
    return 0;
    }
}