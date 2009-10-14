begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|printf_spec
block|{
name|unsigned
name|int
name|minus_flag
range|:
literal|1
decl_stmt|;
name|char
name|converter
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|parse_doprnt_spec
parameter_list|()
block|{
name|struct
name|printf_spec
name|spec
decl_stmt|;
name|spec
operator|.
name|minus_flag
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

