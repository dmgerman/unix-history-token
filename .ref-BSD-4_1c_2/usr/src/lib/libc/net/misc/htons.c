begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)htons.c	4.1 12/15/82 */
end_comment

begin_comment
comment|/* hostorder = htons(netorder) */
end_comment

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_macro
name|ENTRY
argument_list|(
argument|htons
argument_list|)
end_macro

begin_decl_stmt
name|rotl
name|$8
decl_stmt|,4
argument_list|(
name|ap
argument_list|)
decl_stmt|,
name|r0
name|movb
decl|5
argument_list|(
name|ap
argument_list|)
decl_stmt|,
name|r0
name|movzwl
name|r0
decl_stmt|,
name|r0
name|ret
end_decl_stmt

end_unit

