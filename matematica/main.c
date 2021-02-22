#include <stdio.h>
#include <stdlib.h>

/* PROGRESSAO ARITMETICA

    PROPRIEDADE:

        a1 + (n-1)*R = an

        a1: primeiro termo
        n: a posição do elemento que vc quer
        R: Razão da progressão Aritmetica
        an: o elemento

    PROGRESAO GEOMETRICA:

        an = a1 * q^n-1

*/

int progressao_aritmetica(int position_elem, int first_elem, int r);
int progressao_geometrica(int position_elem, int first_elem, int q);

int main()
{
    int v;
    v = progressao_aritmetica(3, 10, 5);
    printf("%i", v);

    return 0;
}

int progressao_aritmetica(int position_elem, int first_elem, int r){
    return first_elem - (position_elem-1)*r;
}

int progressao_geometrica(int position_elem, int first_elem, int q){
    return first_elem * q^position_elem-1;
}

