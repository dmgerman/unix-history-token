begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)ffs.c	4.1 12/15/82 */
end_comment

begin_comment
comment|/* bit = ffs(value) */
end_comment

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|ffs
argument_list|)
end_macro

begin_decl_stmt
name|ffs
name|$0
decl_stmt|,
name|$32
decl_stmt|,4
argument_list|(
name|ap
argument_list|)
decl_stmt|,
name|r0
name|bneq
decl|1f
name|mnegl
name|$1
decl_stmt|,
name|r0
decl|1
range|:
name|incl
name|r0
name|ret
end_decl_stmt

end_unit

