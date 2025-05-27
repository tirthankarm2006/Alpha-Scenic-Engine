#pragma once

#include "core.h"

namespace AS {
	class AS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

