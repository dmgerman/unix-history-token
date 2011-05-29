begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmemdup.c -- Duplicate a memory buffer, using xcalloc.    This trivial function is in the public domain.    Jeff Garzik, September 1999.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement void* xmemdup (void *@var{input}, size_t @var{copy_size}, size_t @var{alloc_size})  Duplicates a region of memory without fail.  First, @var{alloc_size} bytes are allocated, then @var{copy_size} bytes from @var{input} are copied into it, and the new memory is returned.  If fewer bytes are copied than were allocated, the remaining memory is zeroed.  @end deftypefn  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* For size_t. */
end_comment

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

begin_function
name|PTR
name|xmemdup
parameter_list|(
specifier|const
name|PTR
name|input
parameter_list|,
name|size_t
name|copy_size
parameter_list|,
name|size_t
name|alloc_size
parameter_list|)
block|{
name|PTR
name|output
init|=
name|xcalloc
argument_list|(
literal|1
argument_list|,
name|alloc_size
argument_list|)
decl_stmt|;
return|return
operator|(
name|PTR
operator|)
name|memcpy
argument_list|(
name|output
argument_list|,
name|input
argument_list|,
name|copy_size
argument_list|)
return|;
block|}
end_function

end_unit

