#include <stdio.h>
#include <string.h>

int roman_to_integer(char *s)
{
    int result = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        switch (s[i])
        {
        case 'I':
            result = (s[i]== );
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            result += 10;
            break;
        case 'L':
            result += 50;
            break;
        case 'C':
            result += 100;
            break;
        case 'D':
            result += 500;
            break;
        case 'M':
            result += 1000;
            break;
        default:
            printf("Invalid Roman numeral character");
            return -1;
        }
    }

    return result;
}

int main()
{
    // Example usage
    char s[] = "XXVI";
    int integer_value = roman_to_integer(s);

    if (integer_value != -1)
    {
        printf("The integer value of %s is %d\n", s, integer_value);
    }

    return 0;
}
