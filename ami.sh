#!/bin/bash

### AUR Mini Installer (AMI)
# Exaple:
# ./ami.sh [package]

aur_pkg=$1
git clone https://aur.archlinux.org/$aur_pkg.git
cd $aur_pkg
makepkg -si --skippgpcheck
cd ..
rm -rf $aur_pkg
