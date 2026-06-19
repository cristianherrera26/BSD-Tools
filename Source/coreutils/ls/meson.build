executable(
	'ls',
	'cmp.c',
	'ls.c',
	'main.c',
	'print.c',
	'util.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'dir',
	pointing_to: 'ls',
	install_dir: get_option('bindir')
)
install_symlink(
	'vdir',
	pointing_to: 'ls',
	install_dir: get_option('bindir')
)
