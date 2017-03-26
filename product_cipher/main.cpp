/*
 * Copyright 2017 Bill T. Sun. All Rights Reserved.
 *
Licensed under the MIT License;
==============================================================================*/

//Product cipher


#include <iostream>
#include <fstream>
using namespace std;

int key[16] = {15, 11, 2, 10, 16, 3, 7, 14, 4, 12, 9, 06, 01, 05, 8, 13};

//void get_key() {
//    ifstream key_file("Key.txt");
//    if (!key_file.is_open()) {
//        cout << "Error opening key file";
//        exit (1);
//    }
//
//    for (int i = 1; i < 17; ++i) {
//        key_file.operator>>(key[i]);
//    }
//
//    key_file.close();
//}

void encrypt() {
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

        for (int i = 0; buffer[i] != NULL; ++i) {
            ciphertext << buffer[key[i] - 1];
        }
    }

    plaintext.close();
    ciphertext.close();
}

void decrypt() {
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
        char temp[16];

        for (int i = 0; buffer[i] != NULL; ++i) {
            temp[key[i] - 1] = buffer[i];
        }

        for (int i = 0; i < 16; ++i) {
            plaintext << temp[i];
        }
    }

    ciphertext.close();
    plaintext.close();
}

int main() {
    //encryption function
    //encrypt();

    //decryption function
    decrypt();

    return 0;
}