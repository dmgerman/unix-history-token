begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: internal constant [10 x i8] c"abc\00\00\00\00\00\00\00", align 1
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"abc"
decl_stmt|;
comment|// This should convert to utf8.
comment|// CHECK: internal constant [10 x i8] c"\E1\84\A0\C8\A0\F4\82\80\B0\00", align 1
name|char
name|b
index|[
literal|10
index|]
init|=
literal|"\u1120\u0220\U00102030"
decl_stmt|;
comment|// CHECK: private unnamed_addr constant [12 x i8] c"A\00\00\00B\00\00\00\00\00\00\00"
name|void
modifier|*
name|foo
init|=
literal|L"AB"
decl_stmt|;
comment|// CHECK: private unnamed_addr constant [12 x i8] c"4\12\00\00\0B\F0\10\00\00\00\00\00"
name|void
modifier|*
name|bar
init|=
literal|L"\u1234\U0010F00B"
decl_stmt|;
block|}
end_function

end_unit

