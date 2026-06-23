executable(
	'compress',
	'compress.c',
	'zopen.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('compress.1')

install_symlink(
	'uncompress',
	pointing_to: 'compress',
	install_dir: get_option('bindir')
)

install_symlink(
	'uncompress.1',
	pointing_to: 'compress.1',
	install_dir: get_option('mandir') / 'man1'
)
