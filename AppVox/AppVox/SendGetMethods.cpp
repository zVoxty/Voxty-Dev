#include "Essentials.h"

bool Essentials::recvall(char * data, int totalbytes)
{
	int bytesreceived = 0; //Holds the total bytes received

	while (bytesreceived < totalbytes) //While we still have more bytes to recv
	{
		int RetnCheck = recv(Connection, data + bytesreceived, totalbytes - bytesreceived, NULL); //Try to recv remaining bytes

		if (RetnCheck == SOCKET_ERROR) //If there is a socket error while trying to recv bytes
			return false; //Return false - failed to recvall

		bytesreceived += RetnCheck; //Add to total bytes received
	}
	return true; //Success!
}

bool Essentials::GetInt32_t(int32_t & _int32_t)
{
	if (!recvall((char*)&_int32_t, sizeof(int32_t))) //Try to receive int... If int fails to be recv'd
		return false; //Return false: Int not successfully received
	_int32_t = ntohl(_int32_t);
	return true;//Return true if we were successful in retrieving the int
}

bool Essentials::GetPacketType(PacketType & _packettype) {
	int packettype;

	if (!GetInt32_t(packettype)) //Try to receive packet type... If packet type fails to be recv'd
		return false; //Return false: packet type not successfully received

	_packettype = (PacketType)packettype;

	return true;//Return true if we were successful in retrieving the packet type
}

bool Essentials::GetString(std::string & _string)
{
	int32_t bufferlength; //Holds length of the message

	if (!GetInt32_t(bufferlength)) //Get length of buffer and store it in variable: bufferlength
		return false; //If get int fails, return false

	if (bufferlength > 10000)
		return false;

	char * buffer = new char[bufferlength + 1]; //Allocate buffer

	buffer[bufferlength] = '\0'; //Set last character of buffer to be a null terminator so we aren't printing memory that we shouldn't be looking at

	if (!recvall(buffer, bufferlength)) //receive message and store the message in buffer array. If buffer fails to be received...
	{
		delete[] buffer; //delete buffer to prevent memory leak
		return false; //return false: Fails to receive string buffer
	}

	_string = buffer; //set string to received buffer message

	delete[] buffer; //Deallocate buffer memory (cleanup to prevent memory leak)

	return true;//Return true if we were successful in retrieving the string
}

bool Essentials::sendall(char * data, int totalbytes)
{
	int bytessent = 0; //Holds the total bytes sent

	while (bytessent < totalbytes) //While we still have more bytes to send
	{
		int RetnCheck = send(Connection, data + bytessent, totalbytes - bytessent, NULL); //Try to send remaining bytes

		if (RetnCheck == SOCKET_ERROR) //If there is a socket error while trying to send bytes
			return false; //Return false - failed to sendall

		bytessent += RetnCheck; //Add to total bytes sent
	}
	return true; //Success!
}

bool Essentials::SendInt32_t(int32_t _int32_t)
{
	_int32_t = htonl(_int32_t);
	if (!sendall((char*)&_int32_t, sizeof(int32_t))) //Try to send int... If int fails to send
		return false; //Return false: int not successfully sent

	return true; //Return true: int successfully sent
}

bool Essentials::SendPacketType(PacketType _packettype)
{
	if (!SendInt32_t((int32_t)_packettype)) //Try to send packet type... If packet type fails to send
		return false; //Return false: packet type not successfully sent

	return true; //Return true: packet type successfully sent
}
