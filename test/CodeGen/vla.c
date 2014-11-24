begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function_decl
name|int
name|b
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Extremely basic VLA test
end_comment

begin_function
name|void
name|a
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|char
name|arry
index|[
name|x
index|]
decl_stmt|;
name|arry
index|[
literal|0
index|]
operator|=
literal|10
expr_stmt|;
name|b
argument_list|(
name|arry
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|c
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|int
index|[
name|n
index|]
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|vla
index|[
name|x
index|]
decl_stmt|;
return|return
name|vla
index|[
name|x
operator|-
literal|1
index|]
return|;
block|}
end_function

begin_function
name|void
name|f
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|int
name|a
index|[
name|count
index|]
decl_stmt|;
do|do
block|{  }
do|while
condition|(
literal|0
condition|)
do|;
if|if
condition|(
name|a
index|[
literal|0
index|]
operator|!=
literal|3
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|g
parameter_list|(
name|int
name|count
parameter_list|)
block|{
comment|// Make sure we emit sizes correctly in some obscure cases
name|int
argument_list|(
operator|*
name|a
index|[
literal|5
index|]
argument_list|)
index|[
name|count
index|]
expr_stmt|;
name|int
argument_list|(
operator|*
name|b
argument_list|)
index|[]
index|[
name|count
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://8403108
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f_8403108
end_comment

begin_function
name|void
name|f_8403108
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
comment|// CHECK: call i8* @llvm.stacksave()
name|char
name|s1
index|[
name|x
index|]
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|// CHECK: call i8* @llvm.stacksave()
name|char
name|s2
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
literal|1
condition|)
break|break;
comment|// CHECK: call void @llvm.stackrestore(i8*
block|}
comment|// CHECK: call void @llvm.stackrestore(i8*
block|}
end_function

begin_comment
comment|// pr7827
end_comment

