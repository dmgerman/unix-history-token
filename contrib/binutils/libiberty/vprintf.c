begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  @deftypefn Supplemental int vprintf (const char *@var{format}, va_list @var{ap}) @deftypefnx Supplemental int vfprintf (FILE *@var{stream}, const char *@var{format}, va_list @var{ap}) @deftypefnx Supplemental int vsprintf (char *@var{str}, const char *@var{format}, va_list @var{ap})  These functions are the same as @code{printf}, @code{fprintf}, and @code{sprintf}, respectively, except that they are called with a @code{va_list} instead of a variable number of arguments.  Note that they do not call @code{va_end}; this is the application's responsibility.  In @libib{} they are implemented in terms of the nonstandard but common function @code{_doprnt}.  @end deftypefn  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_undef
undef|#
directive|undef
name|vprintf
end_undef

begin_function
name|int
name|vprintf
parameter_list|(
name|format
parameter_list|,
name|ap
parameter_list|)
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
return|return
name|vfprintf
argument_list|(
name|stdout
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
return|;
block|}
end_function

end_unit

