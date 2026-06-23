executable(
	'tail',
	'forward.c',
	'misc.c',
	'read.c',
	'reverse.c',
	'tail.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('tail.1')
install_man('tac.1')

install_symlink(
	'tac',
	pointing_to: 'tail',
	install_dir: get_option('bindir')
)
