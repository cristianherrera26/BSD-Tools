executable(
	'apply',
	'apply.c',
	include_directories : incdir,
	c_args : [ '-Wno-deprecated-declarations' ],
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('apply.1')
