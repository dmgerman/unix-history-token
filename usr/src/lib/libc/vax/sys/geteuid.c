begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* geteuid.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|PSEUDO
argument_list|(
argument|geteuid
argument_list|,
argument|getuid
argument_list|)
end_macro

begin_decl_stmt
name|movl
name|r1
decl_stmt|,
name|r0
name|ret
decl|#
name|euid
init|=
name|geteuid
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

