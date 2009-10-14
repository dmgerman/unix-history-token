begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -emit-llvm -o %t&&
end_comment

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|g
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|g
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|g
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// rdar://6110827
end_comment

begin_typedef
typedef|typedef
name|void
name|T
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|T
name|f
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|int
name|a
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// RUN: grep 'define void @f0()' %t&&
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// RUN: grep 'call void @f1()' %t&&
end_comment

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|f1
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: grep 'define void @f1()' %t&&
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{}
end_function

begin_comment
comment|// RUN: grep 'define .* @f3' %t | not grep -F '...'
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|X
decl_stmt|,
name|Y
decl_stmt|,
name|Z
decl_stmt|;
block|}
name|f3
argument_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// PR4423 - This shouldn't crash in codegen
name|void
name|f4
argument_list|()
block|{}
name|void
name|f5
argument_list|()
block|{
name|f4
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
end_struct

end_unit

