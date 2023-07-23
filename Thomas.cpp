#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));
	m_JumpDuration = .45;
}

bool Thomas::handleInput()
{
	m_JustJumped = false;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (!m_Isjumping && !m_IsFalling)
		{
			m_Isjumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsFalling = false;
		m_IsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}
