begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)fputc.c	4.2 (Berkeley) %G% */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|fputc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
specifier|register
name|FILE
operator|*
name|fp
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|putc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

