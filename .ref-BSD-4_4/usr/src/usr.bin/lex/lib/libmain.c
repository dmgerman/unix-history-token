begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libmain - flex run-time support library "main" function */
end_comment

begin_comment
comment|/* $Header: /usr/fsys/odin/a/vern/flex/RCS/libmain.c,v 1.2 90/05/26 16:50:08 vern Exp $ */
end_comment

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
return|return
name|yylex
argument_list|()
return|;
block|}
end_function

end_unit

