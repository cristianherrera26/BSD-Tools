executable(
	'jot',
	'jot.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)

install_man('jot.1')
