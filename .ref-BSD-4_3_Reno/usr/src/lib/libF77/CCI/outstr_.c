begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)outstr_.c	5.1 (Berkeley) 11/3/86  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* print a character string */
end_comment

begin_expr_stmt
name|outstr_
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|long
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
name|putchar
argument_list|(
operator|*
name|s
operator|++
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

