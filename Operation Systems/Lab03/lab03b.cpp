#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <semaphore.h>

#define NUMSTACK 5000

sem_t sem;
sem_t wait_sem;

std::string text;
std::vector<std::vector<std::string>> text_words;

char stack[2][NUMSTACK];
char word[50];

int func (void* param) {
	int p = *(int*)param;
	p + 1;
	int child_max = 0;
	int child_j_max = 0;

	for (int j = 0; j < text_words[p].size(); j++) {
		if (text_words[p][j].length() > child_max) {
			child_max = text_words[p][j].length();
			child_j_max = j;
		}		
	}

	sem_wait(&sem);
	if (word != text_words[p][child_j_max]) {
		strcpy(word, "No result");
	}
	sem_post(&sem);
	sem_post(&wait_sem);

	return 1;
}


int main() {

	sem_init(&sem, 1, 0);
	sem_init(&wait_sem, 1, 0);

	

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


	

	int max = 0;
	int j_max = 0;

	for (int j = 0; j < text_words[0].size(); j++) {
		if (text_words[0][j].length() > max) {
			max = text_words[0][j].length();
			j_max = j;
		}
	}
	
	std::cout << "Parent Word: " << text_words[0][j_max] << std::endl;

	strcpy(word, text_words[0][j_max].c_str());
	sem_post(&sem);

	
	int param[2];
	for (int i = 0; i < text_words.size(); i++) {
		param[i] = i;
		char *tostack = stack[i];
		clone(func, (void*)(tostack + NUMSTACK - 1), CLONE_VM, (void*)(param+i));
	}

	for (int i = 1; i < text_words.size(); i++) {
		sem_wait(&wait_sem);
	}

	std::cout << "Result word: " << word << std::endl;

	return 0;
}
 