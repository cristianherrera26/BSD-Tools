executable(
	'dc',
	'bcode.c',
	'dc.c',
	'inout.c',
	'main.c',
	'mem.c',
	'stack.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libcrypto,
	install : true,
	install_dir : get_option('bindir')
)

if libedit.found()
executable(
	'bc',
	'bc.c',
	'scan.c',
	'tty.c',
	'bcode.c',
	'dc.c',
	'inout.c',
	'mem.c',
	'stack.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : [ libcrypto, libncurses, libedit ],
	install : true,
	install_dir : get_option('bindir')
)

install_data(
	'bc.library',
	install_dir: get_option('prefix') / 'share' / 'misc'
)

endif
