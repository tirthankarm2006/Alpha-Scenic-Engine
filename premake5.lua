workspace "AlphaScenic"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.builgcfg}-%{cfg.system}-%{cfg.architecture}"

project "AlphaScenic"
    location "AlphaScenic"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")      --where the dll will stored
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")     --where the intermediate obj files will go

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/3rdPartyLibs/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AS_PLATFORM_WINDOWS",
            "AS_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/SandBoxProj")
        }

    filter "configurations:Debug"
        defines "AS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AS_Dist"
        optimize "On"


project "SandBoxProj"
    location "SandBoxProj"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")      --where the dll will stored
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")     --where the intermediate obj files will go

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "AlphaScenic/3rdPartyLibs/spdlog/include",
        "AlphaScenic/src"
    }

    links
    {
        "AlphaScenic"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AS_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AS_Dist"
        optimize "On"
