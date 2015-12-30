begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// XFAIL: hexagon,sparc
end_comment

begin_comment
comment|//        (due to not having native load atomic support)
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|i
init|=
literal|0
decl_stmt|;
atomic|_Atomic
argument_list|(
name|short
argument_list|)
name|j
init|=
literal|0
decl_stmt|;
comment|// Check that multiply / divides on atomics produce a cmpxchg loop
name|i
operator|*=
literal|2
expr_stmt|;
comment|// CHECK: mul nsw i32
comment|// CHECK: {{(cmpxchg i32*|i1 @__atomic_compare_exchange\(i32 4,)}}
name|i
operator|/=
literal|2
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: {{(cmpxchg i32*|i1 @__atomic_compare_exchange\(i32 4, )}}
name|j
operator|/=
name|x
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: {{(cmpxchg i16*|i1 @__atomic_compare_exchange\(i32 2, )}}
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|_Atomic
name|_Bool
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|_Bool
name|bar
parameter_list|()
block|{
comment|// CHECK-LABEL: @bar
comment|// CHECK: %[[load:.*]] = load atomic i8, i8* @b seq_cst
comment|// CHECK: %[[tobool:.*]] = trunc i8 %[[load]] to i1
comment|// CHECK: ret i1 %[[tobool]]
return|return
name|b
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
atomic|_Atomic
argument_list|(
specifier|_Complex
name|int
argument_list|)
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|baz
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: @baz
comment|// CHECK: {{store atomic|call void @__atomic_store}}
name|x
operator|+=
name|y
expr_stmt|;
block|}
end_function

end_unit

