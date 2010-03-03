begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -emit-llvm -std=gnu89 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR5253
end_comment

begin_comment
comment|// If an extern inline function is redefined, functions should call the
end_comment

begin_comment
comment|// redefinition.
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|g
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call i32 @f
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|b
parameter_list|)
block|{
return|return
literal|1
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK: load i32* %{{.*}}
end_comment

begin_comment
comment|// CHECK: add nsw i32 1, %{{.*}}
end_comment

begin_function
name|int
name|h
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call i32 @f
end_comment

begin_comment
comment|// It shouldn't matter if the function was redefined static.
end_comment

begin_function
specifier|extern
specifier|inline
name|int
name|f2
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|int
name|g2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f2
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call i32 @f2
end_comment

begin_function
specifier|static
name|int
name|f2
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK: load i32* %{{.*}}
end_comment

begin_comment
comment|// CHECK: load i32* %{{.*}}
end_comment

begin_comment
comment|// CHECK: mul i32 %{{.*}}, %{{.*}}
end_comment

begin_function
name|int
name|h2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|f2
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call i32 @f2
end_comment

end_unit

