executable(
	'xtest',
	'test.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('test.1')

install_symlink(
	'[',
	pointing_to: 'xtest',
	install_dir: get_option('bindir')
)

install_symlink(
	'test',
	pointing_to: 'xtest',
	install_dir: get_option('bindir')
)

install_symlink(
	'[.1',
	pointing_to: 'test.1',
	install_dir: get_option('mandir') / 'man1'
)
