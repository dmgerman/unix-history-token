begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pperror() writes a system error message to standard error output,  * preceded by the name of the program and message.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|pperror
argument_list|(
argument|message
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|message
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error message */
end_comment

begin_block
block|{
specifier|extern
name|char
modifier|*
name|PGN
decl_stmt|;
comment|/* program name */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|PGN
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

