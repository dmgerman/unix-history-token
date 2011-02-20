begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -O3 -S -o -
end_comment

begin_comment
comment|// PR1175
end_comment

begin_struct
struct|struct
name|empty
block|{ }
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|(
name|struct
name|empty
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|++
expr_stmt|;
block|}
end_function

end_unit

