begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ex.h	7.9 (Berkeley) 1/2/88  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_include
include|#
directive|include
file|<retrofit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ex version 3 (see exact version in ex_cmds.c, search for /Version/)  *  * Mark Horton, UC Berkeley  * Bill Joy, UC Berkeley  * November 1979  *  * This file contains most of the declarations common to a large number  * of routines.  The file ex_vis.h contains declarations  * which are used only inside the screen editor.  * The file ex_tune.h contains parameters which can be diddled per installation.  *  * The declarations relating to the argument list, regular expressions,  * the temporary file data structure used by the editor  * and the data describing terminals are each fairly substantial and  * are kept in the files ex_{argv,re,temp,tty}.h which  * we #include separately.  *  * If you are going to dig into ex, you should look at the outline of the  * distribution of the code into files at the beginning of ex.c and ex_v.c.  * Code which is similar to that of ed is lightly or undocumented in spots  * (e.g. the regular expression code).  Newer code (e.g. open and visual)  * is much more carefully documented, and still rough in spots.  *  * Please forward bug reports to  *  *	Mark Horton  *	Computer Science Division, EECS  *	EVANS HALL  *	U.C. Berkeley 94704  *	(415) 642-4948  *	(415) 642-1024 (dept. office)  *  * or to csvax.mark@berkeley on the ARPA-net.  I would particularly like to hear  * of additional terminal descriptions you add to the termcap data base.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|vms
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXBSIZE
value|1024
end_define

begin_comment
comment|/* Maximum block size */
end_comment

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|vms
end_ifndef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|var
end_ifndef

begin_define
define|#
directive|define
name|var
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	The following little dance copes with the new USG tty handling.  *	This stuff has the advantage of considerable flexibility, and  *	the disadvantage of being incompatible with anything else.  *	The presence of the symbol USG3TTY will indicate the new code:  *	in this case, we define CBREAK (because we can simulate it exactly),  *	but we won't actually use it, so we set it to a value that will  *	probably blow the compilation if we goof up.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG3TTY
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_define
define|#
directive|define
name|CBREAK
value|xxxxx
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|vms
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"vmstty.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_typedef
typedef|typedef
name|short
name|line
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|line
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|short
name|bool
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"ex_tune.h"
end_include

begin_include
include|#
directive|include
file|"ex_vars.h"
end_include

begin_comment
comment|/*  * Options in the editor are referred to usually by "value(name)" where  * name is all uppercase, i.e. "value(PROMPT)".  This is actually a macro  * which expands to a fixed field in a static structure and so generates  * very little code.  The offsets for the option names in the structure  * are generated automagically from the structure initializing them in  * ex_data.c... see the shell script "makeoptions".  */
end_comment

