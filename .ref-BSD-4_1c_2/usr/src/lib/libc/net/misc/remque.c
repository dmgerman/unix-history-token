begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)remque.c	4.1 12/15/82 */
end_comment

begin_comment
comment|/* remque(entry) */
end_comment

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|remque
argument_list|)
end_macro

begin_expr_stmt
name|remque
operator|*
literal|4
operator|(
name|ap
operator|)
operator|,
name|r0
name|ret
end_expr_stmt

end_unit

