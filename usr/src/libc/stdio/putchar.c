begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)putchar.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_comment
comment|/*  * A subroutine version of the macro putchar  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_expr_stmt
name|putchar
argument_list|(
name|c
argument_list|)
specifier|register
name|c
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

