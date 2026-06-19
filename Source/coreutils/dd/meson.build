executable(
	'dd',
	'args.c',
	'conv.c',
	'dd.c',
	'dd_swab.c',
	'misc.c',
	'position.c',
	'dd_hostops.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)
