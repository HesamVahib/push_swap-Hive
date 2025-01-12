#include "push_swap.h"

static int count_words(char *s, char c)
{
    int count;
    bool in_word;

    count = 0;
    while (*s)
    {
        in_word = false;
        while (*s && *s == c)
            s++;
        while (*s && *s != c)
        {
            in_word = true;
            s++;
        }
        if (in_word)
            count++;
    }
    return (count);
}

static char *next_word(char *s, char c)
{
    static int i = 0;
    char *nxt_word;
    size_t len;
    int j;

    len = 0;
    j = 0;
    while (s[i] == c)
        ++i;
    while (s[i + len] && s[i + len] != c)
        ++len;
    nxt_word = (char *)malloc(sizeof(char) * (len + 1));
    if (!nxt_word)
        return (NULL);
    while ((s[i] && s[i] != c))
        nxt_word[j++] = s[i++];
    nxt_word[j] = '\0';
    return (nxt_word);
}

char **ft_split(char const *s, char c) //main was char *s
{
    int words_count;
    char **words;
    int i;

    i = 0;
    words_count = count_words((char *)s, c);
    if (!words_count)
        exit (1);
    words = (char **)malloc(sizeof(char *) * (words_count + 1));
    if (!words)
        return (NULL);
    while (words_count-- >= 0)
    {
        if (i == 0)
        {
            words[i] = malloc(sizeof(char) * 1);
            if (!words[i])
                return (NULL);
            words[i][0] = '\0';
                continue;
        }
        words[i++] = next_word((char *)s, c);
    }
    words[i] = NULL;
    return (words);
}
