#include <stdio.h>
double sqrt(double num, double appro, double error){
    if(appro * appro - num < error && appro * appro - num > -error){
        return appro;
    }
    return sqrt(num, (appro + num / appro) / 2, error);
}
int main(){
    double num, error;
    scanf(" %lf %lf", &num, &error);
    printf("%.8lf\n", sqrt(num, 1, error));
}