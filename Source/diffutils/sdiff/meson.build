executable(
	'sdiff',
	'common.c',
	'edit.c',
	'sdiff.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)
