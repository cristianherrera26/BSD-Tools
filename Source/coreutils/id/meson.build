executable(
	'id',
	'id.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'groups',
	pointing_to: 'id',
	install_dir: get_option('bindir')
)

install_symlink(
	'whoami',
	pointing_to: 'id',
	install_dir: get_option('bindir')
)
