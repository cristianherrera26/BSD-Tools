executable(
	'gzip',
	'gzip.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : [ libz, libbz2, liblzma, libztsd ],
	install : true,
	install_dir : get_option('bindir')
)

install_man('gzip.1')
install_man('gzexe.1')
install_man('zdiff.1')
install_man('zforce.1')
install_man('zmore.1')
install_man('znew.1')

install_data('gzexe',
	install_dir : get_option('bindir'),
	install_mode : 'rwxr-xr-x'
)

install_data('zdiff',
	install_dir : get_option('bindir'),
	install_mode : 'rwxr-xr-x'
)

install_data('zforce',
	install_dir : get_option('bindir'),
	install_mode : 'rwxr-xr-x'
)

install_data('zmore',
	install_dir : get_option('bindir'),
	install_mode : 'rwxr-xr-x'
)

install_data('znew',
	install_dir : get_option('bindir'),
	install_mode : 'rwxr-xr-x'
)

install_symlink(
	'gunzip',
	pointing_to : 'gzip',
	install_dir : get_option('bindir')
)

install_symlink(
	'zcat',
	pointing_to : 'gzip',
	install_dir : get_option('bindir')
)

install_symlink(
	'gzcat',
	pointing_to : 'gzip',
	install_dir : get_option('bindir')
)

install_symlink(
	'zcmp',
	pointing_to : 'zdiff',
	install_dir : get_option('bindir')
)

install_symlink(
	'zless',
	pointing_to : 'zmore',
	install_dir : get_option('bindir')
)
