begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: only.h,v 4.3 85/05/01 11:45:27 lwall Exp $  *  * $Log:	only.h,v $  * Revision 4.3  85/05/01  11:45:27  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NBRA
end_ifndef

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONLY
end_ifdef

begin_decl_stmt
name|EXT
name|char
modifier|*
name|ngtodo
index|[
name|NGMAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restrictions in effect */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPEEDOVERMEM
end_ifdef

begin_decl_stmt
name|EXT
name|COMPEX
modifier|*
name|compextodo
index|[
name|NGMAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restrictions in compiled form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|maxngtodo
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0 => no restrictions */
end_comment

begin_comment
comment|/*>0 => # of entries in ngtodo */
end_comment

begin_function_decl
name|void
name|only_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|inlist
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return TRUE if ngname is in command line list */
end_comment

begin_comment
comment|/* or if there was no list */
end_comment

begin_function_decl
name|void
name|setngtodo
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ONLY
end_ifdef

begin_function_decl
name|void
name|end_only
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

