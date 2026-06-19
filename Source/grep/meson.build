executable(
	'grep',
	'fastgrep.c',
	'file.c',
	'grep.c', 
	'queue.c',
	'util.c',
	include_directories : incdir,
	dependencies : [ libz, libbz2 ],
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'egrep',
	pointing_to: 'grep',
	install_dir: get_option('bindir')
)

install_symlink(
	'fgrep',
	pointing_to: 'grep',
	install_dir: get_option('bindir')
)

install_symlink(
	'zegrep',
	pointing_to: 'grep',
	install_dir: get_option('bindir')
)

install_symlink(
	'zfgrep',
	pointing_to: 'grep',
	install_dir: get_option('bindir')
)
