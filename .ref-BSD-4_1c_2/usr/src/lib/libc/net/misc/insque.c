begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)insque.c	4.1 12/15/82 */
end_comment

begin_comment
comment|/* insque(new, pred) */
end_comment

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|insque
argument_list|)
end_macro

begin_expr_stmt
name|insque
operator|*
literal|4
operator|(
name|ap
operator|)
operator|,
operator|*
literal|8
operator|(
name|ap
operator|)
name|ret
end_expr_stmt

end_unit

