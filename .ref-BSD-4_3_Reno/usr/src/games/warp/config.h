begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RDCHK:  *	This symbol, if defined, indicates that the rdchk routine is available  *	to find out if there is input pending on an IO channel.  Generally  *	the routine is used only if FIONREAD and O_NDELAY aren't available.  */
end_comment

begin_empty
empty|#
comment|/*undef	RDCHK		/**/
end_empty

begin_comment
comment|/* SCOREFULL:  *	This symbol, if defined, indicates that any scoreboard kept by the  *	program should be kept on the basis of the user's full name as opposed  *	to the user's login name.  If the user can change his full name he  *	can enter multiple scores if this is defined.  */
end_comment

begin_empty
empty|#
comment|/*undef	SCOREFULL	/**/
end_empty

begin_comment
comment|/* SIGNEDCHAR:  *	This symbol, if defined, indicates that characters are a signed type.  *	If not defined, things declared as signed characters (and that make  *	use of negative values) should probably be declared as shorts instead.  */
end_comment

begin_define
define|#
directive|define
name|SIGNEDCHAR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* TERMIO:  *	This symbol, if defined, indicates that the program should include  *	termio.h rather than sgtty.h.  There are also differences in the  *	ioctl() calls that depend on the value of this symbol.  */
end_comment

begin_empty
empty|#
comment|/*undef	TERMIO		/**/
end_empty

begin_comment
comment|/* USENDIR:  *	This symbol, if defined, indicates that the program should compile  *	the ndir.c code provided with the package.  */
end_comment

begin_comment
comment|/* LIBNDIR:  *	This symbol, if defined, indicates that the program should include the  *	system's version of ndir.h, rather than the one with this package.  */
end_comment

begin_empty
empty|#
comment|/*undef	USENDIR		/**/
end_empty

begin_empty
empty|#
comment|/*undef	LIBNDIR		/**/
end_empty

begin_define
define|#
directive|define
name|LIBNDIR
end_define

begin_comment
comment|/* WHOAMI:  *	This symbol, if defined, indicates that the program may include  *	whoami.h.  */
end_comment

begin_empty
empty|#
comment|/*undef	WHOAMI		/**/
end_empty

begin_comment
comment|/* HOSTNAME:  *	This symbol contains name of the host the program is going to run on.  *	The domain is not kept with hostname, but must be gotten from MYDOMAIN.  *	The dot comes with MYDOMAIN, and need not be supplied by the program.  *	If gethostname() or uname() exist, HOSTNAME may be ignored.  */
end_comment

begin_comment
comment|/* MYDOMAIN:  *	This symbol contains the domain of the host the program is going to  *	run on.  The domain must be appended to HOSTNAME to form a complete  *	host name.  The dot comes with MYDOMAIN, and need not be supplied by  *	the program.  If the host name is derived from PHOSTNAME, the domain  *	may or may not already be there, and the program should check.  */
end_comment

begin_define
define|#
directive|define
name|HOSTNAME
value|"kazoo"
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|MYDOMAIN
value|".uucp"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* PASSNAMES:  *	This symbol, if defined, indicates that full names are stored in  *	the /etc/passwd file.  */
end_comment

begin_comment
comment|/* BERKNAMES:  *	This symbol, if defined, indicates that full names are stored in  *	the /etc/passwd file in Berkeley format (name first thing, everything  *	up to first comma, with& replaced by capitalized login id, yuck).  */
end_comment

begin_comment
comment|/* USGNAMES:  *	This symbol, if defined, indicates that full names are stored in  *	the /etc/passwd file in USG format (everything after - and before ( is  *	the name).  */
end_comment

begin_define
define|#
directive|define
name|PASSNAMES
end_define

begin_comment
comment|/*  (undef to take name from ~/.fullname) */
end_comment

begin_define
define|#
directive|define
name|BERKNAMES
end_define

begin_comment
comment|/* (that is, ":name,stuff:") */
end_comment

begin_empty
empty|#
comment|/*undef	USGNAMES  /* (that is, ":stuff-name(stuff):") */
end_empty

begin_comment
comment|/* PREFSHELL:  *	This symbol contains the full name of the preferred user shell on this  *	system.  Usual values are /bin/csh, /bin/ksh, /bin/sh.  */
end_comment

begin_define
define|#
directive|define
name|PREFSHELL
value|"/bin/csh"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* RANDBITS:  *	This symbol contains the number of bits of random number the rand()  *	function produces.  Usual values are 15, 16, and 31.  */
end_comment

begin_define
define|#
directive|define
name|RANDBITS
value|15
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Reg1:  *	This symbol, along with Reg2, Reg3, etc. is either the word "register"  *	or null, depending on whether the C compiler pays attention to this  *	many register declarations.  The intent is that you don't have to  *	order your register declarations in the order of importance, so you  *	can freely declare register variables in sub-blocks of code and as  *	function parameters.  Do not use Reg<n> more than once per routine.  */
end_comment

begin_define
define|#
directive|define
name|Reg1
value|register
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg2
value|register
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg3
value|register
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg4
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg5
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg6
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg7
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg8
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg9
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg10
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg11
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg12
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg13
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg14
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg15
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Reg16
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* ROOTID:  *	This symbol contains the uid of root, normally 0.  */
end_comment

begin_define
define|#
directive|define
name|ROOTID
value|0
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* VOIDFLAGS:  *	This symbol indicates how much support of the void type is given by this  *	compiler.  What various bits mean:  *  *	    1 = supports declaration of void  *	    2 = supports arrays of pointers to functions returning void  *	    4 = supports comparisons between pointers to void functions and  *		    addresses of void functions  *  *	The package designer should define VOIDUSED to indicate the requirements  *	of the package.  This can be done either by #defining VOIDUSED before  *	including config.h, or by defining defvoidused in Myinit.U.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VOIDUSED
end_ifndef

begin_define
define|#
directive|define
name|VOIDUSED
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VOIDFLAGS
value|7
end_define

begin_if
if|#
directive|if
operator|(
name|VOIDFLAGS
operator|&
name|VOIDUSED
operator|)
operator|!=
name|VOIDUSED
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_comment
comment|/* is void to be avoided? */
end_comment

begin_define
define|#
directive|define
name|M_VOID
end_define

begin_comment
comment|/* Xenix strikes again */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* warp private library, may use ~ expansion, %x and %l */
end_comment

begin_define
define|#
directive|define
name|PRIVLIB
value|"/usr/games/lib/warp"
end_define

begin_comment
comment|/**/
end_comment

end_unit

