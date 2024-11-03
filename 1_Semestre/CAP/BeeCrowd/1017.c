// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    double Media;
    double L;
    int H;
    int KmH;
    int X;
    
    scanf("%d", &H);
    scanf("%d", &KmH);
    
    X = H * KmH;
    
    Media = 12.000;
    L = X / Media;
    
    printf("%.3lf\n", L);
    
    return 0;
} // Fim da main