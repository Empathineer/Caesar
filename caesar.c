#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string.h>



int main(int argc, string argv[])
// int main(int argc, char** argv)
{
    //Extracting the main key argument from the string array
    string str_key = argv[1];

    //Validating the key
    if (str_key == NULL )
    {
        printf("Usage: ./caesar key.\n");
        return 1;
    }


    int key = atoi(argv[1]);

    if (argc != 2 || key <= 0 )
    {
        printf("Usage: ./caesar key.\n");
        return 1;
    }
    else
    {

        char mychar[20];
        strcpy(mychar, str_key);


        for (int j = 0; j < strlen(mychar); j++)
        {

            if (isalpha(mychar[j]) != 0 )
            {
                printf("Usage: ./caesar key.\n");
                return 1;
            }
        }



        printf("Success\n");

        // int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        int str_length = strlen(plaintext);
        char ciphertext[str_length];

        printf("ciphertext: ");

        for (int i = 0; i < str_length; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if isupper(plaintext[i])
                {
                    int asc_val = (int)plaintext[i]; //get ascii value
                    int alpha_idx = asc_val - 65; //convert to alpha index 0-25
                    int c_i = (alpha_idx + key) % 26; //shift by key positions in alpha index range
                    char new_letter = (char)(c_i + 65); //convert back to ascii
                    // printf("asc_val: %c\n", ); //convert char in ciphertext to ascii value
                    ciphertext[i] = new_letter;
                    printf("%c",ciphertext[i]);

                }

                else
                {
                    int asc_val = (int)plaintext[i]; //get ascii value
                    int alpha_idx = asc_val - 97; //convert to alpha index 0-25
                    int c_i = (alpha_idx + key) % 26; //shift by key positions in alpha index range
                    char new_letter = (char)(c_i + 97); //convert back to ascii
                    ciphertext[i] = new_letter;
                    printf("%c",ciphertext[i]);
                }

            }
            else
            {
                ciphertext[i] = plaintext[i];
                printf("%c",ciphertext[i]);
            }


        }

        printf("\n");

        // printStr(ciphertext);

    }

    return 0;

}


