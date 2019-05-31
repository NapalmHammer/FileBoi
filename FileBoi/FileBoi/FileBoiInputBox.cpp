#include "FileBoiInputBox.h"
#include <ctype.h>

SelectFileIB::SelectFileIB(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, std::string BN)
	:InputBox(R, D, BN)
{
}

void SelectFileIB::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	InputBox::Update(D);
	if (m_tl->GetReady())
	{
		m_FM->CheckFile(m_tl->GetString());
	}
}

IPIB::IPIB(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, std::string BN)
	:InputBox(R, D, BN)
{
}

void IPIB::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	InputBox::Update(D);
	if (m_tl->GetReady())
	{
		auto temp = m_tl->GetString();
		std::cout << "attempting conection to IP: " << temp << "\n";
		for (auto i = 0; i < temp.size(); ++i)
		{
			if (isalpha(temp[i]))
			{
				std::cout << "IP addresses should be numeric only. \n";
				return;
			}
		}
		D->m_net.Connect(temp, 53000);
	}
}
