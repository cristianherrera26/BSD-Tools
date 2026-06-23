executable(
	'chroot',
	'chroot.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('sbindir')
)

install_man('chroot.8')
