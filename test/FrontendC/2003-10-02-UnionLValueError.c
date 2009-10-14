begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_union
union|union
name|U
block|{
name|int
name|i
index|[
literal|8
index|]
decl_stmt|;
name|char
name|s
index|[
literal|80
index|]
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|format_message
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|union
name|U
modifier|*
name|u
parameter_list|)
block|{
name|sprintf
argument_list|(
name|buffer
argument_list|,
name|u
operator|->
name|s
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

