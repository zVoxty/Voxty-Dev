#pragma once

class Packet {
public:
	Packet();
	Packet(char * buffer, int size);
	Packet(const Packet & p);

	int size;
	char * buffer;
};