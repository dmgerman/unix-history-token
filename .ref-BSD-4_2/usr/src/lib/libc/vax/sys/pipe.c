begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pipe.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|SYSCALL
argument_list|(
argument|pipe
argument_list|)
end_macro

begin_expr_stmt
name|movl
literal|4
operator|(
name|ap
operator|)
operator|,
name|r2
name|movl
name|r0
operator|,
operator|(
name|r2
operator|)
operator|+
name|movl
name|r1
operator|,
operator|(
name|r2
operator|)
name|clrl
name|r0
name|ret
end_expr_stmt

end_unit

