#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char t[100];
    char t1[]="Egy meg egy";
    char t2[]=" az ketto!";

    printf("%d\n",strlen(t1));
    strcpy(t,t1);
    puts(t);

    strcat(t,t2);
    puts(t);

    strcpy(t1,"Harry");
    strcpy(t2,"Ron");
    strcpy(t,"Hermione");

    if (strcmp(t1,t2)<0) printf("%s<%s\n",t1,t2);
    else printf("%s>%s\n",t1,t2);

    if (strcmp(t1,t)>0) printf("%s>%s\n",t1,t);
    else printf("%s<%s\n",t1,t);

    if (strcmp(t1,t)==0) printf("%s==%s",t1,t);
    else printf("%s!=%s\n",t1,t);

    if (strchr(t,'o')==NULL)
        printf("%s nem tartalmaz \'o\'-t\n",t);
    if (strstr(t,"on")==NULL)
        printf("%s nem tartalmaz \"on\"-t\n",t);
    else printf("%s tartalmaz \"on\"-t\n",t);

    strncpy(t1,"Beckham",2);
    puts(t1);





    //printf("Hello world!\n");
    return 0;
}
