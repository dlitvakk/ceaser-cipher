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

int main() {
    char message[] = "If he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out.";
    int key = 7;

    char* encryptedMessage = encrypt(message, key);

    if (encryptedMessage) {
        cout << encryptedMessage << endl;
        free(encryptedMessage);
    } else {
        cout << "Memory allocation failed" << endl;
    }

    return 0;
}
