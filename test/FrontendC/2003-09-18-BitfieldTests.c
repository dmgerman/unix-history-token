begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -w -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BF
block|{
name|int
name|A
range|:
literal|1
decl_stmt|;
name|char
name|B
decl_stmt|;
name|int
name|C
range|:
literal|13
decl_stmt|;
block|}
name|BF
typedef|;
end_typedef

begin_function
name|char
modifier|*
name|test1
parameter_list|(
name|BF
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|&
name|b
operator|->
name|B
return|;
comment|// Must be able to address non-bitfield
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|BF
modifier|*
name|b
parameter_list|)
block|{
comment|// Increment and decrement operators
name|b
operator|->
name|A
operator|++
expr_stmt|;
operator|--
name|b
operator|->
name|C
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|BF
modifier|*
name|b
parameter_list|)
block|{
name|b
operator|->
name|C
operator|=
literal|12345
expr_stmt|;
comment|// Store
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
name|BF
modifier|*
name|b
parameter_list|)
block|{
return|return
name|b
operator|->
name|C
return|;
comment|// Load
block|}
end_function

begin_function
name|void
name|test5
parameter_list|(
name|BF
modifier|*
name|b
parameter_list|,
name|int
name|i
parameter_list|)
block|{
comment|// array ref
name|b
index|[
name|i
index|]
operator|.
name|C
operator|=
literal|12345
expr_stmt|;
block|}
end_function

end_unit

