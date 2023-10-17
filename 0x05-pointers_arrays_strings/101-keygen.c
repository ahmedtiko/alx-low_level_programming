#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * random_char - Returns a random character from the given charset.
 * @charset: The character set to choose from.
 * @charset_length: The length of the character set.
 * Return: A random character.
 */


char random_char(const char *charset, int charset_length) 
{
    int index = rand() % charset_length;
    return charset[index];
}

/**
 * main - Entry point for the program.
 * Return: Always 0.
 */

int main() 
{
    const char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    int num_uppercase = 7;
    int num_digits = 3;
    int total_length = 10;
    int i, j;
    char temp;

    srand(time(NULL));

    char password[11];

    if (total_length != num_uppercase + num_digits) 
    {
        printf("Invalid password length.\n");
        return 1;
    }

    for (i = 0; i < num_uppercase; i++) 
    {
        password[i] = random_char(uppercase_letters, sizeof(uppercase_letters) - 1);
    }

    for (i = num_uppercase; i < total_length; i++) 
    {
        password[i] = random_char(digits, sizeof(digits) - 1);
    }

    password[total_length] = '\0';

    for (i = 0; i < total_length - 1; i++) 
    {
        j = i + rand() % (total_length - i);
        temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("Generated Password: %s\n", password);

    return (0);
}
