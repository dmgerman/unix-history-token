begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)globals.c	1.4	(Berkeley) 7/17/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Common variables.  */
end_comment

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/*  * Variables initialized from ../common/conf.h  */
end_comment

begin_decl_stmt
name|char
name|spooldir
index|[]
init|=
name|SPOOLDIR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|activefile
index|[]
init|=
name|ACTIVE_FILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|accessfile
index|[]
init|=
name|ACCESS_FILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|historyfile
index|[]
init|=
name|HISTORY_FILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ngdatefile
index|[]
init|=
name|NGDATE_FILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|inews
index|[]
init|=
name|INEWS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|rnews
index|[]
init|=
name|RNEWS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Other random externals.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|group_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num_groups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ingroup
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|art_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num_arts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|art_array
index|[
name|MAX_ARTICLES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|art_fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uid_poster
decl_stmt|,
name|gid_poster
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|canpost
decl_stmt|,
name|canread
decl_stmt|,
name|canxfer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|ngpermlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ngpermcount
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_decl_stmt
name|int
name|arts_acsd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|grps_acsd
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

