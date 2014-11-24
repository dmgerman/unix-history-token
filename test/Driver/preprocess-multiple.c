begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -E %s %s | FileCheck %s
end_comment

begin_comment
comment|// Test that the driver can preprocess multiple files.
end_comment

begin_macro
name|X
end_macro

begin_comment
comment|// CHECK: X
end_comment

begin_comment
comment|// CHECK: X
end_comment

end_unit

