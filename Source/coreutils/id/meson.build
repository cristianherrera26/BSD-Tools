executable(
	'id',
	'id.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('id.1')
install_man('groups.1')
install_man('whoami.1')

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
