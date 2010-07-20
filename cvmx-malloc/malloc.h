begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2001 Wolfram Gloger Copyright (c) 2006 Cavium networks  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that (i) the above copyright notices and this permission notice appear in all copies of the software and related documentation, and (ii) the name of Wolfram Gloger may not be used in any advertising or publicity relating to the software.  THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL WOLFRAM GLOGER BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|_MALLOC_H
value|1
end_define

begin_undef
undef|#
directive|undef
name|_LIBC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   $Id: malloc.h 30481 2007-12-05 21:46:59Z rfranz $   `ptmalloc2', a malloc implementation for multiple threads without   lock contention, by Wolfram Gloger<wg@malloc.de>.    VERSION 2.7.0    This work is mainly derived from malloc-2.7.0 by Doug Lea<dl@cs.oswego.edu>, which is available from:                   ftp://gee.cs.oswego.edu/pub/misc/malloc.c    This trimmed-down header file only provides function prototypes and   the exported data structures.  For more detailed function   descriptions and compile-time options, see the source file   `malloc.c'. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|__malloc_ptr_t
value|void *
end_define

begin_undef
undef|#
directive|undef
name|size_t
end_undef

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_undef
undef|#
directive|undef
name|ptrdiff_t
end_undef

begin_define
define|#
directive|define
name|ptrdiff_t
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|Void_t
end_undef

begin_define
define|#
directive|define
name|Void_t
value|void
end_define

begin_define
define|#
directive|define
name|__malloc_ptr_t
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_comment
comment|/* Used by GNU libc internals. */
end_comment

begin_define
define|#
directive|define
name|__malloc_size_t
value|size_t
end_define

begin_define
define|#
directive|define
name|__malloc_ptrdiff_t
value|ptrdiff_t
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
name|__attribute_malloc__
end_elif

begin_define
define|#
directive|define
name|__attribute_malloc__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* GCC can always grok prototypes.  For C++ programs we add throw()    to help it optimize the function calls.  But this works only with    gcc 2.8.x and egcs.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|__cplusplus
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|3
operator|||
name|__GNUC_MINOR__
operator|>=
literal|8
operator|)
end_if

begin_define
define|#
directive|define
name|__THROW
value|throw ()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__THROW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__MALLOC_P
parameter_list|(
name|args
parameter_list|)
value|args __THROW
end_define

begin_comment
comment|/* This macro will be used for functions which might take C++ callback    functions.  */
end_comment

begin_define
define|#
directive|define
name|__MALLOC_PMT
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not GCC.  */
end_comment

begin_define
define|#
directive|define
name|__THROW
end_define

begin_if
if|#
directive|if
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
operator|||
name|defined
name|__cplusplus
end_if

begin_define
define|#
directive|define
name|__MALLOC_P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_define
define|#
directive|define
name|__MALLOC_PMT
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI C or C++.  */
end_comment

begin_define
define|#
directive|define
name|__MALLOC_P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_comment
comment|/* No prototypes.  */
end_comment

