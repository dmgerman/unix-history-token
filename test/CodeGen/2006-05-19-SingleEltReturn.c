begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test returning a single element aggregate value containing a double.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|X
block|{
name|double
name|D
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|struct
name|X
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|Y
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|struct
name|Y
modifier|*
name|P
parameter_list|)
block|{
operator|*
name|P
operator|=
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|struct
name|Y
name|bar
parameter_list|()
block|{
name|struct
name|Y
name|a
decl_stmt|;
name|a
operator|.
name|x
operator|.
name|D
operator|=
literal|0
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

