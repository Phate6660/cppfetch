enum PackageManager {
    UNKNOWN,
    APK,    // apk -- package manager for Alpine Linux.
    DNF,    // dnf -- package manager for Red Hat distros.
    DPKG,   // dpkg -- same as apt.
    EOPKG,  // eopkg -- Solus package manager.
    PACMAN, // pacman -- Arch package manager.
    PIP,    // pip -- Python's package manager.
    PKG,    // pkg -- emerge frontend written in Rust.
    QLIST,  // qlist -- list package info for Portage.
    RPM,    // rpm -- like dnf.
    XBPS,   // xbps -- Void Linux's package manager.
    EMERGE, // emerge -- Portage package manager.
};
