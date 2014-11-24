begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm-only -triple=i386-apple-darwin -o %t
end_comment

begin_comment
comment|// RUN: not rm %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-codegen-only -triple=i386-apple-darwin -o %t
end_comment

begin_comment
comment|// RUN: not rm %t
end_comment

begin_comment
comment|// Test that output is not generated when emission is disabled.
end_comment

end_unit

