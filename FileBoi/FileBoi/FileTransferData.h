#pragma once
#include <fstream>
#include <memory>
#include <SFML\Network.hpp>
#include "PacketType.h"

namespace FTDlocalVars
{
	static const sf::Int32 buffersize = 16384;
}
class FileDataBuffer
{
public:
	std::shared_ptr<sf::Packet> toPacket()
	{
		std::shared_ptr<sf::Packet> p = std::make_shared<sf::Packet>();
		*p << std::int32_t(PacketType::FileTransferByteBuffer);
		*p << m_Size;
		*p << m_DataBuffer, m_Size;
		return p;
	}
	char m_DataBuffer[FTDlocalVars::buffersize];
	int m_Size;
};

struct FileTransferData
{
	bool Initialize(const std::string & fileName);
	std::shared_ptr<sf::Packet> GetOutgoingBufferPacket(std::int32_t& bytes, std::string& msg);

	// file data
	FileDataBuffer m_fileDataBuffer;	
	sf::String m_FileName;
	sf::Int32 m_BytesWritten;
	sf::Int32 m_FileOffset;
	sf::Int32 m_RemainingBytes;
	// file stream vars
	std::ifstream m_InfileStream;
	std::ofstream m_OutfileStream;
	std::streamoff m_FileSize;
	// ----
	bool m_TransferInProgress = false;
	static const sf::Int32 m_BufferSize = FTDlocalVars::buffersize;
	char m_Buffer[m_BufferSize];
};