#include <stdio.h>
// Include project description
char key = 7;

// Encryption for Caesar cipher takes an encryption key between 0-25 
//(distance of shift) and an input message, then produce an encrypted result.
char encryptCaesar (char e);

// This decryption for Caesar cipher should take an encrypted message and decrypt it 
// using the supplied key
char decryptCaesar (char e);

char encryptSub (char e);

char decryptSub(char e);

int main() {
    FILE *input;
    FILE *output;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    while (feof(input) == 0){
            char e, f;
            fscanf(input, "%c", &e);
            f = decryptCaesar(e);  
            fprintf(output, "%c", f);
}

    return 0;
}

char encryptCaesar (char e){
   
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            
            if(e + key > 90){ //overflow
                //e = 65 + (((e - 65) - 26) + key); //just don't touch it
                e = e - 26 + key;
            } else if (65 <= e + key) {
                e = e + key;
            }
            return e;       
}

char decryptCaesar (char e){
    if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            
            if(e - key < 65 && e >= 65){ //overflow
                e = e - key + 26;
            } else if (e - key >= 65) {
                e = e - key;
            }
            return e; 
}

char encryptSub (char s){
    return 0;
}

char decryptSub(char f){
    return 0;
}