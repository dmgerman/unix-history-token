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
literal|"@(#)glue2.c	4.3 (Berkeley) 4/18/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_decl_stmt
name|char
name|refdir
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|savedir
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|refdir
index|[
literal|0
index|]
operator|==
literal|0
condition|)
name|corout
argument_list|(
literal|""
argument_list|,
name|refdir
argument_list|,
name|_PATH_PWD
argument_list|,
literal|""
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|trimnl
argument_list|(
name|refdir
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|restodir
argument_list|()
end_macro

begin_block
block|{
name|chdir
argument_list|(
name|refdir
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

