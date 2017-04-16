begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - -fblocks | FileCheck %s
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{}
function_decl|;
end_function_decl

begin_comment
comment|// rdar://6768379
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
function_decl|(
modifier|^
name|a0
function_decl|)
parameter_list|()
parameter_list|)
block|{
return|return
name|a0
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Verify that attributes on blocks are set correctly.
end_comment

begin_typedef
typedef|typedef
name|struct
name|s0
name|T
typedef|;
end_typedef

begin_struct
struct|struct
name|s0
block|{
name|int
name|a
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define internal void @__f2_block_invoke(%struct.s0* noalias sret {{%.*}}, i8* {{%.*}}, %struct.s0* byval align 4 {{.*}})
end_comment

begin_function
name|struct
name|s0
name|f2
parameter_list|(
name|struct
name|s0
name|a0
parameter_list|)
block|{
return|return
lambda|^
parameter_list|(
name|struct
name|s0
name|a1
parameter_list|)
block|{
return|return
name|a1
return|;
block|}
argument_list|(
name|a0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// This should not crash: rdar://6808051
end_comment

begin_decl_stmt
name|void
modifier|*
name|P
init|=
lambda|^
block|{
name|void
modifier|*
name|Q
init|=
name|__func__
decl_stmt|;
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|test1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
specifier|__block
name|int
name|i
function_decl|;
end_function_decl

begin_expr_stmt
lambda|^
block|{
name|i
operator|=
literal|1
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|double
name|ftype
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// It's not clear that we *should* support this syntax, but until that decision
end_comment

begin_comment
comment|// is made, we should support it properly and not crash.
end_comment

begin_decl_stmt
name|ftype
modifier|^
name|test2
init|=
lambda|^
name|ftype
block|{
return|return
literal|0
return|;
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://problem/8605032
end_comment

begin_function_decl
name|void
name|f3_helper
parameter_list|(
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f3
parameter_list|()
block|{
name|_Bool
name|b
init|=
literal|0
decl_stmt|;
name|f3_helper
argument_list|(
lambda|^
block|{
if|if
condition|(
name|b
condition|)
block|{}
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://problem/11322251
end_comment

begin_comment
comment|// The bool can fill in between the header and the long long.
end_comment

begin_comment
comment|// Add the appropriate amount of padding between them.
end_comment

begin_decl_stmt
name|void
name|f4_helper
argument_list|(
name|long
name|long
argument_list|(
operator|^
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @f4()
end_comment

begin_function
name|void
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
name|_Bool
name|b
init|=
literal|0
decl_stmt|;
name|long
name|long
name|ll
init|=
literal|0
decl_stmt|;
comment|// CHECK: alloca<{ i8*, i32, i32, i8*, {{%.*}}*, i8, [3 x i8], i64 }>, align 8
name|f4_helper
argument_list|(
lambda|^
block|{
if|if
condition|(
name|b
condition|)
return|return
name|ll
return|;
return|return
literal|0LL
return|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://problem/11354538
end_comment

begin_comment
comment|// The alignment after rounding up to the align of F5 is actually
end_comment

begin_comment
comment|// greater than the required alignment.  Don't assert.
end_comment

begin_struct
struct|struct
name|F5
block|{
name|char
name|buffer
index|[
literal|32
index|]
name|__attribute
argument_list|(
operator|(
name|aligned
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f5_helper
parameter_list|(
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|struct
name|F5
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @f5()
end_comment

begin_function
name|void
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|F5
name|value
decl_stmt|;
comment|// CHECK: alloca<{ i8*, i32, i32, i8*, {{%.*}}*, [12 x i8], [[F5:%.*]] }>, align 16
name|f5_helper
argument_list|(
lambda|^
parameter_list|(
name|struct
name|F5
modifier|*
name|slot
parameter_list|)
block|{
operator|*
name|slot
operator|=
name|value
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://14085217
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|()
init|=
lambda|^
block|{}
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
operator|(
name|b
condition|?
else|:
lambda|^
block|{}
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: [[ZERO:%.*]] = load void (...)*, void (...)** @b
end_comment

begin_comment
comment|// CHECK-NEXT: [[TB:%.*]] = icmp ne void (...)* [[ZERO]], null
end_comment

begin_comment
comment|// CHECK-NEXT: br i1 [[TB]], label [[CT:%.*]], label [[CF:%.*]]
end_comment

begin_comment
comment|// CHECK: [[ONE:%.*]] = bitcast void (...)* [[ZERO]] to void ()*
end_comment

begin_comment
comment|// CHECK-NEXT:   br label [[CE:%.*]]
end_comment

begin_comment
comment|// Ensure that we don't emit helper code in copy/dispose routines for variables
end_comment

begin_comment
comment|// that are const-captured.
end_comment

begin_function
name|void
name|testConstCaptureInCopyAndDestroyHelpers
parameter_list|()
block|{
specifier|const
name|int
name|x
init|=
literal|0
decl_stmt|;
specifier|__block
name|int
name|i
decl_stmt|;
operator|(
lambda|^
block|{
name|i
operator|=
name|x
expr_stmt|;
block|}
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: testConstCaptureInCopyAndDestroyHelpers_block_invoke
end_comment

begin_comment
comment|// CHECK: @__copy_helper_block
end_comment

begin_comment
comment|// CHECK: alloca
end_comment

begin_comment
comment|// CHECK-NEXT: alloca
end_comment

begin_comment
comment|// CHECK-NEXT: store
end_comment

begin_comment
comment|// CHECK-NEXT: store
end_comment

begin_comment
comment|// CHECK-NEXT: load
end_comment

begin_comment
comment|// CHECK-NEXT: bitcast
end_comment

begin_comment
comment|// CHECK-NEXT: load
end_comment

begin_comment
comment|// CHECK-NEXT: bitcast
end_comment

begin_comment
comment|// CHECK-NEXT: getelementptr
end_comment

begin_comment
comment|// CHECK-NEXT: getelementptr
end_comment

begin_comment
comment|// CHECK-NEXT: load
end_comment

begin_comment
comment|// CHECK-NEXT: bitcast
end_comment

begin_comment
comment|// CHECK-NEXT: call void @_Block_object_assign
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_comment
comment|// CHECK: @__destroy_helper_block
end_comment

begin_comment
comment|// CHECK: alloca
end_comment

begin_comment
comment|// CHECK-NEXT: store
end_comment

begin_comment
comment|// CHECK-NEXT: load
end_comment

begin_comment
comment|// CHECK-NEXT: bitcast
end_comment

begin_comment
comment|// CHECK-NEXT: getelementptr
end_comment

begin_comment
comment|// CHECK-NEXT: load
end_comment

begin_comment
comment|// CHECK-NEXT: call void @_Block_object_dispose
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

end_unit

