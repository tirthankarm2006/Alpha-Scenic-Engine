#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern AS::Application* AS::CreateApplication();

int main(int argc, char** argv) {
	AS::Log::Init();
	AS_CORE_WARN("Initialized Core Logger!");
	AS_INFO("Hello!");
	auto app = AS::CreateApplication();
	app->run();
	delete app;
}

#endif