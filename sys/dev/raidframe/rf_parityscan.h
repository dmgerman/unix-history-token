begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_parityscan.h,v 1.3 1999/02/05 00:06:14 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PARITYSCAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PARITYSCAN_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_function_decl
name|int
name|rf_RewriteParity
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_VerifyParityBasic
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidAddr
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|parityPDA
parameter_list|,
name|int
name|correct_it
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_VerifyParity
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|stripeMap
parameter_list|,
name|int
name|correct_it
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_TryToRedirectPDA
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|pda
parameter_list|,
name|int
name|parity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_VerifyDegrModeWrite
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMapHeader_t
modifier|*
name|asmh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_DagHeader_t
modifier|*
name|rf_MakeSimpleDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|int
name|nNodes
parameter_list|,
name|int
name|bytesPerSU
parameter_list|,
name|char
modifier|*
name|databuf
parameter_list|,
name|int
function_decl|(
modifier|*
name|doFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|undoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|alloclist
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RF_DO_CORRECT_PARITY
value|1
end_define

begin_define
define|#
directive|define
name|RF_DONT_CORRECT_PARITY
value|0
end_define

begin_comment
comment|/*  * Return vals for VerifyParity operation  *  * Ordering is important here.  */
end_comment

begin_define
define|#
directive|define
name|RF_PARITY_OKAY
value|0
end_define

begin_comment
comment|/* or no parity information */
end_comment

begin_define
define|#
directive|define
name|RF_PARITY_CORRECTED
value|1
end_define

begin_define
define|#
directive|define
name|RF_PARITY_BAD
value|2
end_define

begin_define
define|#
directive|define
name|RF_PARITY_COULD_NOT_CORRECT
value|3
end_define

begin_define
define|#
directive|define
name|RF_PARITY_COULD_NOT_VERIFY
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PARITYSCAN_H_ */
end_comment

end_unit

