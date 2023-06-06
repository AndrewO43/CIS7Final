#include <iostream>
#include <string>
using namespace std;

//function for encryption
string encrypt(string text, string key)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            //handles uppercase characters
            result += char(int(text[i] - 65 + key[i] - 97) % 26 + 65);
        else
            //handles lowercase characters
            result += char(int(text[i] - 97 + key[i] - 97) % 26 + 97);
    }

    return result;
}

//function for decryption
string decrypt(string text, string key)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            //handles uppercase characters
            result += char(int(text[i] - 65 - key[i] + 123 + 26) % 26 + 65);
        else
            //handles lowercase characters
            result += char(int(text[i] - 97 - key[i] + 123 + 26) % 26 + 97);
    }

    return result;
}

//makes the key longer if it is too short
string keyExtend(string text, string key)
{
    string extendedKey = "";
    
    //makes the key repeat if the key is shorter than the plain text
    if (text.length() >= key.length())
    {
        extendedKey += key;
        while (text.length() > extendedKey.length())
        {
            extendedKey += key;
        }
    }

    //makes the key always lowercase
    for (int i = 0; i < extendedKey.length(); i++)
    {
        extendedKey[i] = tolower(extendedKey[i]);
    }

    return extendedKey;
}

//main fuction that handles input and output and calls other functions
int main() {
    string text;
    string key;
    string process;
    cout << "Text : ";
    cin >> text;
    cout << "Key: ";
    cin >> key;
    string extendedKey = keyExtend(text, key);
    cout << "Extended Key: " << extendedKey;
    cout << "\nWould you like to encrypt or decrypt? ";
    cin >> process;
    if (process == "encrypt") 
    {
        cout << "\nEncryption: " << encrypt(text, extendedKey);
    }else if (process == "decrypt")
    {
        cout << "\nDecryption: " << decrypt(text, extendedKey);
    }
    
    return 0;
}