begin_define
define|#
directive|define
name|__MALLOC_PMT
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI C or C++.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|((__malloc_ptr_t) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Nonzero if the malloc is already initialized.  */
ifdef|#
directive|ifdef
name|_LIBC
comment|/* In the GNU libc we rename the global variable    `__malloc_initialized' to `__libc_malloc_initialized'.  */
define|#
directive|define
name|__malloc_initialized
value|__libc_malloc_initialized
endif|#
directive|endif
specifier|extern
name|int
name|cvmx__malloc_initialized
decl_stmt|;
comment|/* SVID2/XPG mallinfo structure */
struct|struct
name|mallinfo
block|{
name|int
name|arena
decl_stmt|;
comment|/* non-mmapped space allocated from system */
name|int
name|ordblks
decl_stmt|;
comment|/* number of free chunks */
name|int
name|smblks
decl_stmt|;
comment|/* number of fastbin blocks */
name|int
name|hblks
decl_stmt|;
comment|/* number of mmapped regions */
name|int
name|hblkhd
decl_stmt|;
comment|/* space in mmapped regions */
name|int
name|usmblks
decl_stmt|;
comment|/* maximum total allocated space */
name|int
name|fsmblks
decl_stmt|;
comment|/* space available in freed fastbin blocks */
name|int
name|uordblks
decl_stmt|;
comment|/* total allocated space */
name|int
name|fordblks
decl_stmt|;
comment|/* total free space */
name|int
name|keepcost
decl_stmt|;
comment|/* top-most, releasable (via malloc_trim) space */
block|}
struct|;
comment|/* Returns a copy of the updated current mallinfo. */
specifier|extern
name|struct
name|mallinfo
name|mallinfo
name|__MALLOC_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* SVID2/XPG mallopt options */
ifndef|#
directive|ifndef
name|M_MXFAST
define|#
directive|define
name|M_MXFAST
value|1
comment|/* maximum request size for "fastbins" */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|M_NLBLKS
define|#
directive|define
name|M_NLBLKS
value|2
comment|/* UNUSED in this malloc */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|M_GRAIN
define|#
directive|define
name|M_GRAIN
value|3
comment|/* UNUSED in this malloc */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|M_KEEP
define|#
directive|define
name|M_KEEP
value|4
comment|/* UNUSED in this malloc */
endif|#
directive|endif
comment|/* mallopt options that actually do something */
define|#
directive|define
name|M_TRIM_THRESHOLD
value|-1
define|#
directive|define
name|M_TOP_PAD
value|-2
define|#
directive|define
name|M_MMAP_THRESHOLD
value|-3
define|#
directive|define
name|M_MMAP_MAX
value|-4
define|#
directive|define
name|M_CHECK_ACTION
value|-5
comment|/* General SVID/XPG interface to tunable parameters. */
specifier|extern
name|int
name|mallopt
name|__MALLOC_P
argument_list|(
operator|(
name|int
name|__param
operator|,
name|int
name|__val
operator|)
argument_list|)
decl_stmt|;
comment|/* Release all but __pad bytes of freed top-most memory back to the    system. Return 1 if successful, else 0. */
specifier|extern
name|int
name|malloc_trim
name|__MALLOC_P
argument_list|(
operator|(
name|size_t
name|__pad
operator|)
argument_list|)
decl_stmt|;
comment|/* Report the number of usable allocated bytes associated with allocated    chunk __ptr. */
specifier|extern
name|size_t
name|malloc_usable_size
name|__MALLOC_P
argument_list|(
operator|(
name|__malloc_ptr_t
name|__ptr
operator|)
argument_list|)
decl_stmt|;
comment|/* Prints brief summary statistics on stderr. */
specifier|extern
name|void
name|malloc_stats
name|__MALLOC_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Record the state of all malloc variables in an opaque data structure. */
specifier|extern
name|__malloc_ptr_t
name|malloc_get_state
name|__MALLOC_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
comment|/* Restore the state of all malloc variables from data obtained with    malloc_get_state(). */
specifier|extern
name|int
name|malloc_set_state
name|__MALLOC_P
argument_list|(
operator|(
name|__malloc_ptr_t
name|__ptr
operator|)
argument_list|)
decl_stmt|;
comment|/* Called once when malloc is initialized; redefining this variable in    the application provides the preferred way to set up the hook    pointers. */
extern|extern void (*cmvx__malloc_initialize_hook
block|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_extern

begin_comment
comment|/* Hooks for debugging and user-defined versions. */
end_comment

begin_extern
extern|extern void (*cvmx__free_hook
end_extern

begin_expr_stmt
unit|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|__malloc_ptr_t
name|__ptr
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __malloc_ptr_t (*cvmx__malloc_hook
end_extern

begin_expr_stmt
unit|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|size_t
name|__size
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __malloc_ptr_t (*cvmx__realloc_hook
end_extern

begin_expr_stmt
unit|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|__malloc_ptr_t
name|__ptr
operator|,
name|size_t
name|__size
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __malloc_ptr_t (*cvmx__memalign_hook
end_extern

begin_expr_stmt
unit|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|size_t
name|__alignment
operator|,
name|size_t
name|__size
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*__after_morecore_hook
end_extern

begin_expr_stmt
unit|)
name|__MALLOC_PMT
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Activate a standard set of debugging hooks. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cvmx__malloc_check_init
name|__MALLOC_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal routines, operating on "arenas".  */
end_comment

begin_struct_decl
struct_decl|struct
name|malloc_state
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|malloc_state
modifier|*
name|mstate
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
unit|};
comment|/* end of extern "C" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc.h */
end_comment

end_unit

