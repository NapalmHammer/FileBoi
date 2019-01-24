#pragma once
#include <SFML/Network.hpp>
#include "FileTransferData.h"
#include <iostream>

enum class NetworkStatus
{
	NotConnected,
	Connected, 
	Sending, 
	Receiving
};

class Network
{
public:
	Network();
	~Network();
	void Connect(sf::IpAddress address, sf::Int32 port);
	void Disconenct();
	void Update();
	//void HandlePacket();

private:
	FileTransferData m_fileData;
	sf::TcpListener m_listener;
	sf::TcpSocket m_client;
	sf::Int32 m_bufferSize = 16384;
	NetworkStatus m_status = NetworkStatus::NotConnected;
};

