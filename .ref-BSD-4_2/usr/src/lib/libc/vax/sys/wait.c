begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* wait.c 4.1 82/12/28 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|SYSCALL
argument_list|(
argument|wait
argument_list|)
end_macro

begin_expr_stmt
name|tstl
literal|4
operator|(
name|ap
operator|)
name|jeql
literal|1f
name|movl
name|r1
operator|,
operator|*
literal|4
operator|(
name|ap
operator|)
literal|1
operator|:
name|ret
end_expr_stmt

end_unit

