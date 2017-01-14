#include "Essentials.h"

bool Essentials::ProcessPacket(PacketType _packettype)
{	
	try {
		switch (_packettype)
		{
			case PacketType::ServerCurrentVersion:{
				if (!GetString(serverCurrentVersion)) {
					throw("Cannot get serverVersion");
				}	
				break;
			}
			case PacketType::AppName: {
				if (!GetString(applicationName))
					throw("Cannot get appName");				
				break;
			}
			/*case PacketType::ChatMessage:{
				std::string message;
				if (!GetString(message))
					throw("Cannot get message");
				QString qMessage = QString::fromStdString(message);
				newChat->AppendText("vox", qMessage);
				break;
			}*/
			//case PacketType::ChatMessage: //If packet is a chat message packet
			//{
			//	std::string Message; //string to store our message we received

			//	if (!GetString(Message)) //Get the chat message and store it in variable: Message
			//		return false; //If we do not properly get the chat message, return false

			//	std::cout << Message << std::endl; //Display the message to the user
			//	break;
			//}

			//case PacketType::FileTransferByteBuffer: { //If packet is an file transfer
			//	int32_t buffersize; // Declare buffersize

			//	if (!GetInt32_t(buffersize))
			//		return false;

			//	if (!recvall(file.buffer, buffersize))
			//		return false;

			//	file.outFileStream.write(file.buffer, buffersize);

			//	file.bytesWritten += buffersize;

			//	//std::cout << "Received byte buffer for file transfer of size " << buffersize << std::endl;

			//	SendPacketType(PacketType::FileTransferRequestNextBuffer);

			//	break;
			//}

			//case PacketType::FileTransfer_EndOfFile: { // This packet is received when and of file is reached 

			//	std::cout << "File transfer completed. File received \n";
			//	std::cout << "File Name: " << file.fileName << std::endl;
			//	std::cout << "File Size(bytes) : " << file.bytesWritten << std::endl;

			//	getFile = true;

			//	file.bytesWritten = 0;
			//	file.outFileStream.close();

			//	break;
			//}
			//case PacketType::SetUsername: {
			//	std::string handleUsername;
			//	if (!GetString(handleUsername))
			//		return false;



			//	if (handleUsername == "canSet") {
			//		std::cout << "\n\n\t\t\tSccesfull setting username !\n";
			//		canSendMessages = true;
			//	}

			//	if (handleUsername == "cantSet") {
			//		MessageBoxA(NULL, "Username already exist !", "Info", MB_OK | MB_ICONEXCLAMATION);
			//		canSendMessages = false;
			//	}

			//	break;
			//}

			//case PacketType::ServerCurrentVersion: {
			//	if (!GetString(serverVersion)) //Get the chat message and store it in variable: Message
			//		return false; //If we do not properly get the chat message, return false
			//	break;
			//}

			//case PacketType::ServerLastVersion: {
			//	if (!GetString(serverLastVersion)) //Get the chat message and store it in variable: Message
			//		return false; //If we do not properly get the chat message, return false
			//	break;
			//}

			//case PacketType::BanChat: {
			//	std::string message;
			//	if (!GetString(message))
			//		return false;

			//	message = "Banned from chat reason : " + message;
			//	MessageBoxA(NULL, message.c_str(), "ERROR", MB_OK | MB_ICONEXCLAMATION);
			//	canSendMessages = false;
			//	Lobby();
			//	break;
			//}

		default: //If packet type is not accounted for
			std::string defaultCase = "Unrecognized packet: " + std::to_string((int32_t)_packettype) + "\0";
			throw(defaultCase);
			break;
		}
	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	return true;
}