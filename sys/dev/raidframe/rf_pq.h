begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_pq.h,v 1.3 1999/02/05 00:06:15 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_pq.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Daniel Stodolsky  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PQ_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_pFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_pRecoveryFuncs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rf_RegularONPFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SimpleONPFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RecoveryPFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegularPFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|RF_INCLUDE_DECL_PQ
operator|>
literal|0
operator|)
operator|||
operator|(
name|RF_INCLUDE_RAID6
operator|>
literal|0
operator|)
end_if

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_qFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_qRecoveryFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_pqRecoveryFuncs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|rf_PQDagSelect
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_IoType_t
name|type
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_VoidFuncPtr
modifier|*
name|createFunc
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQCreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|rf_RegularONQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SimpleONQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQCreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|rf_RegularPQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegularQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_Degraded_100_PQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RecoveryQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RecoveryPQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PQ_DegradedWriteQFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_IncQ
parameter_list|(
name|unsigned
name|long
modifier|*
name|dest
parameter_list|,
name|unsigned
name|long
modifier|*
name|buf
parameter_list|,
name|unsigned
name|length
parameter_list|,
name|unsigned
name|coeff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PQ_recover
parameter_list|(
name|unsigned
name|long
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|long
modifier|*
name|qbuf
parameter_list|,
name|unsigned
name|long
modifier|*
name|abuf
parameter_list|,
name|unsigned
name|long
modifier|*
name|bbuf
parameter_list|,
name|unsigned
name|length
parameter_list|,
name|unsigned
name|coeff_a
parameter_list|,
name|unsigned
name|coeff_b
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (RF_INCLUDE_DECL_PQ> 0) || 				 * (RF_INCLUDE_RAID6> 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PQ_H_ */
end_comment

end_unit

