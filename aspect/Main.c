#include "Banco.h"

int main() {
    Conta conta1 = {"Corrente", 500.0};
    Conta conta2 = {"Poupança", 200.0};
    
    sacar(&conta1, 600.0); // Deve gerar erro
    sacar(&conta2, 150.0); // Deve ser aprovado
    
    return 0;
}
