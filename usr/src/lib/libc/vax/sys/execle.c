begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* execle.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|execle
argument_list|)
end_macro

begin_expr_stmt
name|movl
argument_list|(
name|ap
argument_list|)
operator|,
name|r0
name|pushl
argument_list|(
name|ap
argument_list|)
index|[
name|r0
index|]
name|pushab
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
name|execle
argument_list|(
name|file
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
operator|...
argument_list|,
name|env
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

