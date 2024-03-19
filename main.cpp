#include <iostream>
#include <algorithm>

using namespace std;

string caesar_cipher(string text, int s) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {

        if (isspace(text[i])) {
            result += " ";
        }
        else if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
    return result;
}
string generateRandomAlphabet() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(nullptr));
    random_shuffle(alphabet.begin(), alphabet.end());
    return alphabet;
}

string encrypt(string plaintext, const string& key) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            if (isupper(c)) {
                ciphertext += toupper(key[c - 'A']);
            } else {
                ciphertext += tolower(key[c - 'a']);
            }
        } else if (c == ' ') {
            ciphertext += ' ';
        }
    }
    return ciphertext;
}
int main() {
    cout << "Caesar cipher" << endl;
    string text;
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    int s ;
    cout << "Enter Shift Key: ";
    cin>>s;
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << caesar_cipher(text, s);
    cout<<endl;
    cout<<"*****************************************************************"<<endl;
    cout<<"Random alphabet substituation cipher"<<endl;
    string plaintext ;
    cout<<"Enter Text:"<<endl;
   cin>>plaintext;
    string key = generateRandomAlphabet();

    cout << "Original Alphabet: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    cout << "Randomly Generated Alphabet: " << key << endl;

    string encrypted_text = encrypt(plaintext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Encrypted Text: " << encrypted_text << endl;

    return 0;
}
