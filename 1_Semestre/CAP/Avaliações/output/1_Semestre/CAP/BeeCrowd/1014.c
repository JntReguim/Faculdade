// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    int Km;
    double L;
    double Media;
    
    scanf("%d", &Km);
    scanf("%lf", &L);
    
    Media = Km / L;
    printf("%.3lf km/l\n", Media);
    
    return 0;
} // Fim da main