begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iparams - parameters for inews.  */
end_comment

begin_comment
comment|/*	@(#)iparams.h	2.17	11/21/86	*/
end_comment

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external declarations specific to inews */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|nbuf
index|[
name|LBUFLEN
index|]
decl_stmt|,
modifier|*
name|ARTICLE
decl_stmt|,
modifier|*
name|INFILE
decl_stmt|,
modifier|*
name|ALIASES
decl_stmt|,
modifier|*
name|PARTIAL
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ROOTID
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|ROOTID
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct
struct|struct
name|msgtype
block|{
name|char
modifier|*
name|m_name
decl_stmt|;
name|char
modifier|*
name|m_who_to
decl_stmt|;
name|int
function_decl|(
modifier|*
name|m_func
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|msgtype
name|msgtype
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infp
decl_stmt|,
modifier|*
name|actfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tty
decl_stmt|,
name|is_ctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|filename
index|[
name|BUFLEN
index|]
decl_stmt|,
name|is_mod
index|[
name|NAMELEN
index|]
decl_stmt|,
name|not_here
index|[
name|SBUFLEN
index|]
decl_stmt|,
modifier|*
name|DFLTNG
decl_stmt|;
end_decl_stmt

end_unit

