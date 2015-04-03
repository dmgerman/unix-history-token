begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_H
value|1
end_define

begin_comment
comment|/*! \file isc/mem.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/xml.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_define
define|#
directive|define
name|ISC_MEM_LOWATER
value|0
end_define

begin_define
define|#
directive|define
name|ISC_MEM_HIWATER
value|1
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_mem_water_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|isc_memalloc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_memfree_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%  * Define ISC_MEM_DEBUG=1 to make all functions that free memory  * set the pointer being freed to NULL after being freed.  * This is the default; set ISC_MEM_DEBUG=0 to disable it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_DEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%  * Define ISC_MEM_TRACKLINES=1 to turn on detailed tracing of memory  * allocation and freeing by file and line number.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_TRACKLINES
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_TRACKLINES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%  * Define ISC_MEM_CHECKOVERRUN=1 to turn on checks for using memory outside  * the requested space.  This will increase the size of each allocation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_CHECKOVERRUN
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_CHECKOVERRUN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%  * Define ISC_MEM_FILL=1 to fill each block of memory returned to the system  * with the byte string '0xbe'.  This helps track down uninitialized pointers  * and the like.  On freeing memory, the space is filled with '0xde' for  * the same reasons.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_FILL
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_FILL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%  * Define ISC_MEMPOOL_NAMES=1 to make memory pools store a symbolic  * name so that the leaking pool can be more readily identified in  * case of a memory leak.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEMPOOL_NAMES
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEMPOOL_NAMES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|unsigned
name|int
name|isc_mem_debugging
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGTRACE
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGRECORD
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGUSAGE
value|0x00000004U
end_define

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGSIZE
value|0x00000008U
end_define

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGCTX
value|0x00000010U
end_define

begin_define
define|#
directive|define
name|ISC_MEM_DEBUGALL
value|0x0000001FU
end_define

begin_comment
comment|/*!<  * The variable isc_mem_debugging holds a set of flags for  * turning certain memory debugging options on or off at  * runtime.  It is initialized to the value ISC_MEM_DEGBUGGING,  * which is 0 by default but may be overridden at compile time.  * The following flags can be specified:  *  * \li #ISC_MEM_DEBUGTRACE  *	Log each allocation and free to isc_lctx.  *  * \li #ISC_MEM_DEBUGRECORD  *	Remember each allocation, and match them up on free.  *	Crash if a free doesn't match an allocation.  *  * \li #ISC_MEM_DEBUGUSAGE  *	If a hi_water mark is set, print the maximum inuse memory  *	every time it is raised once it exceeds the hi_water mark.  *  * \li #ISC_MEM_DEBUGSIZE  *	Check the size argument being passed to isc_mem_put() matches  *	that passed to isc_mem_get().  *  * \li #ISC_MEM_DEBUGCTX  *	Check the mctx argument being passed to isc_mem_put() matches  *	that passed to isc_mem_get().  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_if
if|#
directive|if
name|ISC_MEM_TRACKLINES
end_if

begin_define
define|#
directive|define
name|_ISC_MEM_FILELINE
value|, __FILE__, __LINE__
end_define

begin_define
define|#
directive|define
name|_ISC_MEM_FLARG
value|, const char *, unsigned int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_ISC_MEM_FILELINE
end_define

begin_define
define|#
directive|define
name|_ISC_MEM_FLARG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!  * Define ISC_MEM_USE_INTERNAL_MALLOC=1 to use the internal malloc()  * implementation in preference to the system one.  The internal malloc()  * is very space-efficient, and quite fast on uniprocessor systems.  It  * performs poorly on multiprocessor machines.  * JT: we can overcome the performance issue on multiprocessor machines  * by carefully separating memory contexts.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_USE_INTERNAL_MALLOC
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_USE_INTERNAL_MALLOC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for isc_mem_create2()calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_MEMFLAG_NOLOCK
value|0x00000001
end_define

begin_comment
comment|/* no lock is necessary */
end_comment

begin_define
define|#
directive|define
name|ISC_MEMFLAG_INTERNAL
value|0x00000002
end_define

begin_comment
comment|/* use internal malloc */
end_comment

begin_if
if|#
directive|if
name|ISC_MEM_USE_INTERNAL_MALLOC
end_if

