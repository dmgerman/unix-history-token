begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* execl.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|execl
argument_list|)
end_macro

begin_expr_stmt
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
name|$2
operator|,
name|_execv
name|ret
operator|#
name|execl
argument_list|(
name|file
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
operator|...
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

