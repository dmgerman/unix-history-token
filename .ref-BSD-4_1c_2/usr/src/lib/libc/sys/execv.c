begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* execv.c 4.2 82/12/29 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_expr_stmt
name|ENTRY
argument_list|(
name|execv
argument_list|)
operator|.
name|globl
name|_environ
name|pushl
name|_environ
name|pushl
literal|8
operator|(
name|ap
operator|)
name|pushl
literal|4
operator|(
name|ap
operator|)
name|calls
name|$3
operator|,
name|_execve
name|ret
operator|#
name|execv
argument_list|(
argument|file
argument_list|,
argument|argv
argument_list|)
end_expr_stmt

end_unit

