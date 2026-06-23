executable(
	'arch',
	'arch.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('arch.1')

install_symlink(
	'machine',
	pointing_to: 'arch',
	install_dir: get_option('bindir')
)

install_symlink(
	'machine.1',
	pointing_to: 'arch.1',
	install_dir: get_option('mandir') / 'man1'
)
