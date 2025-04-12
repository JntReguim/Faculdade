// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    double A, B, MEDIA;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    
    MEDIA = (A * 3.5 + B * 7.5) / (3.5 + 7.5);
    
    printf("MEDIA = %.5lf\n", MEDIA);
    
    return 0;
} // Fim da main