begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of strchr()    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* strchr (const char *@var{s}, int @var{c})  Returns a pointer to the first occurrence of the character @var{c} in the string @var{s}, or @code{NULL} if not found.  If @var{c} is itself the null character, the results are undefined.  @end deftypefn  */
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
specifier|register
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
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

