#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int shmid;
int semid;

sembuf Plus1 = {0, 1, 0};
sembuf Minus1 = {0, -1, 0};

struct max_word {
	char word[50];
} *mem_word;


int main() {

	shmid = shmget(IPC_PRIVATE, sizeof(max_word), IPC_CREAT | 0666);
	if (shmid < 0) {
		std::cout << "Failed to create shared memory" << std::endl;
		return 1;
	}

	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
	if (shmid < 0) {
		std::cout << "Failed to create semafors" << std::endl;
		return 1;
	}

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


	

	int max = 0;
	int j_max = 0;

	for (int j = 0; j < text_words[0].size(); j++) {
		if (text_words[0][j].length() > max) {
			max = text_words[0][j].length();
			j_max = j;
		}
	}
	
	std::cout << "Parent Word: " << text_words[0][j_max] << std::endl;

	mem_word = (max_word*)shmat(shmid, NULL, 0);
	strcpy(mem_word->word, text_words[0][j_max].c_str());
	semop(semid, &Plus1, 1);
	

	for (int i = 1; i < text_words.size(); i++) {
		if (fork() == 0) {
			int child_max = 0;
			int child_j_max = 0;

			for (int j = 0; j < text_words[i].size(); j++) {
				if (text_words[i][j].length() > child_max) {
					child_max = text_words[i][j].length();
					child_j_max = j;
				}		
			}

			std::cout << "Child " << i << " Word: " << text_words[i][child_j_max] << std::endl;

			semop(semid, &Minus1, 1);
			if (mem_word->word != text_words[i][child_j_max]) {
				strcpy(mem_word->word, "No result");
			}
			semop(semid, &Plus1, 1);

			return 1;
		}
	}

	for (int i = 1; i < text_words.size(); i++) {
		wait(NULL);
	}

	std::cout << "Result word: " << mem_word->word << std::endl;

	return 0;
}
 