set_project("cppfetch")
set_config("cxxflags", "-std=c++2a")

option("music")
    set_default(false)
    set_description("Enable music info, require libmpdclient.")
    set_showmenu(true)
    add_defines("MUSIC")
option_end()

if has_config("music") then
    add_requires("libmpdclient")
end

target("cppfetch")
    set_kind("binary")
    set_options("music")
    on_load(function (target)
        local _, compiler_name = target:tool("cc")
        if compiler_name == "clang" then
            print("WARNING: BUILDING WITH CLANG IS UNSUPPORTED (IN FACT IT'S BROKEN), PLEASE CONTINUE AT YOUR OWN RISK.")
        end
    end)
    add_files("src/main.cpp")
    add_files("src/helpers/functions.cpp")
    add_files("src/info/cpu.cpp")
    add_files("src/info/distro.cpp")
    add_files("src/info/environment.cpp")
    add_files("src/info/memory.cpp")
    if has_config("music") then
        add_packages("libmpdclient")
        add_files("src/info/music.cpp")
    end
    add_files("src/info/packages.cpp")
    add_files("src/info/term.cpp")
    add_files("src/info/uptime.cpp")
