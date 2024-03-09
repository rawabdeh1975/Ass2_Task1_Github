#include<iostream>
#include<map>
using namespace std;

string findPositionOfLetter(char letter, char table[5][5])
{
    string position = "";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(table[i][j] == letter)
                {
                    position += to_string(i);
                    position += to_string(j);
                }
        }
    }
    return position;
}


// Function to Encrypt a message using Polybius Cipher Algorithm
string polybiusCipher(string text, string key)
{
    // Checking if the key isn't 5 digits
    // We Output a message and stop the function;
    if(key.length() != 5)
    {
        cout<<"Key must be exactly 5 digits long."<<endl;
        return "";
    }

    // Creating a 2d array to store the conversion of each letter.
    // Each letter will be encrypted to a total of two digits using the given key.
    char table[5][5];
    string alphabet = "abcdefghiklmnopqrstuvwxyz";// Removing 'j' as 'i' and 'j' are encrypted in the same way

    int index = 0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            char letter = alphabet[index];
            int row = key[i] - '0';
            int column = key[j] - '0';
            table[row][column] = letter;
            index++;
        }
    }

    string cipherText = "";
    for(int i=0; i<text.length(); i++)
    {
        char letter = text[i];
        if(letter == ' ')
            cipherText += ' ';
        else if(letter == 'j')
            cipherText += findPositionOfLetter('i', table);
        else
            cipherText += findPositionOfLetter(letter, table);
    }

    return cipherText;

}



string polybiusDecrypt(string ciphertext, string key)
{
    // Check if the key is exactly 5 digits long
    if(key.length() != 5) {
        cout << "Key must be exactly 5 digits long." << endl;
        return "";
    }

    map<char, string> cipherTable;
    string alphabet = "abcdefghiklmnopqrstuvwxyz";// Removing 'j' as 'i' and 'j' are encrypted in the same way
    int keyIndex = 0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            string cipher = "";
            cipher += key[i];
            cipher += key[j];
            cipherTable[alphabet[keyIndex]] = cipher;
            keyIndex++;
        }
    }

    // Decrypt the ciphertext using the Polybius table
   return "";




}
int main()
{
    string plainText = "I Love c plus plus";
    string key = "51423";
    string cipher = polybiusCipher(plainText, key);
    cout<< cipher;

    cout<<endl;
    cout<< polybiusDecrypt(cipher, key);
}
