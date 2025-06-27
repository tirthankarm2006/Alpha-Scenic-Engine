#pragma once
#include "core.h"
#include "spdlog\spdlog.h"
#include "memory"
namespace AS {
	class AS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core log macros
#define AS_CORE_TRACE(...) ::AS::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_INFO(...)  ::AS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AS_CORE_WARN(...)  ::AS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AS_CORE_ERROR(...) ::AS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AS_CORE_FATAL(...) ::AS::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define AS_TRACE(...) ::AS::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_INFO(...)  ::AS::Log::GetClientLogger()->info(__VA_ARGS__)
#define AS_WARN(...)  ::AS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...) ::AS::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_FATAL(...) ::AS::Log::GetClientLogger()->fatal(__VA_ARGS__)

//If it is a distribution build, we define all the core log macros to nothing


