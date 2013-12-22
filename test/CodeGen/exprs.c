begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// PR1895
end_comment

begin_comment
comment|// sizeof function
end_comment

begin_function_decl
name|int
name|zxcv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|zxcv
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|y
init|=
name|__alignof__
argument_list|(
name|zxcv
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|test
parameter_list|(
name|int
modifier|*
name|i
parameter_list|)
block|{
name|short
name|a
init|=
literal|1
decl_stmt|;
name|i
operator|+=
name|a
expr_stmt|;
name|i
operator|+
name|a
expr_stmt|;
name|a
operator|+
name|i
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|_Bool
name|test2b
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test2
parameter_list|()
block|{
if|if
condition|(
name|test2b
condition|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// PR1921
end_comment

begin_function
name|int
name|test3
parameter_list|()
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|bp
decl_stmt|;
name|bp
operator|-=
operator|(
name|short
operator|)
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR2080 - sizeof void
end_comment

begin_decl_stmt
name|int
name|t1
init|=
sizeof|sizeof
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t2
init|=
name|__alignof__
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test4
parameter_list|()
block|{
name|t1
operator|=
sizeof|sizeof
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|t2
operator|=
name|__alignof__
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|t1
operator|=
sizeof|sizeof
argument_list|(
name|test4
argument_list|()
argument_list|)
expr_stmt|;
name|t2
operator|=
name|__alignof__
argument_list|(
name|test4
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// 'const float' promotes to double in varargs.
end_comment

begin_function
name|int
name|test5
parameter_list|(
specifier|const
name|float
name|x
parameter_list|,
name|float
name|float_number
parameter_list|)
block|{
return|return
name|__builtin_isless
argument_list|(
name|x
argument_list|,
name|float_number
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// this one shouldn't fold
end_comment

begin_function
name|int
name|ola
parameter_list|()
block|{
name|int
name|a
init|=
literal|2
decl_stmt|;
if|if
condition|(
operator|(
literal|0
operator|,
operator|(
name|int
operator|)
name|a
operator|)
operator|&
literal|2
condition|)
block|{
return|return
literal|1
return|;
block|}
return|return
literal|2
return|;
block|}
end_function

begin_comment
comment|// this one shouldn't fold as well
end_comment

begin_function
name|void
name|eMaisUma
parameter_list|()
block|{
name|double
name|t
index|[
literal|1
index|]
decl_stmt|;
if|if
condition|(
operator|*
name|t
condition|)
return|return;
block|}
end_function

begin_comment
comment|// rdar://6520707
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp2
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|int
name|x
init|=
name|fp
operator|-
name|fp2
decl_stmt|;
block|}
end_function

begin_comment
comment|// noop casts as lvalues.
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|X
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
operator|(
operator|(
expr|struct
name|X
operator|)
name|foo
argument_list|()
operator|)
operator|.
name|Y
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|// PR3809: INC/DEC of function pointers.
end_comment

begin_function_decl
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|unsigned
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|f2
function_decl|;
operator|++
name|fp
expr_stmt|;
name|fp
operator|++
expr_stmt|;
operator|--
name|fp
expr_stmt|;
name|fp
operator|--
expr_stmt|;
return|return
operator|(
name|unsigned
operator|)
name|fp
return|;
block|}
end_function

begin_union
union|union
name|f3_x
block|{
name|int
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
union|;
end_union

begin_function
name|int
name|f3
parameter_list|()
block|{
return|return
operator|(
operator|(
expr|union
name|f3_x
operator|)
literal|2
operator|)
operator|.
name|x
return|;
block|}
end_function

begin_union
union|union
name|f4_y
block|{
name|int
name|x
decl_stmt|;
specifier|_Complex
name|float
name|y
decl_stmt|;
block|}
union|;
end_union

begin_function
specifier|_Complex
name|float
name|f4
parameter_list|()
block|{
return|return
operator|(
operator|(
expr|union
name|f4_y
operator|)
operator|(
specifier|_Complex
name|float
operator|)
literal|2.0
operator|)
operator|.
name|y
return|;
block|}
end_function

begin_struct
struct|struct
name|f5_a
block|{
name|int
name|a
decl_stmt|;
block|}
name|f5_a
struct|;
end_struct

begin_union
union|union
name|f5_z
block|{
name|int
name|x
decl_stmt|;
name|struct
name|f5_a
name|y
decl_stmt|;
block|}
union|;
end_union

begin_function
name|struct
name|f5_a
name|f5
parameter_list|()
block|{
return|return
operator|(
operator|(
expr|union
name|f5_z
operator|)
name|f5_a
operator|)
operator|.
name|y
return|;
block|}
end_function

begin_comment
comment|// ?: in "lvalue"
end_comment

begin_struct
struct|struct
name|s6
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f6
parameter_list|(
name|int
name|a0
parameter_list|,
name|struct
name|s6
name|a1
parameter_list|,
name|struct
name|s6
name|a2
parameter_list|)
block|{
return|return
operator|(
name|a0
condition|?
name|a1
else|:
name|a2
operator|)
operator|.
name|f0
return|;
block|}
end_function

begin_comment
comment|// PR4026
end_comment

begin_function
name|void
name|f7
parameter_list|()
block|{
name|__func__
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR4067
end_comment

begin_function
name|int
name|f8
parameter_list|()
block|{
return|return
operator|(
block|{
name|foo
argument_list|()
block|; }
operator|)
operator|.
name|Y
return|;
block|}
end_function

begin_comment
comment|// rdar://6880558
end_comment

begin_struct_decl
struct_decl|struct
name|S
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|C
block|{
name|int
name|i
decl_stmt|;
name|struct
name|S
modifier|*
name|tab
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S
block|{
name|struct
name|C
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f9
parameter_list|(
name|struct
name|S
modifier|*
name|x
parameter_list|)
block|{
name|foo
argument_list|(
operator|(
operator|(
name|void
operator|)
literal|1
operator|,
name|x
operator|->
name|c
operator|)
operator|.
name|tab
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f10
parameter_list|()
block|{
name|__builtin_sin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://7530813
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f11
end_comment

begin_function
name|int
name|f11
parameter_list|(
name|long
name|X
parameter_list|)
block|{
name|int
name|A
index|[
literal|100
index|]
decl_stmt|;
return|return
name|A
index|[
name|X
index|]
return|;
comment|// CHECK: [[Xaddr:%[^ ]+]] = alloca i64, align 8
comment|// CHECK: load {{.*}}* [[Xaddr]]
comment|// CHECK-NEXT: getelementptr inbounds [100 x i32]* %A, i32 0,
comment|// CHECK-NEXT: load i32*
block|}
end_function

begin_function
name|int
name|f12
parameter_list|()
block|{
comment|// PR3150
comment|// CHECK-LABEL: define i32 @f12
comment|// CHECK: ret i32 1
return|return
literal|1
operator|||
literal|1
return|;
block|}
end_function

begin_comment
comment|// Make sure negate of fp uses -0.0 for proper -0 handling.
end_comment

begin_function
name|double
name|f13
parameter_list|(
name|double
name|X
parameter_list|)
block|{
comment|// CHECK-LABEL: define double @f13
comment|// CHECK: fsub double -0.0
return|return
operator|-
name|X
return|;
block|}
end_function

begin_comment
comment|// Check operations on incomplete types.
end_comment

begin_function
name|void
name|f14
parameter_list|(
name|struct
name|s14
modifier|*
name|a
parameter_list|)
block|{
operator|(
name|void
operator|)
operator|&
operator|*
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f15
end_comment

begin_function
name|void
name|f15
parameter_list|()
block|{
specifier|extern
name|void
name|f15_start
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|f15_start
argument_list|()
expr_stmt|;
comment|// CHECK: call void @f15_start()
specifier|extern
name|void
modifier|*
name|f15_v
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|void
modifier|*
name|f15_cv
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
specifier|volatile
name|void
modifier|*
name|f15_vv
argument_list|(
name|void
argument_list|)
decl_stmt|;
operator|*
name|f15_v
argument_list|()
expr_stmt|;
operator|*
name|f15_v
argument_list|()
operator|,
operator|*
name|f15_v
argument_list|()
expr_stmt|;
name|f15_v
argument_list|()
condition|?
operator|*
name|f15_v
argument_list|()
else|:
operator|*
name|f15_v
argument_list|()
expr_stmt|;
operator|*
name|f15_cv
argument_list|()
expr_stmt|;
operator|*
name|f15_cv
argument_list|()
operator|,
operator|*
name|f15_cv
argument_list|()
expr_stmt|;
name|f15_cv
argument_list|()
condition|?
operator|*
name|f15_cv
argument_list|()
else|:
operator|*
name|f15_cv
argument_list|()
expr_stmt|;
operator|*
name|f15_vv
argument_list|()
expr_stmt|;
operator|*
name|f15_vv
argument_list|()
operator|,
operator|*
name|f15_vv
argument_list|()
expr_stmt|;
name|f15_vv
argument_list|()
condition|?
operator|*
name|f15_vv
argument_list|()
else|:
operator|*
name|f15_vv
argument_list|()
expr_stmt|;
comment|// CHECK-NOT: load
comment|// CHECK: ret void
block|}
end_function

begin_comment
comment|// PR8967: this was crashing
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f16()
end_comment

begin_function
name|void
name|f16
parameter_list|()
block|{
name|__extension__
argument_list|(
argument|{ goto lbl; }
argument_list|)
empty_stmt|;
name|lbl
label|:
empty_stmt|;
block|}
end_function

begin_comment
comment|// PR13704: negative increment in i128 is not preserved.
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f17()
end_comment

begin_function
name|void
name|f17
parameter_list|()
block|{
specifier|extern
name|void
name|extfunc
argument_list|(
name|__int128
argument_list|)
decl_stmt|;
name|__int128
name|x
init|=
literal|2
decl_stmt|;
name|x
operator|--
expr_stmt|;
name|extfunc
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: add nsw i128 %{{.}}, -1
block|}
end_function

end_unit

