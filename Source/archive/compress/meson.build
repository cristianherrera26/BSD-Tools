executable(
	'compress',
	'compress.c',
	'zopen.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'uncompress',
	pointing_to: 'compress',
	install_dir: get_option('bindir')
)
