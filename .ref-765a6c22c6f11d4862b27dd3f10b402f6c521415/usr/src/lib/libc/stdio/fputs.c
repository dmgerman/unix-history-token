begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)fputs.c	4.1 (Berkeley) %G% */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|fputs
argument_list|(
name|s
argument_list|,
name|iop
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|FILE
modifier|*
name|iop
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|r
expr_stmt|;
specifier|register
name|c
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
operator|++
condition|)
name|r
operator|=
name|putc
argument_list|(
name|c
argument_list|,
name|iop
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_block

end_unit

