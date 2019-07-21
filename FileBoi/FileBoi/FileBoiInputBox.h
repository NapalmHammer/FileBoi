#pragma once
#include "InputBox.h"

class SelectFileIB : public InputBox
{
public:
	SelectFileIB(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, std::string BN);
	void Update(std::shared_ptr<ShareableApplicationData>& D) override;
};


class IPIB : public InputBox
{
public:
	IPIB(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, std::string BN);
	void Update(std::shared_ptr<ShareableApplicationData>& D) override;
};