begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)unlink.c	4.1 (Berkeley) 1/1/83 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|unlink
argument_list|)
end_macro

begin_expr_stmt
name|pushl
literal|4
operator|(
name|ap
operator|)
name|CALL
argument_list|(
literal|1
argument_list|,
argument|_fixf
argument_list|)
name|movl
name|r0
operator|,
literal|4
operator|(
name|ap
operator|)
name|chmk
name|$SYS_unlink
name|jcs
name|err
name|ret
name|err
operator|:
name|jmp
name|cerror
end_expr_stmt

end_unit

