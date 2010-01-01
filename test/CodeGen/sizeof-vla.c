begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o %t %s
end_comment

begin_comment
comment|// PR3442
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|g
parameter_list|(
name|unsigned
name|long
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|unsigned
name|begin_set
index|[
name|n
index|]
decl_stmt|;
name|g
argument_list|(
sizeof|sizeof
argument_list|(
name|begin_set
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

