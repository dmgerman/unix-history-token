begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|op
decl_stmt|;
block|}
name|event_t
typedef|;
end_typedef

begin_function
name|event_t
name|test
parameter_list|(
name|int
name|X
parameter_list|)
block|{
name|event_t
name|foo
init|=
block|{
literal|1
block|}
decl_stmt|,
name|bar
init|=
block|{
literal|2
block|}
decl_stmt|;
return|return
name|X
condition|?
name|foo
else|:
name|bar
return|;
block|}
end_function

end_unit

