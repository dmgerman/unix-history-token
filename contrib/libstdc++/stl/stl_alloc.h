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
value|throw bad_alloc()
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
name|__STL_SOLTHREADS
argument_list|)
expr|\
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
value|if (threads) pthread_mutex_lock(&_S_node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
define|\
value|if (threads) pthread_mutex_unlock(&_S_node_allocator_lock)
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
name|__STL_SOLTHREADS
end_ifdef

begin_include
include|#
directive|include
file|<thread.h>
end_include

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_LOCK
define|\
value|if (threads) mutex_lock(&_S_node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
define|\
value|if (threads) mutex_unlock(&_S_node_allocator_lock)
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
value|EnterCriticalSection(&_S_node_allocator_lock)
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
define|\
value|LeaveCriticalSection(&_S_node_allocator_lock)
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
value|if (threads&& __us_rsthread_malloc) \                 { _S_lock(&_S_node_allocator_lock); }
end_define

begin_define
define|#
directive|define
name|__NODE_ALLOCATOR_UNLOCK
value|if (threads&& __us_rsthread_malloc) \                 { _S_unlock(&_S_node_allocator_lock); }
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
name|__inst
operator|>
name|class
name|__malloc_alloc_template
block|{
name|private
operator|:
specifier|static
name|void
operator|*
name|_S_oom_malloc
argument_list|(
name|size_t
argument_list|)
block|;
specifier|static
name|void
operator|*
name|_S_oom_realloc
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
argument|size_t __n
argument_list|)
block|{
name|void
operator|*
name|__result
operator|=
name|malloc
argument_list|(
name|__n
argument_list|)
block|;
if|if
condition|(
literal|0
operator|==
name|__result
condition|)
name|__result
operator|=
name|_S_oom_malloc
argument_list|(
name|__n
argument_list|)
expr_stmt|;
return|return
name|__result
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
name|__p
parameter_list|,
name|size_t
comment|/* __n */
parameter_list|)
block|{
name|free
argument_list|(
name|__p
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
name|__p
parameter_list|,
name|size_t
comment|/* old_sz */
parameter_list|,
name|size_t
name|__new_sz
parameter_list|)
block|{
name|void
modifier|*
name|__result
init|=
name|realloc
argument_list|(
name|__p
argument_list|,
name|__new_sz
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|==
name|__result
condition|)
name|__result
operator|=
name|_S_oom_realloc
argument_list|(
name|__p
argument_list|,
name|__new_sz
argument_list|)
expr_stmt|;
return|return
name|__result
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|* __set_malloc_handler(void (*__f)())
argument_list|)
operator|(
operator|)
block|{
name|void
argument_list|(
operator|*
name|__old
argument_list|)
argument_list|()
operator|=
name|__malloc_alloc_oom_handler
block|;
name|__malloc_alloc_oom_handler
operator|=
name|__f
block|;
return|return
operator|(
name|__old
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
name|__inst
operator|>
name|void
argument_list|(
operator|*
name|__malloc_alloc_template
operator|<
name|__inst
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
name|__inst
operator|>
name|void
operator|*
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
operator|::
name|_S_oom_malloc
argument_list|(
argument|size_t __n
argument_list|)
block|{
name|void
argument_list|(
operator|*
name|__my_malloc_handler
argument_list|)
argument_list|()
block|;
name|void
operator|*
name|__result
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|__my_malloc_handler
operator|=
name|__malloc_alloc_oom_handler
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|__my_malloc_handler
condition|)
block|{
name|__THROW_BAD_ALLOC
expr_stmt|;
block|}
call|(
modifier|*
name|__my_malloc_handler
call|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__result
operator|=
name|malloc
argument_list|(
name|__n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__result
condition|)
return|return
operator|(
name|__result
operator|)
return|;
end_if

begin_expr_stmt
unit|} }
name|template
operator|<
name|int
name|__inst
operator|>
name|void
operator|*
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
operator|::
name|_S_oom_realloc
argument_list|(
argument|void* __p
argument_list|,
argument|size_t __n
argument_list|)
block|{
name|void
argument_list|(
operator|*
name|__my_malloc_handler
argument_list|)
argument_list|()
block|;
name|void
operator|*
name|__result
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|__my_malloc_handler
operator|=
name|__malloc_alloc_oom_handler
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|__my_malloc_handler
condition|)
block|{
name|__THROW_BAD_ALLOC
expr_stmt|;
block|}
call|(
modifier|*
name|__my_malloc_handler
call|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__result
operator|=
name|realloc
argument_list|(
name|__p
argument_list|,
name|__n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__result
condition|)
return|return
operator|(
name|__result
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
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
name|class
name|simple_alloc
block|{
name|public
operator|:
specifier|static
name|_Tp
operator|*
name|allocate
argument_list|(
argument|size_t __n
argument_list|)
block|{
return|return
literal|0
operator|==
name|__n
operator|?
literal|0
operator|:
operator|(
name|_Tp
operator|*
operator|)
name|_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|_Tp
operator|*
name|allocate
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|_Tp
operator|*
operator|)
name|_Alloc
operator|::
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|_Tp
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
name|_Tp
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|!=
name|__n
condition|)
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
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
name|_Tp
modifier|*
name|__p
parameter_list|)
block|{
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
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
name|_Alloc
operator|>
name|class
name|debug_alloc
block|{
name|private
operator|:
expr|enum
block|{
name|_S_extra
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
argument|size_t __n
argument_list|)
block|{
name|char
operator|*
name|__result
operator|=
operator|(
name|char
operator|*
operator|)
name|_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|+
name|_S_extra
argument_list|)
block|;
operator|*
operator|(
name|size_t
operator|*
operator|)
name|__result
operator|=
name|__n
block|;
return|return
name|__result
operator|+
name|_S_extra
return|;
block|}
specifier|static
name|void
name|deallocate
argument_list|(
argument|void* __p
argument_list|,
argument|size_t __n
argument_list|)
block|{
name|char
operator|*
name|__real_p
operator|=
operator|(
name|char
operator|*
operator|)
name|__p
operator|-
name|_S_extra
block|;
name|assert
argument_list|(
operator|*
operator|(
name|size_t
operator|*
operator|)
name|__real_p
operator|==
name|__n
argument_list|)
block|;
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__real_p
argument_list|,
name|__n
operator|+
name|_S_extra
argument_list|)
block|;   }
specifier|static
name|void
operator|*
name|reallocate
argument_list|(
argument|void* __p
argument_list|,
argument|size_t __old_sz
argument_list|,
argument|size_t __new_sz
argument_list|)
block|{
name|char
operator|*
name|__real_p
operator|=
operator|(
name|char
operator|*
operator|)
name|__p
operator|-
name|_S_extra
block|;
name|assert
argument_list|(
operator|*
operator|(
name|size_t
operator|*
operator|)
name|__real_p
operator|==
name|__old_sz
argument_list|)
block|;
name|char
operator|*
name|__result
operator|=
operator|(
name|char
operator|*
operator|)
name|_Alloc
operator|::
name|reallocate
argument_list|(
name|__real_p
argument_list|,
name|__old_sz
operator|+
name|_S_extra
argument_list|,
name|__new_sz
operator|+
name|_S_extra
argument_list|)
block|;
operator|*
operator|(
name|size_t
operator|*
operator|)
name|__result
operator|=
name|__new_sz
block|;
return|return
name|__result
operator|+
name|_S_extra
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
comment|// 1. If the client request an object of size> _MAX_BYTES, the resulting
end_comment

begin_comment
comment|//    object will be obtained directly from malloc.
end_comment

begin_comment
comment|// 2. In all other cases, we allocate an object of size exactly
end_comment

begin_comment
comment|//    _S_round_up(requested_size).  Thus the client has enough size
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
name|_ALIGN
init|=
literal|8
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|_MAX_BYTES
init|=
literal|128
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|_NFREELISTS
init|=
name|_MAX_BYTES
operator|/
name|_ALIGN
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
name|_ALIGN
operator|=
literal|8
block|}
block|;     enum
block|{
name|_MAX_BYTES
operator|=
literal|128
block|}
block|;     enum
block|{
name|_NFREELISTS
operator|=
name|_MAX_BYTES
operator|/
name|_ALIGN
block|}
block|;
endif|#
directive|endif
specifier|static
name|size_t
name|_S_round_up
argument_list|(
argument|size_t __bytes
argument_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|__bytes
operator|)
operator|+
name|_ALIGN
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|_ALIGN
operator|-
literal|1
operator|)
operator|)
return|;
block|}
name|__PRIVATE
operator|:
expr|union
name|_Obj
block|{
expr|union
name|_Obj
operator|*
name|_M_free_list_link
block|;
name|char
name|_M_client_data
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
name|_Obj
modifier|*
name|__VOLATILE
name|_S_free_list
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
name|_Obj
modifier|*
name|__VOLATILE
name|_S_free_list
index|[
name|_NFREELISTS
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
name|_S_freelist_index
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|__bytes
operator|)
operator|+
name|_ALIGN
operator|-
literal|1
operator|)
operator|/
name|_ALIGN
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|// Returns an object of size __n, and optionally adds to size __n free list.
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|_S_refill
parameter_list|(
name|size_t
name|__n
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
name|_S_chunk_alloc
parameter_list|(
name|size_t
name|__size
parameter_list|,
name|int
modifier|&
name|__nobjs
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
name|_S_start_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_S_end_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|_S_heap_size
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
name|_S_node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|_S_lock
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
name|_S_unlock
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
name|_S_node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_SOLTHREADS
end_ifdef

begin_decl_stmt
specifier|static
name|mutex_t
name|_S_node_allocator_lock
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
name|_S_node_allocator_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|_S_node_allocator_lock_initialized
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
name|_S_node_allocator_lock_initialized
condition|)
block|{
name|InitializeCriticalSection
argument_list|(
operator|&
name|_S_node_allocator_lock
argument_list|)
expr_stmt|;
name|_S_node_allocator_lock_initialized
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
name|_Lock
block|{
name|public
label|:
name|_Lock
argument_list|()
block|{
name|__NODE_ALLOCATOR_LOCK
expr_stmt|;
block|}
operator|~
name|_Lock
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
name|_Lock
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/* __n must be> 0      */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|allocate
parameter_list|(
name|size_t
name|__n
parameter_list|)
block|{
name|_Obj
modifier|*
name|__VOLATILE
modifier|*
name|__my_free_list
decl_stmt|;
name|_Obj
modifier|*
name|__RESTRICT
name|__result
decl_stmt|;
if|if
condition|(
name|__n
operator|>
operator|(
name|size_t
operator|)
name|_MAX_BYTES
condition|)
block|{
return|return
operator|(
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|__n
argument_list|)
operator|)
return|;
block|}
name|__my_free_list
operator|=
name|_S_free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
comment|// Acquire the lock here with a constructor call.
comment|// This ensures that it is released in exit or during stack
comment|// unwinding.
ifndef|#
directive|ifndef
name|_NOTHREADS
comment|/*REFERENCED*/
name|_Lock
name|__lock_instance
decl_stmt|;
endif|#
directive|endif
name|__result
operator|=
operator|*
name|__my_free_list
expr_stmt|;
if|if
condition|(
name|__result
operator|==
literal|0
condition|)
block|{
name|void
modifier|*
name|__r
init|=
name|_S_refill
argument_list|(
name|_S_round_up
argument_list|(
name|__n
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|__r
return|;
block|}
operator|*
name|__my_free_list
operator|=
name|__result
operator|->
name|_M_free_list_link
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* __p may not be 0 */
end_comment

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
name|_Obj
modifier|*
name|__q
init|=
operator|(
name|_Obj
operator|*
operator|)
name|__p
decl_stmt|;
name|_Obj
modifier|*
name|__VOLATILE
modifier|*
name|__my_free_list
decl_stmt|;
if|if
condition|(
name|__n
operator|>
operator|(
name|size_t
operator|)
name|_MAX_BYTES
condition|)
block|{
name|malloc_alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
argument_list|)
expr_stmt|;
return|return;
block|}
name|__my_free_list
operator|=
name|_S_free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
comment|// acquire lock
ifndef|#
directive|ifndef
name|_NOTHREADS
comment|/*REFERENCED*/
name|_Lock
name|__lock_instance
decl_stmt|;
endif|#
directive|endif
comment|/* _NOTHREADS */
name|__q
operator|->
name|_M_free_list_link
operator|=
operator|*
name|__my_free_list
expr_stmt|;
operator|*
name|__my_free_list
operator|=
name|__q
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
name|__p
parameter_list|,
name|size_t
name|__old_sz
parameter_list|,
name|size_t
name|__new_sz
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
name|__threads
operator|,
name|int
name|__inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_chunk_alloc
argument_list|(
argument|size_t __size
argument_list|,
argument|int& __nobjs
argument_list|)
block|{
name|char
operator|*
name|__result
block|;
name|size_t
name|__total_bytes
operator|=
name|__size
operator|*
name|__nobjs
block|;
name|size_t
name|__bytes_left
operator|=
name|_S_end_free
operator|-
name|_S_start_free
block|;
if|if
condition|(
name|__bytes_left
operator|>=
name|__total_bytes
condition|)
block|{
name|__result
operator|=
name|_S_start_free
expr_stmt|;
name|_S_start_free
operator|+=
name|__total_bytes
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|__bytes_left
operator|>=
name|__size
condition|)
block|{
name|__nobjs
operator|=
call|(
name|int
call|)
argument_list|(
name|__bytes_left
operator|/
name|__size
argument_list|)
expr_stmt|;
name|__total_bytes
operator|=
name|__size
operator|*
name|__nobjs
expr_stmt|;
name|__result
operator|=
name|_S_start_free
expr_stmt|;
name|_S_start_free
operator|+=
name|__total_bytes
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
end_elseif

begin_else
else|else
block|{
name|size_t
name|__bytes_to_get
init|=
literal|2
operator|*
name|__total_bytes
operator|+
name|_S_round_up
argument_list|(
name|_S_heap_size
operator|>>
literal|4
argument_list|)
decl_stmt|;
comment|// Try to make use of the left-over piece.
if|if
condition|(
name|__bytes_left
operator|>
literal|0
condition|)
block|{
name|_Obj
modifier|*
name|__VOLATILE
modifier|*
name|__my_free_list
init|=
name|_S_free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__bytes_left
argument_list|)
decl_stmt|;
operator|(
operator|(
name|_Obj
operator|*
operator|)
name|_S_start_free
operator|)
operator|->
name|_M_free_list_link
operator|=
operator|*
name|__my_free_list
expr_stmt|;
operator|*
name|__my_free_list
operator|=
operator|(
name|_Obj
operator|*
operator|)
name|_S_start_free
expr_stmt|;
block|}
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|__bytes_to_get
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|_S_start_free
condition|)
block|{
name|size_t
name|__i
decl_stmt|;
name|_Obj
modifier|*
name|__VOLATILE
modifier|*
name|__my_free_list
decl_stmt|;
name|_Obj
modifier|*
name|__p
decl_stmt|;
comment|// Try to make do with what we have.  That can't
comment|// hurt.  We do not try smaller requests, since that tends
comment|// to result in disaster on multi-process machines.
for|for
control|(
name|__i
operator|=
name|__size
init|;
name|__i
operator|<=
name|_MAX_BYTES
condition|;
name|__i
operator|+=
name|_ALIGN
control|)
block|{
name|__my_free_list
operator|=
name|_S_free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__i
argument_list|)
expr_stmt|;
name|__p
operator|=
operator|*
name|__my_free_list
expr_stmt|;
if|if
condition|(
literal|0
operator|!=
name|__p
condition|)
block|{
operator|*
name|__my_free_list
operator|=
name|__p
operator|->
name|_M_free_list_link
expr_stmt|;
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|__p
expr_stmt|;
name|_S_end_free
operator|=
name|_S_start_free
operator|+
name|__i
expr_stmt|;
return|return
operator|(
name|_S_chunk_alloc
argument_list|(
name|__size
argument_list|,
name|__nobjs
argument_list|)
operator|)
return|;
comment|// Any leftover piece will eventually make it to the
comment|// right free list.
block|}
block|}
name|_S_end_free
operator|=
literal|0
expr_stmt|;
comment|// In case of exception.
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|__bytes_to_get
argument_list|)
expr_stmt|;
comment|// This should either throw an
comment|// exception or remedy the situation.  Thus we assume it
comment|// succeeded.
block|}
name|_S_heap_size
operator|+=
name|__bytes_to_get
expr_stmt|;
name|_S_end_free
operator|=
name|_S_start_free
operator|+
name|__bytes_to_get
expr_stmt|;
return|return
operator|(
name|_S_chunk_alloc
argument_list|(
name|__size
argument_list|,
name|__nobjs
argument_list|)
operator|)
return|;
block|}
end_else

begin_comment
unit|}
comment|/* Returns an object of size __n, and optionally adds to size __n free list.*/
end_comment

begin_comment
comment|/* We assume that __n is properly aligned.                                */
end_comment

begin_comment
comment|/* We hold the allocation lock.                                         */
end_comment

begin_expr_stmt
unit|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|void
operator|*
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_refill
argument_list|(
argument|size_t __n
argument_list|)
block|{
name|int
name|__nobjs
operator|=
literal|20
block|;
name|char
operator|*
name|__chunk
operator|=
name|_S_chunk_alloc
argument_list|(
name|__n
argument_list|,
name|__nobjs
argument_list|)
block|;
name|_Obj
operator|*
name|__VOLATILE
operator|*
name|__my_free_list
block|;
name|_Obj
operator|*
name|__result
block|;
name|_Obj
operator|*
name|__current_obj
block|;
name|_Obj
operator|*
name|__next_obj
block|;
name|int
name|__i
block|;
if|if
condition|(
literal|1
operator|==
name|__nobjs
condition|)
return|return
operator|(
name|__chunk
operator|)
return|;
name|__my_free_list
operator|=
name|_S_free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Build free list in chunk */
end_comment

begin_expr_stmt
name|__result
operator|=
operator|(
name|_Obj
operator|*
operator|)
name|__chunk
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|__my_free_list
operator|=
name|__next_obj
operator|=
operator|(
name|_Obj
operator|*
operator|)
operator|(
name|__chunk
operator|+
name|__n
operator|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|__i
operator|=
literal|1
init|;
condition|;
name|__i
operator|++
control|)
block|{
name|__current_obj
operator|=
name|__next_obj
expr_stmt|;
name|__next_obj
operator|=
operator|(
name|_Obj
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|__next_obj
operator|+
name|__n
operator|)
expr_stmt|;
if|if
condition|(
name|__nobjs
operator|-
literal|1
operator|==
name|__i
condition|)
block|{
name|__current_obj
operator|->
name|_M_free_list_link
operator|=
literal|0
expr_stmt|;
break|break;
block|}
else|else
block|{
name|__current_obj
operator|->
name|_M_free_list_link
operator|=
name|__next_obj
expr_stmt|;
block|}
block|}
end_for

begin_return
return|return
operator|(
name|__result
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
argument|void* __p
argument_list|,
argument|size_t __old_sz
argument_list|,
argument|size_t __new_sz
argument_list|)
block|{
name|void
operator|*
name|__result
block|;
name|size_t
name|__copy_sz
block|;
if|if
condition|(
name|__old_sz
operator|>
operator|(
name|size_t
operator|)
name|_MAX_BYTES
operator|&&
name|__new_sz
operator|>
operator|(
name|size_t
operator|)
name|_MAX_BYTES
condition|)
block|{
return|return
operator|(
name|realloc
argument_list|(
name|__p
argument_list|,
name|__new_sz
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|_S_round_up
argument_list|(
name|__old_sz
argument_list|)
operator|==
name|_S_round_up
argument_list|(
name|__new_sz
argument_list|)
condition|)
return|return
operator|(
name|__p
operator|)
return|;
end_if

begin_expr_stmt
name|__result
operator|=
name|allocate
argument_list|(
name|__new_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__copy_sz
operator|=
name|__new_sz
operator|>
name|__old_sz
condition|?
name|__old_sz
else|:
name|__new_sz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|memcpy
argument_list|(
name|__result
argument_list|,
name|__p
argument_list|,
name|__copy_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__old_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|__result
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
name|__threads
operator|,
name|int
name|__inst
operator|>
name|pthread_mutex_t
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_node_allocator_lock
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
name|__STL_SOLTHREADS
end_ifdef

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|mutex_t
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_node_allocator_lock
operator|=
name|DEFAULTMUTEX
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
name|__threads
operator|,
name|int
name|__inst
operator|>
name|CRITICAL_SECTION
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_node_allocator_lock
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|bool
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_node_allocator_lock_initialized
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
comment|/* XXX should use<ctime> */
name|__STL_BEGIN_NAMESPACE
comment|// Somewhat generic lock implementations.  We need only test-and-set
comment|// and some way to sleep.  These should work with both SGI pthreads
comment|// and sproc threads.  They may be useful on other systems.
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
specifier|volatile
name|unsigned
name|long
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_node_allocator_lock
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
name|__threads
operator|,
name|int
name|__inst
operator|>
name|void
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_lock
argument_list|(
argument|volatile unsigned long* __lock
argument_list|)
block|{
specifier|const
name|unsigned
name|__low_spin_max
operator|=
literal|30
block|;
comment|// spins if we suspect uniprocessor
specifier|const
name|unsigned
name|__high_spin_max
operator|=
literal|1000
block|;
comment|// spins for multiprocessor
specifier|static
name|unsigned
name|__spin_max
operator|=
name|__low_spin_max
block|;
name|unsigned
name|__my_spin_max
block|;
specifier|static
name|unsigned
name|__last_spins
operator|=
literal|0
block|;
name|unsigned
name|__my_last_spins
block|;
name|unsigned
name|__junk
block|;
define|#
directive|define
name|__ALLOC_PAUSE
define|\
value|__junk *= __junk; __junk *= __junk; __junk *= __junk; __junk *= __junk
name|int
name|__i
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
name|__lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
return|return;
block|}
name|__my_spin_max
operator|=
name|__spin_max
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__my_last_spins
operator|=
name|__last_spins
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|__i
operator|=
literal|0
init|;
name|__i
operator|<
name|__my_spin_max
condition|;
name|__i
operator|++
control|)
block|{
if|if
condition|(
name|__i
operator|<
name|__my_last_spins
operator|/
literal|2
operator|||
operator|*
name|__lock
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
name|__lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
comment|// got it!
comment|// Spinning worked.  Thus we're probably not being scheduled
comment|// against the other process with which we were contending.
comment|// Thus it makes sense to spin longer the next time.
name|__last_spins
operator|=
name|__i
expr_stmt|;
name|__spin_max
operator|=
name|__high_spin_max
expr_stmt|;
return|return;
block|}
block|}
end_for

begin_comment
comment|// We are probably being scheduled against the other process.  Sleep.
end_comment

begin_expr_stmt
name|__spin_max
operator|=
name|__low_spin_max
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|__i
operator|=
literal|0
init|;
condition|;
operator|++
name|__i
control|)
block|{
name|struct
name|timespec
name|__ts
decl_stmt|;
name|int
name|__log_nsec
init|=
name|__i
operator|+
literal|6
decl_stmt|;
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
name|__lock
argument_list|,
literal|1
argument_list|)
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|__log_nsec
operator|>
literal|27
condition|)
name|__log_nsec
operator|=
literal|27
expr_stmt|;
comment|/* Max sleep is 2**27nsec ~ 60msec      */
name|__ts
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|__ts
operator|.
name|tv_nsec
operator|=
literal|1
operator|<<
name|__log_nsec
expr_stmt|;
name|nanosleep
argument_list|(
operator|&
name|__ts
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
name|__threads
operator|,
name|int
name|__inst
operator|>
specifier|inline
name|void
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_unlock
argument_list|(
argument|volatile unsigned long* __lock
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
name|__lock
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
name|__lock
argument_list|)
block|;
else|#
directive|else
operator|*
name|__lock
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
name|__threads
operator|,
name|int
name|__inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_start_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|char
operator|*
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_end_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|size_t
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_heap_size
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_Obj
operator|*
name|__VOLATILE
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|::
name|_S_free_list
index|[
name|_NFREELISTS
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

begin_comment
comment|// This implements allocators as specified in the C++ standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that standard-conforming allocators use many language features
end_comment

begin_comment
comment|// that are not yet widely implemented.  In particular, they rely on
end_comment

begin_comment
comment|// member templates, partial specialization, partial ordering of function
end_comment

begin_comment
comment|// templates, the typename keyword, and the use of the template keyword
end_comment

begin_comment
comment|// to refer to a template member of a dependent type.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_STD_ALLOCATORS
end_ifdef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|allocator
block|{
typedef|typedef
name|alloc
name|_Alloc
typedef|;
comment|// The underlying allocator.
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|size_t
name|size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|allocator
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|allocator
argument_list|()
end_macro

begin_macro
name|__STL_NOTHROW
end_macro

begin_block
block|{}
end_block

begin_macro
name|allocator
argument_list|(
argument|const allocator&
argument_list|)
end_macro

begin_macro
name|__STL_NOTHROW
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
name|allocator
argument_list|(
argument|const allocator<_Tp1>&
argument_list|)
name|__STL_NOTHROW
block|{}
operator|~
name|allocator
argument_list|()
name|__STL_NOTHROW
block|{}
name|pointer
name|address
argument_list|(
argument|reference __x
argument_list|)
specifier|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|const_pointer
name|address
argument_list|(
name|const_reference
name|__x
argument_list|)
decl|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_decl_stmt

begin_comment
comment|// __n is permitted to be 0.  The C++ standard says nothing about what
end_comment

begin_comment
comment|// the return value is when __n == 0.
end_comment

begin_function
name|_Tp
modifier|*
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|void
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|__n
operator|!=
literal|0
condition|?
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|// __p is not permitted to be a null pointer.
end_comment

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
name|__STL_NOTHROW
block|{
return|return
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|construct
parameter_list|(
name|pointer
name|__p
parameter_list|,
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|)
block|{
name|new
argument_list|(
argument|__p
argument_list|)
name|_Tp
argument_list|(
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
name|__p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|class
name|allocator
operator|<
name|void
operator|>
block|{
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|allocator
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|allocator
operator|<
name|_T2
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|allocator
operator|<
name|_T2
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_comment
comment|// Allocator adaptor to turn an SGI-style allocator (e.g. alloc, malloc_alloc)
end_comment

begin_comment
comment|// into a standard-conforming allocator.   Note that this adaptor does
end_comment

begin_comment
comment|// *not* assume that all objects of the underlying alloc class are
end_comment

begin_comment
comment|// identical, nor does it assume that all of the underlying alloc's
end_comment

begin_comment
comment|// member functions are static member functions.  Note, also, that
end_comment

begin_comment
comment|// __allocator<_Tp, alloc> is essentially the same thing as allocator<_Tp>.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
expr|struct
name|__allocator
block|{
name|_Alloc
name|__underlying_alloc
block|;
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|__allocator
operator|<
name|_Tp1
operator|,
name|_Alloc
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__allocator
argument_list|()
end_macro

begin_macro
name|__STL_NOTHROW
end_macro

begin_block
block|{}
end_block

begin_macro
name|__allocator
argument_list|(
argument|const __allocator& __a
argument_list|)
end_macro

begin_label
name|__STL_NOTHROW
label|:
end_label

begin_macro
name|__underlying_alloc
argument_list|(
argument|__a.__underlying_alloc
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
name|__allocator
argument_list|(
argument|const __allocator<_Tp1
argument_list|,
argument|_Alloc>& __a
argument_list|)
name|__STL_NOTHROW
operator|:
name|__underlying_alloc
argument_list|(
argument|__a.__underlying_alloc
argument_list|)
block|{}
operator|~
name|__allocator
argument_list|()
name|__STL_NOTHROW
block|{}
name|pointer
name|address
argument_list|(
argument|reference __x
argument_list|)
specifier|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|const_pointer
name|address
argument_list|(
name|const_reference
name|__x
argument_list|)
decl|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_decl_stmt

begin_comment
comment|// __n is permitted to be 0.
end_comment

begin_function
name|_Tp
modifier|*
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|void
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|__n
operator|!=
literal|0
condition|?
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|__underlying_alloc
operator|.
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|// __p is not permitted to be a null pointer.
end_comment

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
name|__underlying_alloc
operator|.
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
name|__STL_NOTHROW
block|{
return|return
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|construct
parameter_list|(
name|pointer
name|__p
parameter_list|,
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|)
block|{
name|new
argument_list|(
argument|__p
argument_list|)
name|_Tp
argument_list|(
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
name|__p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Alloc
operator|>
name|class
name|__allocator
operator|<
name|void
operator|,
name|_Alloc
operator|>
block|{
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|__allocator
operator|<
name|_Tp1
operator|,
name|_Alloc
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a1
operator|,
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a2
operator|)
block|{
return|return
name|__a1
operator|.
name|__underlying_alloc
operator|==
name|__a2
operator|.
name|__underlying_alloc
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_FUNCTION_TMPL_PARTIAL_ORDER
end_ifdef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a1
operator|,
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a2
operator|)
block|{
return|return
name|__a1
operator|.
name|__underlying_alloc
operator|!=
name|__a2
operator|.
name|__underlying_alloc
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_FUNCTION_TMPL_PARTIAL_ORDER */
end_comment

begin_comment
comment|// Comparison operators for all of the predifined SGI-style allocators.
end_comment

begin_comment
comment|// This ensures that __allocator<malloc_alloc> (for example) will
end_comment

begin_comment
comment|// work correctly.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|inst
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__malloc_alloc_template
operator|<
name|inst
operator|>
operator|&
operator|,
specifier|const
name|__malloc_alloc_template
operator|<
name|inst
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_FUNCTION_TMPL_PARTIAL_ORDER
end_ifdef

begin_expr_stmt
name|template
operator|<
name|int
name|__inst
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
operator|&
operator|,
specifier|const
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_FUNCTION_TMPL_PARTIAL_ORDER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USE_MALLOC
end_ifndef

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|&
operator|,
specifier|const
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_FUNCTION_TMPL_PARTIAL_ORDER
end_ifdef

begin_expr_stmt
name|template
operator|<
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|&
operator|,
specifier|const
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_FUNCTION_TMPL_PARTIAL_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|debug_alloc
operator|<
name|_Alloc
operator|>
operator|&
operator|,
specifier|const
name|debug_alloc
operator|<
name|_Alloc
operator|>
operator|&
operator|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_FUNCTION_TMPL_PARTIAL_ORDER
end_ifdef

begin_expr_stmt
name|template
operator|<
name|class
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|debug_alloc
operator|<
name|_Alloc
operator|>
operator|&
operator|,
specifier|const
name|debug_alloc
operator|<
name|_Alloc
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_FUNCTION_TMPL_PARTIAL_ORDER */
end_comment

begin_comment
comment|// Another allocator adaptor: _Alloc_traits.  This serves two
end_comment

begin_comment
comment|// purposes.  First, make it possible to write containers that can use
end_comment

begin_comment
comment|// either SGI-style allocators or standard-conforming allocator.
end_comment

begin_comment
comment|// Second, provide a mechanism so that containers can query whether or
end_comment

begin_comment
comment|// not the allocator has distinct instances.  If not, the container
end_comment

begin_comment
comment|// can avoid wasting a word of memory to store an empty object.
end_comment

begin_comment
comment|// This adaptor uses partial specialization.  The general case of
end_comment

begin_comment
comment|// _Alloc_traits<_Tp, _Alloc> assumes that _Alloc is a
end_comment

begin_comment
comment|// standard-conforming allocator, possibly with non-equal instances
end_comment

begin_comment
comment|// and non-static members.  (It still behaves correctly even if _Alloc
end_comment

begin_comment
comment|// has static member and if all instances are equal.  Refinements
end_comment

begin_comment
comment|// affect performance, not correctness.)
end_comment

begin_comment
comment|// There are always two members: allocator_type, which is a standard-
end_comment

begin_comment
comment|// conforming allocator type for allocating objects of type _Tp, and
end_comment

begin_comment
comment|// _S_instanceless, a static const member of type bool.  If
end_comment

begin_comment
comment|// _S_instanceless is true, this means that there is no difference
end_comment

begin_comment
comment|// between any two instances of type allocator_type.  Furthermore, if
end_comment

begin_comment
comment|// _S_instanceless is true, then _Alloc_traits has one additional
end_comment

begin_comment
comment|// member: _Alloc_type.  This type encapsulates allocation and
end_comment

begin_comment
comment|// deallocation of objects of type _Tp through a static interface; it
end_comment

begin_comment
comment|// has two member functions, whose signatures are
end_comment

begin_comment
comment|//    static _Tp* allocate(size_t)
end_comment

begin_comment
comment|//    static void deallocate(_Tp*, size_t)
end_comment

begin_comment
comment|// The fully general version.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Allocator
operator|>
expr|struct
name|_Alloc_traits
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|false
block|;
typedef|typedef
name|typename
name|_Allocator
operator|::
name|__STL_TEMPLATE
name|rebind
operator|<
name|_Tp
operator|>
operator|::
name|other
name|allocator_type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Allocator
operator|>
specifier|const
name|bool
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Allocator
operator|>
operator|::
name|_S_instanceless
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The version for the default allocator.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|allocator
operator|<
name|_Tp1
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|alloc
operator|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|allocator
operator|<
name|_Tp
operator|>
name|allocator_type
expr_stmt|;
end_typedef

begin_comment
unit|};
comment|// Versions for the predefined SGI-style allocators.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|int
name|__inst
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|__USE_MALLOC
end_ifndef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|bool
name|__threads
operator|,
name|int
name|__inst
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|__default_alloc_template
operator|<
name|__threads
operator|,
name|__inst
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_comment
unit|};
comment|// Versions for the __allocator adaptor used with the predefined
end_comment

begin_comment
comment|// SGI-style allocators.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|,
name|int
name|__inst
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__allocator
operator|<
name|_Tp1
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
operator|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|__malloc_alloc_template
operator|<
name|__inst
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|__USE_MALLOC
end_ifndef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|,
name|bool
name|__thr
operator|,
name|int
name|__inst
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__allocator
operator|<
name|_Tp1
operator|,
name|__default_alloc_template
operator|<
name|__thr
operator|,
name|__inst
operator|>
expr|>
operator|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|__default_alloc_template
operator|<
name|__thr
operator|,
name|__inst
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|__default_alloc_template
operator|<
name|__thr
operator|,
name|__inst
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|,
name|class
name|_Alloc
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__allocator
operator|<
name|_Tp1
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
operator|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|debug_alloc
operator|<
name|_Alloc
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_USE_STD_ALLOCATORS */
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

