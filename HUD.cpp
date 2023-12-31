#include "HUD.h"

HUD::HUD()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	//Load Font
	m_Font.loadFromFile("fonts/Roboto-Light.ttf");

	//When Paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(100);
	m_StartText.setFillColor(Color::White);
	m_StartText.setString("Press Enter When Ready!!");

	//Position thentext
	FloatRect textRect = m_StartText.getLocalBounds();
	m_StartText.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.0f);
	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	// Time
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(75);
	m_TimeText.setFillColor(Color::White);
	m_TimeText.setPosition(resolution.x - 150, 0);
	m_TimeText.setString("------");

	// Level
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(75);
	m_LevelText.setFillColor(Color::White);
	m_LevelText.setPosition(25, 0);
	m_LevelText.setString("1");
}

Text HUD::getMessage()
{
	return m_StartText;
}

Text HUD::getLevel()
{
	return m_LevelText;
}

Text HUD::getTime()
{
	return m_TimeText;
}

void HUD::setLevel(String text)
{
	m_LevelText.setString(text);
}

void HUD::setTime(String text)
{
	m_TimeText.setString(text);
}
