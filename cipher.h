#ifndef VARIABLE
#define VARIABLE
char key = 7;

// Encryption for Caesar cipher takes an encryption key between 0-25 
//(distance of shift) and an input message, then produce an encrypted result.
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
// This decryption for Caesar cipher should take an encrypted message and decrypt it 
// using the supplied key
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

#endif