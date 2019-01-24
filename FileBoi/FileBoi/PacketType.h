#pragma once

enum class PacketType
{
	FileTransferAskSendFile,
	FileTransferByteBuffer,
	FileTransferRequestNextBuffer,
	FileTransfer_EndOfFile,
	CancelFileSend
};