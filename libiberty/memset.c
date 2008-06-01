begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memset    This implementation is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void* memset (void *@var{s}, int @var{c}, size_t @var{count})  Sets the first @var{count} bytes of @var{s} to the constant byte @var{c}, returning a pointer to @var{s}.  @end deftypefn  */
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

begin_function
name|PTR
name|memset
parameter_list|(
name|PTR
name|dest
parameter_list|,
specifier|register
name|int
name|val
parameter_list|,
specifier|register
name|size_t
name|len
parameter_list|)
block|{
specifier|register
name|unsigned
name|char
modifier|*
name|ptr
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|dest
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
operator|*
name|ptr
operator|++
operator|=
name|val
expr_stmt|;
return|return
name|dest
return|;
block|}
end_function

end_unit

