executable(
	'm4',
	'eval.c',
	'expr.c',
	'gnum4.c',
	'look.c',
	'main.c',
	'misc.c',
	'ohash.c',
	'parser.c',
	'tokenizer.c',
	'trace.c',
	include_directories : incdir,
	c_args : [ '-DEXTENDED', '-Wno-sometimes-uninitialized' ],
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)
