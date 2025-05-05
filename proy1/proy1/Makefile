BUILD_DIR?=/home/jahs96/proyectos/proyecto1-2025/proyecto1-2025/proy1/build/sim

SOC_DIRECTORY?=/mnt/c/WINDOWS/system32/litex/litex/litex/soc
include $(BUILD_DIR)/software/include/generated/variables.mak
include $(SOC_DIRECTORY)/software/common.mak

OBJECTS   = helloc.o add_asm.o add.o crt0.o main.o crc32.o crc32_asm.o
ifdef WITH_CXX
	OBJECTS += hellocpp.o
	CFLAGS += -DWITH_CXX
endif

all: proy1.bin


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

vpath %.a $(PACKAGES:%=../%)

proy1.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -T linker.ld -N -o $@ \
		$(OBJECTS) \
		$(PACKAGES:%=-L$(BUILD_DIR)/software/%) \
		-Wl,--whole-archive \
		-Wl,--gc-sections \
		-Wl,-Map,$@.map \
		$(LIBS:lib%=-l%)

ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

donut.o: CFLAGS   += -w

VPATH = $(BIOS_DIRECTORY):$(BIOS_DIRECTORY)/cmds:$(CPU_DIRECTORY)


%.o: %.cpp
	$(compilexx)

%.o: %.c
	$(compile)

%.o: %.S
	$(assemble)

clean:
	$(RM) $(OBJECTS) proy1.elf proy1.bin .*~ *~

.PHONY: all clean
