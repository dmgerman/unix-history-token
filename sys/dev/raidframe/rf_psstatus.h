begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_psstatus.h,v 1.3 1999/02/05 00:06:15 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*****************************************************************************  *  * psstatus.h  *  * The reconstruction code maintains a bunch of status related to the parity  * stripes that are currently under reconstruction.  This header file defines  * the status structures.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PSSTATUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PSSTATUS_H_
end_define

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
file|<dev/raidframe/rf_callback.h>
end_include

begin_define
define|#
directive|define
name|RF_PS_MAX_BUFS
value|10
end_define

begin_comment
comment|/* max number of bufs we'll accumulate before 				 * we do an XOR */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_DEFAULT_TABLESIZE
value|200
end_define

begin_comment
comment|/*  * Macros to acquire/release the mutex lock on a parity stripe status  * descriptor. Note that we use just one lock for the whole hash chain.  */
end_comment

begin_define
define|#
directive|define
name|RF_HASH_PSID
parameter_list|(
name|_raid_
parameter_list|,
name|_psid_
parameter_list|)
value|( (_psid_) % ((_raid_)->pssTableSize) )
end_define

begin_comment
comment|/* simple hash function */
end_comment

begin_define
define|#
directive|define
name|RF_LOCK_PSS_MUTEX
parameter_list|(
name|_raidPtr
parameter_list|,
name|_row
parameter_list|,
name|_psid
parameter_list|)
define|\
value|RF_LOCK_MUTEX((_raidPtr)->reconControl[_row]->pssTable[ RF_HASH_PSID(_raidPtr,_psid) ].mutex)
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_PSS_MUTEX
parameter_list|(
name|_raidPtr
parameter_list|,
name|_row
parameter_list|,
name|_psid
parameter_list|)
define|\
value|RF_UNLOCK_MUTEX((_raidPtr)->reconControl[_row]->pssTable[ RF_HASH_PSID(_raidPtr,_psid) ].mutex)
end_define

begin_struct
struct|struct
name|RF_ReconParityStripeStatus_s
block|{
name|RF_StripeNum_t
name|parityStripeID
decl_stmt|;
comment|/* the parity stripe ID */
name|RF_ReconUnitNum_t
name|which_ru
decl_stmt|;
comment|/* which reconstruction unit with the 					 * indicated parity stripe */
name|RF_PSSFlags_t
name|flags
decl_stmt|;
comment|/* flags indicating various conditions */
name|void
modifier|*
name|rbuf
decl_stmt|;
comment|/* this is the accumulating xor sum */
name|void
modifier|*
name|writeRbuf
decl_stmt|;
comment|/* DEBUG ONLY:  a pointer to the rbuf after it 				 * has filled& been sent to disk */
name|void
modifier|*
name|rbufsForXor
index|[
name|RF_PS_MAX_BUFS
index|]
decl_stmt|;
comment|/* these are buffers still to 						 * be xored into the 						 * accumulating sum */
name|int
name|xorBufCount
decl_stmt|;
comment|/* num buffers waiting to be xored */
name|int
name|blockCount
decl_stmt|;
comment|/* count of # proc that have blocked recon on 				 * this parity stripe */
name|char
modifier|*
name|issued
decl_stmt|;
comment|/* issued[i]==1<=> column i has already 				 * issued a read request for the indicated RU */
name|RF_CallbackDesc_t
modifier|*
name|procWaitList
decl_stmt|;
comment|/* list of user procs waiting 						 * for recon to be done */
name|RF_CallbackDesc_t
modifier|*
name|blockWaitList
decl_stmt|;
comment|/* list of disks blocked 						 * waiting for user write to 						 * complete */
name|RF_CallbackDesc_t
modifier|*
name|bufWaitList
decl_stmt|;
comment|/* list of disks blocked waiting to 					 * acquire a buffer for this RU */
name|RF_ReconParityStripeStatus_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_PSStatusHeader_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
comment|/* mutex for this hash chain */
name|RF_ReconParityStripeStatus_t
modifier|*
name|chain
decl_stmt|;
comment|/* the hash chain */
block|}
struct|;
end_struct

begin_comment
comment|/* masks for the "flags" field above */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_NONE
value|0x00000000
end_define

begin_comment
comment|/* no flags */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_UNDER_RECON
value|0x00000001
end_define

begin_comment
comment|/* this parity stripe is 						 * currently under 						 * reconstruction */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_FORCED_ON_WRITE
value|0x00000002
end_define

begin_comment
comment|/* indicates a recon was 						 * forced due to a user-write 						 * operation */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_FORCED_ON_READ
value|0x00000004
end_define

begin_comment
comment|/* ditto for read, but not 						 * currently implemented */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_RECON_BLOCKED
value|0x00000008
end_define

begin_comment
comment|/* reconstruction is currently 						 * blocked due to a pending 						 * user I/O */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_CREATE
value|0x00000010
end_define

begin_comment
comment|/* tells LookupRUStatus to 						 * create the entry */
end_comment

begin_define
define|#
directive|define
name|RF_PSS_BUFFERWAIT
value|0x00000020
end_define

begin_comment
comment|/* someone is waiting for a 						 * buffer for this RU */
end_comment

begin_function_decl
name|int
name|rf_ConfigurePSStatus
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
name|RF_PSStatusHeader_t
modifier|*
name|rf_MakeParityStripeStatusTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeParityStripeStatusTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PSStatusHeader_t
modifier|*
name|pssTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconParityStripeStatus_t
modifier|*
name|rf_LookupRUStatus
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PSStatusHeader_t
modifier|*
name|pssTable
parameter_list|,
name|RF_StripeNum_t
name|psID
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|,
name|RF_PSSFlags_t
name|flags
parameter_list|,
name|int
modifier|*
name|created
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PSStatusDelete
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PSStatusHeader_t
modifier|*
name|pssTable
parameter_list|,
name|RF_ReconParityStripeStatus_t
modifier|*
name|pssPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_RemoveFromActiveReconTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_StripeNum_t
name|psid
parameter_list|,
name|RF_ReconUnitNum_t
name|which_ru
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconParityStripeStatus_t
modifier|*
name|rf_AllocPSStatus
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreePSStatus
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_ReconParityStripeStatus_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintPSStatusTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PSSTATUS_H_ */
end_comment

end_unit

