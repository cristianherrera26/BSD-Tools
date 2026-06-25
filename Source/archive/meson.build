SUBDIRS = [ 'compress', 'pax' ]

if libztsd.found() 
	SUBDIRS += 'gzip'
endif

foreach i : SUBDIRS
	subdir(i)
endforeach
