begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|RCSIDENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|zzparms
index|[]
init|=
literal|"$Header: parms.h,v 1.7.0.8 85/09/20 12:56:25 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(RCSIDENT)&& defined(MAINLINE)
end_endif

begin_comment
comment|/*  *	This file contains the constants that must be reset on each system  *	when notefiles are first installed.  Other constants exist in  *	structs.h, but in general should not be modified unless needed.  */
end_comment

begin_define
define|#
directive|define
name|ARCHTIME
value|14
end_define

begin_comment
comment|/* expire threshold */
end_comment

begin_define
define|#
directive|define
name|WORKSETSIZE
value|0
end_define

begin_comment
comment|/* working set size */
end_comment

begin_define
define|#
directive|define
name|DFLTSH
value|"/bin/sh"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_define
define|#
directive|define
name|DFLTED
value|"/bin/ed"
end_define

begin_comment
comment|/* default editor */
end_comment

begin_define
define|#
directive|define
name|SEQFILE
value|"Dflt-Seq"
end_define

begin_comment
comment|/* file in MSTDIR */
end_comment

begin_define
define|#
directive|define
name|DFLTSEQ
value|"general,net.general"
end_define

begin_comment
comment|/* unspecified NFSEQ */
end_comment

begin_comment
comment|/*  *	These define defaults for various Unix functions that can  *	be overidden by environment variables   */
end_comment

begin_define
define|#
directive|define
name|MAILER
value|"/usr/ucb/mail"
end_define

begin_comment
comment|/* mailer to use */
end_comment

begin_define
define|#
directive|define
name|SUPERMAILER
end_define

begin_comment
comment|/* is a smart mailer */
end_comment

begin_define
define|#
directive|define
name|PAGER
value|"/usr/ucb/more"
end_define

begin_comment
comment|/* pg/more default */
end_comment

begin_define
define|#
directive|define
name|WRITE
value|"/bin/write"
end_define

begin_comment
comment|/* user-user communication */
end_comment

begin_comment
comment|/*  *	Definition of the domain this binary will run in. Examples  *	are "UUCP", "ARPA", or "Uiuc.ARPA". This string is appended  *	to the hostname and used to build addresses. Thus with a  *	hostname of "uiucdcsb" and a FULLDOMAIN of "Uiuc.ARPA",  *	my articles would show as being from "essick@uiucdcsb.Uiuc.ARPA".  *  *	Undefining this has some effects in the notes/news gateway  *	with stripping/adding domains. It isn't a good idea to have  *	this undefined.  */
end_comment

begin_define
define|#
directive|define
name|FULLDOMAIN
value|"CS.UIUC.EDU"
end_define

begin_comment
comment|/* local domain */
end_comment

begin_undef
undef|#
directive|undef
name|IDDOMAIN
end_undef

begin_comment
comment|/* not in unique id */
end_comment

begin_comment
comment|/*  *	define at most 1 of these (V7, UNIX4.0, etc.)   *	If none are defined, things probably won't go too well.  */
end_comment

begin_undef
undef|#
directive|undef
name|BSD41
end_undef

begin_comment
comment|/* Berkeley 4.1 bsd */
end_comment

begin_undef
undef|#
directive|undef
name|BSD41A
end_undef

begin_comment
comment|/* Berkeley 4.1a bsd */
end_comment

begin_define
define|#
directive|define
name|BSD42
end_define

begin_comment
comment|/* Berkeley 4.2 Bsd */
end_comment

begin_undef
undef|#
directive|undef
name|V7
end_undef

begin_comment
comment|/* version 7 kernel */
end_comment

begin_undef
undef|#
directive|undef
name|SYSIII
end_undef

begin_comment
comment|/* BTL System III kernel */
end_comment

begin_undef
undef|#
directive|undef
name|UNIX40
end_undef

begin_comment
comment|/* Unix 4.0 kernel */
end_comment

begin_undef
undef|#
directive|undef
name|SYSV
end_undef

begin_comment
comment|/* BTL System V kernel */
end_comment

begin_undef
undef|#
directive|undef
name|BSD28
end_undef

begin_comment
comment|/* Berkeley 2.8 */
end_comment

begin_undef
undef|#
directive|undef
name|BSD29
end_undef

begin_comment
comment|/* Berkeley 2.9 */
end_comment

