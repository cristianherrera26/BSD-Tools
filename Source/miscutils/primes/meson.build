executable(
	'primes',
	'pattern.c',
	'primes.c',
	'pr_tbl.c',
	'spsp.c',
	include_directories : incdir,
	link_with : libcompat,
	dependencies : libm,
	install : true,
	install_dir : get_option('bindir')
)

install_man('primes.6')
