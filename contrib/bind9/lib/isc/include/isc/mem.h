begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: mem.h,v 1.54.12.4 2004/10/11 05:55:51 marka Exp $ */
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
comment|/*  * Define ISC_MEM_DEBUG=1 to make all functions that free memory  * set the pointer being freed to NULL after being freed.  * This is the default; set ISC_MEM_DEBUG=0 to disable it.  */
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
comment|/*  * Define ISC_MEM_TRACKLINES=1 to turn on detailed tracing of memory  * allocation and freeing by file and line number.  */
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
comment|/*  * Define ISC_MEM_CHECKOVERRUN=1 to turn on checks for using memory outside  * the requested space.  This will increase the size of each allocation.  */
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
comment|/*  * Define ISC_MEM_FILL=1 to fill each block of memory returned to the system  * with the byte string '0xbe'.  This helps track down uninitialized pointers  * and the like.  On freeing memory, the space is filled with '0xde' for  * the same reasons.  */
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
comment|/*  * Define ISC_MEMPOOL_NAMES=1 to make memory pools store a symbolic  * name so that the leaking pool can be more readily identified in  * case of a memory leak.  */
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

begin_comment
comment|/*  * The variable isc_mem_debugging holds a set of flags for  * turning certain memory debugging options on or off at  * runtime.  Its is intialized to the value ISC_MEM_DEGBUGGING,  * which is 0 by default but may be overridden at compile time.  * The following flags can be specified:  *  * ISC_MEM_DEBUGTRACE  *	Log each allocation and free to isc_lctx.  *  * ISC_MEM_DEBUGRECORD  *	Remember each allocation, and match them up on free.  *	Crash if a free doesn't match an allocation.  *  * ISC_MEM_DEBUGUSAGE  *	If a hi_water mark is set, print the maximium inuse memory  *	every time it is raised once it exceeds the hi_water mark.  */
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
value|, const char *, int
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

begin_define
define|#
directive|define
name|isc_mem_get
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|isc__mem_get((c), (s) _ISC_MEM_FILELINE)
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
value|isc__mem_allocate((c), (s) _ISC_MEM_FILELINE)
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
value|isc__mem_strdup((c), (p) _ISC_MEM_FILELINE)
end_define

begin_define
define|#
directive|define
name|isc_mempool_get
parameter_list|(
name|c
parameter_list|)
value|isc__mempool_get((c) _ISC_MEM_FILELINE)
end_define

