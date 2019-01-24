#include "Network.h"



Network::Network()
{
	m_listener.setBlocking(false);
	m_listener.listen(53000);
	m_client.setBlocking(false);
}

Network::~Network()
{
}

void Network::Connect(sf::IpAddress address, sf::Int32 port)
{
	if (this->m_client.getRemoteAddress() == sf::IpAddress::None)
	{
		if (!this->m_client.connect(address, port))
		{
			std::cout << "Could not connect to address: " + address.toString() + "\n";
		}
		else
		{
			std::cout << "Connected to address: " + address.toString() + "\n";
		}
	}
	else 
	{
		std::cout << "Socket Already connected: " + address.toString() + "\n";
	}

}

void Network::Disconenct()
{
	m_client.disconnect();
	std::cout << "Disconnected \n";

}

void Network::Update()
{
	//std::cout << (int)m_status << "\n";
	switch (m_status)
	{
		case NetworkStatus::Connected :
		{
			break;
		}
		case NetworkStatus::NotConnected :
		{
			if (m_listener.accept(m_client) != sf::Socket::Done)
			{
				std::cout << "line 46 network.cpp \n";
				break;
			}
			else 
			{
				std::cout << "Someone has connected to you. \n";
				m_status = NetworkStatus::Connected;
				break;
			}
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