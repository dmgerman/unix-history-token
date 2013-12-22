begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines are sensitive to line numbers and come below the code.
end_comment

begin_include
include|#
directive|include
file|"retain-comments-from-system-headers.h"
end_include

begin_comment
comment|/**  * user_function  * \param a Aaa.  */
end_comment

begin_function_decl
name|int
name|user_function
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test -test-load-source all %s -I %S/Inputs | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all %s -fretain-comments-from-system-headers -I %S/Inputs | FileCheck %s -check-prefix=CHECK-RETAIN
end_comment

begin_comment
comment|// CHECK: retain-comments-from-system-headers.h:7:5: FunctionDecl=system_function:7:5 Extent=[7:1 - 7:27]
end_comment

begin_comment
comment|// CHECK: retain-comments-from-system-headers.c:9:5: FunctionDecl=user_function:9:5 RawComment=[/**\n * user_function\n * \param a Aaa.\n */] RawCommentRange=[5:1 - 8:4] BriefComment=[user_function]
end_comment

begin_comment
comment|// CHECK-RETAIN: retain-comments-from-system-headers.h:7:5: FunctionDecl=system_function:7:5 RawComment=[/**\n * system_function\n * \param a Aaa.\n */] RawCommentRange=[3:1 - 6:4] BriefComment=[system_function]
end_comment

begin_comment
comment|// CHECK-RETAIN: retain-comments-from-system-headers.c:9:5: FunctionDecl=user_function:9:5 RawComment=[/**\n * user_function\n * \param a Aaa.\n */] RawCommentRange=[5:1 - 8:4] BriefComment=[user_function]
end_comment

end_unit

