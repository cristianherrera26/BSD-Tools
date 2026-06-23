executable(
	'factor',
	'factor.c',
	'pr_tbl.c',
	include_directories : incdir,
	c_args : [ '-Wno-deprecated-declarations' ],
	link_with : libcompat,
	dependencies : [ libcrypto, libcrypt ],
	install : true,
	install_dir : get_option('bindir')
)

install_man('factor.1')