begin_comment
comment|/*  *	Some configurable options.  These depend on how you like   *	to flavor your stew.   *		Define		What it gets you  *		--------	-------------------------------------  *		PROMPT		if you want a command prompt.  *		USERHOST	if you want addresses in the form   *				user@host instead of host!user  *		DYNADIR		enables code to determine Mstdir  *				(the /usr/spool/notes directory) from  *				the /etc/passwd.  When on, Mstdir is  *				set to the directory above notes' home.  *		K_KEY		Defined if you want k and K to be aliases  *				for q and Q.  It is handy and allows you  *				to read with one hand.  You can also  *				get very aggravated when you hit "k" instead  *				of "j".  *		BIGTEXT		change from a u_short to a long counter  *				to allow longer texts...  */
end_comment

begin_undef
undef|#
directive|undef
name|PROMPT
name|"
name|? "
end_undef

begin_comment
comment|/* command prompt */
end_comment

begin_undef
undef|#
directive|undef
name|PROMPTMSGX
name|(
name|17
name|)
end_undef

begin_comment
comment|/* stren(PROMPT) */
end_comment

begin_define
define|#
directive|define
name|USERHOST
end_define

begin_comment
comment|/* user@host */
end_comment

begin_undef
undef|#
directive|undef
name|DYNADIR
end_undef

begin_comment
comment|/* dynamic Mstdir */
end_comment

begin_define
define|#
directive|define
name|K_KEY
end_define

begin_comment
comment|/* k==q, K==Q */
end_comment

begin_define
define|#
directive|define
name|BIGTEXT
end_define

begin_comment
comment|/* 32 bit counters */
end_comment

begin_comment
comment|/*  *	The remaining options are pretty much stock.  You shouldn't  *	have to play with them unless you want to run a very non-standard  *	shop.  */
end_comment

begin_define
define|#
directive|define
name|NFMAINT
value|"nfmaint"
end_define

begin_comment
comment|/* internal logging */
end_comment

begin_define
define|#
directive|define
name|AUTOCREATE
end_define

begin_comment
comment|/* automatic mknf */
end_comment

begin_define
define|#
directive|define
name|STATS
end_define

begin_comment
comment|/* keep usage stats */
end_comment

begin_define
define|#
directive|define
name|FASTSEQ
end_define

begin_comment
comment|/* use stat to check */
end_comment

begin_define
define|#
directive|define
name|DUMPCORE
value|"coredump"
end_define

begin_comment
comment|/* subdir of UTILITY */
end_comment

begin_define
define|#
directive|define
name|FASTFORK
end_define

begin_comment
comment|/* faster forking */
end_comment

begin_comment
comment|/*  *	Thanks to Malcolm Slaney of Purdue EE for both BUFIO and FASTFORK  *	modifications. (BUFIO is now used exclusively and so isn't   *	surrounded by ifdefs any more.  */
end_comment

begin_comment
comment|/*  *	REMAINDER OF THIS FILE PROBABLY DOESN'T NEED TO BE CHANGED  *  *	Do some specific defines that go along with particluar OS's.  *	I may have missed some stuff and if you are running hybrid  *	versions of Unix, you might need to change things.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD41
argument_list|)
end_if

begin_comment
comment|/* UCB 4.1 BSD */
end_comment

begin_define
define|#
directive|define
name|VFORK
end_define

begin_define
define|#
directive|define
name|BSD4x
end_define

begin_endif
endif|#
directive|endif
endif|defined(BSD41)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD41A
argument_list|)
end_if

begin_comment
comment|/* UCB 4.1a BSD */
end_comment

begin_define
define|#
directive|define
name|PORTBINARY
end_define

begin_comment
comment|/* portable binaries */
end_comment

begin_define
define|#
directive|define
name|VFORK
end_define

begin_define
define|#
directive|define
name|BSD4x
end_define

begin_endif
endif|#
directive|endif
endif|defined(BSD41A)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD42
argument_list|)
end_if

begin_comment
comment|/* UCB 4.2 BSD */
end_comment

begin_define
define|#
directive|define
name|PORTBINARY
end_define

begin_define
define|#
directive|define
name|VFORK
end_define

begin_define
define|#
directive|define
name|BSD4x
end_define

begin_define
define|#
directive|define
name|FILENAMELEN
value|255
end_define

