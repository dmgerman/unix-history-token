begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id variable */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mach_h_sid
init|=
literal|"@(#)mach.h	1.11"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  	mach.h	-- define machine-dependent things  *** Pre-processor Flags ***  This set of code is controlled by this set of conditional compilation flags:  TESTING		if defined, do not generate tests, etc. which require 		super-user status.  OLDTTY		if defined, compile for old 1 character TTY names CCTTY		if defined, compile for CC tty name format 		if neither is defined, use v7 ttyname format  PASSWDF		compile in code to handle /etc/passwdf - split passwd files  V6		Assume the v6 features instead of the v7 ones.  FUID		use the funny uid's present on CC V6  DELIVERM	Uses the delivermail program  HPASSWD		The local machine has the hashed password stuff  OLDMAIL		mail is in home-directory/.mail USRMAIL		mail is in /usr/mail/name 		(mail is in /usr/spool/mail/name)  CC		Machine is a Computer Center machine NUID		userid (as returned by getuid()) on this machine UID1CHAR	Uses vanila Version6 userid's (only 1 byte for uid) NOEUID		Does not have the geteuid() system call NFREECMD	doesn't allow any "network" free commands NOFP		floating point just doesn't work on this machine NOREMACCT	allows netlpr's on remote machines without an account CSH		use the /bin/csh shell (Paths.h sets BINSH to this path ). CRN		CC crn's are passed DONTHOLDBIG	large (size> MAXDAYFILE ) jobs wont be held until night for 		transmission  SWAB		this machine has byte-ordering reversed from the DEC VAX  		and PDP-11 standard (the only current example is Onyx) The conditonal flags are first defined in "/usr/include/whoami.h" on the local machine.  For "normal" version 6 machines, there is a dummy machine definition for "VANILLA6" which indicates the v6 UNIX options.  For "normal" version 7 machines, there is a dummy machine definition for "VANILLA7" which indicates the v7 UNIX options. (VM/UNIX and Berkeley VM/VAX/UNIX can use this) */
end_comment

begin_comment
comment|/* be sure to include<stdio.h> before these defns */
end_comment

begin_include
include|#
directive|include
file|<whoami.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/* note NUID is only used in mmail.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RAND
end_ifdef

begin_comment
comment|/* definitions for Rand-Unix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'v'
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GRAPHICS
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'g'
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|GRAPHICS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TP
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'t'
end_define

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|TP
end_endif

begin_comment
comment|/* end of definitions for Rand */
end_comment

begin_endif
endif|#
directive|endif
endif|RAND
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOSC
end_ifdef

begin_comment
comment|/* definitions for Naval Ocean Systems Center NOSC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTS
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'a'
end_define

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|ATTS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CCMM
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'c'
end_define

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|CCMM
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSSF
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'m'
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|MSSF
end_endif

begin_comment
comment|/* end of definitions for NOSC */
end_comment

begin_endif
endif|#
directive|endif
endif|NOSC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BERKELEY
end_ifdef

begin_comment
comment|/* definitions for Berkeley */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|A
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'a'
end_define

begin_endif
endif|#
directive|endif
endif|A
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|B
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'b'
end_define

begin_endif
endif|#
directive|endif
endif|B
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|C
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'c'
end_define

begin_endif
endif|#
directive|endif
endif|C
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|D
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'d'
end_define

begin_endif
endif|#
directive|endif
endif|D
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|E
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'e'
end_define

begin_endif
endif|#
directive|endif
endif|E
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|F
end_ifdef

begin_define
define|#
directive|define
name|CCV7
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'f'
end_define

begin_endif
endif|#
directive|endif
endif|F
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|G
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'g'
end_define

begin_define
define|#
directive|define
name|NUID
value|(501)
end_define

begin_endif
endif|#
directive|endif
endif|G
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ING70
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|PASSWDF
end_define

begin_define
define|#
directive|define
name|DELIVERM
end_define

begin_define
define|#
directive|define
name|MULTNAMS
end_define

begin_define
define|#
directive|define
name|FREELPR
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'i'
end_define

begin_define
define|#
directive|define
name|NUID
value|(174)
end_define

begin_comment
comment|/* correct vers. 7 = LOCAL, NUID */
end_comment

begin_endif
endif|#
directive|endif
endif|ING70
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INGVAX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'j'
end_define

begin_define
define|#
directive|define
name|NUID
value|(37)
end_define

