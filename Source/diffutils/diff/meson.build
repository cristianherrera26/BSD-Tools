executable(
	'diff',
	'diff.c',
	'diffdir.c',
	'diffreg.c',
	'pr.c',
	'xmalloc.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)
