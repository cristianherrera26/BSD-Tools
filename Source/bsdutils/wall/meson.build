executable(
	'wall',
	'wall.c',
	'utmpentry.c',
	'term_chk.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('wall.1')
