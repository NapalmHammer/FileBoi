#include "Network.h"



Network::Network()
{
	m_listener.setBlocking(false);
	m_client.setBlocking(false);
	m_sender.setBlocking(false);
}

Network::~Network()
{
}

void Network::Connect(sf::IpAddress address, sf::Int32 port)
{
	if (!this->m_sender.connect(address, port))
	{
		std::cout << "Could not connect to address: " + address.toString() + "\n";
	}
	else
	{
		std::cout << "Connected to address: " + address.toString() + "\n";
	}
}

void Network::Disconenct()
{
	m_sender.disconnect();
	m_client.disconnect();
	std::cout << "Disconnected \n";

}

void Network::Update()
{
	switch (m_status)
	{
		case NetworkStatus::Connected :
		{
			break;
		}
		case NetworkStatus::NotConnected :
		{
			break;
		}
		case NetworkStatus::Receiving :
		{
			break;
		}
		case NetworkStatus::Sending :
		{
			break;
		}
		default :
		{
			break;
		}
	}
}