begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/* config.h - version 1.0.3 */
end_comment

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG
end_ifndef

begin_comment
comment|/* make sure the compiler doesnt see the typedefs twice */
end_comment

begin_define
define|#
directive|define
name|CONFIG
end_define

begin_define
define|#
directive|define
name|UNIX
end_define

begin_comment
comment|/* delete if no fork(), exec() available */
end_comment

begin_define
define|#
directive|define
name|CHDIR
end_define

begin_comment
comment|/* delete if no chdir() available */
end_comment

begin_comment
comment|/*  * Some include files are in a different place under SYSV  * 	BSD		   SYSV  *<sys/wait.h><wait.h>  *<sys/time.h><time.h>  *<sgtty.h><termio.h>  * Some routines are called differently  * index		strchr  * rindex		strrchr  * Also, the code for suspend and various ioctls is only given for BSD4.2  * (I do not have access to a SYSV system.)  */
end_comment

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* delete this line on System V */
end_comment

begin_comment
comment|/* #define STUPID */
end_comment

begin_comment
comment|/* avoid some complicated expressions if 			   your C compiler chokes on them */
end_comment

begin_comment
comment|/* #define PYRAMID_BUG */
end_comment

begin_comment
comment|/* avoid a bug on the Pyramid */
end_comment

begin_comment
comment|/* #define NOWAITINCLUDE */
end_comment

begin_comment
comment|/* neither<wait.h> nor<sys/wait.h> exists */
end_comment

begin_define
define|#
directive|define
name|WIZARD
value|"bruno"
end_define

begin_comment
comment|/* the person allowed to use the -D option */
end_comment

begin_define
define|#
directive|define
name|RECORD
value|"record"
end_define

begin_comment
comment|/* the file containing the list of topscorers */
end_comment

begin_define
define|#
directive|define
name|NEWS
value|"news"
end_define

begin_comment
comment|/* the file containing the latest hack news */
end_comment

begin_define
define|#
directive|define
name|HELP
value|"help"
end_define

begin_comment
comment|/* the file containing a description of the commands */
end_comment

begin_define
define|#
directive|define
name|SHELP
value|"hh"
end_define

begin_comment
comment|/* abbreviated form of the same */
end_comment

begin_define
define|#
directive|define
name|RUMORFILE
value|"rumors"
end_define

begin_comment
comment|/* a file with fortune cookies */
end_comment

begin_define
define|#
directive|define
name|DATAFILE
value|"data"
end_define

begin_comment
comment|/* a file giving the meaning of symbols used */
end_comment

begin_define
define|#
directive|define
name|FMASK
value|0660
end_define

begin_comment
comment|/* file creation mask */
end_comment

begin_define
define|#
directive|define
name|HLOCK
value|"perm"
end_define

begin_comment
comment|/* an empty file used for locking purposes */
end_comment

begin_define
define|#
directive|define
name|LLOCK
value|"safelock"
end_define

begin_comment
comment|/* link to previous */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/*  * Define DEF_PAGER as your default pager, e.g. "/bin/cat" or "/usr/ucb/more"  * If defined, it can be overridden by the environment variable PAGER.  * Hack will use its internal pager if DEF_PAGER is not defined.  * (This might be preferable for security reasons.)  * #define DEF_PAGER	".../mydir/mypager"  */
end_comment

begin_comment
comment|/*  * If you define MAIL, then the player will be notified of new mail  * when it arrives. If you also define DEF_MAILREADER then this will  * be the default mail reader, and can be overridden by the environment  * variable MAILREADER; otherwise an internal pager will be used.  * A stat system call is done on the mailbox every MAILCKFREQ moves.  */
end_comment

begin_comment
comment|/* #define	MAIL */
end_comment

begin_define
define|#
directive|define
name|DEF_MAILREADER
value|_PATH_MAIL
end_define

begin_comment
comment|/* or e.g. /bin/mail */
end_comment

begin_define
define|#
directive|define
name|MAILCKFREQ
value|100
end_define

begin_define
define|#
directive|define
name|SHELL
end_define

begin_comment
comment|/* do not delete the '!' command */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|SUSPEND
end_define

begin_comment
comment|/* let ^Z suspend the game */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_endif
endif|#
directive|endif
endif|UNIX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CHDIR
end_ifdef

begin_comment
comment|/*  * If you define HACKDIR, then this will be the default playground;  * otherwise it will be the current directory.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUEST
end_ifdef

begin_define
define|#
directive|define
name|HACKDIR
value|_PATH_QUEST
end_define

begin_else
else|#
directive|else
else|QUEST
end_else

begin_define
define|#
directive|define
name|HACKDIR
value|_PATH_HACK
end_define

begin_endif
endif|#
directive|endif
endif|QUEST
end_endif

begin_comment
comment|/*  * Some system administrators are stupid enough to make Hack suid root  * or suid daemon, where daemon has other powers besides that of reading or  * writing Hack files. In such cases one should be careful with chdir's  * since the user might create files in a directory of his choice.  * Of course SECURE is meaningful only if HACKDIR is defined.  */
end_comment

begin_define
define|#
directive|define
name|SECURE
end_define

begin_comment
comment|/* do setuid(getuid()) after chdir() */
end_comment

begin_comment
comment|/*  * If it is desirable to limit the number of people that can play Hack  * simultaneously, define HACKDIR, SECURE and MAX_NR_OF_PLAYERS.  * #define MAX_NR_OF_PLAYERS	100  */
end_comment

begin_endif
endif|#
directive|endif
endif|CHDIR
end_endif

begin_comment
comment|/* size of terminal screen is (at least) (ROWNO+2) by COLNO */
end_comment

begin_define
define|#
directive|define
name|COLNO
value|80
end_define

begin_define
define|#
directive|define
name|ROWNO
value|22
end_define

begin_comment
comment|/*  * small signed integers (8 bits suffice)  *	typedef	char	schar;  * will do when you have signed characters; otherwise use  *	typedef	short int schar;  */
end_comment

begin_typedef
typedef|typedef
name|char
name|schar
typedef|;
end_typedef

begin_comment
comment|/*  * small unsigned integers (8 bits suffice - but 7 bits do not)  * - these are usually object types; be careful with inequalities! -  *	typedef	unsigned char	uchar;  * will be satisfactory if you have an "unsigned char" type; otherwise use  *	typedef unsigned short int uchar;  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_comment
comment|/*  * small integers in the range 0 - 127, usually coordinates  * although they are nonnegative they must not be declared unsigned  * since otherwise comparisons with signed quantities are done incorrectly  */
end_comment

begin_typedef
typedef|typedef
name|schar
name|xchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xchar
name|boolean
typedef|;
end_typedef

begin_comment
comment|/* 0 or 1 */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/*  * Declaration of bitfields in various structs; if your C compiler  * doesnt handle bitfields well, e.g., if it is unable to initialize  * structs containing bitfields, then you might use  *	#define Bitfield(x,n)	uchar x  * since the bitfields used never have more than 7 bits. (Most have 1 bit.)  */
end_comment

begin_define
define|#
directive|define
name|Bitfield
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|unsigned x:n
end_define

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|x
parameter_list|)
value|(int)(sizeof(x) / sizeof(x[0]))
end_define

begin_endif
endif|#
directive|endif
endif|CONFIG
end_endif

end_unit

