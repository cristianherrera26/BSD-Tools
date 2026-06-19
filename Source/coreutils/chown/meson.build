executable(
	'chown',
	'chown.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_symlink(
	'chgrp',
	pointing_to: 'chown',
	install_dir: get_option('bindir')
)
