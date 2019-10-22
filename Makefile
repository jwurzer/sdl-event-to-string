
all: build compile

build:
	-mkdir build
ifeq ($(OS),Windows_NT)
	cd build && cmake -G "Visual Studio 12" ..
	xcopy "C:\Development\Library\lib\x86\*.dll" "build" /s/h/e/k/f/c
else
	cd build; cmake ..
endif

compile:
ifeq ($(OS),Windows_NT)
	@echo ""
	@echo "Open the project with VS2013 and compile it ;-)"
else
	make -C build
endif

clean:
ifeq ($(OS),Windows_NT)
	-rmdir build /s /q
else
	rm -rf build
endif

