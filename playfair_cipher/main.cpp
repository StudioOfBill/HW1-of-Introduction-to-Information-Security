/*
 * Copyright 2017 Bill T. Sun. All Rights Reserved.
 *
Licensed under the MIT License;
==============================================================================*/

//Monoalphabetic cipher


#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <string>
#include <curses.h>

using namespace std;

string get_key() {
    ifstream key_file("Key.txt");
    if (!key_file.is_open()) {
        cout << "Error opening key file";
        exit (1);
    }

    string key, temp;
    bool uniq[27];
    memset(uniq, FALSE, sizeof(uniq));

    key_file >> temp;
    key.assign("?");
    int i = 0;

    for (i = 0; temp[i] != NULL; ++i) {
        uniq[temp[i] - 64] = TRUE;
    }

    for (int j = 1; j < 27; ++j) {
        if ((j + 64) == 'J') {
            continue;
        }
        else if (uniq[j]) {
            char temp_letter = j + 64;
            key += temp_letter;
        }
    }

    for (int j = 1; j < 27; ++j) {
        if ((j + 64) == 'J') {
            continue;
        }
        else if (!uniq[j]) {
            char temp_letter = j + 64;
            key += temp_letter;
        }
    }

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

        for (int i = 0; buffer[i] != NULL; ++i) {
            if (buffer[i] > 96) {
                buffer[i] -= 32;
            }
        }

        for (int i = 0; buffer[i] != NULL; ++i) {
            if (buffer[i] > 73) {
                buffer[i]--;
            }
            buffer[i] -= 64;
        }

        for (int j = 0; buffer[j] != NULL; j += 2) {
            int row[2], col[2];
            row[0] = (buffer[j] / 5),
            col[0] = (buffer[j] % 5),
            row[1] = (buffer[j + 1] / 5),
            col[1] = (buffer[j + 1] % 5);
            if (row[0] == row[1]) {
                ciphertext << key[row[0] * 5 + (col[0] + 1) % 5];
                ciphertext << key[row[1] * 5 + (col[1] + 1) % 5];
            } else {
                if (col[0] == col[1]) {
                    ciphertext << key[((row[0] + 1) % 5) * 5 + col[0]];
                    ciphertext << key[((row[1] + 1) % 5) * 5 + col[1]];
                } else {
                    ciphertext << key[row[0] * 5 + col[1]];
                    ciphertext << key[row[1] * 5 + col[0]];
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

        for (int i = 0; buffer[i] != NULL; ++i) {
            if (buffer[i] > 73) {
                buffer[i]--;
            }
            buffer[i] -= 64;
        }

        for (int j = 0; buffer[j] != NULL; j += 2) {
            int row[2], col[2];
            row[0] = (buffer[j] / 5),
            col[0] = (buffer[j] % 5),
            row[1] = (buffer[j + 1] / 5),
            col[1] = (buffer[j + 1] % 5);
            if (row[0] == row[1]) {
                plaintext << key[row[0] * 5 + (col[0] - 1) % 5] + 32;
                plaintext << key[row[1] * 5 + (col[1] - 1) % 5] + 32;
            } else {
                if (col[0] == col[1]) {
                    plaintext << key[((row[0] - 1) % 5) * 5 + col[0]] + 32;
                    plaintext << key[((row[1] - 1) % 5) * 5 + col[1]] + 32;
                } else {
                    plaintext << key[row[0] * 5 + col[1]] + 32;
                    plaintext << key[row[1] * 5 + col[0]] + 32;
                }
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
    //decrypt(get_key());

    return 0;
}