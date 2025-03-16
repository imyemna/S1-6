#include<stdio.h>

int main(){

    int n=3;
    int * p=&n;
    float max,min,som;
    float t[*p];
    float *q=&t;
    for (int i=0;i<*p;i++){
        printf("entre la valeur du place %d\n",i);
        scanf("%f",q+i);
        som+=*(q+i);
        if (*(q+i)>max)
        max=*(q+i); 
        if (i==0){
        min=*(q+i);
        }else{
            if (*(q+i)<min)
            {
                min=*(q+i);
            }
        }
    
    }
    
    for (int i=0;i<*p;i++){
        printf("la valeur du place %d est %f\n",i,*(q+i));
    }
    printf("la valeur maximale est %f\n",max);
    printf("la valeur minimale est %f\n",min);

    for (int i=0;i<*p;i++){
        printf("la valeur du place %d est %f\n",i,*(q+i));
    }
    printf("la somme est %f",som);
    return 0;
}