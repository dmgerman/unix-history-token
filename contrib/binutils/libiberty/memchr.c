begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  @deftypefn Supplemental void* memchr (const void *@var{s}, int @var{c}, size_t @var{n})  This function searches memory starting at @code{*@var{s}} for the character @var{c}.  The search only ends with the first occurrence of @var{c}, or after @var{length} characters; in particular, a null character does not terminate the search.  If the character @var{c} is found within @var{length} characters of @code{*@var{s}}, a pointer to the character is returned.  If @var{c} is not found, then @code{NULL} is returned.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|PTR
name|memchr
parameter_list|(
name|src_void
parameter_list|,
name|c
parameter_list|,
name|length
parameter_list|)
specifier|register
specifier|const
name|PTR
name|src_void
decl_stmt|;
name|int
name|c
decl_stmt|;
name|size_t
name|length
decl_stmt|;
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|src
init|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|src_void
decl_stmt|;
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|src
operator|==
name|c
condition|)
return|return
operator|(
name|PTR
operator|)
name|src
return|;
name|src
operator|++
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

end_unit

