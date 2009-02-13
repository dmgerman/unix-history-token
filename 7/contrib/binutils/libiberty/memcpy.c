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

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
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

begin_decl_stmt
name|void
name|bcopy
name|PARAMS
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|PTR
name|memcpy
parameter_list|(
name|out
parameter_list|,
name|in
parameter_list|,
name|length
parameter_list|)
name|PTR
name|out
decl_stmt|;
specifier|const
name|PTR
name|in
decl_stmt|;
name|size_t
name|length
decl_stmt|;
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

