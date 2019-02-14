#!/bin/bash

### Simple AUR Helper (SAH)
VERSION="0.0.7 (Early Pre-Alpha)"

pkg_list_path="/home/$USER/.ami_pkg_list"
pkg_list_path_v="/home/$USER/.ami_pkg_list_v"
PKGBUILDs_path="/tmp/PKGBUILDs"

if [[ $1 == "-S" ]]; then
  aur_pkg=$2
  git clone https://aur.archlinux.org/$aur_pkg.git
  cd $aur_pkg
  if [[ $3 != "--rmd" ]]; then
    makepkg -si --skippgpcheck
  elif [[ $3 == "--rmd" ]]; then
    makepkg -sir --skippgpcheck
  fi
  cd ..
  rm -rf $aur_pkg
elif [[ $1 == "-Syu" ]]; then
  echo "Checking for updates from Pacman..."
  sudo pacman -Syu

  echo
  echo "Checking for updates from AUR..."

  pacman -Qqm > $pkg_list_path
  pacman -Qm > $pkg_list_path_v

  readarray -t pkg_list < $pkg_list_path
  readarray -t pkg_list_v < $pkg_list_path_v
  pkgz=${#pkg_list[@]}
  pkgz_v=${#pkg_list_v[@]}

  mkdir $PKGBUILDs_path
  for (( i = 0; i < $pkgz; i++ )); do
    check_pkg=${pkg_list[$i]}
    check_pkg_v=${pkg_list_v[$i]}
    check_pkg_v=$(echo $check_pkg_v | awk '{print $2}')
    latest_version_message="-> $check_pkg - you have the latest version."

    if [[ $check_pkg != "sah" ]]; then
      wget -q "https://aur.archlinux.org/cgit/aur.git/plain/PKGBUILD?h=$check_pkg" -O $PKGBUILDs_path/$check_pkg.txt

      version_main=$(cat /tmp/PKGBUILDs/$check_pkg.txt | grep "pkgver" | head -n 1 | awk -F "=" '{print $2}')
      version_patch=$(cat /tmp/PKGBUILDs/$check_pkg.txt | grep "pkgrel" | head -n 1 | awk -F "=" '{print $2}')
      version_full="$version_main-$version_patch"

      if [[ $check_pkg_v == $version_full ]]; then
        echo "$latest_version_message"
      elif [[ $check_pkg_v != $version_full ]]; then
        # Version from PKGBUILD may has the single quotes.
        echo "$version_full" | grep -q "'"
        if [[ $? == "0" ]]; then
          pkgver_sq=$(echo "$check_pkg_v" | awk -F "-" '{print $1}')
          pkgrel_sq=$(echo "$check_pkg_v" | awk -F "-" '{print $2}')
          check_pkg_v_sq="'$pkgver_sq'-'$pkgrel_sq'"
          if [[ $check_pkg_v_sq != $version_full ]]; then
            echo "Updating $check_pkg..."
            git clone https://aur.archlinux.org/$check_pkg.git
            cd $check_pkg
            if [[ $2 != "--rmd" ]]; then
              makepkg -si --skippgpcheck
            elif [[ $2 == "--rmd" ]]; then
              makepkg -sir --skippgpcheck
            fi
            cd ..
            rm -rf $check_pkg
          fi
        elif [[ $? == "1" ]]; then
          echo "Updating $check_pkg..."
          git clone https://aur.archlinux.org/$check_pkg.git
          cd $check_pkg
          if [[ $2 != "--rmd" ]]; then
            makepkg -si --skippgpcheck
          elif [[ $2 == "--rmd" ]]; then
            makepkg -sir --skippgpcheck
          fi
          cd ..
          rm -rf $check_pkg
        fi
      fi
    # Exceptions
    elif [[ $check_pkg == "sah" ]]; then
      echo "$latest_version_message"
    fi
  done
  rm $pkg_list_path
  rm $pkg_list_path_v
  rm -rf $PKGBUILDs_path
elif [[ $1 == "-R" ]]; then
  aur_pkg=$2
  sudo pacman -R $aur_pkg
elif [[ $1 == "-Qe" ]]; then
  echo "Installed packages (All):"
  pacman -Qe
elif [[ $1 == "-Qm" ]]; then
  echo "Installed packages (AUR):"
  pacman -Qm
elif [[ $1 == "--version" || $1 == "-V" ]]; then
  echo "Simple AUR Helper (SAH) v$VERSION"
elif [[ $1 == "" || $1 == "--help" || $1 == "-h" ]]; then
  echo "Simple AUR Helper (SAH)

Version: $VERSION
Author: zurg3 (Stepan Skryabin)
Created: 12.02.2019
License: GNU GPL v3

Dependencies:
- bash
- sudo
- pacman
- coreutils
- git
- wget
- grep

Examples:
Install package from AUR
./sah.sh -S [package]

Install package from AUR and remove make dependencies
./sah.sh -S [package] --rmd

Update installed packages (Pacman + AUR)
./sah.sh -Syu

Update installed packages (Pacman + AUR) and remove make dependencies of updated AUR packages
./sah.sh -Syu --rmd

Remove package
./sah.sh -R [package]

Show installed packages (All)
./sah.sh -Qe

Show installed packages (AUR)
./sah.sh -Qm"
else
  echo "Something is wrong!"
fi
