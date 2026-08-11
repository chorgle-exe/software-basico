#include <stdio.h>
#include <stdlib.h>

float foo (float pf)
{
    return pf+1;
}

int main (int argc, char **argv)
{
    float f;
    if (argc!=2)
    {
        printf("uso do programa: %s <valor float>\n");
        exit(0);
    }
    
}