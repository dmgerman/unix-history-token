begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	gdefault.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * reset terminal to default graphics state  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|gdefault
argument_list|()
end_macro

begin_block
block|{
name|escseq
argument_list|(
name|ESCM
argument_list|)
expr_stmt|;
name|outstr
argument_list|(
literal|"r"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

