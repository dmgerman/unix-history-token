begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -I %S/Inputs/SystemHeaderPrefix/.. %s 2>&1 | FileCheck -check-prefix=NORMAL -check-prefix=CHECK %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -I %S/Inputs/SystemHeaderPrefix/.. -fdiagnostics-absolute-paths %s 2>&1 | FileCheck -check-prefix=ABSOLUTE -check-prefix=CHECK %s
end_comment

begin_include
include|#
directive|include
file|"absolute-paths.h"
end_include

begin_comment
comment|// Check whether the diagnostic from the header above includes the dummy
end_comment

begin_comment
comment|// directory in the path.
end_comment

begin_comment
comment|// NORMAL: SystemHeaderPrefix
end_comment

begin_comment
comment|// ABSOLUTE-NOT: SystemHeaderPrefix
end_comment

begin_comment
comment|// CHECK: warning: control reaches end of non-void function
end_comment

begin_comment
comment|// For files which don't exist, just print the filename.
end_comment

begin_line
line|#
directive|line
number|123
file|"non-existant.c"
end_line

begin_function
name|int
name|g
parameter_list|()
block|{}
end_function

begin_comment
comment|// NORMAL: non-existant.c:123:10: warning: control reaches end of non-void function
end_comment

begin_comment
comment|// ABSOLUTE: non-existant.c:123:10: warning: control reaches end of non-void function
end_comment

end_unit

