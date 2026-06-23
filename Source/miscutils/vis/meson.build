executable(
	'vis',
	'vis.c',
	'foldit.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('vis.1')
