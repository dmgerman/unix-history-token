begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_debugMem.h,v 1.7 1999/09/05 01:58:11 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Daniel Stodolsky, Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_debugMem.h -- memory leak debugging module  *  * IMPORTANT:  if you put the lock/unlock mutex stuff back in here, you  *             need to take it out of the routines in debugMem.c  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DEBUGMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DEBUGMEM_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_RAIDFRAME
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_Malloc
parameter_list|(
name|_p_
parameter_list|,
name|_size_
parameter_list|,
name|_cast_
parameter_list|)
define|\
value|{                                                                         \      _p_ = _cast_ malloc((u_long)_size_, M_RAIDFRAME, M_NOWAIT | M_ZERO);   \      if (_p_ == NULL) panic("out of memory\n");				    \      if (rf_memDebug) rf_record_malloc(_p_, _size_, __LINE__, __FILE__);    \   }
end_define

begin_define
define|#
directive|define
name|RF_MallocAndAdd
parameter_list|(
name|__p_
parameter_list|,
name|__size_
parameter_list|,
name|__cast_
parameter_list|,
name|__alist_
parameter_list|)
define|\
value|{                                                                         \      RF_Malloc(__p_, __size_, __cast_);                                     \      if (__alist_) rf_AddToAllocList(__alist_, __p_, __size_);              \   }
end_define

begin_define
define|#
directive|define
name|RF_Calloc
parameter_list|(
name|_p_
parameter_list|,
name|_nel_
parameter_list|,
name|_elsz_
parameter_list|,
name|_cast_
parameter_list|)
define|\
value|{                                                                         \      RF_Malloc( _p_, (_nel_) * (_elsz_), _cast_);                           \   }
end_define

begin_define
define|#
directive|define
name|RF_CallocAndAdd
parameter_list|(
name|__p
parameter_list|,
name|__nel
parameter_list|,
name|__elsz
parameter_list|,
name|__cast
parameter_list|,
name|__alist
parameter_list|)
define|\
value|{                                                                         \      RF_Calloc(__p, __nel, __elsz, __cast);                                 \      if (__alist) rf_AddToAllocList(__alist, __p, (__nel)*(__elsz));        \   }
end_define

begin_define
define|#
directive|define
name|RF_Free
parameter_list|(
name|_p_
parameter_list|,
name|_sz_
parameter_list|)
define|\
value|{                                                                         \      free((void *)(_p_), M_RAIDFRAME);                                      \      if (rf_memDebug) rf_unrecord_malloc(_p_, (u_int32_t) (_sz_));          \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|void
name|rf_record_malloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|line
parameter_list|,
name|char
modifier|*
name|filen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_unrecord_malloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|int
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_print_unfreed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureDebugMem
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DEBUGMEM_H_ */
end_comment

end_unit

