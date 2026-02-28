#include <string>
#include <utility>

using namespace std;

class Playfair {
    private:
        char matrix[5][5];
        string key;

        void generateMatrix();
        pair<int, int> findPosition(char c) const;
        string preprocessText(const string& text) const;

    public:
        Playfair(const string& key);

        string encrypt(const string& plaintext) const;
        string decrypt(const string& ciphertext) const;

        void printMatrix() const;
};
