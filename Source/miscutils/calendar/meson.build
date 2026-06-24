executable(
	'calendar',
	'calendar.c',
	include_directories : incdir,
	link_with : libcompat,
	install : true,
	install_dir : get_option('bindir')
)

install_man('calendar.1')

install_subdir(
	'calendars',
	install_dir : get_option('prefix') / 'share/calendar'
)