begin_define
define|#
directive|define
name|ISC_MEMFLAG_DEFAULT
value|ISC_MEMFLAG_INTERNAL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_MEMFLAG_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%<  * We use either isc___mem (three underscores) or isc__mem (two) depending on  * whether it's for BIND9's internal purpose (with -DBIND9) or generic export  * library.  This condition is generally handled in isc/namespace.h, but for  * Windows it doesn't work if it involves multiple times of macro expansion  * (such as isc_mem to isc__mem then to isc___mem).  The following definitions  * are used to work around this portability issue.  Right now, we don't support  * the export library for Windows, so we always use the three-underscore  * version.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|ISCMEMFUNC
parameter_list|(
name|sfx
parameter_list|)
value|isc___mem_ ## sfx
end_define

begin_define
define|#
directive|define
name|ISCMEMPOOLFUNC
parameter_list|(
name|sfx
parameter_list|)
value|isc___mempool_ ## sfx
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISCMEMFUNC
parameter_list|(
name|sfx
parameter_list|)
value|isc__mem_ ## sfx
end_define

begin_define
define|#
directive|define
name|ISCMEMPOOLFUNC
parameter_list|(
name|sfx
parameter_list|)
value|isc__mempool_ ## sfx
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|isc_mem_get
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|ISCMEMFUNC(get)((c), (s) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mem_allocate
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|ISCMEMFUNC(allocate)((c), (s) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mem_reallocate
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|ISCMEMFUNC(reallocate)((c), (p), (s) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mem_strdup
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|ISCMEMFUNC(strdup)((c), (p) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mempool_get
parameter_list|(
name|c
parameter_list|)
value|ISCMEMPOOLFUNC(get)((c) _ISC_MEM_FILELINE)
end_define

begin_comment
comment|/*%  * isc_mem_putanddetach() is a convenience function for use where you  * have a structure with an attached memory context.  *  * Given:  *  * \code  * struct {  *	...  *	isc_mem_t *mctx;  *	...  * } *ptr;  *  * isc_mem_t *mctx;  *  * isc_mem_putanddetach(&ptr->mctx, ptr, sizeof(*ptr));  * \endcode  *  * is the equivalent of:  *  * \code  * mctx = NULL;  * isc_mem_attach(ptr->mctx,&mctx);  * isc_mem_detach(&ptr->mctx);  * isc_mem_put(mctx, ptr, sizeof(*ptr));  * isc_mem_detach(&mctx);  * \endcode  */
end_comment

begin_comment
comment|/*% memory and memory pool methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_memmethods
block|{
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|source
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|memget
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|size_t
name|size
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|memput
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|memputanddetach
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|memallocate
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|size_t
name|size
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|memreallocate
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|memstrdup
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|s
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|memfree
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|void
modifier|*
name|ptr
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setdestroycheck
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_boolean_t
name|flag
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setwater
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|isc_mem_water_t
name|water
parameter_list|,
name|void
modifier|*
name|water_arg
parameter_list|,
name|size_t
name|hiwater
parameter_list|,
name|size_t
name|lowater
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|waterack
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
name|size_t
function_decl|(
modifier|*
name|inuse
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|isovermem
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|mpcreate
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|size_t
name|size
parameter_list|,
name|isc_mempool_t
modifier|*
modifier|*
name|mpctxp
parameter_list|)
function_decl|;
block|}
name|isc_memmethods_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_mempoolmethods
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
modifier|*
name|mpctxp
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|put
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|void
modifier|*
name|mem
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|getallocated
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setmaxalloc
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setfreemax
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setname
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|associatelock
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|isc_mutex_t
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setfillcount
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
block|}
name|isc_mempoolmethods_t
typedef|;
end_typedef

begin_comment
comment|/*%  * This structure is actually just the common prefix of a memory context  * implementation's version of an isc_mem_t.  * \brief  * Direct use of this structure by clients is forbidden.  mctx implementations  * may change the structure.  'magic' must be ISCAPI_MCTX_MAGIC for any of the  * isc_mem_ routines to work.  mctx implementations must maintain all mctx  * invariants.  */
end_comment

begin_struct
struct|struct
name|isc_mem
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_memmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_MCTX_MAGIC
value|ISC_MAGIC('A','m','c','x')
end_define

begin_define
define|#
directive|define
name|ISCAPI_MCTX_VALID
parameter_list|(
name|m
parameter_list|)
value|((m) != NULL&& \ 				 (m)->magic == ISCAPI_MCTX_MAGIC)
end_define

begin_comment
comment|/*%  * This is the common prefix of a memory pool context.  The same note as  * that for the mem structure applies.  */
end_comment

begin_struct
struct|struct
name|isc_mempool
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mempoolmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_MPOOL_MAGIC
value|ISC_MAGIC('A','m','p','l')
end_define

begin_define
define|#
directive|define
name|ISCAPI_MPOOL_VALID
parameter_list|(
name|mp
parameter_list|)
value|((mp) != NULL&& \ 				 (mp)->magic == ISCAPI_MPOOL_MAGIC)
end_define

begin_if
if|#
directive|if
name|ISC_MEM_DEBUG
end_if

begin_define
define|#
directive|define
name|isc_mem_put
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		ISCMEMFUNC(put)((c), (p), (s) _ISC_MEM_FILELINE);	\ 		(p) = NULL; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_mem_putanddetach
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		ISCMEMFUNC(putanddetach)((c), (p), (s) _ISC_MEM_FILELINE); \ 		(p) = NULL; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_mem_free
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
define|\
value|do { \ 		ISCMEMFUNC(free)((c), (p) _ISC_MEM_FILELINE);	\ 		(p) = NULL; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_mempool_put
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
define|\
value|do { \ 		ISCMEMPOOLFUNC(put)((c), (p) _ISC_MEM_FILELINE);	\ 		(p) = NULL; \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isc_mem_put
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|ISCMEMFUNC(put)((c), (p), (s) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mem_putanddetach
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|ISCMEMFUNC(putanddetach)((c), (p), (s) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mem_free
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|ISCMEMFUNC(free)((c), (p) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mempool_put
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|ISCMEMPOOLFUNC(put)((c), (p) _ISC_MEM_FILELINE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|isc_result_t
name|isc_mem_create
parameter_list|(
name|size_t
name|max_size
parameter_list|,
name|size_t
name|target_size
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_mem_create2
parameter_list|(
name|size_t
name|max_size
parameter_list|,
name|size_t
name|target_size
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_mem_createx
parameter_list|(
name|size_t
name|max_size
parameter_list|,
name|size_t
name|target_size
parameter_list|,
name|isc_memalloc_t
name|memalloc
parameter_list|,
name|isc_memfree_t
name|memfree
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_mem_createx2
parameter_list|(
name|size_t
name|max_size
parameter_list|,
name|size_t
name|target_size
parameter_list|,
name|isc_memalloc_t
name|memalloc
parameter_list|,
name|isc_memfree_t
name|memfree
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|mctxp
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Create a memory context.  *  * 'max_size' and 'target_size' are tuning parameters.  When  * ISC_MEMFLAG_INTERNAL is set, allocations smaller than 'max_size'  * will be satisfied by getting blocks of size 'target_size' from the  * system allocator and breaking them up into pieces; larger allocations  * will use the system allocator directly. If 'max_size' and/or  * 'target_size' are zero, default values will be * used.  When  * ISC_MEMFLAG_INTERNAL is not set, 'target_size' is ignored.  *  * 'max_size' is also used to size the statistics arrays and the array  * used to record active memory when ISC_MEM_DEBUGRECORD is set.  Setting  * 'max_size' too low can have detrimental effects on performance.  *  * A memory context created using isc_mem_createx() will obtain  * memory from the system by calling 'memalloc' and 'memfree',  * passing them the argument 'arg'.  A memory context created  * using isc_mem_create() will use the standard library malloc()  * and free().  *  * If ISC_MEMFLAG_NOLOCK is set in 'flags', the corresponding memory context  * will be accessed without locking.  The user who creates the context must  * ensure there be no race.  Since this can be a source of bug, it is generally  * inadvisable to use this flag unless the user is very sure about the race  * condition and the access to the object is highly performance sensitive.  *  * Requires:  * mctxp != NULL&& *mctxp == NULL */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|void
name|isc_mem_attach
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_mem_detach
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Attach to / detach from a memory context.  *  * This is intended for applications that use multiple memory contexts  * in such a way that it is not obvious when the last allocations from  * a given context has been freed and destroying the context is safe.  *  * Most applications do not need to call these functions as they can  * simply create a single memory context at the beginning of main()  * and destroy it at the end of main(), thereby guaranteeing that it  * is not destroyed while there are outstanding allocations.  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|void
name|isc_mem_destroy
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a memory context.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_mem_ondestroy
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Request to be notified with an event when a memory context has  * been successfully destroyed.  */
end_comment

begin_function_decl
name|void
name|isc_mem_stats
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Print memory usage statistics for 'mctx' on the stream 'out'.  */
end_comment

begin_function_decl
name|void
name|isc_mem_setdestroycheck
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_boolean_t
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * If 'on' is ISC_TRUE, 'mctx' will check for memory leaks when  * destroyed and abort the program if any are present.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|void
name|isc_mem_setquota
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|isc_mem_getquota
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set/get the memory quota of 'mctx'.  This is a hard limit  * on the amount of memory that may be allocated from mctx;  * if it is exceeded, allocations will fail.  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|size_t
name|isc_mem_inuse
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get an estimate of the number of memory in use in 'mctx', in bytes.  * This includes quantization overhead, but does not include memory  * allocated from the system but not yet used.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_mem_isovermem
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff the memory context is in "over memory" state, i.e.,  * a hiwater mark has been set and the used amount of memory has exceeds  * the mark.  */
end_comment

begin_function_decl
name|void
name|isc_mem_setwater
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_mem_water_t
name|water
parameter_list|,
name|void
modifier|*
name|water_arg
parameter_list|,
name|size_t
name|hiwater
parameter_list|,
name|size_t
name|lowater
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set high and low water marks for this memory context.  *  * When the memory usage of 'mctx' exceeds 'hiwater',  * '(water)(water_arg, #ISC_MEM_HIWATER)' will be called.  'water' needs to  * call isc_mem_waterack() with #ISC_MEM_HIWATER to acknowledge the state  * change.  'water' may be called multiple times.  *  * When the usage drops below 'lowater', 'water' will again be called, this  * time with #ISC_MEM_LOWATER.  'water' need to calls isc_mem_waterack() with  * #ISC_MEM_LOWATER to acknowledge the change.  *  *	static void  *	water(void *arg, int mark) {  *		struct foo *foo = arg;  *  *		LOCK(&foo->marklock);  *		if (foo->mark != mark) {  * 			foo->mark = mark;  *			....  *			isc_mem_waterack(foo->mctx, mark);  *		}  *		UNLOCK(&foo->marklock);  *	}  *  * If 'water' is NULL then 'water_arg', 'hi_water' and 'lo_water' are  * ignored and the state is reset.  *  * Requires:  *  *	'water' is not NULL.  *	hi_water>= lo_water  */
end_comment

begin_function_decl
name|void
name|isc_mem_waterack
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
name|int
name|mark
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Called to acknowledge changes in signaled by calls to 'water'.  */
end_comment

begin_function_decl
name|void
name|isc_mem_printactive
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Print to 'file' all active memory in 'mctx'.  *  * Requires ISC_MEM_DEBUGRECORD to have been set.  */
end_comment

begin_function_decl
name|void
name|isc_mem_printallactive
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Print to 'file' all active memory in all contexts.  *  * Requires ISC_MEM_DEBUGRECORD to have been set.  */
end_comment

begin_function_decl
name|void
name|isc_mem_checkdestroyed
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check that all memory contexts have been destroyed.  * Prints out those that have not been.  * Fatally fails if there are still active contexts.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mem_references
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the current reference count.  */
end_comment

begin_function_decl
name|void
name|isc_mem_setname
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Name 'ctx'.  *  * Notes:  *  *\li	Only the first 15 characters of 'name' will be copied.  *  *\li	'tag' is for debugging purposes only.  *  * Requires:  *  *\li	'ctx' is a valid ctx.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_mem_getname
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the name of 'ctx', as previously set using isc_mem_setname().  *  * Requires:  *\li	'ctx' is a valid ctx.  *  * Returns:  *\li	A non-NULL pointer to a null-terminated string.  * 	If the ctx has not been named, the string is  * 	empty.  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc_mem_gettag
parameter_list|(
name|isc_mem_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the tag value for  'task', as previously set using isc_mem_setname().  *  * Requires:  *\li	'ctx' is a valid ctx.  *  * Notes:  *\li	This function is for debugging purposes only.  *  * Requires:  *\li	'ctx' is a valid task.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBXML2
end_ifdef

begin_function_decl
name|void
name|isc_mem_renderxml
parameter_list|(
name|xmlTextWriterPtr
name|writer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Render all contexts' statistics and status in XML for writer.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LIBXML2 */
end_comment

begin_comment
comment|/*  * Memory pools  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_mempool_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|size_t
name|size
parameter_list|,
name|isc_mempool_t
modifier|*
modifier|*
name|mpctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a memory pool.  *  * Requires:  *\li	mctx is a valid memory context.  *\li	size> 0  *\li	mpctxp != NULL and *mpctxp == NULL  *  * Defaults:  *\li	maxalloc = UINT_MAX  *\li	freemax = 1  *\li	fillcount = 1  *  * Returns:  *\li	#ISC_R_NOMEMORY		-- not enough memory to create pool  *\li	#ISC_R_SUCCESS		-- all is well.  */
end_comment

begin_function_decl
name|void
name|isc_mempool_destroy
parameter_list|(
name|isc_mempool_t
modifier|*
modifier|*
name|mpctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a memory pool.  *  * Requires:  *\li	mpctxp != NULL&& *mpctxp is a valid pool.  *\li	The pool has no un"put" allocations outstanding  */
end_comment

begin_function_decl
name|void
name|isc_mempool_setname
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a name with a memory pool.  At most 15 characters may be used.  *  * Requires:  *\li	mpctx is a valid pool.  *\li	name != NULL;  */
end_comment

begin_function_decl
name|void
name|isc_mempool_associatelock
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|isc_mutex_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a lock with this memory pool.  *  * This lock is used when getting or putting items using this memory pool,  * and it is also used to set or get internal state via the isc_mempool_get*()  * and isc_mempool_set*() set of functions.  *  * Multiple pools can each share a single lock.  For instance, if "manager"  * type object contained pools for various sizes of events, and each of  * these pools used a common lock.  Note that this lock must NEVER be used  * by other than mempool routines once it is given to a pool, since that can  * easily cause double locking.  *  * Requires:  *  *\li	mpctpx is a valid pool.  *  *\li	lock != NULL.  *  *\li	No previous lock is assigned to this pool.  *  *\li	The lock is initialized before calling this function via the normal  *	means of doing that.  */
end_comment

begin_comment
comment|/*  * The following functions get/set various parameters.  Note that due to  * the unlocked nature of pools these are potentially random values unless  * the imposed externally provided locking protocols are followed.  *  * Also note that the quota limits will not always take immediate effect.  * For instance, setting "maxalloc" to a number smaller than the currently  * allocated count is permitted.  New allocations will be refused until  * the count drops below this threshold.  *  * All functions require (in addition to other requirements):  *	mpctx is a valid memory pool  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mempool_getfreemax
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the maximum allowed size of the free list.  */
end_comment

begin_function_decl
name|void
name|isc_mempool_setfreemax
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets the maximum allowed size of the free list.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mempool_getfreecount
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns current size of the free list.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mempool_getmaxalloc
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * Returns the maximum allowed number of allocations.  */
end_comment

begin_function_decl
name|void
name|isc_mempool_setmaxalloc
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets the maximum allowed number of allocations.  *  * Additional requirements:  *\li	limit> 0  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mempool_getallocated
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the number of items allocated from this pool.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_mempool_getfillcount
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the number of items allocated as a block from the parent memory  * context when the free list is empty.  */
end_comment

begin_function_decl
name|void
name|isc_mempool_setfillcount
parameter_list|(
name|isc_mempool_t
modifier|*
name|mpctx
parameter_list|,
name|unsigned
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets the fillcount.  *  * Additional requirements:  *\li	limit> 0  */
end_comment

begin_comment
comment|/*  * Pseudo-private functions for use via macros.  Do not call directly.  */
end_comment

begin_function_decl
name|void
modifier|*
name|ISCMEMFUNC
function_decl|(
name|get
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|size_t
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ISCMEMFUNC
function_decl|(
name|putanddetach
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ISCMEMFUNC
function_decl|(
name|put
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ISCMEMFUNC
function_decl|(
name|allocate
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|size_t
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ISCMEMFUNC
function_decl|(
name|reallocate
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ISCMEMFUNC
function_decl|(
name|free
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|void
modifier|*
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ISCMEMFUNC
function_decl|(
name|strdup
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ISCMEMPOOLFUNC
function_decl|(
name|get
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ISCMEMPOOLFUNC
function_decl|(
name|put
function_decl|)
parameter_list|(
name|isc_mempool_t
modifier|*
parameter_list|,
name|void
modifier|*
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MEMIMPREGISTER
end_ifdef

begin_comment
comment|/*%<  * See isc_mem_create2() above.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_memcreatefunc_t
function_decl|)
parameter_list|(
name|size_t
name|init_max_size
parameter_list|,
name|size_t
name|target_size
parameter_list|,
name|isc_mem_t
modifier|*
modifier|*
name|ctxp
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_mem_register
parameter_list|(
name|isc_memcreatefunc_t
name|createfunc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a new memory management implementation and add it to the list of  * supported implementations.  This function must be called when a different  * memory management library is used than the one contained in the ISC library.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc__mem_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * A short cut function that specifies the memory management module in the ISC  * library for isc_mem_register().  An application that uses the ISC library  * usually do not have to care about this function: it would call  * isc_lib_register(), which internally calls this function.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MEMIMPREGISTER */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MEM_H */
end_comment

end_unit

