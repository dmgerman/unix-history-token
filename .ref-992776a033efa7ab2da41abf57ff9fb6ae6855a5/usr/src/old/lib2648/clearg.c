begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	clearg.c	4.1	83/03/09	*/
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|clearg
argument_list|()
end_macro

begin_block
block|{
name|sync
argument_list|()
expr_stmt|;
name|escseq
argument_list|(
name|ESCD
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
operator|(
name|_video
operator|==
name|INVERSE
operator|)
condition|?
literal|'b'
else|:
literal|'a'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

