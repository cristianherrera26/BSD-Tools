#include <stdio.h>
#include <stdbool.h>

struct lvalue {
	ssize_t load;
	ssize_t store;
};

int		yylex(void);
void		yyerror(char *);
void		fatal(const char *);
void		abort_line(int);
struct termios;
int		gettty(struct termios *);
void		tstpcont(int);
unsigned char	bc_eof(EditLine *, int);

extern int	lineno;
extern char	*yytext;
extern FILE	*yyin;
extern int	fileindex;
extern int	sargc;
extern char	**sargv;
extern char	*filename;
extern bool	interactive;
extern EditLine	*el;
extern History	*hist;
extern HistEvent he;
extern char	*cmdexpr;
extern struct termios ttysaved;