begin_struct
struct|struct
name|option
block|{
name|char
modifier|*
name|oname
decl_stmt|;
name|char
modifier|*
name|oabbrev
decl_stmt|;
name|short
name|otype
decl_stmt|;
comment|/* Types -- see below */
name|short
name|odefault
decl_stmt|;
comment|/* Default value */
name|short
name|ovalue
decl_stmt|;
comment|/* Current value */
name|char
modifier|*
name|osvalue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ONOFF
value|0
end_define

begin_define
define|#
directive|define
name|NUMERIC
value|1
end_define

begin_define
define|#
directive|define
name|STRING
value|2
end_define

begin_comment
comment|/* SHELL or DIRECTORY */
end_comment

begin_define
define|#
directive|define
name|OTERM
value|3
end_define

begin_define
define|#
directive|define
name|value
parameter_list|(
name|a
parameter_list|)
value|options[a].ovalue
end_define

begin_define
define|#
directive|define
name|svalue
parameter_list|(
name|a
parameter_list|)
value|options[a].osvalue
end_define

begin_decl_stmt
specifier|extern
name|struct
name|option
name|options
index|[
name|NOPTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_define
define|#
directive|define
name|st_blksize
value|st_fab_mrs
end_define

begin_define
define|#
directive|define
name|_exit
parameter_list|(
name|n
parameter_list|)
value|vms_exit(n)
end_define

begin_define
define|#
directive|define
name|fork
parameter_list|()
value|vfork()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The editor does not normally use the standard i/o library.  Because  * we expect the editor to be a heavily used program and because it  * does a substantial amount of input/output processing it is appropriate  * for it to call low level read/write primitives directly.  In fact,  * when debugging the editor we use the standard i/o library.  In any  * case the editor needs a printf which prints through "putchar" ala the  * old version 6 printf.  Thus we normally steal a copy of the "printf.c"  * and "strout" code from the standard i/o library and mung it for our  * purposes to avoid dragging in the stdio library headers, etc if we  * are not debugging.  Such a modified printf exists in "printf.c" here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|var
name|FILE
modifier|*
name|trace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|bool
name|trubble
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|bool
name|techoin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
name|tracbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|u370
end_ifdef

begin_define
define|#
directive|define
name|BUFSIZ
value|4096
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|EOF
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Character constants and bits  *  * The editor uses the QUOTE bit as a flag to pass on with characters  * e.g. to the putchar routine.  The editor never uses a simple char variable.  * Only arrays of and pointers to characters are used and parameters and  * registers are never declared character.  */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|TRIM
value|0177
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vms
end_ifndef

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|(c& 037)
end_define

begin_define
define|#
directive|define
name|NL
value|CTRL('j')
end_define

begin_define
define|#
directive|define
name|CR
value|CTRL('m')
end_define

begin_define
define|#
directive|define
name|DELETE
value|0177
end_define

begin_comment
comment|/* See also ATTN, QUIT in ex_tune.h */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|033
end_define

begin_comment
comment|/*  * Miscellaneous random variables used in more than one place  */
end_comment

begin_decl_stmt
name|var
name|bool
name|aiflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Append/change/insert with autoindent */
end_comment

begin_decl_stmt
name|var
name|bool
name|anymarks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We have used '[a-z] */
end_comment

begin_decl_stmt
name|var
name|int
name|chng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn "No write" */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|Command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|defwind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w# change default window size */
end_comment

begin_decl_stmt
name|var
name|int
name|dirtcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When>= MAXDIRT, should sync temporary */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCLGET
end_ifdef

begin_decl_stmt
name|var
name|bool
name|dosusp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do SIGTSTP in visual when ^Z typed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|var
name|bool
name|edited
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current file is [Edited] */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|endcore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last available core location */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|endline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last cmd mode command ended with \n */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXSTRINGS
end_ifdef

begin_decl_stmt
name|var
name|short
name|erfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error message file unit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|var
name|line
modifier|*
name|fendcore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First address in line pointer space */
end_comment

begin_decl_stmt
name|var
name|char
name|file
index|[
name|FNSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Working file name */
end_comment

begin_decl_stmt
name|var
name|char
name|genbuf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Working buffer when manipulating linebuf */
end_comment

begin_decl_stmt
name|var
name|bool
name|hush
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command line option - was given, hush up! */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|globp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (Untyped) input string to command mode */
end_comment

begin_decl_stmt
name|var
name|bool
name|holdcm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't cursor address */
end_comment

begin_decl_stmt
name|var
name|bool
name|inappend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in ex command append mode */
end_comment

begin_decl_stmt
name|var
name|bool
name|inglobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inside g//... or v//... */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|initev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial : escape for visual */
end_comment

begin_decl_stmt
name|var
name|bool
name|inopen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inside open or visual */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current position in cmd line input buffer */
end_comment

begin_decl_stmt
name|var
name|bool
name|intty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input is a tty */
end_comment

begin_decl_stmt
name|var
name|short
name|io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General i/o unit (auto-closed on error!) */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|lastc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last character ret'd from cmd input */
end_comment

begin_decl_stmt
name|var
name|bool
name|laste
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last command was an "e" (or "rec") */
end_comment

begin_decl_stmt
name|var
name|char
name|lastmac
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last macro called for ** */
end_comment

begin_decl_stmt
name|var
name|char
name|lasttag
index|[
name|TAGSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last argument to a tag command */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|linebp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used in substituting in \n */
end_comment

begin_decl_stmt
name|var
name|char
name|linebuf
index|[
name|LBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The primary line buffer */
end_comment

begin_decl_stmt
name|var
name|bool
name|listf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command should run in list mode */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|loc1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where re began to match (in linebuf) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|loc2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First char after re match (") */
end_comment

begin_decl_stmt
name|var
name|line
name|names
index|[
literal|'z'
operator|-
literal|'a'
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark registers a-z,' */
end_comment

begin_decl_stmt
name|var
name|int
name|notecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count for notify (to visual from cmd) */
end_comment

begin_decl_stmt
name|var
name|bool
name|numberf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command should run in number mode */
end_comment

begin_decl_stmt
name|var
name|char
name|obuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for tty output */
end_comment

begin_decl_stmt
name|var
name|short
name|oprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Saved during source */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output speed (from gtty) */
end_comment

begin_decl_stmt
name|var
name|int
name|otchng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backup tchng to find changes in macros */
end_comment

begin_decl_stmt
name|var
name|short
name|peekc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Peek ahead character (cmd mode input) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|pkill
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Trim for put with ragged (LISP) delete */
end_comment

begin_decl_stmt
name|var
name|bool
name|pfast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have stty -nl'ed to go faster */
end_comment

begin_decl_stmt
name|var
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process id of child */
end_comment

begin_decl_stmt
name|var
name|int
name|ppid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process id of parent (e.g. main ex proc) */
end_comment

begin_decl_stmt
name|var
name|jmp_buf
name|resetlab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For error throws to top level (cmd mode) */
end_comment

begin_decl_stmt
name|var
name|int
name|rpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pid returned from wait() */
end_comment

begin_decl_stmt
name|var
name|bool
name|ruptible
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interruptible is normal state */
end_comment

begin_decl_stmt
name|var
name|bool
name|seenprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if have gotten user input */
end_comment

begin_decl_stmt
name|var
name|bool
name|shudclob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have a prompt to clobber (e.g. on ^D) */
end_comment

begin_decl_stmt
name|var
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Status returned from wait() */
end_comment

begin_decl_stmt
name|var
name|int
name|tchng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If nonzero, then [Modified] */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|tfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary file unit */
end_comment

begin_decl_stmt
name|var
name|bool
name|vcatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Want to catch an error (open/visual) */
end_comment

begin_decl_stmt
name|var
name|jmp_buf
name|vreslab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For error throws to a visual catch */
end_comment

begin_decl_stmt
name|var
name|bool
name|writing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if in middle of a file write */
end_comment

begin_decl_stmt
name|var
name|int
name|xchng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Suppresses multiple "No writes" in !cmd */
end_comment

begin_decl_stmt
name|var
name|long
name|bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Block size for disk i/o */
end_comment

begin_comment
comment|/*  * Macros  */
end_comment

begin_define
define|#
directive|define
name|CP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ignore(strcpy(a, b)))
end_define

begin_comment
comment|/* 			 * FIXUNDO: do we want to mung undo vars? 			 * Usually yes unless in a macro or global. 			 */
end_comment

begin_define
define|#
directive|define
name|FIXUNDO
value|(inopen>= 0&& (inopen || !inglobal))
end_define

begin_define
define|#
directive|define
name|ckaw
parameter_list|()
value|{if (chng&& value(AUTOWRITE)) wop(0);}
end_define

begin_define
define|#
directive|define
name|copy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Copy((char *) a, (char *) b, c)
end_define

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)&& (b)&& strcmp(a, b) == 0)
end_define

begin_define
define|#
directive|define
name|getexit
parameter_list|(
name|a
parameter_list|)
value|copy(a, resetlab, sizeof (jmp_buf))
end_define

begin_define
define|#
directive|define
name|lastchar
parameter_list|()
value|lastc
end_define

begin_define
define|#
directive|define
name|outchar
parameter_list|(
name|c
parameter_list|)
value|(*Outchar)(c)
end_define

begin_define
define|#
directive|define
name|pastwh
parameter_list|()
value|(ignore(skipwh()))
end_define

begin_define
define|#
directive|define
name|pline
parameter_list|(
name|no
parameter_list|)
value|(*Pline)(no)
end_define

begin_define
define|#
directive|define
name|reset
parameter_list|()
value|longjmp(resetlab,1)
end_define

begin_define
define|#
directive|define
name|resexit
parameter_list|(
name|a
parameter_list|)
value|copy(resetlab, a, sizeof (jmp_buf))
end_define

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|setjmp(resetlab)
end_define

begin_define
define|#
directive|define
name|setlastchar
parameter_list|(
name|c
parameter_list|)
value|lastc = c
end_define

begin_define
define|#
directive|define
name|ungetchar
parameter_list|(
name|c
parameter_list|)
value|peekc = c
end_define

begin_define
define|#
directive|define
name|CATCH
value|vcatch = 1; if (setjmp(vreslab) == 0) {
end_define

begin_define
define|#
directive|define
name|ONERR
value|} else { vcatch = 0;
end_define

begin_define
define|#
directive|define
name|ENDCATCH
value|} vcatch = 0;
end_define

begin_comment
comment|/*  * Environment like memory  */
end_comment

begin_decl_stmt
name|var
name|char
name|altfile
index|[
name|FNSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alternate file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|direct
index|[
name|ONMSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file goes here */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|shell
index|[
name|ONMSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copied to be settable */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ttytype
index|[
name|ONMSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A long and pretty name */
end_comment

begin_decl_stmt
name|var
name|char
name|uxb
index|[
name|UXBSIZE
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last !command for !! */
end_comment

begin_comment
comment|/*  * The editor data structure for accessing the current file consists  * of an incore array of pointers into the temporary file tfile.  * Each pointer is 15 bits (the low bit is used by global) and is  * padded with zeroes to make an index into the temp file where the  * actual text of the line is stored.  *  * To effect undo, copies of affected lines are saved after the last  * line considered to be in the buffer, between dol and unddol.  * During an open or visual, which uses the command mode undo between  * dol and unddol, a copy of the entire, pre-command buffer state  * is saved between unddol and truedol.  */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|addr1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First addressed line in a command */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|addr2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Second addressed line */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|dol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last line in buffer */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|dot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current line */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|one
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First line */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|truedol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End of all lines, including saves */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|unddol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End of undo saved lines */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|zero
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to empty slot before one */
end_comment

begin_comment
comment|/*  * Undo information  *  * For most commands we save lines changed by salting them away between  * dol and unddol before they are changed (i.e. we save the descriptors  * into the temp file tfile which is never garbage collected).  The  * lines put here go back after unddel, and to complete the undo  * we delete the lines [undap1,undap2).  *  * Undoing a move is much easier and we treat this as a special case.  * Similarly undoing a "put" is a special case for although there  * are lines saved between dol and unddol we don't stick these back  * into the buffer.  */
end_comment

begin_decl_stmt
name|var
name|short
name|undkind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|line
modifier|*
name|unddel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Saved deleted lines go after here */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|undap1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Beginning of new lines */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|undap2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New lines end before undap2 */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|undadot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If we saved all lines, dot reverts here */
end_comment

begin_define
define|#
directive|define
name|UNDCHANGE
value|0
end_define

begin_define
define|#
directive|define
name|UNDMOVE
value|1
end_define

begin_define
define|#
directive|define
name|UNDALL
value|2
end_define

begin_define
define|#
directive|define
name|UNDNONE
value|3
end_define

begin_define
define|#
directive|define
name|UNDPUT
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CRYPT
end_ifdef

begin_comment
comment|/*  * Various miscellaneous flags and buffers needed by the encryption routines.  */
end_comment

begin_define
define|#
directive|define
name|KSIZE
value|9
end_define

begin_comment
comment|/* key size for encryption */
end_comment

begin_define
define|#
directive|define
name|KEYPROMPT
value|"Key: "
end_define

begin_decl_stmt
name|var
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we are in encryption mode */
end_comment

begin_decl_stmt
name|var
name|int
name|xtflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if the temp file is being encrypted */
end_comment

begin_decl_stmt
name|var
name|int
name|kflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if the key has been accepted */
end_comment

begin_decl_stmt
name|var
name|char
name|perm
index|[
literal|768
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
name|tperm
index|[
literal|768
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
name|crbuf
index|[
name|CRSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getpass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function type definitions  */
end_comment

begin_define
define|#
directive|define
name|NOSTR
value|(char *) 0
end_define

begin_define
define|#
directive|define
name|NOLINE
value|(line *) 0
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|Outchar
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|Pline
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|Put_char
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|var
name|int
function_decl|(
modifier|*
name|oldhup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|int
argument_list|(
operator|*
name|setlist
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|setnorm
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|setnorm
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|setnumb
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|line
modifier|*
name|address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cgoto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|genindent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getblock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_function_decl
name|char
modifier|*
name|getlog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|line
modifier|*
name|getmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|longname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mesg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|place
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|plural
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|line
modifier|*
name|scanfor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|line
modifier|*
name|setin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tailpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|line
modifier|*
name|vback
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vfindcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vgetline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vpastwh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vskipwh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|put
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putreg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|YANKreg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ex_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gettty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|join
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|listchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|normchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|normline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|numbline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|var
name|int
function_decl|(
modifier|*
name|oldquit
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|onhup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|onintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|onsusp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|termchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfilter
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CBREAK
end_ifdef

begin_function_decl
name|int
name|vintr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|vputch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vshftop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yank
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * C doesn't have a (void) cast, so we have to fake it for lint's sake.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|ignore
parameter_list|(
name|a
parameter_list|)
value|Ignore((char *) (a))
end_define

begin_define
define|#
directive|define
name|ignorf
parameter_list|(
name|a
parameter_list|)
value|Ignorf((int (*) ()) (a))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ignore
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|ignorf
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

