# cppfetch

I decided to learn CPP, and I'm using this project as way to actively learn it.

I decided an information gathering program because I'm already accustomed to making<br>
such programs in other languages.

## Building

Dependencies:
- xmake
- libmpdclient\*

\*(Should automatically be installed/compiled with xmake when the music option is enabled.<br>
However if you find it doesn't install, open an issue with the message with the<br>
output of xmake and then try installing libmpdclient from a package manager<br>
(though I'm usually really responsive so I'll probably have it fixed up for you before you have to).)

```bash
git clone https://github.com/Phate6660/cppfetch
cd cppfetch
xmake # or `xmake f --music=y -v && xmake -v` if you want to enable music info
```

(Use `xmake -rv` after the `&&` to have xmake rebuild everything.<br>
It's only needed if you previously built cppfetch with/without music and want the opposite.)

You may also statically build the program with `./build-static`.<br>
It only requires g++ and strip (which you should already have if you're building programs :D).<br>
However, building with music support only works if you built libmpdclient as a static lib.<br>
If you have done that and want music support, then run `./build-static true`.

## Example output

`xmake run` or `xmake run cppfetch l` (if you want the logo to be displayed too)

```
 ██████╗██████╗ ██████╗ ███████╗███████╗████████╗ ██████╗██╗  ██╗
██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██║  ██║
██║     ██████╔╝██████╔╝█████╗  █████╗     ██║   ██║     ███████║
██║     ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══╝     ██║   ██║     ██╔══██║
╚██████╗██║     ██║     ██║     ███████╗   ██║   ╚██████╗██║  ██║
 ╚═════╝╚═╝     ╚═╝     ╚═╝     ╚══════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝
CPU:         Intel(R) Core(TM) i5-3470 CPU @ 3.20GHz
Distro:      Gentoo/Linux
Editor:      /usr/bin/nvim
Environment: herbstluftwm
Memory:      15966MB
Music:       Electric Six - I Shall Exterminate Everything Around Me That Restricts Me From Being The Master - It's Showtime!
Packages:    594 (Portage)
Shell:       /bin/bash
Terminal:    xterm
Uptime:      6d 3h 44m
User:        valley
```

You'll find the binary at: `./build/linux/ARCH/cppfetch`

(Replace ARCH with your architecture, e.g. x86\_64.)
## TODO

- ~~ASCII art~~
  + ~~Disabled by default, enable with `l` or `logo`~~
  + ~~Hardoded ascii art~~
  + ~~User supplied ascii art~~ (place at `~/.config/cppfetch/logo`)
- ~~CPU Info~~
- ~~DE/WM Info~~
- ~~Distro Info~~
- ~~Editor Info~~
- Memory Info
  + Proper formatting (e.g. decimal points / extra calculations where necessary)
  + ~~Total~~
  + Used
- Music Info
  + ~~MPD~~
- Package Count
  + ~~apt~~
  + cargo
  + ~~dnf~~
  + ~~dpkg~~
  + ~~eopkg~~
  + flatpak
  + ~~pacman~~
  + pip
  + ~~[pkg](https://github.com/Phate6660/pkg)~~
  + [ppkg](https://github.com/Phate6660/ppkg)
  + ~~qlist~~ (TODO: get package counts in pure C++)
  + ~~rpm~~
  + ~~xbps~~
  + yum
- ~~Shell Info~~
- ~~Terminal Info~~
- ~~Uptime Info~~
- ~~User Info~~
