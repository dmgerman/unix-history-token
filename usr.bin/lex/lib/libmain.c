begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libmain - flex run-time support library "main" function */
end_comment

begin_comment
comment|/* $Header: /home/daffy/u0/vern/flex/RCS/libmain.c,v 1.4 95/09/27 12:47:55 vern Exp $  * $FreeBSD$ */
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
while|while
condition|(
name|yylex
argument_list|()
operator|!=
literal|0
condition|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

