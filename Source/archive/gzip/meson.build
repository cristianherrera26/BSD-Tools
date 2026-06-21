executable(
	'gzip',
	'gzip.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : [ libz, libbz2, liblzma, libztsd ],
	install : true,
	install_dir : get_option('bindir')
)
