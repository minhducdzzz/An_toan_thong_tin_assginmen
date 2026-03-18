#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hoán vị
void swapVal(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void KSA(vector<int> &S, vector<int> K) {
    int n = S.size();
    int j = 0;

    for (int i = 0; i < n; i++) {
        j = (j + S[i] + K[i % K.size()]) % n;
        swapVal(S[i], S[j]);
    }
}

vector<int> PRGA(vector<int> S, int len) {
    int n = S.size();
    int i = 0, j = 0;
    vector<int> keyStream;

    for (int k = 0; k < len; k++) {
        i = (i + 1) % n;
        j = (j + S[i]) % n;

        swapVal(S[i], S[j]);

        int t = (S[i] + S[j]) % n;
        keyStream.push_back(S[t]);
    }

    return keyStream;
}

// String → ASCII
vector<int> stringToASCII(string text) {
    vector<int> result;
    for (char c : text) {
        result.push_back((int)c);
    }
    return result;
}
// XOR
vector<int> RC4(vector<int> plaintext, vector<int> keyStream) {
    vector<int> cipher;
    for (int i = 0; i < plaintext.size(); i++) {
        cipher.push_back(plaintext[i] ^ keyStream[i]);
    }
    return cipher;
}

int main() {
    vector<int> S(10);
    for (int i = 0; i < 10; i++) S[i] = i;

    vector<int> K = {2, 4, 1, 7};

    string text = "cybersecurity";
    KSA(S, K);

    vector<int> keyStream = PRGA(S, text.length());

    // ASCII
    vector<int> plaintext = stringToASCII(text);
   // ma hoa
    vector<int> cipher = RC4(plaintext, keyStream);

    cout << "i\tChar\tASCII\tKey\tCipher\tCipher_ASCII\n";

    for (int i = 0; i < text.length(); i++) {
        cout << i << "\t"
             << text[i] << "\t"
             << plaintext[i] << "\t"
             << keyStream[i] << "\t"
             << cipher[i] << "\t"
             << (char)cipher[i] << endl;
    }

    //  dòng khóa
    cout << "\nKeyStream: ";
    for (int x : keyStream) cout << x << " ";

    //  dạng số
    cout << "\nCipher (so): ";
    for (int x : cipher) cout << x << " ";

    //  dạng ASCII
    cout << "\nCipher (ASCII): ";
    for (int x : cipher) cout << (char)x;

    cout << endl;

    return 0;
}