#pragma once
#include <SFML/Network.hpp>
#include "FileTransferData.h"
#include <iostream>
#include "Log.h"

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
	void Init(Log* L)
	{
		m_logptr = L;
	}
	void Connect(sf::IpAddress address, sf::Int32 port);
	void Disconect();
	void Update();
	//void HandlePacket();

private:
	FileTransferData m_fileData;
	sf::TcpListener m_listener;
	sf::TcpSocket m_client;
	sf::Int32 m_bufferSize = 16384;
	NetworkStatus m_status = NetworkStatus::NotConnected;
	Log* m_logptr;
};

