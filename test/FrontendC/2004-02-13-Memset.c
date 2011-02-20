begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep llvm.memset | count 3
end_comment

begin_function_decl
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|(
name|void
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|int
modifier|*
name|X
parameter_list|,
name|char
modifier|*
name|Y
parameter_list|)
block|{
name|memset
argument_list|(
name|X
argument_list|,
literal|4
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|Y
argument_list|,
literal|100
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

