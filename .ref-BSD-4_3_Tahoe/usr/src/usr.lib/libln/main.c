begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)main.c	4.1	12/25/82	*/
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|yylex
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

