SUBDIRS = [ 	'archive', 
		'awk', 
		'bc',
		'bsdutils', 
		'coreutils', 
		'diffutils', 
		'findutils', 
		'ksh', 
		'm4', 
		'miscutils', 
		'patch', 
		'sed' 
]

if libz.found() and libbz2.found()
	SUBDIRS += 'grep'
endif

foreach i : SUBDIRS
	subdir(i)
endforeach
