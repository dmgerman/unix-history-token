begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)hunt9.c	4.2 (Berkeley) 4/18/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_macro
name|remote
argument_list|(
argument|in
argument_list|,
argument|out
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|in
decl_stmt|,
modifier|*
name|out
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* "in" is a long distance file name: get it */
empty_stmt|;
block|}
end_block

end_unit

