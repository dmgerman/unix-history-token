begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)stat.c	4.1 (Berkeley) 1/1/83 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|stat
argument_list|)
end_macro

begin_expr_stmt
name|pushl
literal|4
operator|(
name|ap
operator|)
name|CALL
argument_list|(
literal|1
argument_list|,
name|_fixf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|movl
name|r0
decl_stmt|,4
argument_list|(
name|ap
argument_list|)
name|chmk
name|$SYS_stat
name|jcs
name|err
name|ret
name|err
range|:
name|jmp
name|cerror
end_decl_stmt

end_unit

