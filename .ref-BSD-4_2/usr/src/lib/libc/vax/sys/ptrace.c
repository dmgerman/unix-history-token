begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ptrace.c 4.2 83/06/30 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|ptrace
argument_list|)
end_macro

begin_decl_stmt
name|clrl
name|_errno
name|chmk
name|$SYS_ptrace
name|jcs
name|err
name|ret
name|err
range|:
name|jmp
name|cerror
end_decl_stmt

end_unit

