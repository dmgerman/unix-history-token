begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_evenodd_dags.h,v 1.2 1999/02/05 00:06:11 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_evenodd_dags.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chang-Ming Wu  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_EVENODD_DAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_EVENODD_DAGS_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_if
if|#
directive|if
name|RF_UTILITY
operator|==
literal|0
end_if

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dag.h>
end_include

begin_comment
comment|/* extern decl's of the failure mode EO functions.  * swiped from rf_pqdeg.h  */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_100_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_101_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_110_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_200_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EOCreateDoubleDegradedReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_100_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_010_CreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_001_CreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_010_CreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_001_CreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_011_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_110_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_101_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_DoubleDegRead
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EOCreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EOCreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_EO_200_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_UTILITY == 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_EVENODD_DAGS_H_ */
end_comment

end_unit

