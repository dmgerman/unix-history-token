begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Common declarations, includes, and other goodies.  *  * @(#)common.h	1.18	(Berkeley) 10/15/87  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
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
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|"../common/rfc977.h"
end_include

begin_include
include|#
directive|include
file|"../common/response_codes.h"
end_include

begin_include
include|#
directive|include
file|"../common/conf.h"
end_include

begin_comment
comment|/*  *<dbm.h> stupidly defines NULL, which is why the following  * brain death is necessary.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DBM
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_include
include|#
directive|include
file|<dbm.h>
end_include

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * For "spew()"  */
end_comment

begin_define
define|#
directive|define
name|ARTICLE
value|0
end_define

begin_define
define|#
directive|define
name|HEAD
value|1
end_define

begin_define
define|#
directive|define
name|BODY
value|2
end_define

begin_define
define|#
directive|define
name|STAT
value|3
end_define

begin_comment
comment|/*  * For "ngmatch()"  */
end_comment

begin_define
define|#
directive|define
name|ALLBUT
value|1
end_define

begin_define
define|#
directive|define
name|valid_art
parameter_list|(
name|s
parameter_list|)
value|(atoi(s) != 0)
end_define

begin_define
define|#
directive|define
name|putline
parameter_list|(
name|s
parameter_list|)
value|fputs((s), stdout); putchar('\r'); putchar('\n');
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gets
argument_list|()
decl_stmt|,
modifier|*
name|fgets
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|open_valid_art
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|openartbyid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gethistent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|restreql
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strneql
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|spooldir
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|activefile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|accessfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|historyfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ngdatefile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|inews
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|rnews
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|group_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_groups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|homedir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ingroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxgroups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|art_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|art_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|art_fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_arts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uid_poster
decl_stmt|,
name|gid_poster
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|canread
decl_stmt|,
name|canpost
decl_stmt|,
name|canxfer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|ngpermlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ngpermcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|nntp_version
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|grps_acsd
decl_stmt|,
name|arts_acsd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ih_accepted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ih_rejected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ih_failed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nn_told
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nn_took
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

