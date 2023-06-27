mcu = atmega328p
build_dir = ./build
src_dir = ./src
bin_dir = ./binaries
port = COM3
baud = 115200
config_dir= ./config

OPT = Os
CLOCK = 16000000UL

all:
	avr-gcc -$(OPT) -DF_CPU=$(CLOCK) -mmcu=$(mcu) -c -o$(build_dir)/main.o $(src_dir)/main.c
	avr-gcc -mmcu=$(mcu) $(build_dir)/main.o -o$(bin_dir)/main
	avr-objcopy -O ihex -R .eeprom $(bin_dir)/main $(bin_dir)/main.hex
	avr-size -C --mcu=$(mcu) $(bin_dir)/main | awk '{ print "\033[36m" $$0 "\033[0m" }'

flash:
	avrdude -F -V -c arduino -p $(mcu) -P $(port) -b $(baud) -U flash:w:$(bin_dir)/main.hex -C $(config_dir)/avrdude.conf

clean:
	rm $(bin_dir)/*
	rm $(build_dir)/*
