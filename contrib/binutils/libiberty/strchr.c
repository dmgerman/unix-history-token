begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of strchr()    This function is in the public domain.  */
end_comment

begin_comment
comment|/* NAME 	strchr -- return pointer to first occurance of a character  SYNOPSIS 	char *strchr (const char *s, int c)  DESCRIPTION 	Returns a pointer to the first occurance of character C in 	string S, or a NULL pointer if no occurance is found. 	 BUGS 	Behavior when character is the null character is implementation 	dependent. */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_function
name|char
modifier|*
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|register
name|CONST
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
do|do
block|{
if|if
condition|(
operator|*
name|s
operator|==
name|c
condition|)
block|{
return|return
operator|(
name|char
operator|*
operator|)
name|s
return|;
block|}
block|}
do|while
condition|(
operator|*
name|s
operator|++
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

