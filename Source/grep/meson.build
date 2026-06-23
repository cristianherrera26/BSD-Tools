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

install_man('grep.1')

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
	'zgrep',
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

install_symlink(
	'egrep.1',
	pointing_to: 'grep.1',
	install_dir: get_option('mandir') / 'man1'
)

install_symlink(
	'fgrep.1',
	pointing_to: 'grep.1',
	install_dir: get_option('mandir') / 'man1'
)

install_symlink(
	'zgrep.1',
	pointing_to: 'grep.1',
	install_dir: get_option('mandir') / 'man1'
)

install_symlink(
	'zegrep.1',
	pointing_to: 'grep.1',
	install_dir: get_option('mandir') / 'man1'
)

install_symlink(
	'zfgrep.1',
	pointing_to: 'grep.1',
	install_dir: get_option('mandir') / 'man1'
)
