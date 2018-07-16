#!/bin/bash

git clone https://aur.archlinux.org/aurman.git
cd aurman
makepkg -si --noconfirm --skippgpcheck
cd ..
rm -rf aurman
