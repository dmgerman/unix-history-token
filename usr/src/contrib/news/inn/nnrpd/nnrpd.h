begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.15 $ ** **  Net News Reading Protocol server. */
end_comment

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAR_VARARGS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(VAR_VARARGS) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAR_STDARGS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(VAR_STDARGS) */
end_comment

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"paths.h"
end_include

begin_include
include|#
directive|include
file|"nntp.h"
end_include

begin_include
include|#
directive|include
file|"logging.h"
end_include

begin_include
include|#
directive|include
file|"libinn.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"qio.h"
end_include

begin_include
include|#
directive|include
file|"macros.h"
end_include

begin_comment
comment|/* **  Maximum input line length, sigh. */
end_comment

begin_define
define|#
directive|define
name|ART_LINE_LENGTH
value|1000
end_define

begin_define
define|#
directive|define
name|ART_LINE_MALLOC
value|1024
end_define

begin_comment
comment|/* **  Some convenient shorthands. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|in_addr
name|INADDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Printf
value|(void)printf
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAR_NONE
argument_list|)
end_if

begin_define
define|#
directive|define
name|Reply
value|(void)printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(VAR_NONE) */
end_comment

begin_comment
comment|/* **  The XTHREAD command is too ugly to talk about, but if you want it **  change DONT_DO_XTRHEAD to DO_DO_XTRHEAD, below. */
end_comment

begin_define
define|#
directive|define
name|DONT_DO_XTHREAD
end_define

begin_define
define|#
directive|define
name|THREAD_NAMES_FLAT
end_define

begin_define
define|#
directive|define
name|THREAD_SUFFIX
value|""
end_define

begin_define
define|#
directive|define
name|THREAD_DB
value|"/usr/spool/news/trn.threads/db.init"
end_define

begin_define
define|#
directive|define
name|THREAD_DIR
value|"/usr/spool/news/trn.threads"
end_define

begin_define
define|#
directive|define
name|THREAD_NNTP_CODE
value|288
end_define

begin_comment
comment|/* **  A group entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GROUPENTRY
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|ARTNUM
name|High
decl_stmt|;
name|ARTNUM
name|Low
decl_stmt|;
name|char
name|Flag
decl_stmt|;
name|char
modifier|*
name|Alias
decl_stmt|;
block|}
name|GROUPENTRY
typedef|;
end_typedef

begin_comment
comment|/* **  A range of article numbers. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ARTRANGE
block|{
name|int
name|Low
decl_stmt|;
name|int
name|High
decl_stmt|;
block|}
name|ARTRANGE
typedef|;
end_typedef

begin_comment
comment|/* **  What READline returns. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_READTYPE
block|{
name|RTeof
block|,
name|RTok
block|,
name|RTlong
block|,
name|RTtimeout
block|}
name|READTYPE
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_comment
comment|/* NULL */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MAINLINE) */
end_comment

begin_decl_stmt
name|EXTERN
name|BOOL
name|PERMauthorized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|PERMcanpost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|PERMcanread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|PERMneedauth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|PERMspecified
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|Tracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|PERMlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|STRING
name|MyHostName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ACTIVE
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|ClientHost
index|[
name|SMBUF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ACTIVETIMES
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|HISTORY
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|NEWSGROUPS
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|NOACCESS
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|PERMpass
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|PERMuser
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|RemoteMaster
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|ARTNUM
modifier|*
name|ARTcache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|ARTNUM
modifier|*
name|ARTnumbers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|ARTindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|ARTsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PERMdefault
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|ARTcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|GRParticles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|GRPcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|GRPlast
index|[
name|SPOOLNAMEBUFF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|POSTreceived
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|long
name|POSTrejected
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NNRP_LOADLIMIT
operator|>
literal|0
end_if

begin_function_decl
specifier|extern
name|int
name|GetLoadAverage
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NNRP_LOADLIMIT> 0 */
end_comment

begin_function_decl
specifier|extern
name|STRING
name|ARTpost
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ARTclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ARTreadschema
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|Glom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Argify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NORETURN
name|ExitWithStats
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|GetGroupList
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|GRPreport
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GROUPENTRY
modifier|*
name|GRPfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|HISgetent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|LOCALtoGMT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|NGgetlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|NNTPtoGMT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|PERMartok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|PERMinfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|PERMmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ParseDistlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|READTYPE
name|READline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|OVERclose
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAR_STDARGS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|Reply
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(VAR_STDARGS) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAR_VARARGS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|Reply
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(VAR_VARARGS) */
end_comment

end_unit

