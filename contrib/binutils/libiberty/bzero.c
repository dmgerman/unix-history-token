begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of bzero for systems without it.    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void bzero (char *@var{mem}, int @var{count})  Zeros @var{count} bytes starting at @var{mem}.  Use of this function is deprecated in favor of @code{memset}.  @end deftypefn  */
end_comment

begin_function
name|void
name|bzero
parameter_list|(
name|to
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|to
decl_stmt|;
name|int
name|count
decl_stmt|;
block|{
while|while
condition|(
name|count
operator|--
operator|>
literal|0
condition|)
block|{
operator|*
name|to
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

end_unit

