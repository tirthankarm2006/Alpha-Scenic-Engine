#pragma once

#include "Event.h"
#include "KeyCodes.h"

#include "sstream"

namespace AS {
	class AS_API KeyEvent : public Event
	{
	public:
		inline KEYCODE GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKey | EventCateforyInput)
	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

		KEYCODE m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KEYCODE keyCode, bool isRepeat = false) : KeyEvent(keyCode), m_IsRepeat(isRepeat) {}

		bool IsRepeat() const { return m_IsRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed: " << m_KeyCode << " (repeated = " << m_IsRepeat << ")";
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_IsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KEYCODE keyCode) : KeyEvent(keyCode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released: " << m_KeyCode;
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KEYCODE keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Typed: " << m_KeyCode;
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}