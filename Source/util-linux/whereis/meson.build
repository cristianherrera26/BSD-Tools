executable(
	'whereis',
	'whereis.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'which',
	pointing_to: 'whereis',
	install_dir: get_option('bindir')
)
