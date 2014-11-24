begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --system-header-prefix=libs/ --no-system-header-prefix=libs/mylib/ -I%S/Inputs/SystemHeaderPrefix -Wundef -E %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang --system-header-prefix libs/ --no-system-header-prefix libs/mylib/ -I%S/Inputs/SystemHeaderPrefix -Wundef -E %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"src/all.h"
end_include

begin_comment
comment|// CHECK-NOT: BOOST
end_comment

begin_comment
comment|// CHECK: libs{{/|\\}}mylib{{/|\\}}warn.h:1:5: warning: 'MYLIB' is not defined, evaluates to 0
end_comment

begin_comment
comment|// CHECK-NOT: BOOST
end_comment

begin_comment
comment|// CHECK: libs{{/|\\}}mylib{{/|\\}}warn.h:1:5: warning: 'MYLIB' is not defined, evaluates to 0
end_comment

begin_comment
comment|// CHECK-NOT: BOOST
end_comment

begin_comment
comment|// CHECK: src{{/|\\}}warn.h:1:5: warning: 'SRC' is not defined, evaluates to 0
end_comment

begin_comment
comment|// CHECK-NOT: BOOST
end_comment

end_unit

