begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test multiple_decls.c
end_comment

begin_struct
struct|struct
name|wide
block|{
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|wide
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|narrow
block|{
name|char
name|narrow
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|char
name|narrow
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

