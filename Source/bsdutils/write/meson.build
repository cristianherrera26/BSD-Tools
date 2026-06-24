executable(
	'write',
	'write.c',
	'utmpentry.c',
	'term_chk.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('sbindir')
)

install_man('write.1')