begin_define
define|#
directive|define
name|FREELPR
end_define

begin_define
define|#
directive|define
name|DELIVERM
end_define

begin_endif
endif|#
directive|endif
endif|INGVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VIRUS
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'k'
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|VIRUS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IMAGE
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|PASSWDF
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'m'
end_define

begin_define
define|#
directive|define
name|NUID
value|((84<< 8) | 84)
end_define

begin_comment
comment|/* correct vers. 7 = LOCAL, NUID */
end_comment

begin_endif
endif|#
directive|endif
endif|IMAGE
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KIM
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'n'
end_define

begin_define
define|#
directive|define
name|NUID
value|(XXX)
end_define

begin_endif
endif|#
directive|endif
endif|KIM
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ESVAX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'o'
end_define

begin_define
define|#
directive|define
name|NUID
value|(67)
end_define

begin_endif
endif|#
directive|endif
endif|ESVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CAD
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'p'
end_define

begin_define
define|#
directive|define
name|NUID
value|(67)
end_define

begin_endif
endif|#
directive|endif
endif|CAD
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|Q
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|CCV6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|FUID
end_define

begin_define
define|#
directive|define
name|PASSWDF
end_define

begin_define
define|#
directive|define
name|USRMAIL
end_define

begin_define
define|#
directive|define
name|NOEUID
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'q'
end_define

begin_define
define|#
directive|define
name|NOREMACCT
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
end_define

begin_define
define|#
directive|define
name|NUID
value|((11<< 8) | 38)
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_define
define|#
directive|define
name|CRN
end_define

begin_define
define|#
directive|define
name|MAGICCRN
value|"3700"
end_define

begin_comment
comment|/* default CC crn */
end_comment

begin_comment
comment|/* correct vers. 7 = LOCAL, NUID */
end_comment

begin_endif
endif|#
directive|endif
endif|Q
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARPAVAX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'r'
end_define

begin_define
define|#
directive|define
name|NUID
value|(501)
end_define

begin_define
define|#
directive|define
name|DELIVERM
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_endif
endif|#
directive|endif
endif|ARPAVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SRC
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|FUID
end_define

begin_define
define|#
directive|define
name|NOEUID
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'s'
end_define

begin_define
define|#
directive|define
name|NUID
value|38
end_define

begin_define
define|#
directive|define
name|USRMAIL
end_define

begin_comment
comment|/* correct vers. 7 = LOCAL, NUID */
end_comment

begin_endif
endif|#
directive|endif
endif|SRC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MATHSTAT
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'t'
end_define

begin_define
define|#
directive|define
name|NUID
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|MATHSTAT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CSVAX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'v'
end_define

begin_define
define|#
directive|define
name|NUID
value|(501)
end_define

begin_define
define|#
directive|define
name|DELIVERM
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_endif
endif|#
directive|endif
endif|CSVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONYX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'x'
end_define

begin_define
define|#
directive|define
name|NUID
value|(10)
end_define

begin_define
define|#
directive|define
name|NOFP
end_define

begin_define
define|#
directive|define
name|SWAB
end_define

begin_comment
comment|/* on the Ing70 their ncc can't take this undef, so you'll    have to delete it when compiling on the Ing70 */
end_comment

begin_undef
undef|#
directive|undef
name|PARMLIST
end_undef

begin_define
define|#
directive|define
name|PARMLIST
value|20
end_define

begin_endif
endif|#
directive|endif
endif|ONYX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CORY
end_ifdef

begin_define
define|#
directive|define
name|LOCAL
value|'y'
end_define

begin_define
define|#
directive|define
name|NUID
value|(10)
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_undef
undef|#
directive|undef
name|NETLDISC
end_undef

begin_define
define|#
directive|define
name|DELIVERM
end_define

begin_endif
endif|#
directive|endif
endif|CORY
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EECS40
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|USRMAIL
end_define

begin_define
define|#
directive|define
name|PASSWDF
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|LOCAL
value|'z'
end_define

begin_define
define|#
directive|define
name|NUID
value|((1<< 8) | 104)
end_define

begin_define
define|#
directive|define
name|NFREECMD
end_define

begin_define
define|#
directive|define
name|NOFP
end_define

begin_comment
comment|/* correct vers. 7 = LOCAL, NUID */
end_comment

begin_endif
endif|#
directive|endif
endif|EECS40
end_endif

begin_comment
comment|/* end of Berkeley definitions */
end_comment

