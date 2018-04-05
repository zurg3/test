#!/bin/bash

useradd -m -g users -G wheel -s /bin/bash zurg3
passwd zurg3

echo "%wheel ALL=(ALL) ALL" >> /etc/sudoers

echo "[multilib]" >> /etc/pacman.conf
echo "Include = /etc/pacman.d/mirrorlist" >> /etc/pacman.conf

pacman -Syy
pacman -S xorg-server xorg-drivers xorg-xinit virtualbox-guest-utils
pacman -S xfce4 xfce4-goodies lxdm
pacman -S networkmanager network-manager-applet ppp
systemctl enable gdm NetworkManager

reboot
