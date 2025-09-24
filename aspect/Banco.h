#ifndef BANCO_H
#define BANCO_H

#include <stdio.h>
#include <stdbool.h>

// Estrutura base para uma conta bancária
typedef struct {
    char tipo[20];
    double saldo;
} Conta;

// Função para saque (POO)
bool sacar(Conta *conta, double valor);

#endif
#ifndef BANCO_H
#define BANCO_H

#include <stdio.h>
#include <stdbool.h>

// Estrutura base para uma conta bancária
typedef struct {
    char tipo[20];
    double saldo;
} Conta;

// Função para saque (POO)
bool sacar(Conta *conta, double valor);

#endif
