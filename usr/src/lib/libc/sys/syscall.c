begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* syscall.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|syscall
argument_list|)
end_macro

begin_expr_stmt
name|movl
literal|4
operator|(
name|ap
operator|)
operator|,
name|r0
operator|#
name|syscall
name|number
name|subl3
name|$1
operator|,
operator|(
name|ap
operator|)
operator|+
operator|,
operator|(
name|ap
operator|)
operator|#
name|one
name|fewer
name|arguments
name|chmk
name|r0
name|ret
end_expr_stmt

end_unit

