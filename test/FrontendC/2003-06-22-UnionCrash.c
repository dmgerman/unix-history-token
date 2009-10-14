begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|Blend_Map_Entry
block|{
union|union
block|{
name|float
name|Colour
index|[
literal|5
index|]
decl_stmt|;
name|double
name|Point_Slope
index|[
literal|2
index|]
decl_stmt|;
block|}
name|Vals
union|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Blend_Map_Entry
modifier|*
name|Foo
parameter_list|)
block|{ }
end_function

end_unit

