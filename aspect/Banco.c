#include "Banco.h"

bool sacar(Conta *conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado na conta %s.\n", valor, conta->tipo);
        return true;
    }
    return false;
}