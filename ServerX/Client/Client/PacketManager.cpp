#include "PacketManager.h"

bool PacketManager::HasPendingPackets() {
	return (queue_packets.size() > 0);
}

void PacketManager::Append(Packet p) {
	std::lock_guard<std::mutex> lock(mutex_packets);
	queue_packets.push(p);
}

Packet PacketManager::Retrieve() {
	std::lock_guard<std::mutex> lock(mutex_packets);
	Packet p = queue_packets.front();
	queue_packets.pop();

	return p;
}