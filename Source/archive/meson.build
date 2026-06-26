SUBDIRS = [ 'compress', 'pax' ]

if libz.found() and libztsd.found() and libbz2.found() and liblzma.found()
	SUBDIRS += 'gzip'
endif

foreach i : SUBDIRS
	subdir(i)
endforeach
