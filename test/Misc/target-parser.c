begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple armv7--- -target-cpu not-a-cpu -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: unknown target CPU 'not-a-cpu'
end_comment

end_unit

