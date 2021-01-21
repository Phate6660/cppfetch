project('cppfetch', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++2a'])

conf_data = configuration_data()
conf_data.set('version', '0.1')

mdep = dependency('libmpdclient', required : false)

if mdep.found()  
    conf_data.set('MUSIC', true)
    configure_file(output : 'config.h',
               configuration : conf_data)
    configuration_inc = include_directories('.')
    libmpdclient_lib='mpdclient'
    libmpdclient_lib_dir='/usr/lib64'
    libmpdclient_header_dir='/usr/include/mpd'
    libmpdclient_dep = declare_dependency(
        link_args : ['-L' + libmpdclient_lib_dir, '-l' + libmpdclient_lib],
        include_directories : include_directories(libmpdclient_header_dir))
    executable('cppfetch',
               'src/cpu.cpp',
               'src/distro.cpp',
               'src/environment.cpp',
               'src/functions.cpp',
               'src/main.cpp',
               'src/memory.cpp',
               'src/music.cpp',
               'src/uptime.cpp',
               build_rpath : libmpdclient_lib_dir,
               install_rpath : libmpdclient_lib_dir,
               dependencies : [libmpdclient_dep],
               install : true)
else
    conf_data.set('MUSIC', false)
    configure_file(output : 'config.h',
               configuration : conf_data)
    configuration_inc = include_directories('.')
    executable('cppfetch',
               'src/cpu.cpp',
               'src/distro.cpp',
               'src/environment.cpp',
               'src/functions.cpp',
               'src/main.cpp',
               'src/memory.cpp',
               'src/uptime.cpp',
               install : true)
endif
