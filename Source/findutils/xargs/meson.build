executable(
	'xargs',
	'xargs.c',
	'strnsubst.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('xargs.1')
