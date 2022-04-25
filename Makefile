
all: build compile

build:
	-mkdir build
ifeq ($(OS),Windows_NT)
	xcopy evt2str/sdl_event_to_string.c evt2str/sdl_event_to_string.cpp /s/h/e/k/f/c
	cd build && cmake -G "Visual Studio 12" ..
	xcopy "C:\Development\Library\lib\x86\*.dll" "build" /s/h/e/k/f/c
else
	cd evt2str; ln -s sdl_event_to_string.c sdl_event_to_string.cpp
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
	del evt2str/sdl_event_to_string.cpp
else
	rm -rf build
	rm -f evt2str/sdl_event_to_string.cpp
endif

