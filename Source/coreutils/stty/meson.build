executable(
	'stty',
	'cchar.c',
	'gfmt.c',
	'key.c',
	'modes.c',
	'print.c',
	'stty.c',
	c_args : [ '-Wno-string-plus-int' ],
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)
