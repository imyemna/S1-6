#include<stdio.h>

int main(){
    int a,b;
    float div;
    printf("entre la premier valeur:");
    scanf("%d",&a);
    
    printf("entre la deusieme valeur:");
    scanf("%d",&b);

    div=a/b ;
    printf("la division du A:%d SUR B:%d est: %f",a,b,div);
}