#include "romanos.hpp"
#include <string.h>

int valor(char c) {
        
    switch (c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default: return -1;
    }
    return -1;
}

bool subtracao_valida(char atual, char proximo) {
    switch (atual) {
        case 'I': return proximo == 'V' || proximo == 'X';
        case 'X': return proximo == 'L' || proximo == 'C';
        case 'C': return proximo == 'D' || proximo == 'M';
        default: return false;
    }
}


int romanos_para_decimal(const char* num_romano) {

    if (num_romano == nullptr || strlen(num_romano) == 0) {
        return -1; // invalido
    }

    int total = 0;
    int len = strlen(num_romano);
    int repeticoes = 1; // conta repetições do mesmo caractere

    for (int i = 0; i < len; ++i) {
        int atual = valor(num_romano[i]);
        if (atual == -1) return -1;

        int proximo = (i + 1 < len) ? valor(num_romano[i + 1]) : 0;
        if (proximo == -1) return -1;

        if (i > 0 && num_romano[i] == num_romano[i - 1]) {
            repeticoes++;
            // I, X, C e M podem repetir ate 3x
            if ((num_romano[i] == 'I' || num_romano[i] == 'X' ||
                 num_romano[i] == 'C' || num_romano[i] == 'M') && repeticoes > 3)
                return -1;
            // V, L e D nunca podem repetir
            if (num_romano[i] == 'V' || num_romano[i] == 'L' || num_romano[i] == 'D')
                return -1;
        } else {
            repeticoes = 1;
        }

        if (atual < proximo) {
            if (!subtracao_valida(num_romano[i], num_romano[i + 1])) return -1;
            total += proximo - atual;
            ++i;
        } else {
            total += atual;
        }
    }
    
    if (total > 3000) {
        return -1;
    }

    return total;
}
