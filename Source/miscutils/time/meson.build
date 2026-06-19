executable(
	'time',
	'time.c',
	'xtime.c',
	include_directories : incdir,
	c_args : [ '-DNOT_CSH' ],
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)
