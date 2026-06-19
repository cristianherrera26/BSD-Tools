executable(
	'patch',
	'patch.c',
	'pch.c',
	'inp.c',
	'util.c',
	'backupfile.c',
	'mkpath.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)
