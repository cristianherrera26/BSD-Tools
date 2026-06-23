executable(
	'nohup',
	'nohup.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('nohup.1')
