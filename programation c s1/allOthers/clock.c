#include <stdio.h>
#include <unistd.h>

int main(){
    int sec,min;
    for (min = 0; min < 60; min++)
    {
        for ( sec = 0; sec< 60; sec++)
        {
            printf("\r%02d:%02d",min,sec); 
            fflush(stdout);
            sleep(1);
        }
        
    }
    
}