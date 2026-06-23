executable(
	'stat',
	'stat.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('stat.1')
install_man('readlink.1')

install_symlink(
	'readlink',
	pointing_to: 'stat',
	install_dir: get_option('bindir')
)
