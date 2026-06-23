executable(
	'fmt',
	'fmt.c',
	'head.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('fmt.1')
