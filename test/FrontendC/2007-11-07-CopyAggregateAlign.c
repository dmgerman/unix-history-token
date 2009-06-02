begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep "align 2" | count 6
end_comment

begin_struct
struct|struct
name|A
block|{
name|char
name|s
decl_stmt|,
name|t
decl_stmt|,
name|u
decl_stmt|,
name|v
decl_stmt|;
name|short
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|q
parameter_list|()
block|{
name|struct
name|A
name|a
decl_stmt|,
name|b
decl_stmt|;
name|a
operator|=
name|b
expr_stmt|;
block|}
end_function

end_unit

