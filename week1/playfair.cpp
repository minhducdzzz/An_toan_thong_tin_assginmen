#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Tạo ma trận 5x5
void taoMaTran(string key, char matrix[5][5]) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string result = "";

    // Thêm key 
    for (char &c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (isalpha(c) && result.find(c) == string::npos)
            result += c;
    }

    // Thêm các chữ còn lại
    for (char c : alphabet) {
        if (result.find(c) == string::npos)
            result += c;
    }

    // Đổ vào ma trận
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = result[k++];
}

// Tìm vị trí chữ trong ma trận
void timViTri(char matrix[5][5], char c, int &row, int &col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                row = i;
                col = j;
            }
}

// Chuẩn hóa văn bản
string chuanHoa(string text) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            result += c;
        }
    }

    // Chèn X nếu trùng
    for (int i = 0; i < result.length(); i += 2) {
        if (i + 1 < result.length() && result[i] == result[i + 1])
            result.insert(i + 1, 1, 'X');
    }

    // Nếu lẻ thì thêm X
    if (result.length() % 2 != 0)
        result += 'X';

    return result;
}

// Mã hóa
string maHoa(string text, string key) {

    char matrix[5][5];
    taoMaTran(key, matrix);
    text = chuanHoa(text);

    string result = "";

    for (int i = 0; i < text.length(); i += 2) {
        int r1, c1, r2, c2;

        timViTri(matrix, text[i], r1, c1);
        timViTri(matrix, text[i + 1], r2, c2);

        // Cùng hàng
        if (r1 == r2) {
            result += matrix[r1][(c1 + 1) % 5];
            result += matrix[r2][(c2 + 1) % 5];
        }
        // Cùng cột
        else if (c1 == c2) {
            result += matrix[(r1 + 1) % 5][c1];
            result += matrix[(r2 + 1) % 5][c2];
        }
        // Hình chữ nhật
        else {
            result += matrix[r1][c2];
            result += matrix[r2][c1];
        }
    }

    return result;
}

int main() {

    string key = "MONARCHY";
    string text = "DO YOU LIKE TO STUDY CRYPTOGRAPHY COURSE";

    string cipher = maHoa(text, key);

    cout << "Key: " << key << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Ciphertext: " << cipher << endl;

    return 0;
}