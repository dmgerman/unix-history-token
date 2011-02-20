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
comment|// CHECK: define void @f_8403108
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
comment|// CHECK: define double @test_PR8567
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
comment|// CHECK: store [[vla_type:.*]] %p,
comment|// CHECK: load i32*
comment|// CHECK-NEXT: mul i32 40
comment|// CHECK-NEXT: [[byte_idx:%.*]] = mul i32 1
comment|// CHECK-NEXT: [[tmp_1:%.*]] = load [[vla_type]]*
comment|// CHECK-NEXT: [[tmp_2:%.*]] = bitcast [[vla_type]] [[tmp_1]] to i8*
comment|// CHECK-NEXT: [[idx:%.*]] = getelementptr inbounds i8* [[tmp_2]], i32 [[byte_idx]]
comment|// CHECK-NEXT: bitcast i8* [[idx]] to [[vla_type]]
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

end_unit

