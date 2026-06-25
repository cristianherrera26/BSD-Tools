project('BSD-Tools', 'c',
	version : '11.99.6',
	default_options : [
		'c_std=c23',
	]
)

cc = meson.get_compiler('c')

if host_machine.system() != 'linux'
	warning('This project only has been tested on linux')
endif

libz = cc.find_library(
	'z',
	required : false
)

libbz2 = cc.find_library(
	'bz2',
	required : false
)

liblzma = cc.find_library(
	'lzma',
	required : false
)

libztsd = dependency(
	'libzstd',
	required : false
)

libm = cc.find_library(
	'm',
	required : false
)

libmd = dependency(
	'libmd',
	required : false
)

libedit = dependency(
	'libedit',
	required : false
)

libcrypto = dependency(
	'libcrypto',
	required : false
)

libcrypt = cc.find_library(
	'crypt',
	required : false
)

libncurses = cc.find_library(
	'libncurses',
	required : false
)

incdir = include_directories('Headers')
SUBDIRS = [ 'Library', 'Source' ]

foreach i : SUBDIRS
	subdir(i)
endforeach
