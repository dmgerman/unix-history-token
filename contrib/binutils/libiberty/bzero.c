begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of bzero for systems without it.    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void bzero (char *@var{mem}, int @var{count})  Zeros @var{count} bytes starting at @var{mem}.  Use of this function is deprecated in favor of @code{memset}.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
specifier|extern
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bzero
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
name|memset
argument_list|(
name|to
argument_list|,
literal|0
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

