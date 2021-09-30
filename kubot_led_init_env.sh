#!/bin/bash

tput setaf 2
echo "Build kubot led udev rulse..."
tput sgr0

echo 'KERNEL=="ttyUSB*", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", MODE:="0777", SYMLINK+="kubot_led"' >/etc/udev/rules.d/kubot_led.rules

status=$?
if [ $status -eq 0 ]; then
   tput setaf 2
   echo "Initialized LED controller successfully"
   tput sgr0
else
   tput setaf 1
   echo "Failed to initialize LED controller!"
   tput sgr0
   exit 1
fi

sudo udevadm control --reload
sudo udevadm trigger

tput setaf 2
echo "Finish build kubot led udev rulse..."
tput sgr0
