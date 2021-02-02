
enum PackageManager {
    UNKNOWN,
    PKG,    // pkg -- emerge frontend written in Rust.
    QLIST,  // qlist -- list package info for Portage.
    APK,    // apk -- package manager for Alpine Linux.
    APT,    // apt -- package manager for Debian/Ubuntu-based distros.
    DNF,    // dnf -- package manager for Red Hat distros.
    DPKG,   // dpkg -- same as apt.
    EOPKG,  // eopkg -- Solus package manager.
    PACMAN, // pacman -- Arch package manager.
    PIP,    // pip -- Python's package manager.
    RPM,    // rpm -- like dnf.
    XBPS,   // xbps -- Void Linux's package manager.
};

