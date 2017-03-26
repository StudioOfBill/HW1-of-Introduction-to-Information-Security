/*
 * Copyright 2017 Bill T. Sun. All Rights Reserved.
 *
Licensed under the MIT License;
==============================================================================*/

//Vernam proposed the autokey system


#include <iostream>
#include <fstream>
using namespace std;

string get_key() {
    ifstream key_file("Key.txt");
    if (!key_file.is_open()) {
        cout << "Error opening key file";
        exit (1);
    }

    string key;
    key_file >> key;
    key_file.close();

    return key;
}

void encrypt(string key) {
    const int SIZE = sizeof(key) * 128;
    char buffer[SIZE];

    ifstream plaintext("Plaintext.txt");
    if (!plaintext.is_open()) {
        cout << "Error opening plaintext file";
        exit (1);
    }

    ofstream ciphertext("Ciphertext.txt");

    while (!plaintext.eof()) {
        plaintext.getline(buffer, 1e3);

        for (int i = 0; buffer[i] != NULL; ++i) {
            if (buffer[i] > 96) {
                buffer[i] -= 32;
            }
            buffer[i] -= 65;
        }

        for (int i = 0; buffer[i] != NULL; ++i) {
            ciphertext << (char)(((buffer[i] + (key[i % key.size()] - 65)) % 25) + 65);
        }
    }

    plaintext.close();
    ciphertext.close();
}

void decrypt(string key) {
    const int SIZE = sizeof(key) * 128;
    char buffer[SIZE];

    ifstream ciphertext("Ciphertext.txt");
    if (!ciphertext.is_open()) {
        cout << "Error opening ciphertext file";
        exit (1);
    }

    ofstream plaintext("Plaintext.txt");

    while (!ciphertext.eof()) {
        ciphertext.getline(buffer, 1e3);

        for (int i = 0; buffer[i] != NULL; ++i) {
            buffer[i] -= 65;
        }

        for (int i = 0; buffer[i] != NULL; ++i) {
            plaintext << (char)(((buffer[i] - (key[i % key.size()] - 65) + 25) % 25) + 97);
        }
    }

    ciphertext.close();
    plaintext.close();
}

int main() {
    //encryption function
    //encrypt(get_key());

    //decryption function
    //decrypt(get_key());

    return 0;
}