begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)error.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|_error
argument_list|(
name|s
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|static
name|reentered
expr_stmt|;
if|if
condition|(
name|reentered
operator|++
condition|)
name|_exit
argument_list|(
literal|0177
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|s
argument_list|,
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0176
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

