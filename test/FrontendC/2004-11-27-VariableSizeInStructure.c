begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o /dev/null
end_comment

begin_comment
comment|// GCC allows variable sized arrays in structures, crazy!
end_comment

begin_comment
comment|// This is PR360.
end_comment

begin_function
name|int
name|sub1
parameter_list|(
name|int
name|i
parameter_list|,
name|char
modifier|*
name|pi
parameter_list|)
block|{
typedef|typedef
name|int
name|foo
index|[
name|i
index|]
typedef|;
struct|struct
name|bar
block|{
name|foo
name|f1
decl_stmt|;
name|int
name|f2
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
expr|struct
name|bar
operator|*
operator|)
name|pi
struct|;
return|return
name|p
operator|->
name|f2
return|;
block|}
end_function

end_unit

