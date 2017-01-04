#pragma once
#include <queue>
#include <mutex>
#include "Packet.h"

class PacketManager {
private:
	std::queue<Packet> queue_packets;
	std::mutex mutex_packets;
public:
	bool HasPendingPackets();
	void Append(Packet p);
	Packet Retrieve();
};