begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	zoomn.c	4.1	83/03/09	*/
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|zoomn
argument_list|(
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
name|size
decl_stmt|;
end_decl_stmt

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
name|size
operator|+
literal|'0'
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
literal|'i'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

