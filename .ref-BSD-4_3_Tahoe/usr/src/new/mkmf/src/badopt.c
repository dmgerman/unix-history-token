begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: badopt.c,v 1.2 85/04/02 07:45:43 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * badopt() places a "bad option" error message on the standard error  * output stream stderr.  */
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
name|badopt
argument_list|(
argument|sign
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offending option */
end_comment

begin_decl_stmt
name|char
name|sign
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* '+' or '-' sign preceding option */
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
literal|"bad option %c%c\n"
argument_list|,
name|sign
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

