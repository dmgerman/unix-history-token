begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Wrapper to implement ANSI C's memmove using BSD's bcopy. */
end_comment

begin_comment
comment|/* This function is in the public domain.  --Per Bothner. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void* memmove (void *@var{from}, const void *@var{to}, size_t @var{count})  Copies @var{count} bytes from memory area @var{from} to memory area @var{to}, returning a pointer to @var{to}.  @end deftypefn  */
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
name|memmove
parameter_list|(
name|PTR
name|s1
parameter_list|,
specifier|const
name|PTR
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|bcopy
argument_list|(
name|s2
argument_list|,
name|s1
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|s1
return|;
block|}
end_function

end_unit

