#include "Server.h"

bool Server::recvall(int ID, char * data, int totalbytes)
{
	int bytesreceived = 0; //Holds the total bytes received
	while (bytesreceived < totalbytes) //While we still have more bytes to recv
	{
		int RetnCheck = recv(connections[ID]->socket, data, totalbytes - bytesreceived, NULL); //Try to recv remaining bytes
		if (RetnCheck == SOCKET_ERROR) //If there is a socket error while trying to recv bytes
			return false; //Return false - failed to recvall
		bytesreceived += RetnCheck; //Add to total bytes received
	}
	return true; //Success!
}

bool Server::sendall(int ID, char * data, int totalbytes)
{
	int bytessent = 0; //Holds the total bytes sent
	while (bytessent < totalbytes) //While we still have more bytes to send
	{
		int RetnCheck = send(connections[ID]->socket, data + bytessent, totalbytes - bytessent, NULL); //Try to send remaining bytes
		if (RetnCheck == SOCKET_ERROR) //If there is a socket error while trying to send bytes
			return false; //Return false - failed to sendall
		bytessent += RetnCheck; //Add to total bytes sent
	}
	return true; //Success!
}

bool Server::Getint32_t(int ID, int32_t & _int32_t)
{
	if (!recvall(ID, (char*)&_int32_t, sizeof(int32_t))) //Try to receive long (4 byte int)... If int fails to be recv'd
		return false; //Return false: Int not successfully received
	_int32_t = ntohl(_int32_t); //Convert long from Network Byte Order to Host Byte Order
	return true;//Return true if we were successful in retrieving the int
}

bool Server::GetPacketType(int ID, PacketType & _packettype)
{
	int packettype;

	if (!Getint32_t(ID, packettype)) //Try to receive packet type... If packet type fails to be recv'd
		return false; //Return false: packet type not successfully received

	_packettype = (PacketType)packettype;

	return true;//Return true if we were successful in retrieving the packet type
}

void Server::SendString(int ID, std::string & _string)
{
	PS::ChatMessage message(_string);
	connections[ID]->pm.Append(message.toPacket());
}

bool Server::GetString(int ID, std::string & _string)
{
	int32_t bufferlength; //Holds length of the message

	if (!Getint32_t(ID, bufferlength)) //Get length of buffer and store it in variable: bufferlength
		return false; //If get int fails, return false

	char * buffer = new char[bufferlength + 1]; //Allocate buffer

	buffer[bufferlength] = '\0'; //Set last character of buffer to be a null terminator so we aren't printing memory that we shouldn't be looking at

	if (!recvall(ID, buffer, bufferlength)) //receive message and store the message in buffer array. If buffer fails to be received...
	{
		delete[] buffer; //delete buffer to prevent memory leak
		return false; //return false: Fails to receive string buffer
	}

	_string = buffer; //set string to received buffer message

	delete[] buffer; //Deallocate buffer memory (cleanup to prevent memory leak)

	return true;//Return true if we were successful in retrieving the string
}

void Server::SendCustomString_Packet(int ID, std::string & _string, PacketType _packettype) {
	const int packetsize = sizeof(int32_t) * 2 + _string.size() * sizeof(char); //Calculate total size of buffer for packet contents
	char * buffer = new char[packetsize]; //Create buffer big enough to hold all info for message
	int32_t packettype = htonl((int32_t)_packettype); //Convert packet type (int32_t) to network byte order
	int32_t messagesize = htonl(_string.size()); //Convert message size (int32_t) to network byte order
	memcpy(buffer, &packettype, sizeof(int32_t)); //Copy Packet Type to first 4 bytes of buffer
	memcpy(buffer + sizeof(int32_t), &messagesize, sizeof(int32_t)); //Copy size to next 4 bytes of buffer
	memcpy(buffer + sizeof(int32_t) * 2, _string.c_str(), _string.size() * sizeof(char)); //Copy message to fill the rest of the buffer
	Packet p(buffer, packetsize); //Create packet to be returned
	connections[ID]->pm.Append(p);
}
