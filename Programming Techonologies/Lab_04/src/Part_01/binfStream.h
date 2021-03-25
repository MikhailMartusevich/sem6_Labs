#ifndef BIN_F_STREAM
#define BIN_F_STREAM

#include <iostream>
#include <fstream>

class bin_instream : public std::ifstream {
public:
	bin_instream(const char* file_name) : std::ifstream(file_name, std::ios::in | std::ios::binary) {}
	void readData(const void* ptr, int size);
	
	bin_instream& operator>>(int& value) {
		readData(&value, sizeof(value));
		return *this;
	}
};

class bin_outstream : public std::ofstream {
public:
	bin_outstream(const char* file_name) : std::ofstream(file_name, std::ios::out | std::ios::binary) {}
	void writeData(const void* ptr, int size);

	bin_outstream& operator<<(int value) {
		writeData(&value, sizeof(value));
		return *this;
	}
};

#endif // !BIN_F_STREAM
