begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: warn.c,v 1.2 85/03/25 12:36:56 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * warn() places an error message on the standard error output stream  * stderr.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PGN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_macro
name|warn
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* warning message */
end_comment

begin_block
block|{
if|if
condition|(
name|PGN
operator|!=
name|NULL
operator|&&
operator|*
name|PGN
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|PGN
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

