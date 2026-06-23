executable(
	'diff3',
	'diff3.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)

install_man('diff3.1')
