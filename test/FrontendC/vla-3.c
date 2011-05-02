begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -std=gnu99 %s -S -o - | grep ".*alloca.*align 16"
end_comment

begin_function_decl
name|void
name|adr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|vlaalign
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|char
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|tmp
index|[
name|size
operator|+
literal|32
index|]
decl_stmt|;
name|char
name|tmp2
index|[
name|size
operator|+
literal|16
index|]
decl_stmt|;
name|adr
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

