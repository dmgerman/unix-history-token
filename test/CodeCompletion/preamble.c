begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"some_struct.h"
end_include

begin_function
name|void
name|foo
parameter_list|()
block|{
name|struct
name|X
name|x
decl_stmt|;
name|x
operator|.
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -code-completion-at=%s:4:5 -Xclang -code-completion-patterns  %s | FileCheck -check-prefix=CHECK-CC1 %s
comment|// CHECK-CC1: FieldDecl:{ResultType int}{TypedText m} (35) (parent: StructDecl 'X')
end_function

end_unit

