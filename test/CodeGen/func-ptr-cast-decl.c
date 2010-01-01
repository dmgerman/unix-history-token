begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm-only %s -verify
end_comment

begin_comment
comment|// PR5882
end_comment

begin_function_decl
name|int
name|q_sk_num
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|a
parameter_list|()
block|{
operator|(
operator|(
name|fptr
operator|)
name|q_sk_num
operator|)
operator|(
literal|0
operator|)
expr_stmt|;
block|}
end_function

end_unit

