begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cleara.c	4.1	83/03/09	*/
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|cleara
argument_list|()
end_macro

begin_block
block|{
name|sync
argument_list|()
expr_stmt|;
name|escseq
argument_list|(
name|NONE
argument_list|)
expr_stmt|;
name|outstr
argument_list|(
literal|"\33H\33J"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

