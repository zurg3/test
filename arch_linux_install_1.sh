#!/bin/bash

loadkeys ru
setfont cyr-sun16
timedatectl set-ntp true

(
  echo o;
  
  echo n;
  echo;
  echo;
  echo;
  echo +500M;
  
  echo n;
  echo;
  echo;
  echo;
  echo +20G;
  
  echo n;
  echo;
  echo;
  echo;
  echo +2G;
  
  echo n;
  echo p;
  echo;
  echo;
  
  echo a;
  echo 1;
  
  echo w;
) | fdisk /dev/sda

fdisk -l

mkfs.ext2 /dev/sda1 -L boot
mkfs.ext4 /dev/sda2 -L root
mkswap /dev/sda3 -L swap
mkfs.ext4 /dev/sda4 -L home

mount /dev/sda2 /mnt
mkdir /mnt/{boot,home}
mount /dev/sda1 /mnt/boot
swapon /dev/sda3
mount /dev/sda4 /mnt/home

echo "Server = http://mirror.yandex.ru/archlinux/\$repo/os/\$arch" > /etc/pacman.d/mirrorlist
pacstrap /mnt base base-devel

genfstab -pU /mnt >> /mnt/etc/fstab

(
  arch-chroot /mnt
  echo "zurg3" > /etc/hostname
  ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime
  echo "en_US.UTF-8 UTF-8" > /etc/locale.gen
  echo "ru_RU.UTF-8 UTF-8" >> /etc/locale.gen
  locale-gen
  echo "LANG=ru_RU.UTF-8" > /etc/locale.conf
  echo "KEYMAP=ru" > /etc/vconsole.conf
  echo "FONT=cyr-sun16" >> /etc/vconsole.conf
  mkinitcpio -p linux
  passwd
  pacman -S grub
  grub-install /dev/sda
  grub-mkconfig -o /boot/grub/grub.cfg
  exit
) | arch-chroot /mnt

# arch-chroot /mnt
# echo "zurg3" > /etc/hostname
# ln -sf /usr/share/zoneinfo/Europe/Moscow /etc/localtime
# echo "en_US.UTF-8 UTF-8" > /etc/locale.gen
# echo "ru_RU.UTF-8 UTF-8" >> /etc/locale.gen
# locale-gen
# echo "LANG=ru_RU.UTF-8" > /etc/locale.conf
# echo "KEYMAP=ru" > /etc/vconsole.conf
# echo "FONT=cyr-sun16" >> /etc/vconsole.conf
# mkinitcpio -p linux
# passwd
# pacman -S grub
# grub-install /dev/sda
# grub-mkconfig -o /boot/grub/grub.cfg
# exit

umount /mnt/{boot,home,}
reboot
