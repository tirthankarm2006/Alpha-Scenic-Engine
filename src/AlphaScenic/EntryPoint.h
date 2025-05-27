#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern AS::Application* AS::CreateApplication();

int main(int argc, char** argv) {
	auto app = AS::CreateApplication();
	app->run();
	delete app;
}

#endif