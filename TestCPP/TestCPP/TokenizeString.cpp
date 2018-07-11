#include <stdafx.h>

vector<string> tokenizer(string line, char delimiter)
{
	vector <string> tokens;
	// stringstream class check1
	stringstream check1(line);
	string intermediate;
	// Tokenizing w.r.t. space ' '
	while (getline(check1, intermediate, delimiter))
		tokens.push_back(intermediate);
	return tokens;
}

void tokenizer2()
{
	char str[] = "Geeks-for-Geeks";
	// Returns first token 
	char *token = strtok(str, "-");
	// Keep printing tokens while one of the
	// delimiters present in str[].
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}
}

int main()
{
	auto tokens = tokenizer("GeeksForGeeks is a must try", ' ');
	for (const auto & token : tokens)
		cout << token << '\n';
	getchar();
}
