#! /bin/bash

printf "This bash command sets up the USB port to enable the Linux machine to write.\n"

echo "These was the last device you connected to the port:"

dmesg | tail

printf "\nCopy the name of your USB port, for example:\n"

printf "[515487.665936] usb 1-1: ch341-uart converter now attached to ttyUSB0\n\n"

echo "On this case 'ttyUSB0' is our port, copy yours and paste it, then hit enter."

read usbport

sudo chmod a+rw /dev/$usbport