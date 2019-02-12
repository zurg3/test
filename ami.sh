#!/bin/bash

### AUR Mini Installer (AMI)
## Dependencies:
# bash
# pacman
# git
## Exaples:
# ./ami.sh -S [package] | Install package from AUR
# ./ami.sh -Syu | Update installed packages from AUR
# ./ami.sh -R [package] | Remove package
# ./ami.sh -Qe | Show installed packages (All)
# ./ami.sh -Qm | Show installed packages (AUR)

if [[ $1 == "-S" ]]; then
  aur_pkg=$2
  git clone https://aur.archlinux.org/$aur_pkg.git
  cd $aur_pkg
  makepkg -si --skippgpcheck
  cd ..
  rm -rf $aur_pkg
elif [[ $1 == "-Syu" ]]; then
  pkg_list_path="/home/$USER/.ami_pkg_list"

  sudo pacman -Syu

  pacman -Qqm > $pkg_list_path

  readarray -t pkg_list < $pkg_list_path
  pkgz=${#pkg_list[@]}

  echo "Checking for updates from AUR..."

  for (( i = 0; i < $pkgz; i++ )); do
    check_pkg=${pkg_list[$i]}
    git clone https://aur.archlinux.org/$check_pkg.git
    cd $check_pkg
    makepkg -si --skippgpcheck --needed
    cd ..
    rm -rf $check_pkg
    sleep 5
  done
elif [[ $1 == "-R" ]]; then
  aur_pkg=$2
  sudo pacman -R $aur_pkg
elif [[ $1 == "-Qe" ]]; then
  echo "Installed packages (All):"
  pacman -Qe
elif [[ $1 == "-Qm" ]]; then
  echo "Installed packages (AUR):"
  pacman -Qm
else
  echo "Something is wrong!"
fi
