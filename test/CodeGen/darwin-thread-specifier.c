begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @b = thread_local global i32 5, align 4
end_comment

begin_decl_stmt
name|__thread
name|int
name|b
init|=
literal|5
decl_stmt|;
end_decl_stmt

end_unit

