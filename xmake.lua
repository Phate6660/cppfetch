set_project("cppfetch")
set_config("cxxflags", "-std=c++2a")

option("music")
    set_default(false)
    set_description("Enable music info, require libmpdclient.")
    set_showmenu(true)
    add_defines("MUSIC")
option_end()

if has_config("music") then
    add_requires("libmpdclient", {system = false})
end

target("cppfetch")
    set_kind("binary")
    set_options("music")
    add_files("src/main.cpp")
    add_files("src/helpers/functions.cpp")
    add_files("src/info/cpu.cpp")
    add_files("src/info/distro.cpp")
    add_files("src/info/environment.cpp")
    add_files("src/info/memory.cpp")
    if has_config("music") then
        add_packages("libmpdclient")
        add_links("mpdclient")
        add_linkdirs(os.getenv("HOME") .. "/.xmake/packages/l/libmpdclient/2.19/eef0428b5c924272a357006e1e7d5ead/lib/x86_64-linux-gnu")
        add_linkdirs(os.getenv("HOME") .. "/.xmake/packages/l/libmpdclient/2.19/eef0428b5c924272a357006e1e7d5ead/lib64")
        add_includedirs(os.getenv("HOME") .. "/.xmake/packages/l/libmpdclient/2.19/eef0428b5c924272a357006e1e7d5ead/include/")
        add_files("src/info/music.cpp")
    end
    add_files("src/info/packages.cpp")
    add_files("src/info/term.cpp")
    add_files("src/info/uptime.cpp")

