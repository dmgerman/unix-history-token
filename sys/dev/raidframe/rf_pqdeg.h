begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_pqdeg.h,v 1.3 1999/02/05 00:06:15 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Daniel Stodolsky  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_PQDEG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_PQDEG_H_
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
comment|/* extern decl's of the failure mode PQ functions.  * See pddeg.c for nomenclature discussion.  */
end_comment

begin_comment
comment|/* reads, single failure  */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_100_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reads, two failure */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_110_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_101_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_200_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* writes, single failure */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_100_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_010_CreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_010_CreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_001_CreateSmallWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_001_CreateLargeWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* writes, double failure */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_011_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_110_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_101_CreateWriteDAG
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
comment|/* RF_UTILITY == 0 */
end_comment

begin_typedef
typedef|typedef
name|RF_uint32
name|RF_ua32_t
index|[
literal|32
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|RF_uint8
name|RF_ua1024_t
index|[
literal|1024
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|RF_ua32_t
name|rf_rn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_ua32_t
name|rf_qfor
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* we don't support PQ in the kernel yet, so 				 * don't link in this monster table */
end_comment

begin_decl_stmt
specifier|extern
name|RF_ua1024_t
name|rf_qinv
index|[
literal|29
operator|*
literal|29
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_decl_stmt
specifier|extern
name|RF_ua1024_t
name|rf_qinv
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_PQDEG_H_ */
end_comment

end_unit

