begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_ALLOC_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__SUNPRO_CC
end_ifdef

begin_define
define|#
directive|define
name|__PRIVATE
value|public
end_define

begin_comment
comment|// Extra access restrictions prevent us from really making some things
end_comment

begin_comment
comment|// private.
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PRIVATE
value|private
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
end_ifdef

begin_define
define|#
directive|define
name|__USE_MALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This implements some standard node allocators.  These are
end_comment

begin_comment
comment|// NOT the same as the allocators in the C++ draft standard or in
end_comment

begin_comment
comment|// in the original STL.  They do not encapsulate different pointer
end_comment

begin_comment
comment|// types; indeed we assume that there is only one pointer type.
end_comment

begin_comment
comment|// The allocation primitives are intended to allocate individual objects,
end_comment

begin_comment
comment|// not larger arenas as with the original STL allocators.
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<new>
end_include

begin_define
define|#
directive|define
name|__THROW_BAD_ALLOC
value|throw bad_alloc
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__THROW_BAD_ALLOC
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_define
define|#
directive|define
name|__THROW_BAD_ALLOC
value|cerr<< "out of memory"<< endl; exit(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ALLOC
end_ifndef

begin_define
define|#
directive|define
name|__ALLOC
value|alloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_WIN32THREADS
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__RESTRICT
end_ifndef

begin_define
define|#
directive|define
name|__RESTRICT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STL_PTHREADS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_NOTHREADS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__STL_SGI_THREADS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STL_WIN32THREADS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_NOTHREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_PTHREADS
end_ifdef

begin_comment
comment|// POSIX Threads
end_comment

begin_comment
comment|// This is dubious, since this is likely to be a high contention
end_comment

begin_comment
comment|// lock.   Performance may not be adequate.
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_LOCK
define|\
value|if (threads) pthread_mutex_lock(&__node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
define|\
value|if (threads) pthread_mutex_unlock(&__node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_THREADS
value|true
end_define

begin_define
define|#
directive|define
name|__VOLATILE
value|volatile
end_define

begin_comment
comment|// Needed at -O3 on SGI
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_WIN32THREADS
end_ifdef

begin_comment
comment|// The lock needs to be initialized by constructing an allocator
end_comment

begin_comment
comment|// objects of the right type.  We do that here explicitly for alloc.
end_comment

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_LOCK
define|\
value|EnterCriticalSection(&__node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
define|\
value|LeaveCriticalSection(&__node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_THREADS
value|true
end_define

begin_define
define|#
directive|define
name|__VOLATILE
value|volatile
end_define

begin_comment
comment|// may not be needed
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32THREADS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_SGI_THREADS
end_ifdef

begin_comment
comment|// This should work without threads, with sproc threads, or with
end_comment

begin_comment
comment|// pthreads.  It is suboptimal in all cases.
end_comment

begin_comment
comment|// It is unlikely to even compile on nonSGI machines.
end_comment

begin_extern
extern|extern
literal|"C"
block|{
specifier|extern
name|int
name|__us_rsthread_malloc
decl_stmt|;
block|}
end_extern

begin_comment
comment|// The above is copied from malloc.h.  Including<malloc.h>
end_comment

begin_comment
comment|// would be cleaner but fails with certain levels of standard
end_comment

begin_comment
comment|// conformance.
end_comment

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_LOCK
value|if (threads&& __us_rsthread_malloc) \                 { __lock(&__node_allocator_lock); }
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
value|if (threads&& __us_rsthread_malloc) \                 { __unlock(&__node_allocator_lock); }
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_THREADS
value|true
end_define

begin_define
define|#
directive|define
name|__VOLATILE
value|volatile
end_define

begin_comment
comment|// Needed at -O3 on SGI
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_NOTHREADS
end_ifdef

begin_comment
comment|//  Thread-unsafe
end_comment

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_LOCK
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_THREADS
value|false
end_define

begin_define
define|#
directive|define
name|__VOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__STL_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|_MIPS_SIM
operator|!=
name|_MIPS_SIM_ABI32
operator|)
pragma|#
directive|pragma
name|set
name|woff
name|1174
endif|#
directive|endif
comment|// Malloc-based allocator.  Typically slower than default alloc below.
comment|// Typically thread-safe and more storage efficient.
ifdef|#
directive|ifdef
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
ifdef|#
directive|ifdef
name|__DECLARE_GLOBALS_HERE
name|void
function_decl|(
modifier|*
name|__malloc_alloc_oom_handler
function_decl|)
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|// g++ 2.7.2 does not handle static template data members.
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|__malloc_alloc_oom_handler
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|int
name|inst
operator|>
name|class
name|__malloc_alloc_template
block|{
name|private
operator|:
specifier|static
name|void
operator|*
name|oom_malloc
argument_list|(
name|size_t
argument_list|)
block|;
specifier|static
name|void
operator|*
name|oom_realloc
argument_list|(
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
block|;
ifndef|#
directive|ifndef
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
specifier|static
name|void
argument_list|(
operator|*
name|__malloc_alloc_oom_handler
argument_list|)
argument_list|()
block|;
endif|#
directive|endif
name|public
operator|:
specifier|static
name|void
operator|*
name|allocate
argument_list|(
argument|size_t n
argument_list|)
block|{
name|void
operator|*
name|result
operator|=
name|malloc
argument_list|(
name|n
argument_list|)
block|;
if|if
condition|(
literal|0
operator|==
name|result
condition|)
name|result
operator|=
name|oom_malloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
comment|/* n */
parameter_list|)
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
modifier|*
name|reallocate
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
comment|/* old_sz */
parameter_list|,
name|size_t
name|new_sz
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
name|realloc
argument_list|(
name|p
argument_list|,
name|new_sz
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|==
name|result
condition|)
name|result
operator|=
name|oom_realloc
argument_list|(
name|p
argument_list|,
name|new_sz
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|* set_malloc_handler(void (*f)())
argument_list|)
operator|(
operator|)
block|{
name|void
argument_list|(
operator|*
name|old
argument_list|)
argument_list|()
operator|=
name|__malloc_alloc_oom_handler
block|;
name|__malloc_alloc_oom_handler
operator|=
name|f
block|;
return|return
operator|(
name|old
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// malloc_alloc out-of-memory handling
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
end_ifndef

begin_expr_stmt
name|template
operator|<
name|int
name|inst
operator|>
name|void
argument_list|(
operator|*
name|__malloc_alloc_template
operator|<
name|inst
operator|>
operator|::
name|__malloc_alloc_oom_handler
argument_list|)
argument_list|()
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|int
name|inst
operator|>
name|void
operator|*
name|__malloc_alloc_template
operator|<
name|inst
operator|>
operator|::
name|oom_malloc
argument_list|(
argument|size_t n
argument_list|)
block|{
name|void
argument_list|(
operator|*
name|my_malloc_handler
argument_list|)
argument_list|()
block|;
name|void
operator|*
name|result
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|my_malloc_handler
operator|=
name|__malloc_alloc_oom_handler
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|my_malloc_handler
condition|)
block|{
name|__THROW_BAD_ALLOC
expr_stmt|;
block|}
call|(
modifier|*
name|my_malloc_handler
call|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|result
operator|=
name|malloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|result
condition|)
return|return
operator|(
name|result
operator|)
return|;
end_if

begin_expr_stmt
unit|} }
name|template
operator|<
name|int
name|inst
operator|>
name|void
operator|*
name|__malloc_alloc_template
operator|<
name|inst
operator|>
operator|::
name|oom_realloc
argument_list|(
argument|void *p
argument_list|,
argument|size_t n
argument_list|)
block|{
name|void
argument_list|(
operator|*
name|my_malloc_handler
argument_list|)
argument_list|()
block|;
name|void
operator|*
name|result
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|my_malloc_handler
operator|=
name|__malloc_alloc_oom_handler
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|my_malloc_handler
condition|)
block|{
name|__THROW_BAD_ALLOC
expr_stmt|;
block|}
call|(
modifier|*
name|my_malloc_handler
call|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|result
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|result
condition|)
return|return
operator|(
name|result
operator|)
return|;
end_if

begin_typedef
unit|} }
typedef|typedef
name|__malloc_alloc_template
operator|<
literal|0
operator|>
name|malloc_alloc
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Alloc
operator|>
name|class
name|simple_alloc
block|{
name|public
operator|:
specifier|static
name|T
operator|*
name|allocate
argument_list|(
argument|size_t n
argument_list|)
block|{
return|return
literal|0
operator|==
name|n
operator|?
literal|0
operator|:
operator|(
name|T
operator|*
operator|)
name|Alloc
operator|::
name|allocate
argument_list|(
name|n
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|T
operator|*
name|allocate
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|T
operator|*
operator|)
name|Alloc
operator|::
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|T
modifier|*
name|p
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|!=
name|n
condition|)
name|Alloc
operator|::
name|deallocate
argument_list|(
name|p
argument_list|,
name|n
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|T
modifier|*
name|p
parameter_list|)
block|{
name|Alloc
operator|::
name|deallocate
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|// Allocator adaptor to check size arguments for debugging.
end_comment

begin_comment
comment|// Reports errors using assert.  Checking can be disabled with
end_comment

begin_comment
comment|// NDEBUG, but it's far better to just use the underlying allocator
end_comment

begin_comment
comment|// instead when no checking is desired.
end_comment

begin_comment
comment|// There is some evidence that this can confuse Purify.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Alloc
operator|>
name|class
name|debug_alloc
block|{
name|private
operator|:
expr|enum
block|{
name|extra
operator|=
literal|8
block|}
block|;
comment|// Size of space used to store size.  Note
comment|// that this must be large enough to preserve
comment|// alignment.
name|public
operator|:
specifier|static
name|void
operator|*
name|allocate
argument_list|(
argument|size_t n
argument_list|)
block|{
name|char
operator|*
name|result
operator|=
operator|(
name|char
operator|*
operator|)
name|Alloc
operator|::
name|allocate
argument_list|(
name|n
operator|+
name|extra
argument_list|)
block|;
operator|*
operator|(
name|size_t
operator|*
operator|)
name|result
operator|=
name|n
block|;
return|return
name|result
operator|+
name|extra
return|;
block|}
specifier|static
name|void
name|deallocate
argument_list|(
argument|void *p
argument_list|,
argument|size_t n
argument_list|)
block|{
name|char
operator|*
name|real_p
operator|=
operator|(
name|char
operator|*
operator|)
name|p
operator|-
name|extra
block|;
name|assert
argument_list|(
operator|*
operator|(
name|size_t
operator|*
operator|)
name|real_p
operator|==
name|n
argument_list|)
block|;
name|Alloc
operator|::
name|deallocate
argument_list|(
name|real_p
argument_list|,
name|n
operator|+
name|extra
argument_list|)
block|; }
specifier|static
name|void
operator|*
name|reallocate
argument_list|(
argument|void *p
argument_list|,
argument|size_t old_sz
argument_list|,
argument|size_t new_sz
argument_list|)
block|{
name|char
operator|*
name|real_p
operator|=
operator|(
name|char
operator|*
operator|)
name|p
operator|-
name|extra
block|;
name|assert
argument_list|(
operator|*
operator|(
name|size_t
operator|*
operator|)
name|real_p
operator|==
name|old_sz
argument_list|)
block|;
name|char
operator|*
name|result
operator|=
operator|(
name|char
operator|*
operator|)
name|Alloc
operator|::
name|reallocate
argument_list|(
name|real_p
argument_list|,
name|old_sz
operator|+
name|extra
argument_list|,
name|new_sz
operator|+
name|extra
argument_list|)
block|;
operator|*
operator|(
name|size_t
operator|*
operator|)
name|result
operator|=
name|new_sz
block|;
return|return
name|result
operator|+
name|extra
return|;
block|}
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__USE_MALLOC
end_ifdef

begin_typedef
typedef|typedef
name|malloc_alloc
name|alloc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|malloc_alloc
name|single_client_alloc
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Default node allocator.
end_comment

begin_comment
comment|// With a reasonable compiler, this should be roughly as fast as the
end_comment

begin_comment
comment|// original STL class-specific allocators, but with less fragmentation.
end_comment

begin_comment
comment|// Default_alloc_template parameters are experimental and MAY
end_comment

begin_comment
comment|// DISAPPEAR in the future.  Clients should just use alloc for now.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Important implementation properties:
end_comment

begin_comment
comment|// 1. If the client request an object of size> __MAX_BYTES, the resulting
end_comment

begin_comment
comment|//    object will be obtained directly from malloc.
end_comment

begin_comment
comment|// 2. In all other cases, we allocate an object of size exactly
end_comment

begin_comment
comment|//    ROUND_UP(requested_size).  Thus the client has enough size
end_comment

begin_comment
comment|//    information that we can return the object to the proper free list
end_comment

begin_comment
comment|//    without permanently losing part of the object.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first template parameter specifies whether more than one thread
end_comment

begin_comment
comment|// may use this allocator.  It is safe to allocate an object from
end_comment

begin_comment
comment|// one instance of a default_alloc and deallocate it with another
end_comment

begin_comment
comment|// one.  This effectively transfers its ownership to the second one.
end_comment

begin_comment
comment|// This may have undesirable effects on reference locality.
end_comment

begin_comment
comment|// The second parameter is unreferenced and serves only to allow the
end_comment

begin_comment
comment|// creation of multiple default_alloc instances.
end_comment

begin_comment
comment|// Node that containers built on different allocator instances have
end_comment

begin_comment
comment|// different types, limiting the utility of this approach.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SUNPRO_CC
end_ifdef

begin_comment
comment|// breaks if we make these template class members:
end_comment

begin_enum
enum|enum
block|{
name|__ALIGN
init|=
literal|8
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|__MAX_BYTES
init|=
literal|128
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|__NFREELISTS
init|=
name|__MAX_BYTES
operator|/
name|__ALIGN
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|class
name|__default_alloc_template
block|{
name|private
operator|:
comment|// Really we should use static const int x = N
comment|// instead of enum { x = N }, but few compilers accept the former.
ifndef|#
directive|ifndef
name|__SUNPRO_CC
expr|enum
block|{
name|__ALIGN
operator|=
literal|8
block|}
block|;     enum
block|{
name|__MAX_BYTES
operator|=
literal|128
block|}
block|;     enum
block|{
name|__NFREELISTS
operator|=
name|__MAX_BYTES
operator|/
name|__ALIGN
block|}
block|;
endif|#
directive|endif
specifier|static
name|size_t
name|ROUND_UP
argument_list|(
argument|size_t bytes
argument_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|bytes
operator|)
operator|+
name|__ALIGN
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|__ALIGN
operator|-
literal|1
operator|)
operator|)
return|;
block|}
name|__PRIVATE
operator|:
expr|union
name|obj
block|{
expr|union
name|obj
operator|*
name|free_list_link
block|;
name|char
name|client_data
index|[
literal|1
index|]
block|;
comment|/* The client sees this.        */
block|}
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_ifdef
ifdef|#
directive|ifdef
name|__SUNPRO_CC
end_ifdef

begin_decl_stmt
specifier|static
name|obj
modifier|*
name|__VOLATILE
name|free_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Specifying a size results in duplicate def for 4.1
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|obj
modifier|*
name|__VOLATILE
name|free_list
index|[
name|__NFREELISTS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|size_t
name|FREELIST_INDEX
parameter_list|(
name|size_t
name|bytes
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|bytes
operator|)
operator|+
name|__ALIGN
operator|-
literal|1
operator|)
operator|/
name|__ALIGN
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|// Returns an object of size n, and optionally adds to size n free list.
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|refill
parameter_list|(
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Allocates a chunk for nobjs of size "size".  nobjs may be reduced
end_comment

begin_comment
comment|// if it is inconvenient to allocate the requested number.
end_comment

begin_function_decl
specifier|static
name|char
modifier|*
name|chunk_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
modifier|&
name|nobjs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Chunk allocation state.
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|start_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|end_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|heap_size
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_SGI_THREADS
end_ifdef

begin_decl_stmt
specifier|static
specifier|volatile
name|unsigned
name|long
name|__node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|__lock
parameter_list|(
specifier|volatile
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|__unlock
parameter_list|(
specifier|volatile
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_PTHREADS
end_ifdef

begin_decl_stmt
specifier|static
name|pthread_mutex_t
name|__node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_WIN32THREADS
end_ifdef

begin_decl_stmt
specifier|static
name|CRITICAL_SECTION
name|__node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|__node_allocator_lock_initialized
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|__default_alloc_template
argument_list|()
end_macro

begin_block
block|{
comment|// This assumes the first constructor is called before threads
comment|// are started.
if|if
condition|(
operator|!
name|__node_allocator_lock_initialized
condition|)
block|{
name|InitializeCriticalSection
argument_list|(
operator|&
name|__node_allocator_lock
argument_list|)
expr_stmt|;
name|__node_allocator_lock_initialized
operator|=
name|true
expr_stmt|;
block|}
block|}
end_block

begin_label
name|private
label|:
end_label

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|lock
block|{
name|public
label|:
name|lock
argument_list|()
block|{
name|__NODE_ALLOCATOR_LOCK
expr_stmt|;
block|}
operator|~
name|lock
argument_list|()
block|{
name|__NODE_ALLOCATOR_UNLOCK
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|friend
name|class
name|lock
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/* n must be> 0      */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|allocate
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
name|obj
modifier|*
name|__VOLATILE
modifier|*
name|my_free_list
decl_stmt|;
name|obj
modifier|*
name|__RESTRICT
name|result
decl_stmt|;
if|if
condition|(
name|n
operator|>
operator|(
name|size_t
operator|)
name|__MAX_BYTES
condition|)
block|{
return|return
operator|(
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|n
argument_list|)
operator|)
return|;
block|}
name|my_free_list
operator|=
name|free_list
operator|+
name|FREELIST_INDEX
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|// Acquire the lock here with a constructor call.
comment|// This ensures that it is released in exit or during stack
comment|// unwinding.
ifndef|#
directive|ifndef
name|_NOTHREADS
comment|/*REFERENCED*/
name|lock
name|lock_instance
decl_stmt|;
endif|#
directive|endif
name|result
operator|=
operator|*
name|my_free_list
expr_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
name|void
modifier|*
name|r
init|=
name|refill
argument_list|(
name|ROUND_UP
argument_list|(
name|n
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|r
return|;
block|}
operator|*
name|my_free_list
operator|=
name|result
operator|->
name|free_list_link
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* p may not be 0 */
end_comment

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|obj
modifier|*
name|q
init|=
operator|(
name|obj
operator|*
operator|)
name|p
decl_stmt|;
name|obj
modifier|*
name|__VOLATILE
modifier|*
name|my_free_list
decl_stmt|;
if|if
condition|(
name|n
operator|>
operator|(
name|size_t
operator|)
name|__MAX_BYTES
condition|)
block|{
name|malloc_alloc
operator|::
name|deallocate
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return;
block|}
name|my_free_list
operator|=
name|free_list
operator|+
name|FREELIST_INDEX
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|// acquire lock
ifndef|#
directive|ifndef
name|_NOTHREADS
comment|/*REFERENCED*/
name|lock
name|lock_instance
decl_stmt|;
endif|#
directive|endif
comment|/* _NOTHREADS */
name|q
operator|->
name|free_list_link
operator|=
operator|*
name|my_free_list
expr_stmt|;
operator|*
name|my_free_list
operator|=
name|q
expr_stmt|;
comment|// lock is released here
block|}
end_function

begin_function_decl
specifier|static
name|void
modifier|*
name|reallocate
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|old_sz
parameter_list|,
name|size_t
name|new_sz
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
unit|} ;
typedef|typedef
name|__default_alloc_template
operator|<
name|__NODE_ALLOCATOR_THREADS
operator|,
literal|0
operator|>
name|alloc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__default_alloc_template
operator|<
name|false
operator|,
literal|0
operator|>
name|single_client_alloc
expr_stmt|;
end_typedef

begin_comment
comment|/* We allocate memory in large chunks in order to avoid fragmenting     */
end_comment

begin_comment
comment|/* the malloc heap too much.                                            */
end_comment

begin_comment
comment|/* We assume that size is properly aligned.                             */
end_comment

begin_comment
comment|/* We hold the allocation lock.                                         */
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|chunk_alloc
argument_list|(
argument|size_t size
argument_list|,
argument|int& nobjs
argument_list|)
block|{
name|char
operator|*
name|result
block|;
name|size_t
name|total_bytes
operator|=
name|size
operator|*
name|nobjs
block|;
name|size_t
name|bytes_left
operator|=
name|end_free
operator|-
name|start_free
block|;
if|if
condition|(
name|bytes_left
operator|>=
name|total_bytes
condition|)
block|{
name|result
operator|=
name|start_free
expr_stmt|;
name|start_free
operator|+=
name|total_bytes
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|bytes_left
operator|>=
name|size
condition|)
block|{
name|nobjs
operator|=
name|bytes_left
operator|/
name|size
expr_stmt|;
name|total_bytes
operator|=
name|size
operator|*
name|nobjs
expr_stmt|;
name|result
operator|=
name|start_free
expr_stmt|;
name|start_free
operator|+=
name|total_bytes
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_elseif

begin_else
else|else
block|{
name|size_t
name|bytes_to_get
init|=
literal|2
operator|*
name|total_bytes
operator|+
name|ROUND_UP
argument_list|(
name|heap_size
operator|>>
literal|4
argument_list|)
decl_stmt|;
comment|// Try to make use of the left-over piece.
if|if
condition|(
name|bytes_left
operator|>
literal|0
condition|)
block|{
name|obj
modifier|*
name|__VOLATILE
modifier|*
name|my_free_list
init|=
name|free_list
operator|+
name|FREELIST_INDEX
argument_list|(
name|bytes_left
argument_list|)
decl_stmt|;
operator|(
operator|(
name|obj
operator|*
operator|)
name|start_free
operator|)
operator|->
name|free_list_link
operator|=
operator|*
name|my_free_list
expr_stmt|;
operator|*
name|my_free_list
operator|=
operator|(
name|obj
operator|*
operator|)
name|start_free
expr_stmt|;
block|}
name|start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|bytes_to_get
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|start_free
condition|)
block|{
name|int
name|i
decl_stmt|;
name|obj
modifier|*
name|__VOLATILE
modifier|*
name|my_free_list
decl_stmt|,
modifier|*
name|p
decl_stmt|;
comment|// Try to make do with what we have.  That can't
comment|// hurt.  We do not try smaller requests, since that tends
comment|// to result in disaster on multi-process machines.
for|for
control|(
name|i
operator|=
name|size
init|;
name|i
operator|<=
name|__MAX_BYTES
condition|;
name|i
operator|+=
name|__ALIGN
control|)
block|{
name|my_free_list
operator|=
name|free_list
operator|+
name|FREELIST_INDEX
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|p
operator|=
operator|*
name|my_free_list
expr_stmt|;
if|if
condition|(
literal|0
operator|!=
name|p
condition|)
block|{
operator|*
name|my_free_list
operator|=
name|p
operator|->
name|free_list_link
expr_stmt|;
name|start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|p
expr_stmt|;
name|end_free
operator|=
name|start_free
operator|+
name|i
expr_stmt|;
return|return
operator|(
name|chunk_alloc
argument_list|(
name|size
argument_list|,
name|nobjs
argument_list|)
operator|)
return|;
comment|// Any leftover piece will eventually make it to the
comment|// right free list.
block|}
block|}
name|end_free
operator|=
literal|0
expr_stmt|;
comment|// In case of exception.
name|start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|bytes_to_get
argument_list|)
expr_stmt|;
comment|// This should either throw an
comment|// exception or remedy the situation.  Thus we assume it
comment|// succeeded.
block|}
name|heap_size
operator|+=
name|bytes_to_get
expr_stmt|;
name|end_free
operator|=
name|start_free
operator|+
name|bytes_to_get
expr_stmt|;
return|return
operator|(
name|chunk_alloc
argument_list|(
name|size
argument_list|,
name|nobjs
argument_list|)
operator|)
return|;
block|}
end_else

begin_comment
unit|}
comment|/* Returns an object of size n, and optionally adds to size n free list.*/
end_comment

begin_comment
comment|/* We assume that n is properly aligned.                                */
end_comment

begin_comment
comment|/* We hold the allocation lock.                                         */
end_comment

begin_expr_stmt
unit|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|void
operator|*
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|refill
argument_list|(
argument|size_t n
argument_list|)
block|{
name|int
name|nobjs
operator|=
literal|20
block|;
name|char
operator|*
name|chunk
operator|=
name|chunk_alloc
argument_list|(
name|n
argument_list|,
name|nobjs
argument_list|)
block|;
name|obj
operator|*
name|__VOLATILE
operator|*
name|my_free_list
block|;
name|obj
operator|*
name|result
block|;
name|obj
operator|*
name|current_obj
block|,
operator|*
name|next_obj
block|;
name|int
name|i
block|;
if|if
condition|(
literal|1
operator|==
name|nobjs
condition|)
return|return
operator|(
name|chunk
operator|)
return|;
name|my_free_list
operator|=
name|free_list
operator|+
name|FREELIST_INDEX
argument_list|(
name|n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Build free list in chunk */
end_comment

begin_expr_stmt
name|result
operator|=
operator|(
name|obj
operator|*
operator|)
name|chunk
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|my_free_list
operator|=
name|next_obj
operator|=
operator|(
name|obj
operator|*
operator|)
operator|(
name|chunk
operator|+
name|n
operator|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|i
operator|=
literal|1
init|;
condition|;
name|i
operator|++
control|)
block|{
name|current_obj
operator|=
name|next_obj
expr_stmt|;
name|next_obj
operator|=
operator|(
name|obj
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|next_obj
operator|+
name|n
operator|)
expr_stmt|;
if|if
condition|(
name|nobjs
operator|-
literal|1
operator|==
name|i
condition|)
block|{
name|current_obj
operator|->
name|free_list_link
operator|=
literal|0
expr_stmt|;
break|break;
block|}
else|else
block|{
name|current_obj
operator|->
name|free_list_link
operator|=
name|next_obj
expr_stmt|;
block|}
block|}
end_for

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|void
operator|*
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|reallocate
argument_list|(
argument|void *p
argument_list|,
argument|size_t old_sz
argument_list|,
argument|size_t new_sz
argument_list|)
block|{
name|void
operator|*
name|result
block|;
name|size_t
name|copy_sz
block|;
if|if
condition|(
name|old_sz
operator|>
operator|(
name|size_t
operator|)
name|__MAX_BYTES
operator|&&
name|new_sz
operator|>
operator|(
name|size_t
operator|)
name|__MAX_BYTES
condition|)
block|{
return|return
operator|(
name|realloc
argument_list|(
name|p
argument_list|,
name|new_sz
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|ROUND_UP
argument_list|(
name|old_sz
argument_list|)
operator|==
name|ROUND_UP
argument_list|(
name|new_sz
argument_list|)
condition|)
return|return
operator|(
name|p
operator|)
return|;
end_if

begin_expr_stmt
name|result
operator|=
name|allocate
argument_list|(
name|new_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|copy_sz
operator|=
name|new_sz
operator|>
name|old_sz
condition|?
name|old_sz
else|:
name|new_sz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|memcpy
argument_list|(
name|result
argument_list|,
name|p
argument_list|,
name|copy_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|deallocate
argument_list|(
name|p
argument_list|,
name|old_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__STL_PTHREADS
end_ifdef

begin_expr_stmt
unit|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|pthread_mutex_t
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__node_allocator_lock
operator|=
name|PTHREAD_MUTEX_INITIALIZER
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_WIN32THREADS
end_ifdef

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|CRITICAL_SECTION
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__node_allocator_lock
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|bool
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__node_allocator_lock_initialized
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_SGI_THREADS
end_ifdef

begin_expr_stmt
name|__STL_END_NAMESPACE
include|#
directive|include
file|<mutex.h>
include|#
directive|include
file|<time.h>
name|__STL_BEGIN_NAMESPACE
comment|// Somewhat generic lock implementations.  We need only test-and-set
comment|// and some way to sleep.  These should work with both SGI pthreads
comment|// and sproc threads.  They may be useful on other systems.
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
specifier|volatile
name|unsigned
name|long
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__node_allocator_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__mips
operator|<
literal|3
operator|||
operator|!
operator|(
name|defined
argument_list|(
name|_ABIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_ABI64
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__test_and_set
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|test_and_set(l,v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|void
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__lock
argument_list|(
argument|volatile unsigned long *lock
argument_list|)
block|{
specifier|const
name|unsigned
name|low_spin_max
operator|=
literal|30
block|;
comment|// spin cycles if we suspect uniprocessor
specifier|const
name|unsigned
name|high_spin_max
operator|=
literal|1000
block|;
comment|// spin cycles for multiprocessor
specifier|static
name|unsigned
name|spin_max
operator|=
name|low_spin_max
block|;
name|unsigned
name|my_spin_max
block|;
specifier|static
name|unsigned
name|last_spins
operator|=
literal|0
block|;
name|unsigned
name|my_last_spins
block|;
specifier|static
expr|struct
name|timespec
name|ts
operator|=
block|{
literal|0
block|,
literal|1000
block|}
block|;
name|unsigned
name|junk
block|;
define|#
directive|define
name|__ALLOC_PAUSE
value|junk *= junk; junk *= junk; junk *= junk; junk *= junk
name|int
name|i
block|;
if|if
condition|(
operator|!
name|__test_and_set
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
return|return;
block|}
name|my_spin_max
operator|=
name|spin_max
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|my_last_spins
operator|=
name|last_spins
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|my_spin_max
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|<
name|my_last_spins
operator|/
literal|2
operator|||
operator|*
name|lock
condition|)
block|{
name|__ALLOC_PAUSE
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|!
name|__test_and_set
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
comment|// got it!
comment|// Spinning worked.  Thus we're probably not being scheduled
comment|// against the other process with which we were contending.
comment|// Thus it makes sense to spin longer the next time.
name|last_spins
operator|=
name|i
expr_stmt|;
name|spin_max
operator|=
name|high_spin_max
expr_stmt|;
return|return;
block|}
block|}
end_for

begin_comment
comment|// We are probably being scheduled against the other process.  Sleep.
end_comment

begin_expr_stmt
name|spin_max
operator|=
name|low_spin_max
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|!
name|__test_and_set
argument_list|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
return|return;
block|}
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_for

begin_expr_stmt
unit|}  template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
specifier|inline
name|void
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__unlock
argument_list|(
argument|volatile unsigned long *lock
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__mips
operator|>=
literal|3
name|asm
argument_list|(
literal|"sync"
argument_list|)
block|;
operator|*
name|lock
operator|=
literal|0
block|;
elif|#
directive|elif
name|__mips
operator|>=
literal|3
operator|&&
operator|(
name|defined
argument_list|(
name|_ABIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_ABI64
argument_list|)
operator|)
name|__lock_release
argument_list|(
name|lock
argument_list|)
block|;
else|#
directive|else
operator|*
name|lock
operator|=
literal|0
block|;
comment|// This is not sufficient on many multiprocessors, since
comment|// writes to protected variables and the lock may be reordered.
endif|#
directive|endif
block|}
endif|#
directive|endif
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|start_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|end_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|size_t
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|heap_size
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|threads
operator|,
name|int
name|inst
operator|>
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|obj
operator|*
name|__VOLATILE
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|free_list
index|[
ifdef|#
directive|ifdef
name|__SUNPRO_CC
name|__NFREELISTS
else|#
directive|else
name|__default_alloc_template
operator|<
name|threads
operator|,
name|inst
operator|>
operator|::
name|__NFREELISTS
endif|#
directive|endif
index|]
operator|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The 16 zeros are necessary to make version 4.1 of the SunPro
end_comment

begin_comment
comment|// compiler happy.  Otherwise it appears to allocate too little
end_comment

begin_comment
comment|// space for the array.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_WIN32THREADS
end_ifdef

begin_comment
comment|// Create one to get critical section initialized.
end_comment

begin_comment
comment|// We do this onece per file, but only the first constructor
end_comment

begin_comment
comment|// does anything.
end_comment

begin_decl_stmt
specifier|static
name|alloc
name|__node_allocator_dummy_instance
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __USE_MALLOC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|_MIPS_SIM
operator|!=
name|_MIPS_SIM_ABI32
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|reset
name|woff
name|1174
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__STL_END_NAMESPACE
end_macro

begin_undef
undef|#
directive|undef
name|__PRIVATE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_ALLOC_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

