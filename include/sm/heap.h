begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, 2006 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: heap.h,v 1.23 2006/08/15 00:53:46 ca Exp $  */
end_comment

begin_comment
comment|/* **  Sendmail debugging memory allocation package. **  See libsm/heap.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_HEAP_H
end_ifndef

begin_define
define|#
directive|define
name|SM_HEAP_H
end_define

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sm/debug.h>
end_include

begin_include
include|#
directive|include
file|<sm/exc.h>
end_include

begin_comment
comment|/* change default to 0 for production? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_HEAP_CHECK
end_ifndef

begin_define
define|#
directive|define
name|SM_HEAP_CHECK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_HEAP_CHECK */
end_comment

begin_if
if|#
directive|if
name|SM_HEAP_CHECK
end_if

begin_define
define|#
directive|define
name|sm_malloc_x
parameter_list|(
name|sz
parameter_list|)
value|sm_malloc_tagged_x(sz, __FILE__, __LINE__, SmHeapGroup)
end_define

begin_define
define|#
directive|define
name|sm_malloc
parameter_list|(
name|size
parameter_list|)
value|sm_malloc_tagged(size, __FILE__, __LINE__, SmHeapGroup)
end_define

begin_define
define|#
directive|define
name|sm_free
parameter_list|(
name|ptr
parameter_list|)
value|sm_free_tagged(ptr, __FILE__, __LINE__)
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_malloc_tagged
name|__P
argument_list|(
operator|(
name|size_t
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_malloc_tagged_x
name|__P
argument_list|(
operator|(
name|size_t
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_free_tagged
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_realloc_x
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sm_heap_register
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_heap_checkptr_tagged
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_heap_report
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_define
define|#
directive|define
name|sm_malloc_tagged
parameter_list|(
name|size
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|grp
parameter_list|)
value|sm_malloc(size)
end_define

begin_define
define|#
directive|define
name|sm_malloc_tagged_x
parameter_list|(
name|size
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|grp
parameter_list|)
value|sm_malloc_x(size)
end_define

begin_define
define|#
directive|define
name|sm_free_tagged
parameter_list|(
name|ptr
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|sm_free(ptr)
end_define

begin_define
define|#
directive|define
name|sm_heap_register
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|,
name|grp
parameter_list|)
value|(true)
end_define

begin_define
define|#
directive|define
name|sm_heap_checkptr_tagged
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|,
name|num
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|sm_heap_report
parameter_list|(
name|file
parameter_list|,
name|verbose
parameter_list|)
value|((void)0)
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_malloc
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_malloc_x
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_realloc_x
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_free
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_realloc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sm_heap_checkptr
parameter_list|(
name|ptr
parameter_list|)
value|sm_heap_checkptr_tagged(ptr, __FILE__, __LINE__)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* **  sm_f[mc]alloc are plug in replacements for malloc and calloc **  which can be used in a context requiring a function pointer, **  and which are compatible with sm_free.  Warning: sm_heap_report **  cannot report where storage leaked by sm_f[mc]alloc was allocated. */
end_comment

begin_comment
comment|/* XXX unused right now */
end_comment

begin_endif
unit|extern void * sm_fmalloc __P(( 	size_t));  extern void * sm_fcalloc __P(( 	size_t, 	size_t));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* **  Allocate 'permanent' storage that can be freed but may still be **  allocated when the process exits.  sm_heap_report will not complain **  about a storage leak originating from a call to sm_pmalloc. */
end_comment

begin_define
define|#
directive|define
name|sm_pmalloc
parameter_list|(
name|size
parameter_list|)
value|sm_malloc_tagged(size, __FILE__, __LINE__, 0)
end_define

begin_define
define|#
directive|define
name|sm_pmalloc_x
parameter_list|(
name|size
parameter_list|)
value|sm_malloc_tagged_x(size, __FILE__, __LINE__, 0)
end_define

begin_define
define|#
directive|define
name|sm_heap_group
parameter_list|()
value|SmHeapGroup
end_define

begin_define
define|#
directive|define
name|sm_heap_setgroup
parameter_list|(
name|g
parameter_list|)
value|(SmHeapGroup = (g))
end_define

begin_define
define|#
directive|define
name|sm_heap_newgroup
parameter_list|()
value|(SmHeapGroup = ++SmHeapMaxGroup)
end_define

begin_define
define|#
directive|define
name|SM_FREE
parameter_list|(
name|ptr
parameter_list|)
define|\
value|do				\ 	{				\ 		if ((ptr) != NULL)	\ 		{			\ 			sm_free(ptr);	\ 			(ptr) = NULL;	\ 		}			\ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|SmHeapGroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SmHeapMaxGroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmHeapTrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmHeapCheck
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_EXC_T
name|SmHeapOutOfMemory
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_HEAP_H */
end_comment

end_unit

