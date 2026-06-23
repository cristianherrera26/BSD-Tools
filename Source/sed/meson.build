executable(
	'sed',
	'compile.c',
	'main.c',
	'misc.c',
	'process.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('sed.1')
