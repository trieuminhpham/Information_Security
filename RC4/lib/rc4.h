#ifndef RC4_H
#define RC4_H

#include <vector>
#include <string>

class RC4 {
private:
    std::vector<int> S;
    int i;
    int j;
    int N;

public:
    RC4(const std::vector<int>& key, int state_size = 256);
    int next_keystream();
    std::string encrypt(const std::string& plaintext);
};

void run_rc4_assignment();

#endif