begin_endif
endif|#
directive|endif
endif|BERKELEY
end_endif

begin_comment
comment|/* 	the CC V6 machines are all the same. 	splitting their type into a separate group will 	allow the binary patching program "patchd" to be 	used to patch the binaries so the sources can be compiled 	on one CC machine and the binaries shipped around 	to the other CC machines. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCV7
end_ifdef

begin_undef
undef|#
directive|undef
name|CC
end_undef

begin_define
define|#
directive|define
name|NOREMACCT
end_define

begin_define
define|#
directive|define
name|NUID
value|(10)
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_define
define|#
directive|define
name|CSH
end_define

begin_define
define|#
directive|define
name|CRN
end_define

begin_define
define|#
directive|define
name|MAGICCRN
value|"3700"
end_define

begin_comment
comment|/* default CC crn */
end_comment

begin_endif
endif|#
directive|endif
endif|CCV7
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CC
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|CCV6
end_define

begin_define
define|#
directive|define
name|CCTTY
end_define

begin_define
define|#
directive|define
name|PASSWDF
end_define

begin_define
define|#
directive|define
name|FUID
end_define

begin_define
define|#
directive|define
name|USRMAIL
end_define

begin_define
define|#
directive|define
name|NUID
value|(115)
end_define

begin_define
define|#
directive|define
name|MAXSENDQ
value|35
end_define

begin_define
define|#
directive|define
name|NOREMACCT
end_define

begin_define
define|#
directive|define
name|CSH
end_define

begin_define
define|#
directive|define
name|CRN
end_define

begin_define
define|#
directive|define
name|MAGICCRN
value|"3700"
end_define

begin_comment
comment|/* default CC crn */
end_comment

begin_endif
endif|#
directive|endif
endif|CC
end_endif

begin_comment
comment|/* default version 6 options */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VANILLA6
end_ifdef

begin_define
define|#
directive|define
name|V6
end_define

begin_define
define|#
directive|define
name|UID1CHAR
end_define

begin_define
define|#
directive|define
name|OLDTTY
end_define

begin_define
define|#
directive|define
name|OLDMAIL
end_define

begin_endif
endif|#
directive|endif
endif|VANILLA6
end_endif

begin_comment
comment|/* default version 7 options */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VANILLA7
end_ifdef

begin_endif
endif|#
directive|endif
endif|VANILLA7
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|V6
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_define
define|#
directive|define
name|getsize
parameter_list|(
name|S
parameter_list|)
value|((S)->st_size)
end_define

begin_define
define|#
directive|define
name|gettime
parameter_list|()
value|(time(0))
end_define

begin_expr_stmt
name|int
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* #define	SIG_DFL	(int (*)())0 #define	SIG_IGN	(int (*)())1 */
end_comment

begin_else
else|#
directive|else
else|V6
end_else

begin_define
define|#
directive|define
name|ETXTBSY
value|26
end_define

begin_define
define|#
directive|define
name|S_IREAD
value|0400
end_define

begin_define
define|#
directive|define
name|S_IFMT
value|060000
end_define

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_define
define|#
directive|define
name|ANYP
value|0300
end_define

begin_define
define|#
directive|define
name|ECHO
value|010
end_define

begin_define
define|#
directive|define
name|ROOTINO
value|1
end_define

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_define
define|#
directive|define
name|TIOCEXCL
value|0
end_define

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|1
end_define

