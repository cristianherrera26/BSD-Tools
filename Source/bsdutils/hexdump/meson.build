executable(
	'hexdump',
	'conv.c',
	'display.c',
	'hexdump.c',
	'hexsyntax.c',
	'odsyntax.c',
	'parse.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'od',
	pointing_to: 'hexdump',
	install_dir: get_option('bindir')
)
