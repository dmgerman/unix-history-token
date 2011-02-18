begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memory allocation routines with error checking.    Copyright 1989, 90, 91, 92, 93, 94 Free Software Foundation, Inc.     This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement void* xmalloc (size_t)  Allocate memory without fail.  If @code{malloc} fails, this will print a message to @code{stderr} (using the name set by @code{xmalloc_set_program_name}, if any) and then call @code{xexit}.  Note that it is therefore safe for a program to contain @code{#define malloc xmalloc} in its source.  @end deftypefn  @deftypefn Replacement void* xrealloc (void *@var{ptr}, size_t @var{size}) Reallocate memory without fail.  This routine functions like @code{realloc}, but will behave the same as @code{xmalloc} if memory cannot be found.  @end deftypefn  @deftypefn Replacement void* xcalloc (size_t @var{nelem}, size_t @var{elsize})  Allocate memory without fail, and set it to zero.  This routine functions like @code{calloc}, but will behave the same as @code{xmalloc} if memory cannot be found.  @end deftypefn  @deftypefn Replacement void xmalloc_set_program_name (const char *@var{name})  You can use this to set the name of the program used by @code{xmalloc_failed} when printing a failure message.  @end deftypefn  @deftypefn Replacement void xmalloc_failed (size_t)  This function is not meant to be called by client code, and is listed here for completeness only.  If any of the allocation routines fail, this function will be called to print an error message and terminate execution.  @end deftypefn  */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
name|VMS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unixlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* For systems with larger pointers than ints, these must be declared.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
operator|&&
name|HAVE_UNISTD_H
operator|&&
name|HAVE_DECL_MALLOC
expr|\
operator|&&
name|HAVE_DECL_REALLOC
operator|&&
name|HAVE_DECL_CALLOC
operator|&&
name|HAVE_DECL_SBRK
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
modifier|*
name|sbrk
parameter_list|(
name|ptrdiff_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H ...  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* The program name if set.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|name
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SBRK
end_ifdef

begin_comment
comment|/* The initial sbrk, set when the program name is set. Not used for win32    ports other than cygwin32.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|first_break
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SBRK */
end_comment

begin_function
name|void
name|xmalloc_set_program_name
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|name
operator|=
name|s
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SBRK
comment|/* Win32 ports other than cygwin32 don't have brk() */
if|if
condition|(
name|first_break
operator|==
name|NULL
condition|)
name|first_break
operator|=
operator|(
name|char
operator|*
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SBRK */
block|}
end_function

begin_function
name|void
name|xmalloc_failed
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_SBRK
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
name|size_t
name|allocated
decl_stmt|;
if|if
condition|(
name|first_break
operator|!=
name|NULL
condition|)
name|allocated
operator|=
operator|(
name|char
operator|*
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
operator|-
name|first_break
expr_stmt|;
else|else
name|allocated
operator|=
operator|(
name|char
operator|*
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
operator|-
operator|(
name|char
operator|*
operator|)
operator|&
name|environ
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s%sout of memory allocating %lu bytes after a total of %lu bytes\n"
argument_list|,
name|name
argument_list|,
operator|*
name|name
condition|?
literal|": "
else|:
literal|""
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|size
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|allocated
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* HAVE_SBRK */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s%sout of memory allocating %lu bytes\n"
argument_list|,
name|name
argument_list|,
operator|*
name|name
condition|?
literal|": "
else|:
literal|""
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SBRK */
name|xexit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|PTR
name|xmalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|PTR
name|newmem
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
condition|)
name|size
operator|=
literal|1
expr_stmt|;
name|newmem
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|newmem
condition|)
name|xmalloc_failed
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|newmem
operator|)
return|;
block|}
end_function

begin_function
name|PTR
name|xcalloc
parameter_list|(
name|size_t
name|nelem
parameter_list|,
name|size_t
name|elsize
parameter_list|)
block|{
name|PTR
name|newmem
decl_stmt|;
if|if
condition|(
name|nelem
operator|==
literal|0
operator|||
name|elsize
operator|==
literal|0
condition|)
name|nelem
operator|=
name|elsize
operator|=
literal|1
expr_stmt|;
name|newmem
operator|=
name|calloc
argument_list|(
name|nelem
argument_list|,
name|elsize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|newmem
condition|)
name|xmalloc_failed
argument_list|(
name|nelem
operator|*
name|elsize
argument_list|)
expr_stmt|;
return|return
operator|(
name|newmem
operator|)
return|;
block|}
end_function

begin_function
name|PTR
name|xrealloc
parameter_list|(
name|PTR
name|oldmem
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|PTR
name|newmem
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
condition|)
name|size
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|oldmem
condition|)
name|newmem
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
else|else
name|newmem
operator|=
name|realloc
argument_list|(
name|oldmem
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|newmem
condition|)
name|xmalloc_failed
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|newmem
operator|)
return|;
block|}
end_function

end_unit

