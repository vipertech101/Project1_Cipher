#include <stdio.h>
// Include project description
char key = 3;
//Function definitions need comments too
// Encryption for Caesar cipher should take an encryption key between 0-25 
//(distance of shift) and an input message, then produce an encrypted result.
char encryptCaesar (char e);
// Decryption for Caesar cipher should take an encrypted message and decrypt it by testing
// keys and checking for intelligble words
/*void decryptCaesar (char *str);

void encryptSub (char *str);

void decryptSub(char *str);*/

int main() {
    FILE *input;
    FILE *output;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    while (feof(input) == 0){
            char e, f;
            fscanf(input, "%c", &e);
            f = encryptCaesar(e);  
            fprintf(output, "%c", f);
}

    return 0;
}

char encryptCaesar (char e){
   
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            
            if(e > 65 + key && e <= 90){
                e = 65 + (26 - (e - 65) - key);
            } else if (e >= 65 && e <= 65 + key) {
                e = e + key;
            }
            return e;
            
}
