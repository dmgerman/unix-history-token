begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Optrace.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SYS_ptrace
value|26
end_define

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

