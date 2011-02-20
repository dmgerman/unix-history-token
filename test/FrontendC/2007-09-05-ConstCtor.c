begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc -Os -S %s -o /dev/null
end_comment

begin_comment
comment|// PR1641
end_comment

begin_struct
struct|struct
name|A
block|{
name|unsigned
name|long
name|l
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|bar
parameter_list|(
name|struct
name|A
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bork
parameter_list|()
block|{
specifier|const
name|unsigned
name|long
name|vcgt
init|=
literal|1234
decl_stmt|;
name|struct
name|A
name|a
init|=
block|{
name|vcgt
block|}
decl_stmt|;
name|bar
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

