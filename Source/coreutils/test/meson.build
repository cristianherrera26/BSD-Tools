executable(
	'xtest',
	'test.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'[',
	pointing_to: 'test',
	install_dir: get_option('bindir')
)
