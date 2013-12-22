begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -Wfatal-errors -verify %s 2>&1 | FileCheck %s
end_comment

begin_error
error|#
directive|error
error|first fatal
end_error

begin_comment
comment|// expected-error@-1 {{first fatal}}
end_comment

begin_error
error|#
directive|error
error|second fatal
end_error

begin_comment
comment|// expected-error@-1 {{second fatal}}
end_comment

begin_comment
comment|//      CHECK: error: 'error' diagnostics expected but not seen:
end_comment

begin_comment
comment|// CHECK-NEXT:   Line 6 (directive at {{.*}}verify-fatal.c:7): second fatal
end_comment

begin_comment
comment|// CHECK-NEXT: 1 error generated.
end_comment

end_unit

