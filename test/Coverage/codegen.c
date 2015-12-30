begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm-bc -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -debug-info-kind=limited -emit-llvm-bc -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm-bc -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -debug-info-kind=limited -emit-llvm-bc -o %t %s
end_comment

begin_include
include|#
directive|include
file|"c-language-features.inc"
end_include

end_unit

