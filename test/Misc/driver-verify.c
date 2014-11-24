begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -verify %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -cc1 -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Test that -verify is strictly rejected as unknown by the driver.
end_comment

begin_comment
comment|// CHECK: unknown argument: '-verify'
end_comment

end_unit

