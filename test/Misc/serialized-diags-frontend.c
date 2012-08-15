begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only %s -Wblahblah --serialize-diagnostics %t> /dev/null 2>&1 || true
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// This test case tests that we can handle frontend diagnostics.
end_comment

begin_comment
comment|// CHECK: warning: unknown warning option '-Wblahblah'
end_comment

begin_comment
comment|// CHECK: Number of diagnostics: 1
end_comment

end_unit

