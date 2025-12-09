#include <unistd.h>
#include <stdio.h>

void    rush(unsigned int ligne,unsigned int colone)
{
    unsigned int i, j;
    char t[ligne][colone];

    i = 0;
    if (ligne == 0 || colone == 0)
        write(1, "Argument Eroor!", 15);
    else if ((ligne == 1 && colone != 1) || (ligne != 1 && colone == 1))
    {
        if (ligne == 1)
        {
            j = 0;
            while (j < colone)
            {
                if(j == 0)
                    t[i][j] = 'A';
                else if (j == colone-1)
                    t[i][j] = 'C';
                else
                    t[i][j] = 'B';
                j++;
            }
        }
        else if (colone == 1)
        {
            j = 0;
            i = 0;
            while (i < ligne)
            {
                if(i == 0)
                    t[i][j] = 'A';
                else if (i == ligne-1)
                    t[i][j] = 'C';
                else
                    t[i][j] = 'B';
                i++;
            }
        }
    }
    else
    {
        while ( i < ligne)
        {
            j = 0;
            while (j < colone)
            {
                if((i == 0 && j == 0) || (i == ligne-1 && j == colone-1))
                    t[i][j] = 'A';
                else if((i == 0 && j == colone-1) || (i == ligne-1 && j == 0))
                    t[i][j] = 'C';
                else if (((i == 0 && j != 0 && j != colone-1) || (i == ligne-1 && j != 0 && j != colone-1)) 
                    || ((j == 0 && i != 0 && i != ligne-1) || (j == colone-1 && i != 0 && i != ligne-1)))
                    t[i][j] = 'B';
                else
                    t[i][j] = ' ';
                j++;
            }
            i++;
        }
    }
    i = 0;
    while (i < ligne)
    {
        j = 0;
        while (j < colone)
        {
            write(1, &t[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        rush((av[1][0] - '0'),(av[2][0] -'0'));
    else
        write(1, "Argument Eroor!", 15);
    return 0;
}