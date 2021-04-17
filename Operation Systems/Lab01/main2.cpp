#include <iostream>
#include <string>
#include <vector>


int main() {

	std::string str;
	std::string resstr;
	std::vector<char> symbols;
	char sym;

	std::cin >> str;

	for (int x = 0; x < str.size(); x++) {
		resstr = str; // app#1 throws string to app#2

		int count = 0;
		int max_count = -1;
		char max = NULL;
		bool copy = false;

		for (int i = 0; i < str.size(); i++) {

			copy = false;
			for (int m = 0; m < symbols.size(); m++) {
				if (symbols[m] == str[i]) 
					copy = true;
			}

			if (!copy) {
				count = 0;
				for (int j = i; j < str.size(); j++) {
					if (str[j] == str[i])
						count++;
				}
				if (count > max_count) {
					max_count = count;
					max = str[i];
				}
			}

		}

		std::cout << "\nmax symbol: " << max << std::endl;

		bool sym_copy = false;

		std::cin >> sym;
		for (int i = 0; i < symbols.size(); i++) {
			if (symbols[i] == sym)
				sym_copy = true;
		}

		if (!sym_copy) {
			symbols.push_back(sym);

			for (int i = 0; i < resstr.size(); i++) {
				if (resstr[i] == max)
					resstr[i] = sym;
			}
		}

		//sym_copy = false;

		std::cout << "\n result string: " << resstr << std::endl;

		str = resstr; // app#2 returns result string to app#1
	}

	return 0;
}
