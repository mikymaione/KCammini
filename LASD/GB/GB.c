#include <string.h>
#include <stdlib.h>

char * bool_ul_to_str(unsigned long l)
{
    return (l == 0 ? "false" : "true");
}

char * bool_l_to_str(long l)
{
    return (l == 0 ? "false" : "true");
}

char * bool_ui_to_str(unsigned int l)
{
    return (l == 0 ? "false" : "true");
}

char * bool_i_to_str(int l)
{
    return (l == 0 ? "false" : "true");
}

long random_number(long min_num, long max_num) //chiamare prima srand(time(NULL));
{
    long low_num = 0;
    long hi_num = 0;

    if (min_num > max_num)
        max_num = min_num + 1;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
    }
    else
    {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    long r = ((rand() % (hi_num - low_num)) + low_num);

    if (r < min_num)
        r = min_num;
    else if (r > max_num)
        r = max_num;

    return r;
}

char *random_string(unsigned long lunghezza) //chiamare prima srand(time(NULL));
{
    int x;
    unsigned long i;
    char * Lettere = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char * r = calloc(lunghezza, sizeof (char));
    size_t le = strlen(Lettere);

    for (i = 0; i < lunghezza; i++)
    {
        x = rand() % le;
        r[i] = Lettere[x];
    }

    return r;
}

char *CharAppend(const char *a, const char *b)
{
    size_t na = 0;
    size_t nb = 0;
    size_t nc = 0;

    if (a)
        na = sizeof a / sizeof (char);

    if (b)
        nb = sizeof b / sizeof (char);

    if (na < 1)
        na = 0;

    if (nb < 1)
        nb = 0;

    nc = na + nb;

    if (nc > 0)
    {
        size_t i, x;
        char *c = calloc(nc, sizeof (char));
        x = 0;

        if (na > 0)
            for (i = 0; i < na; i++)
            {
                c[x] = a[i];
                x += 1;
            }

        if (nb > 0)
            for (i = 0; i < nb; i++)
            {
                c[x] = b[i];
                x += 1;
            }

        return c;
    }

    return "";
}