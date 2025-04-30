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

int romanos_para_decimal(const char* num_romano) {
    int total = 0;
    int tamanho = strlen(num_romano);
    
    for (int i = 0; i < tamanho; ++i) {
        if (valor(num_romano[i]) == -1) return -1;
    }
    return -1;
}