begin_function
name|void
name|function
parameter_list|(
name|short
name|width
parameter_list|,
name|int
name|data
index|[]
index|[
name|width
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note {{passing argument to parameter 'data' here}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|int
name|bork
index|[
literal|4
index|]
index|[
literal|13
index|]
decl_stmt|;
comment|// CHECK: call void @function(i16 signext 1, i32* null)
name|function
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @function(i16 signext 1, i32* inttoptr
name|function
argument_list|(
literal|1
argument_list|,
literal|0xbadbeef
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible integer to pointer conversion passing}}
comment|// CHECK: call void @function(i16 signext 1, i32* {{.*}})
name|function
argument_list|(
literal|1
argument_list|,
name|bork
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|function1
parameter_list|(
name|short
name|width
parameter_list|,
name|int
name|data
index|[]
index|[
name|width
index|]
index|[
name|width
index|]
parameter_list|)
block|{}
end_function

begin_function
name|void
name|test1
parameter_list|()
block|{
name|int
name|bork
index|[
literal|4
index|]
index|[
literal|13
index|]
index|[
literal|15
index|]
decl_stmt|;
comment|// CHECK: call void @function1(i16 signext 1, i32* {{.*}})
name|function1
argument_list|(
literal|1
argument_list|,
name|bork
argument_list|)
expr_stmt|;
comment|// CHECK: call void @function(i16 signext 1, i32* {{.*}})
name|function
argument_list|(
literal|1
argument_list|,
name|bork
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://8476159
end_comment

begin_decl_stmt
specifier|static
name|int
name|GLOB
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test2
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|GLOB
operator|=
literal|0
expr_stmt|;
name|char
name|b
index|[
literal|1
index|]
index|[
name|n
operator|+
literal|3
index|]
decl_stmt|;
comment|/* Variable length array.  */
comment|// CHECK:  [[tmp_1:%.*]] = load i32* @GLOB, align 4
comment|// CHECK-NEXT: add nsw i32 [[tmp_1]], 1
name|__typeof__
argument_list|(
argument|b[GLOB++]
argument_list|)
name|c
expr_stmt|;
return|return
name|GLOB
return|;
block|}
end_function

begin_comment
comment|// http://llvm.org/PR8567
end_comment

begin_comment
comment|// CHECK-LABEL: define double @test_PR8567
end_comment

begin_decl_stmt
name|double
name|test_PR8567
argument_list|(
name|int
name|n
argument_list|,
name|double
argument_list|(
operator|*
name|p
argument_list|)
index|[
name|n
index|]
index|[
literal|5
index|]
argument_list|)
block|{
comment|// CHECK:      [[NV:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[PV:%.*]] = alloca [5 x double]*, align 4
comment|// CHECK-NEXT: store
comment|// CHECK-NEXT: store
comment|// CHECK-NEXT: [[N:%.*]] = load i32* [[NV]], align 4
comment|// CHECK-NEXT: [[P:%.*]] = load [5 x double]** [[PV]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = mul nsw i32 1, [[N]]
comment|// CHECK-NEXT: [[T1:%.*]] = getelementptr inbounds [5 x double]* [[P]], i32 [[T0]]
comment|// CHECK-NEXT: [[T2:%.*]] = getelementptr inbounds [5 x double]* [[T1]], i32 2
comment|// CHECK-NEXT: [[T3:%.*]] = getelementptr inbounds [5 x double]* [[T2]], i32 0, i32 3
comment|// CHECK-NEXT: [[T4:%.*]] = load double* [[T3]]
comment|// CHECK-NEXT: ret double [[T4]]
return|return
name|p
index|[
literal|1
index|]
index|[
literal|2
index|]
index|[
literal|3
index|]
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|test4
argument_list|(
name|unsigned
name|n
argument_list|,
name|char
argument_list|(
operator|*
name|p
argument_list|)
index|[
name|n
index|]
index|[
name|n
operator|+
literal|1
index|]
index|[
literal|6
index|]
argument_list|)
block|{
comment|// CHECK-LABEL:    define i32 @test4(
comment|// CHECK:      [[N:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[P:%.*]] = alloca [6 x i8]*, align 4
comment|// CHECK-NEXT: [[P2:%.*]] = alloca [6 x i8]*, align 4
comment|// CHECK-NEXT: store i32
comment|// CHECK-NEXT: store [6 x i8]*
comment|// VLA captures.
comment|// CHECK-NEXT: [[DIM0:%.*]] = load i32* [[N]], align 4
comment|// CHECK-NEXT: [[T0:%.*]] = load i32* [[N]], align 4
comment|// CHECK-NEXT: [[DIM1:%.*]] = add i32 [[T0]], 1
comment|// CHECK-NEXT: [[T0:%.*]] = load [6 x i8]** [[P]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = load i32* [[N]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = udiv i32 [[T1]], 2
comment|// CHECK-NEXT: [[T3:%.*]] = mul nuw i32 [[DIM0]], [[DIM1]]
comment|// CHECK-NEXT: [[T4:%.*]] = mul nsw i32 [[T2]], [[T3]]
comment|// CHECK-NEXT: [[T5:%.*]] = getelementptr inbounds [6 x i8]* [[T0]], i32 [[T4]]
comment|// CHECK-NEXT: [[T6:%.*]] = load i32* [[N]], align 4
comment|// CHECK-NEXT: [[T7:%.*]] = udiv i32 [[T6]], 4
comment|// CHECK-NEXT: [[T8:%.*]] = sub i32 0, [[T7]]
comment|// CHECK-NEXT: [[T9:%.*]] = mul nuw i32 [[DIM0]], [[DIM1]]
comment|// CHECK-NEXT: [[T10:%.*]] = mul nsw i32 [[T8]], [[T9]]
comment|// CHECK-NEXT: [[T11:%.*]] = getelementptr inbounds [6 x i8]* [[T5]], i32 [[T10]]
comment|// CHECK-NEXT: store [6 x i8]* [[T11]], [6 x i8]** [[P2]], align 4
name|__typeof
argument_list|(
argument|p
argument_list|)
name|p2
operator|=
operator|(
name|p
operator|+
name|n
operator|/
literal|2
operator|)
operator|-
name|n
operator|/
literal|4
expr_stmt|;
comment|// CHECK-NEXT: [[T0:%.*]] = load [6 x i8]** [[P2]], align 4
comment|// CHECK-NEXT: [[T1:%.*]] = load [6 x i8]** [[P]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = ptrtoint [6 x i8]* [[T0]] to i32
comment|// CHECK-NEXT: [[T3:%.*]] = ptrtoint [6 x i8]* [[T1]] to i32
comment|// CHECK-NEXT: [[T4:%.*]] = sub i32 [[T2]], [[T3]]
comment|// CHECK-NEXT: [[T5:%.*]] = mul nuw i32 [[DIM0]], [[DIM1]]
comment|// CHECK-NEXT: [[T6:%.*]] = mul nuw i32 6, [[T5]]
comment|// CHECK-NEXT: [[T7:%.*]] = sdiv exact i32 [[T4]], [[T6]]
comment|// CHECK-NEXT: ret i32 [[T7]]
return|return
name|p2
operator|-
name|p
return|;
block|}
end_decl_stmt

begin_comment
comment|// rdar://11485774
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test5(
name|int
name|a
index|[
literal|5
index|]
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK: [[A:%.*]] = alloca [5 x i32], align 4
comment|// CHECK-NEXT: [[I:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[CL:%.*]] = alloca i32*, align 4
comment|// CHECK-NEXT: store i32 0, i32* [[I]], align 4
operator|(
name|typeof
argument_list|(
operator|++
name|i
argument_list|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
name|i
index|]
operator|)
name|a
argument_list|)
operator|)
block|{
operator|&
name|a
block|}
operator|+=
literal|0
expr_stmt|;
comment|// CHECK-NEXT: [[Z:%.*]] = load i32* [[I]], align 4
comment|// CHECK-NEXT: [[INC:%.*]]  = add nsw i32 [[Z]], 1
comment|// CHECK-NEXT: store i32 [[INC]], i32* [[I]], align 4
comment|// CHECK-NEXT: [[O:%.*]] = load i32* [[I]], align 4
comment|// CHECK-NEXT: [[AR:%.*]] = getelementptr inbounds [5 x i32]* [[A]], i32 0, i32 0
comment|// CHECK-NEXT: [[T:%.*]] = bitcast [5 x i32]* [[A]] to i32*
comment|// CHECK-NEXT: store i32* [[T]], i32** [[CL]]
comment|// CHECK-NEXT: [[TH:%.*]] = load i32** [[CL]]
comment|// CHECK-NEXT: [[VLAIX:%.*]] = mul nsw i32 0, [[O]]
comment|// CHECK-NEXT: [[ADDPTR:%.*]] = getelementptr inbounds i32* [[TH]], i32 [[VLAIX]]
comment|// CHECK-NEXT: store i32* [[ADDPTR]], i32** [[CL]]
block|}
end_function

begin_function
name|void
name|test6
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test6(
name|int
name|n
init|=
literal|20
decl_stmt|,
modifier|*
modifier|*
name|a
decl_stmt|,
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK: [[N:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[A:%.*]] = alloca i32**, align 4
comment|// CHECK-NEXT: [[I:%.*]] = alloca i32, align 4
operator|(
name|int
argument_list|(
operator|*
operator|*
argument_list|)
index|[
name|i
index|]
operator|)
block|{
operator|&
name|a
block|}
index|[
literal|0
index|]
index|[
literal|1
index|]
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
comment|// CHECK-NEXT: [[CL:%.*]] = alloca i32**, align 4
comment|// CHECK-NEXT: store i32 20, i32* [[N]], align 4
comment|// CHECK-NEXT: store i32 0, i32* [[I]], align 4
comment|// CHECK-NEXT: [[Z:%.*]] = load i32* [[I]], align 4
comment|// CHECK-NEXT: [[O:%.*]] = bitcast i32*** [[A]] to i32**
comment|// CHECK-NEXT: store i32** [[O]], i32*** [[CL]]
comment|// CHECK-NEXT: [[T:%.*]] = load i32*** [[CL]]
comment|// CHECK-NEXT: [[IX:%.*]] = getelementptr inbounds i32** [[T]], i32 0
comment|// CHECK-NEXT: [[TH:%.*]] = load i32** [[IX]], align 4
comment|// CHECK-NEXT: [[F:%.*]] = mul nsw i32 1, [[Z]]
comment|// CHECK-NEXT: [[IX1:%.*]] = getelementptr inbounds i32* [[TH]], i32 [[F]]
comment|// CHECK-NEXT: [[IX2:%.*]] = getelementptr inbounds i32* [[IX1]], i32 5
comment|// CHECK-NEXT: store i32 0, i32* [[IX2]], align 4
block|}
end_function

begin_comment
comment|// Follow gcc's behavior for VLAs in parameter lists.  PR9559.
end_comment

begin_function
name|void
name|test7
parameter_list|(
name|int
name|a
index|[
name|b
argument_list|(
literal|0
argument_list|)
index|]
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test7(
comment|// CHECK: call i32 @b(i8* null)
block|}
end_function

begin_comment
comment|// Make sure we emit dereferenceable or nonnull when the static keyword is
end_comment

begin_comment
comment|// provided.
end_comment

begin_function
name|void
name|test8
parameter_list|(
name|int
name|a
index|[
specifier|static
literal|3
index|]
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test8(i32* dereferenceable(12) %a)
end_comment

begin_function
name|void
name|test9
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|a
index|[
specifier|static
name|n
index|]
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test9(i32 %n, i32* nonnull %a)
end_comment

end_unit

