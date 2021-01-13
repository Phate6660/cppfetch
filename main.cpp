#include <iostream>

using namespace std;

string distro();

int main() {
    // Print the output the distro function.
    // It should be `PRETTY_NAME="$DISTRO"`.
    // Example: `PRETTY_NAME="Gentoo/Linux"`.
    cout << distro();
    return 0;
}
