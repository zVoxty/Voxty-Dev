#pragma once
enum class PacketType
{
	ChatMessage,
	FileTransferRequestFile, // Sent to request a file
	FileTransfer_EndOfFile, // Sent for when file transfer is complete
	FileTransferByteBuffer, // Send Before sendint a byte buffer for file transfer
	FileTransferRequestNextBuffer, // Send to request the next byte buffer for file
	BanChat,
	CanSetUsername,
	CantSetUsername,
	ServerVersion,
	ServerVersionNOk,
	SetUsername
};