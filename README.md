# cppfetch

I decided to learn CPP, and I'm using this project as way to actively learn it.

I decided an information gathering program because I'm already accustomed to making<br>
such programs in other languages.

## Building

```bash
git clone https://github.com/Phate6660/cppfetch
cd cppfetch
meson build
ninja -C build/ # Or whatever generator you have set for `meson`
                # `make` is the default but I personally really like `ninja`
```

## Example output

`$ ./build/cppfetch l`

```
 ██████╗██████╗ ██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗
██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║
██║     ██████╔╝██████╔╝█████╗  █████╗     ██║   ██║     ███████║
██║     ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║
╚██████╗██║     ██║     ██║     ███████╗   ██║   ╚██████╗██║  ██║
 ╚═════╝╚═╝     ╚═╝     ╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝
CPU:         Intel(R) Core(TM) i5-3470 CPU @ 3.20GHz
Distro:      Gentoo/Linux
Editor:      /usr/bin/emacsclient
Environment: herbstluftwm
Shell:       /bin/bash
Uptime:      15d 14h 44m
User:        valley
```

## TODO

- ASCII art (maybe? not sure yet)
  + ~~Disabled by default, enable with `l` or `logo`~~
  + ~~Hardoded ascii art~~
  + User supplied ascii art
- ~~CPU Info~~
- ~~DE/WM Info~~
- ~~Distro Info~~
- ~~Editor Info~~
- Memory Info
- Music Info
- ~~Shell Info~~
- Terminal Info
- ~~Uptime Info~~
- ~~User Info~~
