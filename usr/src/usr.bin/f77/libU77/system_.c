begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_system[] = "@(#)system_.c	1.1";  *  * execute a unix command  *  * calling sequence:  *	iexit = system(command)  * where:  *	iexit will return the exit status of the command  *	command is a character string containing the command to be executed  */
end_comment

begin_function
name|long
name|system_
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|long
name|n
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|system
argument_list|(
name|s
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

