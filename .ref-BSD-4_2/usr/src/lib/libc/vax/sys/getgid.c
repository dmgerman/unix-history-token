begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getgid.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|SYSCALL
argument_list|(
argument|getgid
argument_list|)
end_macro

begin_expr_stmt
name|ret
operator|#
name|gid
operator|=
name|getgid
argument_list|()
expr_stmt|;
end_expr_stmt

end_unit

