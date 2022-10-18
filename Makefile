
WIN_SDL2_PATH="C:\Development\Library\SDL2-2.24.1"


all: build compile

build:
	-mkdir build
ifeq ($(OS),Windows_NT)
	cd build && cmake ..
	xcopy "$(WIN_SDL2_PATH)\lib\x64\*.dll" "build" /s/h/e/k/f/c
else
	cd build; cmake ..
endif

compile:
ifeq ($(OS),Windows_NT)
	@echo ""
	@echo "Open the project with Visual Studio and compile it ;-)"
else
	make -C build
endif

clean:
ifeq ($(OS),Windows_NT)
	-rmdir /s /q build
else
	rm -rf build
endif

