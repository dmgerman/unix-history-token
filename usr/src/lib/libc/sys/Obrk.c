begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Obrk.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SYS_brk
value|17
end_define

begin_expr_stmt
operator|.
name|globl
name|curbrk
name|SYSCALL
argument_list|(
argument|brk
argument_list|)
name|movl
literal|4
operator|(
name|ap
operator|)
operator|,
name|curbrk
name|clrl
name|r0
name|ret
end_expr_stmt

end_unit

