begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* setrgid.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|setrgid
argument_list|)
end_macro

begin_expr_stmt
name|pushl
name|$
operator|-
literal|1
name|pushl
literal|4
operator|(
name|ap
operator|)
name|CALL
argument_list|(
literal|2
argument_list|,
argument|setregid
argument_list|)
name|ret
end_expr_stmt

end_unit

