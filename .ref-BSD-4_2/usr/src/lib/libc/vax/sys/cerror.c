begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cerror.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_expr_stmt
operator|.
name|globl
name|_errno
name|cerror
operator|:
name|movl
name|r0
operator|,
name|_errno
name|mnegl
name|$1
operator|,
name|r0
name|ret
end_expr_stmt

end_unit

