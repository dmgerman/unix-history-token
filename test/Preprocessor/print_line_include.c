begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -P %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: int x;
end_comment

begin_comment
comment|// CHECK-NEXT: int x;
end_comment

begin_include
include|#
directive|include
file|"print_line_include.h"
end_include

begin_include
include|#
directive|include
file|"print_line_include.h"
end_include

end_unit

