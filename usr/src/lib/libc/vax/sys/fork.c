begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fork.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_macro
name|SYSCALL
argument_list|(
argument|fork
argument_list|)
end_macro

begin_decl_stmt
name|jlbc
name|r1
decl_stmt|,1f	#
name|parent
decl_stmt|,
name|since
name|r1
decl|== 0
name|in
name|parent
decl_stmt|, 1
name|in
name|child
name|clrl
name|r0
decl|1
range|:
name|ret
operator|#
name|pid
operator|=
name|fork
argument_list|()
end_decl_stmt

end_unit

