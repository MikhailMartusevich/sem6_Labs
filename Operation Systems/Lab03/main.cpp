#include <iostream>
#include <string>
#include <vector>

int main() {

	std::string text;
	std::vector<std::vector<std::string>> text_words;

	std::cout << "Enter your text" << std::endl;

	std::getline(std::cin, text);

	int i = 0;
	std::vector<std::string> temp_words;
	std::string temp_string = "";

	while (i < text.length()) {
		if (text[i] == ',' || text[i] == ';') {
			i++;
			continue;
		}

		if (text[i] == ' ') {
			temp_words.push_back(temp_string);
			temp_string = "";
			i++;
			continue;
		}

		if (text[i] == '.') {
			temp_words.push_back(temp_string);
			text_words.push_back(temp_words);
			temp_string = "";
			temp_words.clear();
			i++;
			continue;
		}

		temp_string += text.at(i);

		i++;
	}
	

	//std::cout << temp_string << std::endl;
	

	for (int i = 0; i < text_words.size(); i++) {
		int max = 0;
		int j_max = 0;

		for (int j = 0; j < text_words[i].size(); j++) {
			if (text_words[i][j].length() > max) {
				max = text_words[i][j].length();
				j_max = j;
			}
		}

		std::cout << text_words[i][j_max] << std::endl;
	}
	
	return 0;
}
 