begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_parityloggingdags.h,v 1.3 1999/02/05 00:06:14 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: William V. Courtright II  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/****************************************************************************  *                                                                          *  * rf_parityloggingdags.h -- header file for parity logging dags            *  *                                                                          *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PARITYLOGGINGDAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PARITYLOGGINGDAGS_H_
end_define

begin_comment
comment|/* routines that create DAGs */
end_comment

begin_function_decl
name|void
name|rf_CommonCreateParityLoggingLargeWriteDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|,
name|int
name|nfaults
parameter_list|,
name|int
function_decl|(
modifier|*
name|redFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CommonCreateParityLoggingSmallWriteDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|,
name|RF_RedFuncs_t
modifier|*
name|pfuncs
parameter_list|,
name|RF_RedFuncs_t
modifier|*
name|qfuncs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CreateParityLoggingLargeWriteDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|,
name|int
name|nfaults
parameter_list|,
name|int
function_decl|(
modifier|*
name|redFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CreateParityLoggingSmallWriteDAG
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_DagHeader_t
modifier|*
name|dag_h
parameter_list|,
name|void
modifier|*
name|bp
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|,
name|RF_AllocListElem_t
modifier|*
name|allocList
parameter_list|,
name|RF_RedFuncs_t
modifier|*
name|pfuncs
parameter_list|,
name|RF_RedFuncs_t
modifier|*
name|qfuncs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PARITYLOGGINGDAGS_H_ */
end_comment

end_unit

