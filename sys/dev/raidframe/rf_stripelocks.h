begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_stripelocks.h,v 1.3 1999/02/05 00:06:18 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************  *  * stripelocks.h -- header file for locking stripes  *  * Note that these functions are called from the execution routines of certain  * DAG Nodes, and so they must be NON-BLOCKING to assure maximum parallelism  * in the DAG.  Accordingly, when a node wants to acquire a lock, it calls  * AcquireStripeLock, supplying a pointer to a callback function.  If the lock  * is free at the time of the call, 0 is returned, indicating that the lock  * has been acquired.  If the lock is not free, 1 is returned, and a copy of  * the function pointer and argument are held in the lock table.  When the  * lock becomes free, the callback function is invoked.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_STRIPELOCKS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_STRIPELOCKS_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_KERNEL
end_if

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_general.h>
end_include

begin_struct
struct|struct
name|RF_LockReqDesc_s
block|{
name|RF_IoType_t
name|type
decl_stmt|;
comment|/* read or write */
name|RF_int64
name|start
decl_stmt|,
name|stop
decl_stmt|;
comment|/* start and end of range to be locked */
name|RF_int64
name|start2
decl_stmt|,
name|stop2
decl_stmt|;
comment|/* start and end of 2nd range to be locked */
name|void
function_decl|(
modifier|*
name|cbFunc
function_decl|)
parameter_list|(
name|RF_Buf_t
parameter_list|)
function_decl|;
comment|/* callback function */
name|void
modifier|*
name|cbArg
decl_stmt|;
comment|/* argument to callback function */
name|RF_LockReqDesc_t
modifier|*
name|next
decl_stmt|;
comment|/* next element in chain */
name|RF_LockReqDesc_t
modifier|*
name|templink
decl_stmt|;
comment|/* for making short-lived lists of 					 * request descriptors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_ASSERT_VALID_LOCKREQ
parameter_list|(
name|_lr_
parameter_list|)
value|{ \ 	RF_ASSERT(RF_IO_IS_R_OR_W((_lr_)->type)); \ }
end_define

begin_struct
struct|struct
name|RF_StripeLockDesc_s
block|{
name|RF_StripeNum_t
name|stripeID
decl_stmt|;
comment|/* the stripe ID */
name|RF_LockReqDesc_t
modifier|*
name|granted
decl_stmt|;
comment|/* unordered list of granted requests */
name|RF_LockReqDesc_t
modifier|*
name|waitersH
decl_stmt|;
comment|/* FIFO queue of all waiting reqs, 					 * both read and write (Head and Tail) */
name|RF_LockReqDesc_t
modifier|*
name|waitersT
decl_stmt|;
name|int
name|nWriters
decl_stmt|;
comment|/* number of writers either granted or waiting */
name|RF_StripeLockDesc_t
modifier|*
name|next
decl_stmt|;
comment|/* for hash table collision resolution */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_LockTableEntry_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* mutex on this hash chain */
name|RF_StripeLockDesc_t
modifier|*
name|descList
decl_stmt|;
comment|/* hash chain of lock descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initializes a stripe lock descriptor.  _defSize is the number of sectors  * that we lock when there is no parity information in the ASM (e.g. RAID0).  */
end_comment

begin_define
define|#
directive|define
name|RF_INIT_LOCK_REQ_DESC
parameter_list|(
name|_lrd
parameter_list|,
name|_typ
parameter_list|,
name|_cbf
parameter_list|,
name|_cba
parameter_list|,
name|_asm
parameter_list|,
name|_defSize
parameter_list|)
define|\
value|{                                                                                                          \     (_lrd).type    = _typ;                                                                                   \     (_lrd).start2  = -1;                                                                                     \     (_lrd).stop2   = -1;                                                                                     \     if ((_asm)->parityInfo) {                                                                                \       (_lrd).start = (_asm)->parityInfo->startSector;                                                        \       (_lrd).stop  = (_asm)->parityInfo->startSector + (_asm)->parityInfo->numSector-1;                      \       if ((_asm)->parityInfo->next) {                                                                        \         (_lrd).start2  = (_asm)->parityInfo->next->startSector;                                              \         (_lrd).stop2   = (_asm)->parityInfo->next->startSector + (_asm)->parityInfo->next->numSector-1;      \       }                                                                                                      \     } else {                                                                                                 \       (_lrd).start = 0;                                                                                      \       (_lrd).stop  = (_defSize);                                                                             \     }													     \     (_lrd).templink= NULL;                                                                                   \     (_lrd).cbFunc  = (_cbf);                                                                                 \     (_lrd).cbArg   = (void *) (_cba);                                                                        \   }
end_define

begin_function_decl
name|int
name|rf_ConfigureStripeLockFreeList
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_LockTableEntry_t
modifier|*
name|rf_MakeLockTable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ShutdownStripeLocks
parameter_list|(
name|RF_LockTableEntry_t
modifier|*
name|lockTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureStripeLocks
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_AcquireStripeLock
parameter_list|(
name|RF_LockTableEntry_t
modifier|*
name|lockTable
parameter_list|,
name|RF_StripeNum_t
name|stripeID
parameter_list|,
name|RF_LockReqDesc_t
modifier|*
name|lockReqDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ReleaseStripeLock
parameter_list|(
name|RF_LockTableEntry_t
modifier|*
name|lockTable
parameter_list|,
name|RF_StripeNum_t
name|stripeID
parameter_list|,
name|RF_LockReqDesc_t
modifier|*
name|lockReqDesc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_STRIPELOCKS_H_ */
end_comment

end_unit

