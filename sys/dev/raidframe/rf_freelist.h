begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_freelist.h,v 1.6 2002/08/08 02:53:01 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_freelist.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_freelist.h -- code to manage counted freelists  *  * Keep an arena of fixed-size objects. When a new object is needed,  * allocate it as necessary. When an object is freed, either put it  * in the arena, or really free it, depending on the maximum arena  * size.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_FREELIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_FREELIST_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_debugMem.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_general.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_define
define|#
directive|define
name|RF_FREELIST_STATS
value|0
end_define

begin_if
if|#
directive|if
name|RF_FREELIST_STATS
operator|>
literal|0
end_if

begin_typedef
typedef|typedef
struct|struct
name|RF_FreeListStats_s
block|{
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
name|int
name|allocations
decl_stmt|;
name|int
name|frees
decl_stmt|;
name|int
name|max_free
decl_stmt|;
name|int
name|grows
decl_stmt|;
name|int
name|outstanding
decl_stmt|;
name|int
name|max_outstanding
decl_stmt|;
block|}
name|RF_FreeListStats_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_INIT
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	bzero((char *)&((_fl_)->stats), sizeof(RF_FreeListStats_t)); \ 	(_fl_)->stats.file = __FILE__; \ 	(_fl_)->stats.line = __LINE__; \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_ALLOC
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	(_fl_)->stats.allocations++; \ 	(_fl_)->stats.outstanding++; \ 	if ((_fl_)->stats.outstanding> (_fl_)->stats.max_outstanding) \ 		(_fl_)->stats.max_outstanding = (_fl_)->stats.outstanding; \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_FREE_UPDATE
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	if ((_fl_)->free_cnt> (_fl_)->stats.max_free) \ 		(_fl_)->stats.max_free = (_fl_)->free_cnt; \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_FREE
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	(_fl_)->stats.frees++; \ 	(_fl_)->stats.outstanding--; \ 	RF_FREELIST_STAT_FREE_UPDATE(_fl_); \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_GROW
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	(_fl_)->stats.grows++; \ 	RF_FREELIST_STAT_FREE_UPDATE(_fl_); \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_REPORT
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	printf("Freelist at %s %d (%s)\n", (_fl_)->stats.file, (_fl_)->stats.line, RF_STRING(_fl_)); \ 	printf("  %d allocations, %d frees\n", (_fl_)->stats.allocations, (_fl_)->stats.frees); \ 	printf("  %d grows\n", (_fl_)->stats.grows); \ 	printf("  %d outstanding\n", (_fl_)->stats.outstanding); \ 	printf("  %d free (max)\n", (_fl_)->stats.max_free); \ 	printf("  %d outstanding (max)\n", (_fl_)->stats.max_outstanding); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* RF_FREELIST_STATS> 0 */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_INIT
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_ALLOC
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_FREE_UPDATE
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_FREE
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_GROW
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_STAT_REPORT
parameter_list|(
name|_fl_
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_FREELIST_STATS> 0 */
end_comment

begin_struct
struct|struct
name|RF_FreeList_s
block|{
name|void
modifier|*
name|objlist
decl_stmt|;
comment|/* list of free obj */
name|int
name|free_cnt
decl_stmt|;
comment|/* how many free obj */
name|int
name|max_free_cnt
decl_stmt|;
comment|/* max free arena size */
name|int
name|obj_inc
decl_stmt|;
comment|/* how many to allocate at a time */
name|int
name|obj_size
decl_stmt|;
comment|/* size of objects */
name|RF_DECLARE_MUTEX
argument_list|(
argument|lock
argument_list|)
if|#
directive|if
name|RF_FREELIST_STATS
operator|>
literal|0
name|RF_FreeListStats_t
name|stats
decl_stmt|;
comment|/* statistics */
endif|#
directive|endif
comment|/* RF_FREELIST_STATS> 0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * fl     = freelist  * maxcnt = max number of items in arena  * inc    = how many to allocate at a time  * size   = size of object  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_CREATE
parameter_list|(
name|_fl_
parameter_list|,
name|_maxcnt_
parameter_list|,
name|_inc_
parameter_list|,
name|_size_
parameter_list|)
value|{ \ 	int rc; \ 	RF_ASSERT((_inc_)> 0); \ 	RF_Malloc(_fl_, sizeof(RF_FreeList_t), (RF_FreeList_t *)); \ 	(_fl_)->objlist = NULL; \ 	(_fl_)->free_cnt = 0; \ 	(_fl_)->max_free_cnt = _maxcnt_; \ 	(_fl_)->obj_inc = _inc_; \ 	(_fl_)->obj_size = _size_; \ 	rc = rf_mutex_init(&(_fl_)->lock, "RF_FREELIST"); \ 	if (rc) { \ 		RF_Free(_fl_, sizeof(RF_FreeList_t)); \ 		_fl_ = NULL; \ 	} \ 	RF_FREELIST_STAT_INIT(_fl_); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * cnt   = number to prime with  * nextp = name of "next" pointer in obj  * cast  = object cast  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_PRIME
parameter_list|(
name|_fl_
parameter_list|,
name|_cnt_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	for(_i=0;_i<(_cnt_);_i++) { \ 		RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 		if (_p) { \ 			RF_LOCK_MUTEX((_fl_)->lock); \ 			(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 			(_fl_)->objlist = _p; \ 			(_fl_)->free_cnt++; \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \ 		} \ 		else { \ 			break; \ 		} \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_FREE_UPDATE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_MUTEX_OF
parameter_list|(
name|_fl_
parameter_list|)
value|((_fl_)->lock)
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_DO_UNLOCK
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_define
define|#
directive|define
name|RF_FREELIST_DO_LOCK
parameter_list|(
name|_fl_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * cnt   = number to prime with  * nextp = name of "next" pointer in obj  * cast  = object cast  * init  = func to call to init obj  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_PRIME_INIT
parameter_list|(
name|_fl_
parameter_list|,
name|_cnt_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_init_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	for(_i=0;_i<(_cnt_);_i++) { \ 		RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 		if (_init_ (_cast_ _p)) { \ 			RF_Free(_p,(_fl_)->obj_size); \ 			_p = NULL; \ 		} \ 		if (_p) { \ 			RF_LOCK_MUTEX((_fl_)->lock); \ 			(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 			(_fl_)->objlist = _p; \ 			(_fl_)->free_cnt++; \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \ 		} \ 		else { \ 			break; \ 		} \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_FREE_UPDATE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * cnt   = number to prime with  * nextp = name of "next" pointer in obj  * cast  = object cast  * init  = func to call to init obj  * arg   = arg to init obj func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_PRIME_INIT_ARG
parameter_list|(
name|_fl_
parameter_list|,
name|_cnt_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_init_
parameter_list|,
name|_arg_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	for(_i=0;_i<(_cnt_);_i++) { \ 		RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 		if (_init_ (_cast_ _p,_arg_)) { \ 			RF_Free(_p,(_fl_)->obj_size); \ 			_p = NULL; \ 		} \ 		if (_p) { \ 			RF_LOCK_MUTEX((_fl_)->lock); \ 			(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 			(_fl_)->objlist = _p; \ 			(_fl_)->free_cnt++; \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \ 		} \ 		else { \ 			break; \ 		} \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_FREE_UPDATE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to allocate  * nextp = name of "next" pointer in obj  * cast  = cast of obj assignment  * init  = init obj func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_GET_INIT
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_init_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_ASSERT(sizeof(*(_obj_))==((_fl_)->obj_size)); \ 	if (_fl_->objlist) { \ 		_obj_ = _cast_((_fl_)->objlist); \ 		(_fl_)->objlist = (void *)((_obj_)->_nextp_); \ 		(_fl_)->free_cnt--; \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	else { \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \
comment|/* \ 		 * Allocate one at a time so we can free \ 		 * one at a time without cleverness when arena \ 		 * is full. \ 		 */
value|\ 		RF_Calloc(_obj_,1,(_fl_)->obj_size,_cast_); \ 		if (_obj_) { \ 			if (_init_ (_obj_)) { \ 				RF_Free(_obj_,(_fl_)->obj_size); \ 				_obj_ = NULL; \ 			} \ 			else { \ 				for(_i=1;_i<(_fl_)->obj_inc;_i++) { \ 					RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 					if (_p) { \ 						if (_init_ (_p)) { \ 							RF_Free(_p,(_fl_)->obj_size); \ 							_p = NULL; \ 							break; \ 						} \ 						RF_LOCK_MUTEX((_fl_)->lock); \ 						(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 						(_fl_)->objlist = _p; \ 						RF_UNLOCK_MUTEX((_fl_)->lock); \ 					} \ 					else { \ 						break; \ 					} \ 				} \ 			} \ 		} \ 		RF_LOCK_MUTEX((_fl_)->lock); \ 		RF_FREELIST_STAT_GROW(_fl_); \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_ALLOC(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to allocate  * nextp = name of "next" pointer in obj  * cast  = cast of obj assignment  * init  = init obj func  * arg   = arg to init obj func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_GET_INIT_ARG
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_init_
parameter_list|,
name|_arg_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_ASSERT(sizeof(*(_obj_))==((_fl_)->obj_size)); \ 	if (_fl_->objlist) { \ 		_obj_ = _cast_((_fl_)->objlist); \ 		(_fl_)->objlist = (void *)((_obj_)->_nextp_); \ 		(_fl_)->free_cnt--; \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	else { \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \
comment|/* \ 		 * Allocate one at a time so we can free \ 		 * one at a time without cleverness when arena \ 		 * is full. \ 		 */
value|\ 		RF_Calloc(_obj_,1,(_fl_)->obj_size,_cast_); \ 		if (_obj_) { \ 			if (_init_ (_obj_,_arg_)) { \ 				RF_Free(_obj_,(_fl_)->obj_size); \ 				_obj_ = NULL; \ 			} \ 			else { \ 				for(_i=1;_i<(_fl_)->obj_inc;_i++) { \ 					RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 					if (_p) { \ 						if (_init_ (_p,_arg_)) { \ 							RF_Free(_p,(_fl_)->obj_size); \ 							_p = NULL; \ 							break; \ 						} \ 						RF_LOCK_MUTEX((_fl_)->lock); \ 						(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 						(_fl_)->objlist = _p; \ 						RF_UNLOCK_MUTEX((_fl_)->lock); \ 					} \ 					else { \ 						break; \ 					} \ 				} \ 			} \ 		} \ 		RF_LOCK_MUTEX((_fl_)->lock); \ 		RF_FREELIST_STAT_GROW(_fl_); \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_ALLOC(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to allocate  * nextp = name of "next" pointer in obj  * cast  = cast of obj assignment  * init  = init obj func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_GET_INIT_NOUNLOCK
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_init_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_ASSERT(sizeof(*(_obj_))==((_fl_)->obj_size)); \ 	if (_fl_->objlist) { \ 		_obj_ = _cast_((_fl_)->objlist); \ 		(_fl_)->objlist = (void *)((_obj_)->_nextp_); \ 		(_fl_)->free_cnt--; \ 	} \ 	else { \
comment|/* \ 		 * Allocate one at a time so we can free \ 		 * one at a time without cleverness when arena \ 		 * is full. \ 		 */
value|\ 		RF_Calloc(_obj_,1,(_fl_)->obj_size,_cast_); \ 		if (_obj_) { \ 			if (_init_ (_obj_)) { \ 				RF_Free(_obj_,(_fl_)->obj_size); \ 				_obj_ = NULL; \ 			} \ 			else { \ 				for(_i=1;_i<(_fl_)->obj_inc;_i++) { \ 					RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 					if (_p) { \ 						if (_init_ (_p)) { \ 							RF_Free(_p,(_fl_)->obj_size); \ 							_p = NULL; \ 							break; \ 						} \ 						(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 						(_fl_)->objlist = _p; \ 					} \ 					else { \ 						break; \ 					} \ 				} \ 			} \ 		} \ 		RF_FREELIST_STAT_GROW(_fl_); \ 	} \ 	RF_FREELIST_STAT_ALLOC(_fl_); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to allocate  * nextp = name of "next" pointer in obj  * cast  = cast of obj assignment  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_GET
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|)
value|{ \ 	void *_p; \ 	int _i; \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_ASSERT(sizeof(*(_obj_))==((_fl_)->obj_size)); \ 	if (_fl_->objlist) { \ 		_obj_ = _cast_((_fl_)->objlist); \ 		(_fl_)->objlist = (void *)((_obj_)->_nextp_); \ 		(_fl_)->free_cnt--; \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	else { \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \
comment|/* \ 		 * Allocate one at a time so we can free \ 		 * one at a time without cleverness when arena \ 		 * is full. \ 		 */
value|\ 		RF_Calloc(_obj_,1,(_fl_)->obj_size,_cast_); \ 		if (_obj_) { \ 			for(_i=1;_i<(_fl_)->obj_inc;_i++) { \ 				RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 				if (_p) { \ 					RF_LOCK_MUTEX((_fl_)->lock); \ 					(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 					(_fl_)->objlist = _p; \ 					RF_UNLOCK_MUTEX((_fl_)->lock); \ 				} \ 				else { \ 					break; \ 				} \ 			} \ 		} \ 		RF_LOCK_MUTEX((_fl_)->lock); \ 		RF_FREELIST_STAT_GROW(_fl_); \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	RF_FREELIST_STAT_ALLOC(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to allocate  * nextp = name of "next" pointer in obj  * cast  = cast of obj assignment  * num   = num objs to return  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_GET_N
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_num_
parameter_list|)
value|{ \ 	void *_p, *_l, *_f; \ 	int _i, _n; \ 	_l = _f = NULL; \ 	_n = 0; \ 	RF_ASSERT(sizeof(*(_obj_))==((_fl_)->obj_size)); \ 	for(_n=0;_n<_num_;_n++) { \ 		RF_LOCK_MUTEX((_fl_)->lock); \ 		if (_fl_->objlist) { \ 			_obj_ = _cast_((_fl_)->objlist); \ 			(_fl_)->objlist = (void *)((_obj_)->_nextp_); \ 			(_fl_)->free_cnt--; \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \ 		} \ 		else { \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \
comment|/* \ 			 * Allocate one at a time so we can free \ 			 * one at a time without cleverness when arena \ 			 * is full. \ 			 */
value|\ 			RF_Calloc(_obj_,1,(_fl_)->obj_size,_cast_); \ 			if (_obj_) { \ 				for(_i=1;_i<(_fl_)->obj_inc;_i++) { \ 					RF_Calloc(_p,1,(_fl_)->obj_size,(void *)); \ 					if (_p) { \ 						RF_LOCK_MUTEX((_fl_)->lock); \ 						(_cast_(_p))->_nextp_ = (_fl_)->objlist; \ 						(_fl_)->objlist = _p; \ 						RF_UNLOCK_MUTEX((_fl_)->lock); \ 					} \ 					else { \ 						break; \ 					} \ 				} \ 			} \ 			RF_LOCK_MUTEX((_fl_)->lock); \ 			RF_FREELIST_STAT_GROW(_fl_); \ 			RF_UNLOCK_MUTEX((_fl_)->lock); \ 		} \ 		RF_LOCK_MUTEX((_fl_)->lock); \ 		if (_f == NULL) \ 			_f = _obj_; \ 		if (_obj_) { \ 			(_cast_(_obj_))->_nextp_ = _l; \ 			_l = _obj_; \ 			RF_FREELIST_STAT_ALLOC(_fl_); \ 		} \ 		else { \ 			(_cast_(_f))->_nextp_ = (_fl_)->objlist; \ 			(_fl_)->objlist = _l; \ 			_n = _num_; \ 		} \ 		RF_UNLOCK_MUTEX((_fl_)->lock); \ 	} \ }
end_define

begin_comment
comment|/*  * fl = freelist  * obj   = object to free  * nextp = name of "next" pointer in obj  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_FREE
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	if ((_fl_)->free_cnt == (_fl_)->max_free_cnt) { \ 		RF_Free(_obj_,(_fl_)->obj_size); \ 	} \ 	else { \ 		RF_ASSERT((_fl_)->free_cnt< (_fl_)->max_free_cnt); \ 		(_obj_)->_nextp_ = (_fl_)->objlist; \ 		(_fl_)->objlist = (void *)(_obj_); \ 		(_fl_)->free_cnt++; \ 	} \ 	RF_FREELIST_STAT_FREE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to free  * nextp = name of "next" pointer in obj  * num   = num to free (debugging)  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_FREE_N
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_num_
parameter_list|)
value|{ \ 	void *_no; \ 	int _n; \ 	_n = 0; \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	while(_obj_) { \ 		_no = (_cast_(_obj_))->_nextp_; \ 		if ((_fl_)->free_cnt == (_fl_)->max_free_cnt) { \ 			RF_Free(_obj_,(_fl_)->obj_size); \ 		} \ 		else { \ 			RF_ASSERT((_fl_)->free_cnt< (_fl_)->max_free_cnt); \ 			(_obj_)->_nextp_ = (_fl_)->objlist; \ 			(_fl_)->objlist = (void *)(_obj_); \ 			(_fl_)->free_cnt++; \ 		} \ 		_n++; \ 		_obj_ = _no; \ 		RF_FREELIST_STAT_FREE(_fl_); \ 	} \ 	RF_ASSERT(_n==(_num_)); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to free  * nextp = name of "next" pointer in obj  * clean = undo for init  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_FREE_CLEAN
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_clean_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	if ((_fl_)->free_cnt == (_fl_)->max_free_cnt) { \ 		_clean_ (_obj_); \ 		RF_Free(_obj_,(_fl_)->obj_size); \ 	} \ 	else { \ 		RF_ASSERT((_fl_)->free_cnt< (_fl_)->max_free_cnt); \ 		(_obj_)->_nextp_ = (_fl_)->objlist; \ 		(_fl_)->objlist = (void *)(_obj_); \ 		(_fl_)->free_cnt++; \ 	} \ 	RF_FREELIST_STAT_FREE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to free  * nextp = name of "next" pointer in obj  * clean = undo for init  * arg   = arg for undo func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_FREE_CLEAN_ARG
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_clean_
parameter_list|,
name|_arg_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	if ((_fl_)->free_cnt == (_fl_)->max_free_cnt) { \ 		_clean_ (_obj_,_arg_); \ 		RF_Free(_obj_,(_fl_)->obj_size); \ 	} \ 	else { \ 		RF_ASSERT((_fl_)->free_cnt< (_fl_)->max_free_cnt); \ 		(_obj_)->_nextp_ = (_fl_)->objlist; \ 		(_fl_)->objlist = (void *)(_obj_); \ 		(_fl_)->free_cnt++; \ 	} \ 	RF_FREELIST_STAT_FREE(_fl_); \ 	RF_UNLOCK_MUTEX((_fl_)->lock); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * obj   = object to free  * nextp = name of "next" pointer in obj  * clean = undo for init  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_FREE_CLEAN_NOUNLOCK
parameter_list|(
name|_fl_
parameter_list|,
name|_obj_
parameter_list|,
name|_nextp_
parameter_list|,
name|_clean_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_fl_)->lock); \ 	if ((_fl_)->free_cnt == (_fl_)->max_free_cnt) { \ 		_clean_ (_obj_); \ 		RF_Free(_obj_,(_fl_)->obj_size); \ 	} \ 	else { \ 		RF_ASSERT((_fl_)->free_cnt< (_fl_)->max_free_cnt); \ 		(_obj_)->_nextp_ = (_fl_)->objlist; \ 		(_fl_)->objlist = (void *)(_obj_); \ 		(_fl_)->free_cnt++; \ 	} \ 	RF_FREELIST_STAT_FREE(_fl_); \ }
end_define

begin_comment
comment|/*  * fl     = freelist  * nextp = name of "next" pointer in obj  * cast  = cast to object type  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_DESTROY
parameter_list|(
name|_fl_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|)
value|{ \ 	void *_cur, *_next; \ 	RF_FREELIST_STAT_REPORT(_fl_); \ 	rf_mutex_destroy(&((_fl_)->lock)); \ 	for(_cur=(_fl_)->objlist;_cur;_cur=_next) { \ 		_next = (_cast_ _cur)->_nextp_; \ 		RF_Free(_cur,(_fl_)->obj_size); \ 	} \ 	RF_Free(_fl_,sizeof(RF_FreeList_t)); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * nextp = name of "next" pointer in obj  * cast  = cast to object type  * clean = func to undo obj init  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_DESTROY_CLEAN
parameter_list|(
name|_fl_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_clean_
parameter_list|)
value|{ \ 	void *_cur, *_next; \ 	RF_FREELIST_STAT_REPORT(_fl_); \ 	rf_mutex_destroy(&((_fl_)->lock)); \ 	for(_cur=(_fl_)->objlist;_cur;_cur=_next) { \ 		_next = (_cast_ _cur)->_nextp_; \ 		_clean_ (_cur); \ 		RF_Free(_cur,(_fl_)->obj_size); \ 	} \ 	RF_Free(_fl_,sizeof(RF_FreeList_t)); \ }
end_define

begin_comment
comment|/*  * fl    = freelist  * nextp = name of "next" pointer in obj  * cast  = cast to object type  * clean = func to undo obj init  * arg   = arg for undo func  */
end_comment

begin_define
define|#
directive|define
name|RF_FREELIST_DESTROY_CLEAN_ARG
parameter_list|(
name|_fl_
parameter_list|,
name|_nextp_
parameter_list|,
name|_cast_
parameter_list|,
name|_clean_
parameter_list|,
name|_arg_
parameter_list|)
value|{ \ 	void *_cur, *_next; \ 	RF_FREELIST_STAT_REPORT(_fl_); \ 	rf_mutex_destroy(&((_fl_)->lock)); \ 	for(_cur=(_fl_)->objlist;_cur;_cur=_next) { \ 		_next = (_cast_ _cur)->_nextp_; \ 		_clean_ (_cur,_arg_); \ 		RF_Free(_cur,(_fl_)->obj_size); \ 	} \ 	RF_Free(_fl_,sizeof(RF_FreeList_t)); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_FREELIST_H_ */
end_comment

end_unit

