begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bcmp    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int bcmp (char *@var{x}, char *@var{y}, int @var{count})  Compares the first @var{count} bytes of two areas of memory.  Returns zero if they are the same, nonzero otherwise.  Returns zero if @var{count} is zero.  A nonzero result only indicates a difference, it does not indicate any sorting order (say, by having a positive result mean @var{x} sorts before @var{y}).  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
specifier|extern
name|int
name|memcmp
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|bcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function

end_unit

