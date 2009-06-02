begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o -
end_comment

begin_function
name|char
name|p
parameter_list|(
name|int
name|n
parameter_list|)
block|{
struct|struct
name|f
block|{
name|char
name|w
decl_stmt|;
name|char
name|x
index|[
name|n
index|]
decl_stmt|;
name|char
name|y
index|[
name|n
index|]
decl_stmt|;
block|}
name|F
struct|;
return|return
name|F
operator|.
name|x
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

