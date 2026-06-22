all: build

build:
	meson setup --prefix=/usr build
	ninja -C build
rebuild:
	ninja -C build
install: 
	DESTDIR=$(DESTDIR) ninja -C build install
clean:
	rm -rf build
.PHONY: all build install clean
