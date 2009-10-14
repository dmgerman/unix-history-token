begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|_GIOChannel
block|{
name|int
name|write_buf
decl_stmt|;
name|char
name|partial_write_buf
index|[
literal|6
index|]
decl_stmt|;
name|int
name|d
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|g_io_channel_init
parameter_list|(
name|struct
name|_GIOChannel
modifier|*
name|channel
parameter_list|)
block|{
name|channel
operator|->
name|partial_write_buf
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

end_unit

