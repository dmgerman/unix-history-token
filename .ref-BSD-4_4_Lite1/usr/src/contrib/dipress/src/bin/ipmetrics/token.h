begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983     Lee Moore  */
end_comment

begin_struct
struct|struct
name|TokenState
block|{
name|FILE
modifier|*
name|Input
decl_stmt|;
name|int
name|LastTokenInLine
decl_stmt|;
name|int
name|NotEndOfFile
decl_stmt|;
name|int
name|CurChar
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|TokenState
modifier|*
name|InitTokenStream
parameter_list|()
function_decl|;
end_function_decl

end_unit

