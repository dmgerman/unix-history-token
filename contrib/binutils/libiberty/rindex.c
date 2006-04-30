begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stub implementation of (obsolete) rindex(). */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* rindex (const char *@var{s}, int @var{c})  Returns a pointer to the last occurrence of the character @var{c} in the string @var{s}, or @code{NULL} if not found.  The use of @code{rindex} is deprecated in new programs in favor of @code{strrchr}.  @end deftypefn  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|rindex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
return|return
name|strrchr
argument_list|(
name|s
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

end_unit

