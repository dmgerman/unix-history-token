begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iparams - parameters for inews.  */
end_comment

begin_comment
comment|/*	@(#)iparams.h	2.12	4/16/85	*/
end_comment

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_comment
comment|/* external declarations specific to inews */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|nbuf
index|[]
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
index|[]
decl_stmt|,
modifier|*
name|DFLTNG
decl_stmt|;
end_decl_stmt

end_unit

