#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

void Encrypt(void);
void Decrypt(void);
void Brute_Force(void);

int main(void)
{
    printf("Press 1 for Encryption\n");
    printf("Press 2 for decryption with key\n");
    printf("Press 3 for brute force decryption\n");
    int x = get_int("Enter Function to be done: ");
    if (x == 1)
    {
        Encrypt();
    }
    else if (x == 2)
    {
        Decrypt();
    }
    else if(x == 3)
    {
        Brute_Force();
    }
    else
    {
        printf("Enter Valid options from 1 2 3\n");
    }
}
 void Encrypt(void)
 {
    int key = get_int("Enter encryption key: ");
    string s = get_string("Enter text to be encrypted: ");
    printf("The Encrypted text is: ");
    for(int i = 0 ; i < strlen(s);i++)
    {
        if(s[i]>='a' && s[i] <= 'z')
        {
            printf("%c",(s[i] - 'a' + key)%26 + 'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c",(s[i] - 'A' + key)%26 + 'A');
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
 }


 void Decrypt(void)
 {
    string s = get_string("Enter text to be decrypted: ");
    int key = get_int("Enter decyption key: ");
    printf("The Decrypted text is: ");
    for(int i = 0 ; i < strlen(s);i++)
    {
        if(s[i]>='a' && s[i] <= 'z')
        {
            printf("%c",(s[i] - 'a' - key)%26 + 'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c",(s[i] + 'A' - key)%26 + 'A');
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
 }

void Brute_Force(void)
{
    string s = get_string("Enter text to be decrypted: ");

    for(int j = 0; j < 26; j++)
    {
        printf("\nKey %i: ", j);
        for(int i = 0 ; i < strlen(s);i++)
        {
            if(s[i]>='a' && s[i] <= 'z')
            {
                printf("%c",(s[i] - 'a' - j + 26)%26 + 'a');
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c",(s[i] - 'A' - j + 26)%26 + 'A');
            }
            else
            {
                printf("%c",s[i]);
            }
        }

        printf("\n");
    }
}



