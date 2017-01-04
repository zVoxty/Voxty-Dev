#pragma once
#include <fstream>

struct FileTransferData {
	static const int bufferSize = 8192;
	std::string fileName; // for when receiving files
	int bytesWritten; // For when receiving files;
	int fileOffset; // For when reading a file
	int fileSize; // For when reading a file
	int remainingBytes; // For when reading a file
	std::ifstream inFileStream; // For reading a file that is being sent
	std::ofstream outFileStream; // For writing a file that is being received
	char buffer[bufferSize]; //buffer used for when sending or receiving
};