begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dup2.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|dup2
argument_list|)
end_macro

begin_decl_stmt
name|bisb2
name|$0100
decl_stmt|,4
argument_list|(
name|ap
argument_list|)
comment|/* XXX */
name|chmk
name|$SYS_dup
comment|/* XXX */
name|jcs
name|err
name|ret
name|err
range|:
name|jmp
name|cerror
end_decl_stmt

end_unit

