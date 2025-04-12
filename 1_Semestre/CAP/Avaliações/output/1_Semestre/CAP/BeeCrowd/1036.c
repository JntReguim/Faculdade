// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    double A, B, C;
    double x1, x2;
    double D;
    
    scanf("%lf %lf %lf", &A, &B, &C);

    if(A == 0){
        if(B != 0){
            printf("Impossivel calcular\n");
        } 
    } 
    else {
        D = (B * B) - 4 * A * C;

        if(D >= 0){
            x1 = (-B + sqrt(D)) / (2 * A);
            printf("R1 = %.5lf\n", x1);
            
            x2 = (-B - sqrt(D)) / (2 * A);
            printf("R2 = %.5lf\n", x2);
        } 
        else{
            printf("Impossivel calcular\n");
        }
    }
    
    return 0;
} // Fim da main