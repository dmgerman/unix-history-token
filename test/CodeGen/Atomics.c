begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test frontend handling of __sync builtins.
end_comment

begin_comment
comment|// Modified from a gcc testcase.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s -o - | FileCheck %s
end_comment

begin_decl_stmt
name|signed
name|char
name|sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|short
name|ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|int
name|si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|signed
name|long
name|long
name|sll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|ull
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_op_ignore
parameter_list|(
name|void
parameter_list|)
comment|// CHECK-LABEL: define void @test_op_ignore
block|{
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i8
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i8
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i16
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i16
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i32
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i32
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i64
operator|(
name|void
operator|)
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i64
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i8
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i8
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i16
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i16
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i32
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i32
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i64
operator|(
name|void
operator|)
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i64
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i8
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i8
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i16
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i16
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i32
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i32
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i64
operator|(
name|void
operator|)
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or i64
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i8
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i8
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i16
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i16
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i32
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i32
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i64
operator|(
name|void
operator|)
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor i64
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i8
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i8
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i16
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i16
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i32
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i32
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i64
operator|(
name|void
operator|)
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and i64
block|}
end_function

begin_function
name|void
name|test_fetch_and_op
parameter_list|(
name|void
parameter_list|)
comment|// CHECK-LABEL: define void @test_fetch_and_op
block|{
name|sc
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|sc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|uc
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|uc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ss
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ss
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|us
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|us
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|si
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|si
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ui
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ui
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|sll
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|sll
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ull
operator|=
name|__sync_fetch_and_add
argument_list|(
operator|&
name|ull
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|sc
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|sc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|uc
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|uc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ss
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ss
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|us
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|us
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|si
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|si
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ui
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ui
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|sll
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|sll
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ull
operator|=
name|__sync_fetch_and_sub
argument_list|(
operator|&
name|ull
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|sc
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|sc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|uc
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|uc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ss
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ss
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|us
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|us
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|si
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|si
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ui
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ui
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|sll
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|sll
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ull
operator|=
name|__sync_fetch_and_or
argument_list|(
operator|&
name|ull
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|sc
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|sc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|uc
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|uc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ss
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ss
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|us
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|us
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|si
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|si
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ui
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ui
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|sll
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|sll
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ull
operator|=
name|__sync_fetch_and_xor
argument_list|(
operator|&
name|ull
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|sc
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|sc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|uc
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|uc
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ss
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ss
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|us
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|us
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|si
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|si
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ui
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ui
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|sll
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|sll
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ull
operator|=
name|__sync_fetch_and_and
argument_list|(
operator|&
name|ull
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
block|}
end_function

begin_function
name|void
name|test_op_and_fetch
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|uc
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ss
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|us
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|si
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ui
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|sll
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|ull
operator|=
name|__sync_add_and_fetch
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add
name|sc
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|uc
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ss
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|us
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|si
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ui
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|sll
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|ull
operator|=
name|__sync_sub_and_fetch
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub
name|sc
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|uc
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ss
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|us
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|si
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ui
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|sll
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|ull
operator|=
name|__sync_or_and_fetch
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw or
name|sc
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|uc
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ss
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|us
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|si
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ui
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|sll
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|ull
operator|=
name|__sync_xor_and_fetch
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xor
name|sc
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|uc
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ss
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|us
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|si
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ui
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|sll
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
name|ull
operator|=
name|__sync_and_and_fetch
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw and
block|}
end_function

begin_function
name|void
name|test_compare_and_swap
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i8
comment|// CHECK: extractvalue { i8, i1 } [[PAIR]], 0
name|uc
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i8
comment|// CHECK: extractvalue { i8, i1 } [[PAIR]], 0
name|ss
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i16
comment|// CHECK: extractvalue { i16, i1 } [[PAIR]], 0
name|us
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i16
comment|// CHECK: extractvalue { i16, i1 } [[PAIR]], 0
name|si
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i32
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 0
name|ui
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i32
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 0
name|sll
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i64
comment|// CHECK: extractvalue { i64, i1 } [[PAIR]], 0
name|ull
operator|=
name|__sync_val_compare_and_swap
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i64
comment|// CHECK: extractvalue { i64, i1 } [[PAIR]], 0
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|sc
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i8
comment|// CHECK: extractvalue { i8, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|uc
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i8
comment|// CHECK: extractvalue { i8, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|ss
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i16
comment|// CHECK: extractvalue { i16, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|us
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i16
comment|// CHECK: extractvalue { i16, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|si
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i32
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|ui
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i32
comment|// CHECK: extractvalue { i32, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|sll
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i64
comment|// CHECK: extractvalue { i64, i1 } [[PAIR]], 1
name|ui
operator|=
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|ull
argument_list|,
name|uc
argument_list|,
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: [[PAIR:%[a-z0-9._]+]] = cmpxchg i64
comment|// CHECK: extractvalue { i64, i1 } [[PAIR]], 1
block|}
end_function

begin_function
name|void
name|test_lock
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|sc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i8
name|uc
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|uc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i8
name|ss
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|ss
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i16
name|us
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|us
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i16
name|si
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|si
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i32
name|ui
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|ui
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i32
name|sll
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|sll
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i64
name|ull
operator|=
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|ull
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw xchg i64
name|__sync_synchronize
argument_list|()
expr_stmt|;
comment|// CHECK: fence seq_cst
name|__sync_lock_release
argument_list|(
operator|&
name|sc
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 1
name|__sync_lock_release
argument_list|(
operator|&
name|uc
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 1
name|__sync_lock_release
argument_list|(
operator|&
name|ss
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 2
name|__sync_lock_release
argument_list|(
operator|&
name|us
argument_list|)
expr_stmt|;
comment|/// CHECK: store atomic {{.*}} release, align 2
name|__sync_lock_release
argument_list|(
operator|&
name|si
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 4
name|__sync_lock_release
argument_list|(
operator|&
name|ui
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 4
name|__sync_lock_release
argument_list|(
operator|&
name|sll
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 8
name|__sync_lock_release
argument_list|(
operator|&
name|ull
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic {{.*}} release, align 8
block|}
end_function

end_unit

