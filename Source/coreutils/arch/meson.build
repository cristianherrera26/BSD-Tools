executable(
	'arch',
	'arch.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'machine',
	pointing_to: 'arch',
	install_dir: get_option('bindir')
)
