begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|putw
argument_list|(
name|i
argument_list|,
name|iop
argument_list|)
specifier|register
name|i
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|_iobuf
modifier|*
name|iop
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putc
argument_list|(
name|i
argument_list|,
name|iop
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|i
operator|>>
literal|8
argument_list|,
name|iop
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

