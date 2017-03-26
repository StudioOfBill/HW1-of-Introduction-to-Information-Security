/*
 * Copyright 2017 Bill T. Sun. All Rights Reserved.
 *
Licensed under the MIT License;
==============================================================================*/

//Row transposition


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
    const int SIZE = 1024;
    char buffer[SIZE];

    ifstream plaintext("Plaintext.txt");
    if (!plaintext.is_open()) {
        cout << "Error opening plaintext file";
        exit (1);
    }

    ofstream ciphertext("Ciphertext.txt");

    while (!plaintext.eof()) {
        plaintext.getline(buffer, 1e3);

        for (int i = 0; i < key.size(); ++i) {
            for (int j = 0; buffer[j] != NULL; ++j) {
                if ((j % key.size()) == key.find(i + 49)) {
                    ciphertext << buffer[j];
                }
            }
        }
    }

    plaintext.close();
    ciphertext.close();
}

void decrypt(string key) {
    const int SIZE = 1024;
    char buffer[SIZE];

    ifstream ciphertext("Ciphertext.txt");
    if (!ciphertext.is_open()) {
        cout << "Error opening ciphertext file";
        exit (1);
    }

    ofstream plaintext("Plaintext.txt");

    while (!ciphertext.eof()) {
        ciphertext.getline(buffer, 1e3);

        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < key.size(); ++i) {
                plaintext << buffer[(key[i] - 49) * 2 + j];
            }
        }
    }

    ciphertext.close();
    plaintext.close();
}

int main() {
    //encryption function
    //encrypt(get_key());

    //decryption function
    decrypt(get_key());

    return 0;
}