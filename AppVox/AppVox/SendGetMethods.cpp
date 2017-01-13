#include "AppVox.h"

bool AppVox::recvall(char * data, int totalbytes)
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

bool AppVox::GetInt32_t(int32_t & _int32_t)
{
	if (!recvall((char*)&_int32_t, sizeof(int32_t))) //Try to receive int... If int fails to be recv'd
		return false; //Return false: Int not successfully received
	_int32_t = ntohl(_int32_t);
	return true;//Return true if we were successful in retrieving the int
}

bool AppVox::GetPacketType(PacketType & _packettype) {
	int packettype;

	if (!GetInt32_t(packettype)) //Try to receive packet type... If packet type fails to be recv'd
		return false; //Return false: packet type not successfully received

	_packettype = (PacketType)packettype;

	return true;//Return true if we were successful in retrieving the packet type
}