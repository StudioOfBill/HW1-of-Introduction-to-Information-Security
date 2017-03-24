/*
 * Copyright 2017 Bill T. Sun. All Rights Reserved.
 *
Licensed under the MIT License;
==============================================================================*/

//Caser Cipher


#include <iostream>
#include <fstream>
using namespace std;

int get_key() {
    ifstream key_file("Key.txt");
    if (!key_file.is_open()) {
        cout << "Error opening key file";
        exit (1);
    }

    int key;
    key_file >> key;
    key_file.close();

    return key;
}

void encrypt(int key) {
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
            int temp = buffer[i] + key;
            if (temp > 122) {
                temp %= 122;
            } else if ((temp > 90) && (temp < 97)) {
                temp %= 90;
            }

            ciphertext << (char)(temp);
        }
    }

    plaintext.close();
    ciphertext.close();
}

void decrypt(int key) {
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

        for (int i = 0; buffer[i] != NULL; ++i) {
            int temp = buffer[i] - key;
            if (temp < 65) {
                temp += 26;
            } else if ((temp > 90) && (temp < 97)) {
                temp += 26;
            }

            plaintext << (char)(temp);
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