begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of strrchr().    This function is in the public domain. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* strrchr (const char *@var{s}, int @var{c})  Returns a pointer to the last occurrence of the character @var{c} in the string @var{s}, or @code{NULL} if not found.  If @var{c} is itself the null character, the results are undefined.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_function
name|char
modifier|*
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|register
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
name|char
modifier|*
name|rtnval
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|*
name|s
operator|==
name|c
condition|)
name|rtnval
operator|=
operator|(
name|char
operator|*
operator|)
name|s
expr_stmt|;
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
name|rtnval
operator|)
return|;
block|}
end_function

end_unit

