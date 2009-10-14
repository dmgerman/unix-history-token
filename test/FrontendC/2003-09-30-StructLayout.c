begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_enum
enum|enum
name|En
block|{
name|ENUM_VAL
block|}
enum|;
end_enum

begin_struct
struct|struct
name|St
block|{
name|unsigned
name|char
name|A
decl_stmt|;
name|enum
name|En
name|B
decl_stmt|;
name|unsigned
name|char
name|C
decl_stmt|;
name|enum
name|En
name|D
decl_stmt|;
name|float
name|E
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|func
parameter_list|(
name|struct
name|St
modifier|*
name|A
parameter_list|)
block|{
name|A
operator|->
name|D
operator|=
name|ENUM_VAL
expr_stmt|;
block|}
end_function

end_unit

