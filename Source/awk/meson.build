executable(
	'awk',
	'awkgram.c',
	'b.c',
	'lex.c',
	'lib.c',
	'main.c',
	'parse.c',
	'proctab.c',
	'run.c',
	'tran.c',
	include_directories : incdir,
	dependencies : libm,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('awk.1')
