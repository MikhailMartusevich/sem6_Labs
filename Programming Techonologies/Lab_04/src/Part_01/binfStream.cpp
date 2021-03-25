#include "binfStream.h"
#include "errorHandler.h"

void bin_instream::readData(const void* ptr, int size) {
	if (!ptr)
		return;

	if (size <= 0)
		return;

	read((char*)ptr, size);
}

void bin_outstream::writeData(const void* ptr, int size) {
	if (!ptr)
		return;

	if (size <= 0)
		return;

	write((char*)ptr, size);
}
