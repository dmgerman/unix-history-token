begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* setuid.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|setuid
argument_list|)
end_macro

begin_expr_stmt
name|pushl
literal|4
operator|(
name|ap
operator|)
name|pushl
literal|4
operator|(
name|ap
operator|)
name|CALL
argument_list|(
literal|2
argument_list|,
argument|setreuid
argument_list|)
name|ret
end_expr_stmt

end_unit

