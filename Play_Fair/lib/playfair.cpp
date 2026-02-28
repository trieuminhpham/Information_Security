#include "playfair.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Playfair::Playfair(const string& key) {
    this->key = key;
    generateMatrix();
}

void Playfair::generateMatrix() {
    string tempKey;
    vector<bool> used(26, false);

    for (char c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I';

        if (isalpha(c) && !used[c - 'A']) {
            tempKey += c;
            used[c - 'A'] = true;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            tempKey += c;
        }
    }

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = tempKey[index++];
        }
    }
}

void Playfair::printMatrix() const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

pair<int, int> Playfair::findPosition(char c) const {
    if (c == 'J') c = 'I';

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == c) 
                return {i, j};
        }
    }

    return {-1, -1};
}

string Playfair::preprocessText(const string& text) const {
    string cleaned;

    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            cleaned += c;
        }
    }

    string result;
    int i = 0;

    while (i < cleaned.length()) {
        char first = cleaned[i];
        char second;

        if (i + 1 < cleaned.length()) {
            second = cleaned[i + 1];

            if (first == second) {
                result += first;
                result += 'X';
                i += 1;
            } else {
                result += first;
                result += second;
                i += 2; 
            }
        } else {
            result += first;
            result += 'X';
            i += 1;
        }
    }

    return result;
}

string Playfair::encrypt(const string& plaintext) const {
    string text = preprocessText(plaintext);
    string cipher;

    for (size_t i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        auto posA = findPosition(a);
        auto posB = findPosition(b);

        if (posA.first == posB.first) {
            cipher += matrix[posA.first][(posA.second + 1) % 5];
            cipher += matrix[posB.first][(posB.second + 1) % 5];
        }
        else if (posA.second == posB.second) {
            cipher += matrix[(posA.first + 1) % 5][posA.second];
            cipher += matrix[(posB.first + 1) % 5][posB.second];
        }
        else {
            cipher += matrix[posA.first][posB.second];
            cipher += matrix[posB.first][posA.second];
        }
    }

    return cipher;
}

string Playfair::decrypt(const string& ciphertext) const {
    string plain;

    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];

        auto posA = findPosition(a);
        auto posB = findPosition(b);

        if (posA.first == posB.first) {
            plain += matrix[posA.first][(posA.second + 4) % 5];
            plain += matrix[posB.first][(posB.second + 4) % 5];
        }
        else if (posA.second == posB.second) {
            plain += matrix[(posA.first + 4) % 5][posA.second];
            plain += matrix[(posB.first + 4) % 5][posB.second];
        }
        else {
            plain += matrix[posA.first][posB.second];
            plain += matrix[posB.first][posA.second];
        }
    }

    return plain;
}
