python3 -m pip install --user qmk
qmk setup -H /workspaces/qmk_firmware -y
qmk config user.keyboard=crkbd
qmk config user.keymap=korzun
