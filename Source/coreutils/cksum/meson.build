executable(
	'cksum',
	'cksum.c',
	'crc.c',
	'md2.c',
	'md4.c',
	'md5.c',
	'print.c',
	'rmd160.c',
	'sha1.c',
	'sha256.c',
	'sha384.c',
	'sha512.c',
	'sum1.c',
	'sum2.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libmd,
	install : true,
	install_dir : get_option('bindir')
)

install_man('cksum.1')

install_symlink(
	'sum',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'md2',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'md4',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'md5',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'sha1',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'sha256',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'sha384',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'sha512',
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink( 
	'rmd160', 
	pointing_to : 'cksum',
	install_dir : get_option('bindir')
)

install_symlink(
	'sum.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'md2.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'md4.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'md5.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'sha1.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'sha256.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'sha384.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'sha512.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)

install_symlink(
	'rmd160.1',
	pointing_to : 'cksum.1',
	install_dir : get_option('mandir') / 'man1'
)
