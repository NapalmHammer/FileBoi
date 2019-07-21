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
			m_logptr->AddString("Could not connect to address: " + address.toString());
		}
		else
		{
			m_logptr->AddString("Connected to address: " + address.toString());
		}
	}
	else 
	{
		m_logptr->AddString("Socket Already connected: " + address.toString());
	}

}

void Network::Disconect()
{
	m_client.disconnect();
	m_logptr->AddString("Disconnected");

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
				break;
			}
			else 
			{
				m_logptr->AddString("Someone has connected to you.");
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