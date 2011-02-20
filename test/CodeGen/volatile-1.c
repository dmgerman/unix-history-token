begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-return-type -Wno-unused-value -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @i = common global [[INT:i[0-9]+]] 0
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|ar
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @ci = common global [[CINT:%.*]] zeroinitializer
end_comment

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|int
name|ci
decl_stmt|;
end_decl_stmt

begin_struct
specifier|volatile
struct|struct
name|S
block|{
ifdef|#
directive|ifdef
name|__cplusplus
name|void
name|operator
init|=
operator|(
specifier|volatile
expr|struct
name|S
operator|&
name|o
operator|)
specifier|volatile
decl_stmt|;
endif|#
directive|endif
name|int
name|i
decl_stmt|;
block|}
name|a
struct|,
name|b
struct|;
end_struct

begin_comment
comment|//void operator =(volatile struct S&o1, volatile struct S&o2) volatile;
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note that these test results are very much specific to C!
end_comment

begin_comment
comment|// Assignments in C++ yield l-values, not r-values, and the situations
end_comment

begin_comment
comment|// that do implicit lvalue-to-rvalue conversion are substantially
end_comment

begin_comment
comment|// reduced.
end_comment

begin_comment
comment|// CHECK: define void @test()
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
comment|// CHECK: volatile load [[INT]]* @i
name|i
expr_stmt|;
comment|// CHECK-NEXT: volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: sitofp [[INT]]
call|(
name|float
call|)
argument_list|(
name|ci
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
operator|(
name|void
operator|)
name|ci
expr_stmt|;
comment|// CHECK-NEXT: bitcast
comment|// CHECK-NEXT: memcpy
operator|(
name|void
operator|)
name|a
expr_stmt|;
comment|// CHECK-NEXT: [[R:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: volatile store [[INT]] [[R]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: volatile store [[INT]] [[I]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
call|(
name|void
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[T:%.*]] = volatile load [[INT]]* @j
comment|// CHECK-NEXT: volatile store [[INT]] [[T]], [[INT]]* @i
call|(
name|void
call|)
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[R1:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I1:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: [[R2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// Not sure why they're ordered this way.
comment|// CHECK-NEXT: [[R:%.*]] = add [[INT]] [[R2]], [[R1]]
comment|// CHECK-NEXT: [[I:%.*]] = add [[INT]] [[I2]], [[I1]]
comment|// CHECK-NEXT: volatile store [[INT]] [[R]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: volatile store [[INT]] [[I]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
name|ci
operator|+=
name|ci
expr_stmt|;
comment|// CHECK-NEXT: [[R1:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I1:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: [[R2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: [[R:%.*]] = add [[INT]] [[R2]], [[R1]]
comment|// CHECK-NEXT: [[I:%.*]] = add [[INT]] [[I2]], [[I1]]
comment|// CHECK-NEXT: volatile store [[INT]] [[R]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: volatile store [[INT]] [[I]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: [[R2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 0)
comment|// CHECK-NEXT: [[I2:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// These additions can be elided
comment|// CHECK-NEXT: add [[INT]] [[R]], [[R2]]
comment|// CHECK-NEXT: add [[INT]] [[I]], [[I2]]
operator|(
name|ci
operator|+=
name|ci
operator|)
operator|+
name|ci
expr_stmt|;
comment|// CHECK-NEXT: call void asm
asm|asm("nop");
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add nsw [[INT]]
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add nsw [[INT]]
operator|(
name|i
operator|+=
name|j
operator|)
operator|+
name|k
expr_stmt|;
comment|// CHECK-NEXT: call void asm
asm|asm("nop");
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add nsw [[INT]]
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: add nsw [[INT]]
operator|(
name|i
operator|+=
name|j
operator|)
operator|+
literal|1
expr_stmt|;
comment|// CHECK-NEXT: call void asm
asm|asm("nop");
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add [[INT]]
comment|// CHECK-NEXT: add [[INT]]
name|ci
operator|+
name|ci
expr_stmt|;
comment|// CHECK-NEXT: volatile load
name|__real
name|i
decl_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
operator|+
name|ci
expr_stmt|;
comment|// CHECK-NEXT: call void asm
asm|asm("nop");
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
call|(
name|void
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: sitofp
call|(
name|float
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
operator|(
name|void
operator|)
name|i
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
name|i
operator|=
name|i
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
name|i
operator|=
name|i
operator|=
name|i
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
operator|(
name|void
operator|)
name|__builtin_choose_expr
argument_list|(
literal|0
argument_list|,
name|i
operator|=
name|i
argument_list|,
name|j
operator|=
name|j
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: icmp
comment|// CHECK-NEXT: br i1
comment|// CHECK: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: br label
comment|// CHECK: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: br label
name|k
condition|?
operator|(
name|i
operator|=
name|i
operator|)
else|:
operator|(
name|j
operator|=
name|j
operator|)
expr_stmt|;
comment|// CHECK: phi
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
call|(
name|void
call|)
argument_list|(
name|i
argument_list|,
operator|(
name|i
operator|=
name|i
operator|)
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile load
name|i
operator|=
name|i
operator|,
name|i
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
operator|(
name|i
operator|=
name|j
operator|,
name|k
operator|=
name|j
operator|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile load
operator|(
name|i
operator|=
name|j
operator|,
name|k
operator|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
operator|(
name|i
operator|,
name|j
operator|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: trunc
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: sext
comment|// CHECK-NEXT: volatile store
name|i
operator|=
name|c
operator|=
name|k
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add nsw [[INT]]
comment|// CHECK-NEXT: volatile store
name|i
operator|+=
name|k
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
name|ci
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
operator|(
name|int
operator|)
name|ci
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: icmp ne
comment|// CHECK-NEXT: icmp ne
comment|// CHECK-NEXT: or i1
operator|(
name|_Bool
operator|)
name|ci
expr_stmt|;
endif|#
directive|endif
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
name|ci
operator|=
name|ci
expr_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
name|ci
operator|=
name|ci
operator|=
name|ci
expr_stmt|;
comment|// CHECK-NEXT: [[T:%.*]] = volatile load [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: volatile store [[INT]] [[T]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
comment|// CHECK-NEXT: volatile store [[INT]] [[T]], [[INT]]* getelementptr inbounds ([[CINT]]* @ci, i32 0, i32 1)
name|__imag
name|ci
init|=
name|__imag
name|ci
operator|=
name|__imag
name|ci
decl_stmt|;
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
name|__real
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: volatile load
name|__imag
name|i
decl_stmt|;
comment|// ============================================================
comment|// FIXME: Test cases we get wrong.
comment|// A use.  We load all of a into a copy of a, then load i.  gcc forgets to do
comment|// the assignment.
comment|// (a = a).i;
comment|// ============================================================
comment|// Test cases where we intentionally differ from gcc, due to suspected bugs in
comment|// gcc.
comment|// Not a use.  gcc forgets to do the assignment.
comment|// CHECK-NEXT: call void @llvm.memcpy{{.*}}, i1 true
comment|// CHECK-NEXT: bitcast
comment|// CHECK-NEXT: call void @llvm.memcpy{{.*}}, i1 true
operator|(
operator|(
name|a
operator|=
name|a
operator|)
operator|,
name|a
operator|)
expr_stmt|;
comment|// Not a use.  gcc gets this wrong, it doesn't emit the copy!
comment|// (void)(a=a);
comment|// Not a use.  gcc got this wrong in 4.2 and omitted the side effects
comment|// entirely, but it is fixed in 4.4.0.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
name|__imag
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// A use of the real part
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: sitofp
call|(
name|float
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// Not a use, bug?  gcc treats this as not a use, that's probably a bug due to
comment|// tree folding ignoring volatile.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
call|(
name|int
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// A use.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: sitofp
call|(
name|float
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// A use.  gcc treats this as not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
call|(
name|int
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// A use.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: sub
operator|-
operator|(
name|i
operator|=
name|j
operator|)
expr_stmt|;
comment|// A use.  gcc treats this a not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
operator|+
operator|(
name|i
operator|=
name|k
operator|)
expr_stmt|;
comment|// A use. gcc treats this a not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile store
name|__real
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// A use.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add
name|i
operator|+
literal|0
expr_stmt|;
comment|// A use.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: add
operator|(
name|i
operator|=
name|j
operator|)
operator|+
name|i
expr_stmt|;
comment|// A use.  gcc treats this as not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
comment|// CHECK-NEXT: volatile load
comment|// CHECK-NEXT: volatile store
comment|// CHECK-NEXT: add
operator|(
name|i
operator|=
name|j
operator|)
operator|+
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
operator|(
name|i
operator|,
name|j
operator|)
operator|=
name|k
expr_stmt|;
operator|(
name|j
operator|=
name|k
operator|,
name|i
operator|)
operator|=
name|i
expr_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|s
struct|,
name|s1
struct|;
name|printf
argument_list|(
literal|"s is at %p\n"
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"s is at %p\n"
argument_list|,
operator|&
operator|(
name|s
operator|=
name|s1
operator|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"s.x is at %p\n"
argument_list|,
operator|&
operator|(
operator|(
name|s
operator|=
name|s1
operator|)
operator|.
name|x
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|volatile
name|enum
name|X
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define void @test1()
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
specifier|extern
name|void
name|test1_helper
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|test1_helper
argument_list|()
expr_stmt|;
comment|// CHECK: call void @test1_helper()
comment|// CHECK-NEXT: ret void
name|x
expr_stmt|;
operator|(
name|void
operator|)
name|x
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

