#include <iostream>
#include <dlfcn.h>
using namespace std;

int main() {
    // Load the dynamic library
    void* handle = dlopen("/Users/dlitvakk21/CLionProjects/untitled3/libceaser.dylib", RTLD_LAZY);

    if (!handle) {
        cout << "Error: " << dlerror() << endl;
        return 1;
    }

    // Load the function from the library
    typedef char* (*encrypt_t)(char*, int);
    encrypt_t encrypt = encrypt_t(dlsym(handle, "encrypt"));

    if (!encrypt) {
        cout << "Error: " << dlerror() << endl;
        dlclose(handle);
        return 1;
    }

    typedef char* (*decrypt_t)(char*, int);
    decrypt_t decrypt = decrypt_t(dlsym(handle, "decrypt"));

    if (!decrypt) {
        cout << "Error: " << dlerror() << endl;
        dlclose(handle);
        return 1;
    }

    // Example usage of the encrypt function
    char message[] = "If he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out.";
    int key = 7;

    char* encrypted_message = encrypt(message, key);
    cout << encrypted_message << endl;

    char encrypt_message[] = "Pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";

    char* decrypted_message = decrypt(encrypt_message, key);
    cout << decrypted_message << endl;

// Close the library
    dlclose(handle);
    return 0;
}
