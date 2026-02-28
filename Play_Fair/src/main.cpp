#include "playfair.h"
#include <iostream>

int main() {
    Playfair cipher("monarchy");

    cipher.printMatrix();

    std::string plaintext = "do you like to study a cryptography course";
    std::string encrypted = cipher.encrypt(plaintext);

    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << cipher.decrypt(encrypted) << std::endl;

    return 0;
}