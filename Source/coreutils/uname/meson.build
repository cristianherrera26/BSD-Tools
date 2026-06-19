executable(
	'uname',
	'uname.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'arch',
	pointing_to: 'uname',
	install_dir: get_option('bindir')
)

install_symlink(
	'machine',
	pointing_to: 'uname',
	install_dir: get_option('bindir')
)
