begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure of a symbol table entry  */
end_comment

begin_struct
struct|struct
name|symbol
block|{
name|char
name|sy_name
index|[
literal|8
index|]
decl_stmt|;
name|char
name|sy_type
decl_stmt|;
name|int
name|sy_value
decl_stmt|;
block|}
struct|;
end_struct

end_unit

