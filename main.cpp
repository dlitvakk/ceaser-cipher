#include <iostream>
using namespace std;

char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = (char*)malloc((length + 1) * sizeof(char)); // Allocate memory for the encrypted string

    for (int i = 0; i < length; i++) {
        char curr_char = rawText[i];

        if (isalpha(curr_char)) { // check if the character is an alphabet
            char base = islower(curr_char) ? 'a' : 'A'; // if the character is lowercase, then we start from lowercase letters, otherwise uppercase
            encryptedText[i] = (curr_char - base + key) % 26 + base;
        } else {
            encryptedText[i] = curr_char;
        }
    }

    encryptedText[length] = '\0'; // the last character is the end of the string
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = (char*)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        char curr_char = encryptedText[i];

        if (isalpha(curr_char)) { // check if the character is an alphabet
            char base = islower(curr_char) ? 'a' : 'A'; // if the character is lowercase, then we start from lowercase letters, otherwise uppercase
            decryptedText[i] = (curr_char - base + 26 - key) % 26 + base;
        } else {
            decryptedText[i] = curr_char;
        }
    }

    decryptedText[length] = '\0'; // the last character is the end of the string
    return decryptedText;
}

int main() {
    char message[] = "If he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out.";
    int key = 7;

    char* encrypted_message = encrypt(message, key);

    cout << encrypted_message << endl;
    free(encrypted_message);

    char encrypted_text[] = "Pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";;

    char* decrypted_message = decrypt(encrypted_text, key);

    cout << decrypted_message << endl;
    free(decrypted_message);

    return 0;
}
