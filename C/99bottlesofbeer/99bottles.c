#include <stdio.h>

int
main (void)
{
    int i = 99;
    char c[2] = "s\0";

    while(i)
      {
        printf("%d bottle%s of beer on the wall, ", i, c);
        printf("%d bottle%s of beer!\n", i, c);
        i--;
        printf("You take one down, pass it around, ");
        if (i == 1)
            c[0] = '\0'; /* Делаем пустую строку */
        if (i == 0)
            goto nobottles;
        printf("%d bottle%s of beer on the wall!\n\n", i, c);
      }
    
    nobottles:
    printf("no more bottles of beer on the wall.\n");

    return 0;
}