begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -std=gnu89 -triple i386-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix GNU89 %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -std=c99 -triple i386-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix C99 %s
end_comment

begin_comment
comment|// CHECK-GNU89: define i32 @f0()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f0()
end_comment

begin_function_decl
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f1()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f1()
end_comment

begin_function_decl
specifier|inline
name|int
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f2()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f2()
end_comment

begin_function_decl
name|int
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|int
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f3()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f3()
end_comment

begin_function_decl
specifier|extern
specifier|inline
name|int
name|f3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f5()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f5()
end_comment

begin_function_decl
specifier|extern
specifier|inline
name|int
name|f5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|int
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f6()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f6()
end_comment

begin_function_decl
specifier|inline
name|int
name|f6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|extern
specifier|inline
name|int
name|f6
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @f7()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f7()
end_comment

begin_function_decl
specifier|extern
specifier|inline
name|int
name|f7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|extern
name|int
name|f7
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define i32 @fA()
end_comment

begin_function
specifier|inline
name|int
name|fA
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define available_externally i32 @f4()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f4()
end_comment

begin_function_decl
name|int
name|f4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|extern
specifier|inline
name|int
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define available_externally i32 @f8()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f8()
end_comment

begin_function_decl
specifier|extern
name|int
name|f8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|extern
specifier|inline
name|int
name|f8
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-GNU89: define available_externally i32 @f9()
end_comment

begin_comment
comment|// CHECK-C99: define i32 @f9()
end_comment

begin_function_decl
specifier|extern
specifier|inline
name|int
name|f9
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|extern
specifier|inline
name|int
name|f9
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-C99: define available_externally i32 @fA()
end_comment

begin_function
name|int
name|test_all
parameter_list|()
block|{
return|return
name|f0
argument_list|()
operator|+
name|f1
argument_list|()
operator|+
name|f2
argument_list|()
operator|+
name|f3
argument_list|()
operator|+
name|f4
argument_list|()
operator|+
name|f5
argument_list|()
operator|+
name|f6
argument_list|()
operator|+
name|f7
argument_list|()
operator|+
name|f8
argument_list|()
operator|+
name|f9
argument_list|()
operator|+
name|fA
argument_list|()
return|;
block|}
end_function

end_unit

