begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* exect.c 4.2 82/12/17 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_macro
name|ENTRY
argument_list|(
argument|exect
argument_list|)
end_macro

begin_expr_stmt
name|bispsw
name|$PSL_T
name|chmk
name|$SYS_execve
name|jmp
name|cerror
operator|#
name|exect
argument_list|(
argument|file
argument_list|,
argument|argv
argument_list|,
argument|env
argument_list|)
end_expr_stmt

end_unit

