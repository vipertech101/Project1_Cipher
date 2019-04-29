#ifndef VARIABLE
#define VARIABLE
char key = 7; //hardcoded rotation cipher key, number == how many units you want each alphabet letter shifted

// Encryption for Caesar cipher takes an encryption key between 0-25 
//(distance of shift) and an input message, then produce an encrypted result.
// The char e passed to this function and to decryptCaesar is each character in the input file being ciphered, the e returned is the ciphered file to be printed to the output file
// These do not mess with any punctuation/ non-letter characters
char encryptCaesar (char e){
   if ((e >= 97 && e <= 122)||(e >= 65 && e <= 90)){
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            
            if(e + key > 90){ //overflow
                //e = 65 + (((e - 65) - 26) + key); //just don't touch it
                e = e - 26 + key;
            } else if (65 <= e + key) {
                e = e + key;
            }
        }
            return e; 
        
}
// This decryption for Caesar cipher should take an encrypted message and decrypt it 
// using the supplied key. char e fed to function is character from input file, returned e is ciphered character to print to output file
// Does not edit punctuation/ non-letter characters
char decryptCaesar (char e){
    if ((e >= 97 && e <= 122)||(e >= 65 && e <= 90)){
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            
            if(e - key < 65 && e >= 65){ //overflow
                e = e - key + 26;
            } else if (e - key >= 65) {
                e = e - key;
            }
        }
            return e; 
}
//takes each character from input file, first array is organised alphabet using ascii decimals, second array is cipher key using ascii decimals
//checks each position in first array until it is equal to the input character, then converts it to the corresponding character in the key
//if the fed character is not a letter, it is not edited
char encryptSub (char e){
    if ((e >= 97 && e <= 122)||(e >= 65 && e <= 90)){
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
        }
    return e;
}
//checks each character for position in sub key, then converts to corresponding character in alphabet, simply reversing the encryption process
//non letter characters are not edited
char decryptSub(char e){
    if ((e >= 97 && e <= 122)||(e >= 65 && e <= 90)){
            if(e >= 97 && e <= 122){ //make letter a capital
                e = e - 32;
            }
            char alpha[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
            char subkey[] = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};
            for (int i = 0 ; i < 26 ; i++) {
                if (subkey[i] == e) {
                    e = alpha[i];
                    break;
                } //that hilarious moment when you realise that this entire function is unnecessary, as it does the exact same thing as the encryption function, so really you just needed to call the encryption function again on an already encrypted message to decrypt
            }
        }
    return e;
}

/* char keylessRot(char e){
    int tKey = 0;
    if (message makes sense) {
        return stuff;
    } else {
        tKey++;
    }
} */

#endif