begin_define
define|#
directive|define
name|ASSERT
value|"Assertion failed: file %s, line %d\n", __FILE__, __LINE__);exit(1);}}
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ex
parameter_list|)
value|{if (!(ex)){fprintf(stderr,ASSERT
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|(040<= c&& c<= 0176)
end_define

begin_define
define|#
directive|define
name|longjmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|reset()
end_define

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|a
parameter_list|)
value|setexit()
end_define

begin_struct
struct|struct
name|stat
block|{
name|int
name|st_dev
decl_stmt|;
name|int
name|st_ino
decl_stmt|;
name|int
name|st_mode
decl_stmt|;
name|char
name|st_nlink
range|:
literal|8
decl_stmt|;
name|char
name|st_uid
range|:
literal|8
decl_stmt|;
name|char
name|st_gid
range|:
literal|8
decl_stmt|;
name|char
name|st_size0
decl_stmt|;
name|int
name|st_size1
decl_stmt|;
name|int
name|st_addr
index|[
literal|8
index|]
decl_stmt|;
name|long
name|st_atime
decl_stmt|;
name|long
name|st_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|direct
block|{
name|int
name|d_ino
decl_stmt|;
name|char
name|d_name
index|[
name|DIRSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tms
block|{
comment|/* see times - sect 2 */
name|int
name|tms_utime
decl_stmt|;
comment|/* user time */
name|int
name|tms_stime
decl_stmt|;
comment|/* system time */
name|long
name|tms_cutime
decl_stmt|;
comment|/* user time, children */
name|long
name|tms_cstime
decl_stmt|;
comment|/* system time, children */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
name|char
name|sg_ospeed
decl_stmt|;
name|char
name|sg_erase
decl_stmt|;
name|char
name|sg_kill
decl_stmt|;
name|int
name|sg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|passwd
block|{
comment|/* see getpwent(3) */
name|char
modifier|*
name|pw_name
decl_stmt|;
name|char
modifier|*
name|pw_passwd
decl_stmt|;
name|int
name|pw_uid
decl_stmt|;
name|int
name|pw_gid
decl_stmt|;
name|int
name|pw_quota
decl_stmt|;
name|char
modifier|*
name|pw_comment
decl_stmt|;
name|char
modifier|*
name|pw_gecos
decl_stmt|;
name|char
modifier|*
name|pw_dir
decl_stmt|;
name|char
modifier|*
name|pw_shell
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* /usr/include/varargs.h */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|list
parameter_list|)
value|list = (char *)&va_alist
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|list
parameter_list|)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|list
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(list += sizeof(mode)))[-1]
end_define

begin_typedef
typedef|typedef
name|int
name|jmp_buf
index|[
literal|10
index|]
typedef|;
end_typedef

begin_decl_stmt
name|long
name|gettime
argument_list|()
decl_stmt|,
name|getsize
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_comment
comment|/* end of non-v7 defns */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FUID
end_ifdef

begin_define
define|#
directive|define
name|getgid
parameter_list|(
name|s
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
endif|FUID
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UID1CHAR
end_ifdef

begin_define
define|#
directive|define
name|uidmask
parameter_list|(
name|S
parameter_list|)
value|(S& 0377)
end_define

begin_define
define|#
directive|define
name|geteuid
parameter_list|()
value|((getuid()>>8)&0377)
end_define

begin_else
else|#
directive|else
else|UID1CHAR
end_else

begin_define
define|#
directive|define
name|uidmask
parameter_list|(
name|S
parameter_list|)
value|(S)
end_define

begin_endif
endif|#
directive|endif
endif|UID1CHAR
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOEUID
end_ifdef

begin_define
define|#
directive|define
name|geteuid
parameter_list|(
name|S
parameter_list|)
value|(-1)
end_define

begin_endif
endif|#
directive|endif
endif|NOEUID
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CCTTY
end_ifdef

begin_define
define|#
directive|define
name|ttyname
parameter_list|(
name|S
parameter_list|)
value|myttyname(S)
end_define

begin_endif
endif|#
directive|endif
endif|CCTTY
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRN
end_ifdef

begin_include
include|#
directive|include
file|<gecos.h>
end_include

begin_endif
endif|#
directive|endif
endif|CRN
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OLDTTY
end_ifdef

begin_comment
comment|/* this is the version 7 utmp structure. the getutmp() procedure    converts the v6 structure into this format */
end_comment

begin_struct
struct|struct
name|utmp
block|{
name|char
name|ut_line
index|[
literal|8
index|]
decl_stmt|;
comment|/* tty name */
name|char
name|ut_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* user id */
name|long
name|ut_time
decl_stmt|;
comment|/* time on */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
else|OLDTTY
end_else

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_endif
endif|#
directive|endif
endif|OLDTTY
end_endif

begin_define
define|#
directive|define
name|chfromf
parameter_list|(
name|S
parameter_list|)
value|(S ? 'T' : 'F')
end_define

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hgethome
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getname
argument_list|()
decl_stmt|,
modifier|*
name|getun
argument_list|()
decl_stmt|,
modifier|*
name|getlogin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|SnFromUid
argument_list|()
decl_stmt|,
modifier|*
name|ttyname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwnam
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|atol
argument_list|()
decl_stmt|,
name|time
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|utmp
modifier|*
name|getutmp
parameter_list|()
function_decl|;
end_function_decl

end_unit

