begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|clearerr
argument_list|(
name|iop
argument_list|)
specifier|register
expr|struct
name|_iobuf
operator|*
name|iop
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|iop
operator|->
name|_flag
operator|&=
operator|~
operator|(
name|_IOERR
operator||
name|_IOEOF
operator|)
expr_stmt|;
block|}
end_block

end_unit

