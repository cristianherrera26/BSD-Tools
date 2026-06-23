executable(
	'xinstall',
	'xinstall.c',
	'getid.c',
	include_directories : incdir,
	c_args : [ '-Wno-unused-function', '-Wno-unused-variable' ],
	link_with : libcompat,
	dependencies : libmd,
	install : true,
	install_dir : get_option('bindir')
)

install_man('install.1')

install_symlink(
	'install',
	pointing_to: 'xinstall',
	install_dir: get_option('bindir')
)
