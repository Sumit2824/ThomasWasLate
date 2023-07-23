#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));
	m_JumpDuration = .25;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_Isjumping && !m_IsFalling)
		{

			m_Isjumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_Isjumping = false;
		m_IsFalling = true;

	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;
	
}
