begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)lastpart.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******  *	char *  *	lastpart(file)	find last part of file name  *	char *file;  *  *	return - pointer to last part  */
end_comment

begin_function
name|char
modifier|*
name|lastpart
parameter_list|(
name|file
parameter_list|)
specifier|register
name|char
modifier|*
name|file
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|c
decl_stmt|;
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
name|c
operator|=
name|rindex
argument_list|(
name|file
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
condition|)
return|return
name|c
operator|+
literal|1
return|;
else|else
return|return
name|file
return|;
block|}
end_function

end_unit

