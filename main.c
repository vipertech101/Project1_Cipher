#include <stdio.h>
#include <string.h> //probably not necessary, I don't even think it's being used
#include "cipher.h" //just my own header file because why not practice having somewhere else to put all the function definitions

// This program serves to read a char input from a file and then either encrypt or decrypt this input, writing a char output to another file
// It is capable of encrypting using a rotation (Caesar) cipher or a substitution cipher
// input.txt as the name implies is a text file in which the cipher input should be written prior to running the program
// output.txt is the text file where the program will write 

//char key = 7; //this is rotation cipher key, must be hardcoded initially
//char encryptCaesar (char e);
//char decryptCaesar (char e);
//char encryptSub (char e);
//char decryptSub(char e);

int main() {
    FILE *input; //specifies as a unique file location
    FILE *output;
    
    input = fopen("input.txt", "r"); //initialises the file input.txt for reading
    output = fopen("output.txt", "w"); //initialises the file output.txt for writing
    

    while (feof(input) == 0){ // until the end of the file...
            char e, f;
            fscanf(input, "%c", &e); // reads character from input file and stores in e
            f = decryptSub(e);  // sends character to function for processing
            fprintf(output, "%c", f); //prints processed character to ouput file
}

    return 0;
}
/*
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

char encryptSub (char e){
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            char alpha[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
            char subkey[] = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};
            for (int i = 0 ; i < 26 ; i++) {
                if (alpha[i] == e) {
                    e = subkey[i];
                    break;
                }
            }
    return e;
}

char decryptSub(char e){
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            char alpha[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
            char subkey[] = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};
            for (int i = 0 ; i < 26 ; i++) {
                if (subkey[i] == e) {
                    e = alpha[i];
                    break;
                }
            }
    return e;
}
*/