executable(
	'stat',
	'stat.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'readlink',
	pointing_to: 'stat',
	install_dir: get_option('bindir')
)
