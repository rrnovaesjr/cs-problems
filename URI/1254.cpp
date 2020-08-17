#include <bits/stdc++.h>

using namespace std;

/* Token processing part */
enum TokenType {
	OPEN_TAG, CLOSE_TAG, WORD, EOW
};

struct Token {
	
	static const Token END;

	TokenType type;
	string value;

	Token(string t_value, TokenType t_type): type(t_type), value(t_value) {}

	const bool operator == (const Token &other) const {
		return type == other.type && value == other.value;
	}

	const bool operator != (const Token &other) const {
		return !((*this) == other);
	}
};

const Token Token::END = Token("", TokenType::EOW);

struct TokenReader {

	const int INITIAL_STATE = 0;

	const int FINAL_STATE = 1;

	string tag;

	int tagIndex;

	TokenReader(string t_tag): tag(t_tag), tagIndex(0) {}

	Token nextToken() {
		string value = "";
		char ch;
		int state = INITIAL_STATE;

		if (tagIndex == tag.size()) {
			return Token("", TokenType::EOW);
		}

		while (tagIndex < tag.size() && state != FINAL_STATE) {	
			ch = tag[tagIndex];
			
			if (ch == '<') {
				state = FINAL_STATE;
			} else if (ch == '>') {
				state = FINAL_STATE;
			} else {
				value.push_back(ch);
			}
				
			tagIndex++;
		}

		if (!value.empty()) {
			if (ch == '>' || ch == '<')
				tagIndex--;
			return Token(value, TokenType::WORD);			
		}
		if (ch == '<') {
			return Token("<", TokenType::OPEN_TAG);
		}
		return Token(">", TokenType::CLOSE_TAG);
	}
};

/* Conversion state */
struct Command {
	
	virtual ~Command() {}	

	virtual string run() = 0;
};

struct TagCommand : public Command {

	shared_ptr<Command> wordCommand;
	
	string pattern;
	
	string target;
	
	TagCommand(shared_ptr<Command> t_wordCommand, string t_pattern, string t_target):
		wordCommand(t_wordCommand),
		pattern(t_pattern),
		target(t_target) {}
		
	string run() override {
		string currWord = string(wordCommand.get()->run());
		return "<" + subTag(currWord, pattern, target) + ">";
	}
	
	private: 

	string subTag(string s, string a, string b) {
		string lower_s = string(s);
		transform(s.begin(), s.end(), lower_s.begin(), ::tolower);
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		auto position = lower_s.find(a);
		while(position != string::npos) {
			s.replace(position, a.size(), b);
			lower_s.replace(position, a.size(), b);
			position = lower_s.find(a, position + b.size());
		}
		return s;
	}

};

struct WordCommand : public Command {

	string currWord;
	
	WordCommand(string t_currWord): currWord(t_currWord) {}
	
	string run() override {
		return currWord;
	}
};

/* Text analysis state */

struct Interpreter {

	string tagInicial;
	
	string tag;
	
	string valor;
	
	TokenReader tokenReader;
	
	Token currToken;
	
	Interpreter (string t_tagInicial, string t_tag, string t_valor):
		tagInicial(t_tagInicial),
		tag(t_tag),
		valor(t_valor),
		tokenReader(TokenReader(t_tag)),
		currToken(tokenReader.nextToken()) {}


	bool matchToken (TokenType expected) {
		if (expected == currToken.type) {
			currToken = tokenReader.nextToken();
			return true;
		}
		return false;
	}	
	
	vector<shared_ptr<Command>> runAnalysis() {
		vector<shared_ptr<Command>> commands;
		while (!matchToken(TokenType::EOW)) {
			commands.push_back(doAnalysis());
		}
		return commands;
	}
	
	private: 

		shared_ptr<Command> doAnalysis() {
			if (matchToken(TokenType::OPEN_TAG)) {
				return runTagAnalysis();
			}
			return runWordAnalysis();
		}

		shared_ptr<Command> runTagAnalysis() {
			shared_ptr<Command> wordCommand = runWordAnalysis();
			if (matchToken(TokenType::CLOSE_TAG)) {
				return shared_ptr<Command>(new TagCommand(wordCommand, tagInicial, valor));
			}
			return wordCommand;
		}
		
		shared_ptr<Command> runWordAnalysis() {
			string value = currToken.value;
			if (matchToken(TokenType::WORD)) {
				return shared_ptr<Command>(new WordCommand(value));			
			}
			return shared_ptr<Command>(new WordCommand(""));
		}

};


int main() {
	string tagInicial;
	string valor;
	string tag;

	while (getline(cin, tagInicial)) {
		getline(cin, valor);
		getline(cin, tag);
		
		Interpreter in(tagInicial, tag, valor);
		
		auto commands = in.runAnalysis();
		
		for (auto command : commands) {
			cout << command.get()->run();
		}
		cout << endl;
	}


	return 0;
}
