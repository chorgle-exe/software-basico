#include <stdio.h>

int is_little()
{
    int i = 1;
    unsigned char *c = (unsigned char*)&i;
    if (*c == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(void)
{
    if (is_little())
    {
        printf("little endian\n");
    }
    else 
    {
        printf("big endian\n- %p");
    }
    
    return 0;
}