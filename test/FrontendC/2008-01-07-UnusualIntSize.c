begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - -O | grep i33
end_comment

begin_comment
comment|// PR1721
end_comment

begin_struct
struct|struct
name|s
block|{
name|unsigned
name|long
name|long
name|u33
range|:
literal|33
decl_stmt|;
block|}
name|a
struct|,
name|b
struct|;
end_struct

begin_comment
comment|// This should turn into a real 33-bit add, not a 64-bit add.
end_comment

begin_function
name|_Bool
name|test
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|a
operator|.
name|u33
operator|+
name|b
operator|.
name|u33
operator|!=
literal|0
return|;
block|}
end_function

end_unit