begin_comment
comment|/*  * isc_mem_putanddetach() is a convienence function for use where you  * have a structure with an attached memory context.  *  * Given:  *  * struct {  *	...  *	isc_mem_t *mctx;  *	...  * } *ptr;  *  * isc_mem_t *mctx;  *  * isc_mem_putanddetach(&ptr->mctx, ptr, sizeof(*ptr));  *  * is the equivalent of:  *  * mctx = NULL;  * isc_mem_attach(ptr->mctx,&mctx);  * isc_mem_detach(&ptr->mctx);  * isc_mem_put(mctx, ptr, sizeof(*ptr));  * isc_mem_detach(&mctx);  */
end_comment

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
value|do { \ 		isc__mem_put((c), (p), (s) _ISC_MEM_FILELINE); \ 		(p) = NULL; \ 	} while (0)
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
value|do { \ 		isc__mem_putanddetach((c), (p), (s) _ISC_MEM_FILELINE); \ 		(p) = NULL; \ 	} while (0)
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
value|do { \ 		isc__mem_free((c), (p) _ISC_MEM_FILELINE); \ 		(p) = NULL; \ 	} while (0)
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
value|do { \ 		isc__mempool_put((c), (p) _ISC_MEM_FILELINE); \ 		(p) = NULL; \ 	} while (0)
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
value|isc__mem_put((c), (p), (s) _ISC_MEM_FILELINE)
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
value|isc__mem_putanddetach((c), (p), (s) _ISC_MEM_FILELINE)
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
value|isc__mem_free((c), (p) _ISC_MEM_FILELINE)
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
value|isc__mempool_put((c), (p) _ISC_MEM_FILELINE)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Create a memory context.  *  * 'max_size' and 'target_size' are tuning parameters.  When  * ISC_MEM_USE_INTERNAL_MALLOC is true, allocations smaller than  * 'max_size' will be satisfied by getting blocks of size  * 'target_size' from the system allocator and breaking them up into  * pieces; larger allocations will use the system allocator directly.  * If 'max_size' and/or 'target_size' are zero, default values will be  * used.  When ISC_MEM_USE_INTERNAL_MALLOC is false, 'target_size' is  * ignored.  *  * 'max_size' is also used to size the statistics arrays and the array  * used to record active memory when ISC_MEM_DEBUGRECORD is set.  Settin  * 'max_size' too low can have detrimental effects on performance.  *  * A memory context created using isc_mem_createx() will obtain  * memory from the system by calling 'memalloc' and 'memfree',  * passing them the argument 'arg'.  A memory context created  * using isc_mem_create() will use the standard library malloc()  * and free().  *  * Requires:  * mctxp != NULL&& *mctxp == NULL */
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
comment|/*  * Attach to / detach from a memory context.  *  * This is intended for applications that use multiple memory contexts  * in such a way that it is not obvious when the last allocations from  * a given context has been freed and destroying the context is safe.  *   * Most applications do not need to call these functions as they can  * simply create a single memory context at the beginning of main()  * and destroy it at the end of main(), thereby guaranteeing that it  * is not destroyed while there are outstanding allocations.  */
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
comment|/*  * Destroy a memory context.  */
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
comment|/*  * Request to be notified with an event when a memory context has  * been successfully destroyed.  */
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
comment|/*  * Print memory usage statistics for 'mctx' on the stream 'out'.  */
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
comment|/*  * Iff 'on' is ISC_TRUE, 'mctx' will check for memory leaks when  * destroyed and abort the program if any are present.  */
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
comment|/*  * Set/get the memory quota of 'mctx'.  This is a hard limit  * on the amount of memory that may be allocated from mctx;  * if it is exceeded, allocations will fail.  */
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
comment|/*  * Get an estimate of the number of memory in use in 'mctx', in bytes.  * This includes quantization overhead, but does not include memory  * allocated from the system but not yet used.  */
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
comment|/*  * Set high and low water marks for this memory context.  When the memory  * usage of 'mctx' exceeds 'hiwater', '(water)(water_arg, ISC_MEM_HIWATER)'  * will be called.  When the usage drops below 'lowater', 'water' will  * again be called, this time with ISC_MEM_LOWATER.  *  * If 'water' is NULL then 'water_arg', 'hi_water' and 'lo_water' are  * ignored and the state is reset.  *  * Requires:  *  *	'water' is not NULL.  *	hi_water>= lo_water  */
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
comment|/*  * Create a memory pool.  *  * Requires:  *	mctx is a valid memory context.  *	size> 0  *	mpctxp != NULL and *mpctxp == NULL  *  * Defaults:  *	maxalloc = UINT_MAX  *	freemax = 1  *	fillcount = 1  *  * Returns:  *	ISC_R_NOMEMORY		-- not enough memory to create pool  *	ISC_R_SUCCESS		-- all is well.  */
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
comment|/*  * Destroy a memory pool.  *  * Requires:  *	mpctxp != NULL&& *mpctxp is a valid pool.  *	The pool has no un"put" allocations outstanding  */
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
comment|/*  * Associate a name with a memory pool.  At most 15 characters may be used.  *  * Requires:  *	mpctx is a valid pool.  *	name != NULL;  */
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
comment|/*  * Associate a lock with this memory pool.  *  * This lock is used when getting or putting items using this memory pool,  * and it is also used to set or get internal state via the isc_mempool_get*()  * and isc_mempool_set*() set of functions.  *  * Mutiple pools can each share a single lock.  For instance, if "manager"  * type object contained pools for various sizes of events, and each of  * these pools used a common lock.  Note that this lock must NEVER be used  * by other than mempool routines once it is given to a pool, since that can  * easily cause double locking.  *  * Requires:  *  *	mpctpx is a valid pool.  *  *	lock != NULL.  *  *	No previous lock is assigned to this pool.  *  *	The lock is initialized before calling this function via the normal  *	means of doing that.  */
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
comment|/*  * Returns the maximum allowed size of the free list.  */
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
comment|/*  * Sets the maximum allowed size of the free list.  */
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
comment|/*  * Returns current size of the free list.  */
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
comment|/*  * Returns the maximum allowed number of allocations.  */
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
comment|/*  * Sets the maximum allowed number of allocations.  *  * Additional requirements:  *	limit> 0  */
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
comment|/*  * Returns the number of items allocated from this pool.  */
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
comment|/*  * Returns the number of items allocated as a block from the parent memory  * context when the free list is empty.  */
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
comment|/*  * Sets the fillcount.  *  * Additional requirements:  *	limit> 0  */
end_comment

begin_comment
comment|/*  * Pseudo-private functions for use via macros.  Do not call directly.  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc__mem_get
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
name|isc__mem_putanddetach
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
name|isc__mem_put
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
name|isc__mem_allocate
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
name|isc__mem_free
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
name|isc__mem_strdup
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
name|isc__mempool_get
parameter_list|(
name|isc_mempool_t
modifier|*
name|_ISC_MEM_FLARG
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc__mempool_put
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

