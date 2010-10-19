begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stub implementation of (obsolete) index(). */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* index (char *@var{s}, int @var{c})  Returns a pointer to the first occurrence of the character @var{c} in the string @var{s}, or @code{NULL} if not found.  The use of @code{index} is deprecated in new programs in favor of @code{strchr}.  @end deftypefn  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|index
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|strchr
argument_list|(
name|s
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

end_unit

