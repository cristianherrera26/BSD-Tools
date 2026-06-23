executable(
	'whereis',
	'whereis.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('whereis.1')
install_man('which.1')

install_symlink(
	'which',
	pointing_to: 'whereis',
	install_dir: get_option('bindir')
)
