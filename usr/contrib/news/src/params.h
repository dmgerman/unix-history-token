begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * params.h - parameters for everyone.  */
end_comment

begin_comment
comment|/*	@(#)params.h	2.20	1/17/86	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_1C
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sane */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sane */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNAME
end_ifndef

begin_comment
comment|/*  * 9 bytes is for compatibility with USG, in case you forget to define UNAME.  * 33 bytes in nodename because many sites have names longer than 8 chars.  */
end_comment

begin_struct
struct|struct
name|utsname
block|{
name|char
name|sysname
index|[
literal|9
index|]
decl_stmt|;
name|char
name|nodename
index|[
literal|33
index|]
decl_stmt|;
name|char
name|release
index|[
literal|9
index|]
decl_stmt|;
name|char
name|version
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
name|unsigned
name|short
name|millitm
decl_stmt|;
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_comment
comment|/* line from SUBFILE */
end_comment

begin_struct
struct|struct
name|srec
block|{
name|char
name|s_name
index|[
literal|2
operator|*
name|BUFLEN
index|]
decl_stmt|;
comment|/* system name		*/
name|char
modifier|*
name|s_nosend
decl_stmt|;
comment|/* systems that inhibit sending */
name|char
name|s_nbuf
index|[
name|LBUFLEN
index|]
decl_stmt|;
comment|/* system subscriptions */
name|char
name|s_flags
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* system flags		*/
name|char
name|s_xmit
index|[
name|LBUFLEN
index|]
decl_stmt|;
comment|/* system xmit routine	*/
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|uid
decl_stmt|,
name|gid
decl_stmt|,
name|duid
decl_stmt|,
name|dgid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|savmask
decl_stmt|,
name|SigTrap
decl_stmt|,
name|mode
decl_stmt|,
name|lockcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hbuf
name|header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bfr
index|[
name|LBUFLEN
index|]
decl_stmt|,
modifier|*
name|username
decl_stmt|,
modifier|*
name|userhome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SPOOL
decl_stmt|,
modifier|*
name|LIB
decl_stmt|,
modifier|*
name|BIN
decl_stmt|,
modifier|*
name|SUBFILE
decl_stmt|,
modifier|*
name|ACTIVE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LOCKFILE
decl_stmt|,
modifier|*
name|SEQFILE
decl_stmt|,
modifier|*
name|ARTFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|news_version
decl_stmt|,
modifier|*
name|Progname
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NOTIFY
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TELLME
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTIFY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDENNET
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LOCALSYSNAME
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HIDDENNET */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FULLSYSNAME
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL */
end_comment

begin_comment
comment|/* external function declarations */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|xfopen
argument_list|()
decl_stmt|,
modifier|*
name|hread
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|mktemp
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|arpadate
argument_list|()
decl_stmt|,
modifier|*
name|dirname
argument_list|()
decl_stmt|,
modifier|*
name|AllocCpy
argument_list|()
decl_stmt|,
modifier|*
name|strpbrk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|errmsg
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|,
modifier|*
name|getpwent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|time_t
name|time
argument_list|()
decl_stmt|,
name|getdate
argument_list|()
decl_stmt|,
name|cgtdate
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|broadcast
argument_list|()
decl_stmt|,
name|save
argument_list|()
decl_stmt|,
name|newssave
argument_list|()
decl_stmt|,
name|ushell
argument_list|()
decl_stmt|,
name|onsig
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* This horrible gross kludge is the only way I know to  * convince lint that signal(SIGINT,SIG_IGN) is legal. It hates SIG_IGN.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_IGN
end_ifdef

begin_undef
undef|#
directive|undef
name|SIG_IGN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_IGN */
end_comment

begin_define
define|#
directive|define
name|SIG_IGN
value|main
end_define

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|LINK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|vmslink(a,b)
end_define

begin_define
define|#
directive|define
name|UNLINK
parameter_list|(
name|a
parameter_list|)
value|vmsunlink(a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|link(a,b)
end_define

begin_define
define|#
directive|define
name|UNLINK
parameter_list|(
name|a
parameter_list|)
value|unlink(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VMS */
end_comment

end_unit

