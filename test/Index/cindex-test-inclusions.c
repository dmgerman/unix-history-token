begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-inclusion-stack-source %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"include_test.h"
end_include

begin_comment
comment|// CHECK: cindex-test-inclusions.c
end_comment

begin_comment
comment|// CHECK: included by:
end_comment

begin_comment
comment|// CHECK: include_test.h
end_comment

begin_comment
comment|// CHECK: included by:
end_comment

begin_comment
comment|// CHECK: cindex-test-inclusions.c:3:10
end_comment

begin_comment
comment|// CHECK: include_test_2.h
end_comment

begin_comment
comment|// CHECK: included by:
end_comment

begin_comment
comment|// CHECK: include_test.h:1:10
end_comment

begin_comment
comment|// CHECK: cindex-test-inclusions.c:3:10
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-inclusion-stack-source %s 2>&1 | FileCheck -check-prefix=REPARSE %s
end_comment

begin_comment
comment|// REPARSE: include_test_2.h
end_comment

begin_comment
comment|// REPARSE: included by:
end_comment

begin_comment
comment|// REPARSE: include_test.h:1:10
end_comment

begin_comment
comment|// REPARSE: cindex-test-inclusions.c:3:10
end_comment

begin_comment
comment|// REPARSE: include_test.h
end_comment

begin_comment
comment|// REPARSE: included by:
end_comment

begin_comment
comment|// REPARSE: cindex-test-inclusions.c:3:10
end_comment

begin_comment
comment|// REPARSE: cindex-test-inclusions.c
end_comment

begin_comment
comment|// REPARSE: included by:
end_comment

end_unit

