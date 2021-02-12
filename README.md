# cppfetch

I decided to learn CPP, and I'm using this project as way to actively learn it.

I decided an information gathering program because I'm already accustomed to making<br>
such programs in other languages.

## Building

Dependencies:
- Meson (reason: build system)
- A generator such as make or ninja (I recommend ninja)
- libmpdclient for music info (OPTIONAL)

```bash
git clone https://github.com/Phate6660/cppfetch
cd cppfetch
meson build
ninja -C build/ # Or whatever generator you have set for `meson`
                # `make` is the default but I personally really like `ninja`
```

## Example output

`$ ./build/cppfetch`

```
CPU:         Intel(R) Core(TM) i5-3470 CPU @ 3.20GHz
Distro:      Gentoo/Linux
Editor:      /usr/bin/emacsclient
Environment: herbstluftwm
Memory:      15966MB
Music:       Pantera - Vulgar Display of Power - Regular People (Conceit)
Packages:    715 (Portage), 16 (pip)
Shell:       /bin/bash
Terminal:    xterm
Uptime:      7d 0h 17m
User:        valley
```

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
