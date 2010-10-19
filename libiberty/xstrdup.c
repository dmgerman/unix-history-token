begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xstrdup.c -- Duplicate a string in memory, using xmalloc.    This trivial function is in the public domain.    Ian Lance Taylor, Cygnus Support, December 1995.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement char* xstrdup (const char *@var{s})  Duplicates a character string without fail, using @code{xmalloc} to obtain memory.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
specifier|register
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
decl_stmt|;
specifier|register
name|char
modifier|*
name|ret
init|=
name|XNEWVEC
argument_list|(
name|char
argument_list|,
name|len
argument_list|)
decl_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|memcpy
argument_list|(
name|ret
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

end_unit

