begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -asdf -verify %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|//      CHECK: error: 'error' diagnostics seen but not expected:
end_comment

begin_comment
comment|// CHECK-NEXT: (frontend): unknown argument: '-asdf'
end_comment

end_unit

