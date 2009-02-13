begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memcpy (the standard C function)    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void* memcpy (void *@var{out}, const void *@var{in}, size_t @var{length})  Copies @var{length} bytes from memory region @var{in} to region @var{out}.  Returns a pointer to @var{out}.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
name|void
name|bcopy
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|PTR
name|memcpy
parameter_list|(
name|PTR
name|out
parameter_list|,
specifier|const
name|PTR
name|in
parameter_list|,
name|size_t
name|length
parameter_list|)
block|{
name|bcopy
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_function

end_unit

