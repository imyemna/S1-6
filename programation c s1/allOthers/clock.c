#include <stdio.h>
#include <unistd.h>

int main(){
    int sec,min;
    for (min = 0; min < 24; min++)
    {
        for ( sec = 0; sec< 60; sec++)
        {
            printf("%d:%d\n",min,sec);
            sleep(1);
        }
        
    }
    
}