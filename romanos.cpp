#include "romanos.hpp"
#include <string.h>

int romanos_para_decimal(const char* num_romano) {
    if (strcmp(num_romano, "I") == 0) return 1;
    if (strcmp(num_romano, "V") == 0) return 5;
    if (strcmp(num_romano, "X") == 0) return 10;
    if (strcmp(num_romano, "L") == 0) return 50;
    if (strcmp(num_romano, "C") == 0) return 100;
    if (strcmp(num_romano, "D") == 0) return 500;
    if (strcmp(num_romano, "M") == 0) return 1000;
    if (strcmp(num_romano, "MMM") == 0) return 3000;
    
    return -1;
}
