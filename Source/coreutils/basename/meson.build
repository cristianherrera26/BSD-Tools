executable(
	'basename',
	'basename.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('basename.1')

install_symlink(
	'dirname.1',
	pointing_to : 'basename.1',
	install_dir : get_option('mandir') / 'man1'
)
