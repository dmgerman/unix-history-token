begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep {getelementptr inbounds \\\[0 x i32\\\]}
end_comment

begin_function_decl
specifier|extern
name|void
name|f
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|e
parameter_list|(
name|int
name|m
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|int
name|x
index|[
name|n
index|]
decl_stmt|;
name|f
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|x
index|[
name|m
index|]
return|;
block|}
end_function

end_unit

