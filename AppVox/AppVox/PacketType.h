#ifndef PACKETTYPE_H
#define PAKCETTYPE_H

enum class PacketType
{
	ChatMessage,
	FileTransferRequestFile, // Sent to request a file
	FileTransfer_EndOfFile, // Sent for when file transfer is complete
	FileTransferByteBuffer, // Send Before sendint a byte buffer for file transfer
	FileTransferRequestNextBuffer, // Send to request the next byte buffer for file
	BanChat, // Ban user from chat
	CanSetUsername, // Return can set username
	CantSetUsername, // Return can't set username 
	ServerCurrentVersion, // Send server current version
	ServerLastVersion, // Send server last version
	AppName,
	SetUsername // Try to set username received from user
};

#endif // !PACKETTYPE_H
