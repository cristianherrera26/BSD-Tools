executable(
	'cal',
	'cal.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libncurses,
	install : true,
	install_dir : get_option('bindir')
)

install_man('cal.1')
