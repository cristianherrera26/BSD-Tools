executable(
	'expand',
	'expand.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('expand.1')

install_symlink(
	'unexpand.1',
	pointing_to : 'expand.1',
	install_dir : get_option('mandir') / 'man1'
)
