/* 
The encryption step performed by a Caesar cipher is often incorporated as part of more complex schemes, such as the Vigenère cipher, and still has modern application in the ROT13 system. As with all single-alphabet substitution ciphers, the Caesar cipher is easily broken and in modern practice offers essentially no communications security.

The action of a Caesar cipher is to replace each plaintext letter with a different one a fixed number of places down the alphabet.

The encryption can also be represented using modular arithmetic by first transforming the letters into numbers, according to the scheme, A → 0, B → 1, ..., Z → 25.[2] Encryption of a letter x by a shift n can be described mathematically as,

Encryption(x) = (x + n)%26
Decryption(x) = (x - n)%26
'''

'''
Algorithm for Caesar Cipher: 

Input: A String of lower case letters, called Text and an Integer between 0-25 denoting the required shift.

Procedure: 
1. Traverse the string characters.
2. For each character, transform the given character as per the rule, depending on whether we’re encrypting or decrypting the text.
3. Return the new string generated.

To decrypt remember Cipher(n) = De-cipher(26-n)
*/


#include <iostream>
using namespace std;

// This function receives text and shift and
// returns the encrypted text
string encrypt(string text, int s)
{
	string result = "";

	// traverse text
	for (int i=0;i<text.length();i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result += char(int(text[i]+s-65)%26 +65);

	// Encrypt Lowercase letters
	else
		result += char(int(text[i]+s-97)%26 +97);
	}

	// Return the resulting string
	return result;
}

string decrypt(string enc, int s)
{
	string result = "";
    s = 26 - s;

	// traverse text
	for (int i=0;i<enc.length();i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(enc[i]))
			result += char(int(enc[i]+s-65)%26 +65);

	// Encrypt Lowercase letters
	else
		result += char(int(enc[i]+s-97)%26 +97);
	}

	// Return the resulting string
	return result;
}

// Driver program to test the above function
int main()
{
	string text="ATTACKATONCE";
	int s = 4;
	cout << "Text : " << text;
	cout << "\nShift: " << s;
    string enc = encrypt(text, s);
	cout << "\nCipher: " << encrypt(text, s);
    cout << "\nDecipher: " << decrypt(enc, s);
	return 0;
}