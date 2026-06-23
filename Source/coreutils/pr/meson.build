executable(
	'pr',
	'pr.c',
	'egetopt.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('pr.1')
