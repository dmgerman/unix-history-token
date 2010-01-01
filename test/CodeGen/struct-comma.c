begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|x
struct|;
end_struct

begin_function
name|void
name|a
parameter_list|(
name|struct
name|S
modifier|*
name|b
parameter_list|)
block|{
operator|*
name|b
operator|=
operator|(
name|r
argument_list|()
operator|,
name|x
operator|)
expr_stmt|;
block|}
end_function

end_unit