begin_endif
endif|#
directive|endif
endif|defined(BSD42)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
end_if

begin_comment
comment|/* Research V7 */
end_comment

begin_define
define|#
directive|define
name|WHOAMI
end_define

begin_define
define|#
directive|define
name|WHOAMIFILE
value|"/usr/include/whoami.h"
end_define

begin_comment
comment|/*  *	has a line in it of the form:  *	#define sysname "XXXX"  *	and maybe other lines too.  */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(V7)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSIII
argument_list|)
end_if

begin_comment
comment|/* BTL System III */
end_comment

begin_define
define|#
directive|define
name|UNAME
end_define

begin_comment
comment|/* more port-binary */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* BTL Unix */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(SYSIII)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNIX40
argument_list|)
end_if

begin_comment
comment|/* BTL (internal) */
end_comment

begin_define
define|#
directive|define
name|UNAME
end_define

begin_comment
comment|/* more port-binary */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* BTL Unix */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(UNIX40)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_comment
comment|/* BTL System V */
end_comment

begin_define
define|#
directive|define
name|UNAME
end_define

begin_comment
comment|/* more port-binary */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* BTL Unix */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(SYSV)
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_comment
comment|/* a BTL Unix */
end_comment

begin_comment
comment|/*  *	BTL Unix doesn't have index/rindex. Instead have strchr/strrchr.  *	define as macros here instead of plain substitution so won't  *	get tripped on a variable called "index" someday.  */
end_comment

begin_define
define|#
directive|define
name|index
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strchr(s,c)
end_define

begin_comment
comment|/* 1st char */
end_comment

begin_define
define|#
directive|define
name|rindex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strrchr(s,c)
end_define

begin_comment
comment|/* last char */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for lint */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for lint */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|USG
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD28
argument_list|)
end_if

begin_comment
comment|/* UCB 2.8 BSD */
end_comment

begin_define
define|#
directive|define
name|BSD2x
end_define

begin_endif
endif|#
directive|endif
endif|defined(BSD28)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD29
argument_list|)
end_if

begin_comment
comment|/* UCB 2.9 BSD */
end_comment

begin_define
define|#
directive|define
name|BSD2x
end_define

begin_endif
endif|#
directive|endif
endif|defined(BSD29)
end_endif

begin_comment
comment|/*  *	if the kernel hasn't already selected this...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILENAMELEN
end_ifndef

begin_define
define|#
directive|define
name|FILENAMELEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ROTATE
value|13
end_define

begin_comment
comment|/* rotation factor */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROMPTMSGX
end_ifndef

begin_define
define|#
directive|define
name|PROMPTMSGX
value|(15)
end_define

begin_comment
comment|/* make sure it's there */
end_comment

begin_endif
endif|#
directive|endif
endif|PROMPTMSGX
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VFORK
end_ifndef

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_comment
comment|/*  *	There are legit uses of both fork/vfork.  *	This lets us use vfork where we should and it defaults   *	to fork on systems that don't have it.  *  *	This may be a red herring for this implementation, but I   *	like the idea.  */
end_comment

begin_endif
endif|#
directive|endif
endif|VFORK
end_endif

begin_define
define|#
directive|define
name|SHAREDATA
end_define

begin_comment
comment|/* in note.c, resp.c */
end_comment

begin_undef
undef|#
directive|undef
name|RUNSUID
end_undef

begin_comment
comment|/* use set-gid */
end_comment

begin_comment
comment|/*  *	Version of the database in use. You don't want to change this.  *	This reflects the format of the notesfile database and when  *	the database format changes, this changes. It shouldn't  *	change unless the database format changes.  *	Format:		yyyymmdd  */
end_comment

begin_define
define|#
directive|define
name|DBVERSION
value|19850101
end_define

begin_comment
comment|/* current format */
end_comment

begin_comment
comment|/*  *	If worrying about mangled id's coming back from older  *	notesfile sites with shorter fields. This affects code  *	in "find.c"  */
end_comment

begin_define
define|#
directive|define
name|IDCOMPAT
end_define

begin_define
define|#
directive|define
name|OLDSYSSZ
value|10
end_define

begin_comment
comment|/* old SYSSZ */
end_comment

begin_undef
undef|#
directive|undef
name|FIXTIMES
end_undef

begin_comment
comment|/* fix gmttimes in future */
end_comment

end_unit

