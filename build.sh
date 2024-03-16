# check the meson build system
if pip3 show meson && pip3 show ninja; then
    echo "Meson build system is already installed."
else
    echo "Installing meson build system..."
    pip3 install --user meson ninja
fi
# check the SDL2 library (I use the 'dnf' package manager)
if dnf list --installed | grep SDL2 && dnf list --installed | grep SDL2-devel; then
    echo "SDL2 is already installed."
else
    echo "Installing SDL2..."
    sudo dnf install -y SDL2 SDL2-devel
fi
# cleanup
rm -rf builddir subprojects
# create required directories
mkdir builddir subprojects
# setup
meson setup builddir
meson wrap install sdl2

echo "DONE!"
exit 0
