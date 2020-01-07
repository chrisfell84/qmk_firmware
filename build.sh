# planck (not working)
make planck-rev4-chrisfell
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash ~/Projects/planck_firmware/.build/planck_rev4_chrisfell.hex

# preonic
make preonic/rev3:chrisfell:flash
