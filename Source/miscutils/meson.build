SUBDIRS = [ 	'apply', 
		'asa',
		'banner',
		'biff',
		'c11', 
		'c17',
		'c89', 
		'c99',
		'calendar', 
		'column', 
		'domainname', 
		'gencat',
		'getconf',
		'jot', 
		'primes', 
		'progress',
		'rs',
		'time', 
		'unvis', 
		'vis' ]

if libncurses.found()
	SUBDIRS += 'cal'
endif

foreach i : SUBDIRS
	subdir(i)
endforeach
