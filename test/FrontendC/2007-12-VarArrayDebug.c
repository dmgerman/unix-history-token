begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -g -O %s -o - | llc
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -g %s -o - | llc
end_comment

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|baz
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|foo
argument_list|()
expr_stmt|;
typedef|typedef
name|char
name|A
index|[
name|i
index|]
typedef|;
struct|struct
block|{
name|A
name|b
decl_stmt|;
block|}
modifier|*
name|x
init|=
literal|0
struct|;
block|}
end_function

begin_function
name|void
name|bar
parameter_list|(
name|i
parameter_list|)
block|{
name|baz
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

