#include "rc4.h"
#include <utility>
#include <iostream>
#include <iomanip>

using namespace std;

RC4::RC4(const std::vector<int>& key, int state_size) {
    this->N = state_size;
    this->S.resize(N);
    this->i = 0;
    this->j = 0;

    for (int k = 0; k < N; ++k) {
        S[k] = k;
    }

    int j_ksa = 0;
    int key_length = key.size();
    for (int k = 0; k < N; ++k) {
        j_ksa = (j_ksa + S[k] + key[k % key_length]) % N;
        std::swap(S[k], S[j_ksa]);
    }
}

int RC4::next_keystream() {
    i = (i + 1) % N;
    j = (j + S[i]) % N;
    std::swap(S[i], S[j]);
    int t = (S[i] + S[j]) % N;
    return S[t];
}

std::string RC4::encrypt(const std::string& plaintext) {
    std::string ciphertext = "";
    for (char c : plaintext) {
        int k = next_keystream();
        ciphertext += static_cast<char>(c ^ k);
    }
    return ciphertext;
}

void run_rc4_assignment() {
    int N = 10;
    vector<int> K = {2, 4, 1, 7};
    string message = "cybersecurity";

    cout << "===== BAI TAP RC4 - MON AN TOAN THONG TIN =====" << endl;
    cout << "Thong diep m(t) : " << message << endl;
    cout << "Chieu dai       : " << message.length() << " ky tu.\n" << endl;

    RC4 rc4_keystream_gen(K, N);
    RC4 rc4_cipher(K, N);

    cout << "[Yeu cau 1] Cac gia tri dong khoa Keystream tao ra tu K va S:" << endl;
    vector<int> keystream;
    for (size_t k = 0; k < message.length(); ++k) {
        int key_byte = rc4_keystream_gen.next_keystream();
        keystream.push_back(key_byte);
        cout << key_byte << " ";
    }
    cout << "\n\n";

    cout << "[Yeu cau 2] Qua trinh ma hoa tung byte C(t) = m(t) XOR Key(t):" << endl;
    
    string ciphertext = rc4_cipher.encrypt(message);

    cout << left << setw(5) << "t" 
         << setw(10) << "m(t)" 
         << setw(12) << "ASCII_m" 
         << setw(10) << "Key(t)" 
         << setw(12) << "ASCII_C" 
         << setw(10) << "C(t)[Char]" << endl;
    cout << string(60, '-') << endl;

    for (size_t k = 0; k < message.length(); ++k) {
        cout << left << setw(5) << k
             << setw(10) << message[k]
             << setw(12) << (int)message[k]
             << setw(10) << keystream[k]
             << setw(12) << (int)ciphertext[k]
             << ciphertext[k] << endl;
    }

    cout << "\nBan ma cuoi cung (ASCII): " << ciphertext << "\n" << endl;
}