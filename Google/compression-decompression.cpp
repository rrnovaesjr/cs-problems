#include <bits/stdc++.h>

using namespace std;

typedef int ull;

/*
* An enum that identifies the token type.
*/
enum TokenType {
	NUMBER, WORD, OPEN_BRACKET, CLOSE_BRACKET, EOS
};

/*
* A structure that stores a token.
*/
struct Token {
	
	TokenType type;
	
	string word;
	
	ull number;
	
	Token() {}
	
	Token(TokenType type, string word): type(type), word(word) {}
	
	Token(TokenType type, ull number): type(type), number(number) {}
};

/*
* Returns the next token from the input.
*/
Token eat(int& currIndex, const string input) {
	string word = "";
	TokenType type;
	while(currIndex < input.size() && input[currIndex] != '[' && input[currIndex] != ']') {
		word += input[currIndex];
		currIndex++;
	}
	if(word.empty()) {
		if(currIndex >= input.size()) type = EOS;
		else if(input[currIndex] == '[') { type = OPEN_BRACKET; currIndex++; }
		else if(input[currIndex] == ']') { type = CLOSE_BRACKET; currIndex++; }
	}
	else {
		if(currIndex >= input.size()) type = WORD;
		else if(input[currIndex] == '[') type = NUMBER;
		else if(input[currIndex] == ']') type = WORD;
	}
	return type == NUMBER ? Token(type, stoi(word, 0)) : Token(type, word);
}

/* 
* Checks wether expected == got 
*/
bool matchToken(TokenType expected, TokenType got) {
	return expected == got;
}

/*
* Process a number input. NUMBER := "number" "[" NUMBER "word" "]" | "number "[" "word" "]"
*/
string procNumber(int &currIndex, string input, ull number) {
	string result = "", preResult = "";
	matchToken(OPEN_BRACKET, eat(currIndex, input).type);
	Token currToken = eat(currIndex, input);
	if(matchToken(NUMBER, currToken.type)) {
		preResult += procNumber(currIndex, input, currToken.number);
		currToken = eat(currIndex, input);
	}
	if(matchToken(WORD, currToken.type)) {
		preResult += currToken.word;
		currToken = eat(currIndex, input);
	}
	matchToken(CLOSE_BRACKET, currToken.type);
	for(ull rep = number; rep > 0ULL; rep--)
		result += preResult;
	return result;
}


/*
* Process the input starting from index = 0. INPUT := NUMBER INPUT | "word" "eos" 
*
* Examples for input '3[abc]4[ab]c':
*
*	1. INPUT-0 := NUMBER-1 INPUT-1
*	2. NUMBER-1 := "3" "[" "abc" "]" : result = "abcabcabc";
*	3. INPUT-1 := NUMBER-2 INPUT-2
*	4. NUMBER-2 := "4" "[" "ab" "]" : result = "abababab";
*	5. INPUT-2 := "c" "\0" : result = "c";
*	6. INPUT-O := "abcabcabcabababababc". 
*/
string procInput(int& currIndex, string input) {
	string result = "";
	Token currToken = eat(currIndex, input);
	if(matchToken(NUMBER, currToken.type)) {
		result += procNumber(currIndex, input, currToken.number);
		result += procInput(currIndex, input); 
	}
	else {
		result += currToken.word;
		matchToken(EOS, eat(currIndex, input).type);	
	}
	return result;
}

int main() {
	string input;
	int currIndex = 0;
	cin >> input;
	cout << procInput(currIndex, input) << endl;
	return 0;
}
