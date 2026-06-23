executable(
	'find',
	'find.c',
	'function.c',
	'ls.c',
	'main.c',
	'misc.c',
	'operator.c',
	'option.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('find.1')
