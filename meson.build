project('BSD-Tools', 'c',
	version : '11.99.6'
)

cc = meson.get_compiler('c')

libz = cc.find_library(
	'z',
	required : false
)

libbz2 = cc.find_library(
	'bz2',
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

libcrypto = dependency(
	'libcrypto',
	required : false
)

libcrypt = dependency(
	'libcrypt',
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
