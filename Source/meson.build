SUBDIRS = [ 'coreutils', 'diffutils', 'findutils', 'ksh', 'miscutils', 'patch', 'sed', 'util-linux' ]

if libz.found() and libbz2.found()
	SUBDIRS += 'grep'
endif

foreach i : SUBDIRS
	subdir(i)
endforeach
