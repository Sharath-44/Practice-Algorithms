#include <stdio.h>
#include <string.h>

int checkVowel(int c)
{
    char ch;
    ch = tolower(c);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void invertVowels(char *s)
{
    // Your code here
    char *ptr = s;
    char *cpt = ptr + strlen(ptr);

    while (ptr < cpt)
    {
        while (ptr < cpt && !checkVowel(*ptr))
        {
            ptr++;
        }
        while (ptr < cpt && !checkVowel(*cpt))
        {
            cpt--;
        }
        if (ptr != cpt)
        {
            char c = *ptr;
            *ptr++ = *cpt;
            *cpt-- = tolower(c);
        }
    }
}

int main()
{
    char s[100000];
    scanf("%s", s);
    invertVowels(s);
    printf("%s", s);
    return 0;
}