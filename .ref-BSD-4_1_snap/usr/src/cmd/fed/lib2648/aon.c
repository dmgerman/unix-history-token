begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|aon
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
literal|'e'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|aoff
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
literal|'f'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

