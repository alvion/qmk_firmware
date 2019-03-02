# Wangledorf's Chimera LS Keymap

## Flashing

To flash the firmware on an Ubuntu system (Or one of its derivatives), execute
the following steps in *bash*:

```bash
# Install dependencies
sudo apt-get -y install avr-libc avrdude gcc-avr

# Checkout out the QMK repository
git clone https://github.com/qmk/qmk_firmware
cd qmk_firmware

# Make sure the firmware compiles
make chimera_ls:wangledorf

# Flash the firmware
sudo make chimera_ls:wangledorf:avrdude

# When the "Detecting USB port, reset your controller now..." prompt appears,
# press the button on the receiver labeled "R".
```

## Fixing Flashing Issues

If you are seeing weird errors with the butterfly bootloader while flashing,
you may need to run the following steps on your system:
```bash
sudo usermod -a -G dialout <yourUserName>
sudo apt-get --purge remove modemmanager
```

I'm not sure why this is the case, but I ran into this problem and found the
solution in the following Arduino form posts:
- https://forum.arduino.cc/index.php?topic=129647.0
- https://forum.arduino.cc/index.php?topic=580326.0
