begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_pqdegdags.h,v 1.3 1999/02/05 00:06:15 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_pqdegdags.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Daniel Stodolsky  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_pqdegdags.c  * Degraded mode dags for double fault cases.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PQDEGDAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PQDEGDAGS_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dag.h>
end_include

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_DoubleDegRead
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|rf_PQDoubleRecoveryFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_PQWriteDoubleRecoveryFunc
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
name|rf_PQ_DDLargeWrite
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_DDSimpleSmallWrite
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_200_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PQDEGDAGS_H_ */
end_comment

end_unit

