begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getgroups.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|SYSCALL
argument_list|(
argument|getgroups
argument_list|)
end_macro

begin_expr_stmt
name|ret
operator|#
name|ngroups
operator|=
name|getgroups
argument_list|(
argument|gidsetsize
argument_list|,
argument|gidset
argument_list|)
end_expr_stmt

end_unit

