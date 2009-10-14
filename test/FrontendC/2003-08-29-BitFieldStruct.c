begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|Word
block|{
name|short
name|bar
decl_stmt|;
name|short
name|baz
decl_stmt|;
name|int
name|final
range|:
literal|1
decl_stmt|;
name|short
name|quux
decl_stmt|;
block|}
modifier|*
name|word_limit
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
name|word_limit
operator|->
name|final
operator|=
operator|(
name|word_limit
operator|->
name|final
operator|&&
name|word_limit
operator|->
name|final
operator|)
expr_stmt|;
block|}
end_function

end_unit

