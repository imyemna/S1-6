#include <stdio.h>
#include <unistd.h>

int main(){
    int i,clip;
    printf("enter the clips size :");
    scanf("%d",&clip);
    for (i=clip;i>0;i--)
    {
        printf("left :%d ,pow \n",i);
        usleep(50000);
        if (i==1)
        {
            printf("amo is 0\n");
            i=clip;
            printf("chek\n");
            sleep(1);
            printf("chek\n");
            printf(" the clip is reloded\n");   
        }
         
    }
    // hadi 7sen ri 7ayed l comment ,
    /*printf("relode the clip\n");
    main();*/
     

}