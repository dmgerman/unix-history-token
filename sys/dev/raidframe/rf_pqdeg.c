begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rf_pqdeg.c,v 1.5 2000/01/07 03:41:04 oster Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Daniel Stodolsky  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

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

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_raid.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dag.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagutils.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagfuncs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagffrd.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagffwr.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagdegrd.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagdegwr.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_etimer.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_pqdeg.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_general.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_pqdegdags.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_pq.h>
end_include

begin_comment
comment|/*    Degraded mode dag functions for P+Q calculations.     The following nomenclature is used.     PQ_<D><P><Q>_Create{Large,Small}<Write|Read>DAG     where<D><P><Q> are single digits representing the number of failed    data units<D> (0,1,2), parity units<P> (0,1), and Q units<Q>, effecting    the I/O. The reads have only  PQ_<D><P><Q>_CreateReadDAG variants, while    the single fault writes have both large and small write versions. (Single fault    PQ is equivalent to normal mode raid 5 in many aspects.     Some versions degenerate into the same case, and are grouped together below. */
end_comment

begin_comment
comment|/* Reads, single failure     we have parity, so we can do a raid 5    reconstruct read. */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_100_CreateReadDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CreateDegradedReadDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
operator|&
name|rf_pRecoveryFuncs
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Reads double failure  */
end_comment

begin_comment
comment|/*    Q is lost, but not parity    so we can a raid 5 reconstruct read. */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_101_CreateReadDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CreateDegradedReadDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
operator|&
name|rf_pRecoveryFuncs
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*   parity is lost, so we need to   do a reconstruct read and recompute   the data with Q. */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_110_CreateReadDAG
argument_list|)
end_macro

begin_block
block|{
name|RF_PhysDiskAddr_t
modifier|*
name|temp
decl_stmt|;
comment|/* swap P and Q pointers to fake out the DegradedReadDAG code */
name|temp
operator|=
name|asmap
operator|->
name|parityInfo
expr_stmt|;
name|asmap
operator|->
name|parityInfo
operator|=
name|asmap
operator|->
name|qInfo
expr_stmt|;
name|asmap
operator|->
name|qInfo
operator|=
name|temp
expr_stmt|;
name|rf_CreateDegradedReadDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
operator|&
name|rf_qRecoveryFuncs
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*   Two data units are dead in this stripe, so we will need read   both P and Q to reconstruct the data. Note that only   one data unit we are reading may actually be missing. */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_CreateDoubleDegradedReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_CreateDoubleDegradedReadDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_PQ_DoubleDegRead
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_200_CreateReadDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_200_CreateReadDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CreateDoubleDegradedReadDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Writes, single failure */
end_comment

begin_expr_stmt
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
name|rf_PQ_100_CreateWriteDAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_100_CreateWriteDAG
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|asmap
operator|->
name|numStripeUnitsAccessed
operator|!=
literal|1
operator|&&
name|asmap
operator|->
name|failedPDAs
index|[
literal|0
index|]
operator|->
name|numSector
operator|!=
name|raidPtr
operator|->
name|Layout
operator|.
name|sectorsPerStripeUnit
condition|)
name|RF_PANIC
argument_list|()
expr_stmt|;
name|rf_CommonCreateSimpleDegradedWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
literal|2
argument_list|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|RF_DagNode_t
operator|*
argument_list|)
operator|)
name|rf_Degraded_100_PQFunc
argument_list|,
name|RF_FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Dead  P - act like a RAID 5 small write with parity = Q */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_010_CreateSmallWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|RF_PhysDiskAddr_t
modifier|*
name|temp
decl_stmt|;
comment|/* swap P and Q pointers to fake out the DegradedReadDAG code */
name|temp
operator|=
name|asmap
operator|->
name|parityInfo
expr_stmt|;
name|asmap
operator|->
name|parityInfo
operator|=
name|asmap
operator|->
name|qInfo
expr_stmt|;
name|asmap
operator|->
name|qInfo
operator|=
name|temp
expr_stmt|;
name|rf_CommonCreateSmallWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
operator|&
name|rf_qFuncs
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Dead Q - act like a RAID 5 small write */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_001_CreateSmallWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CommonCreateSmallWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
operator|&
name|rf_pFuncs
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Dead P - act like a RAID 5 large write but for Q */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_010_CreateLargeWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|RF_PhysDiskAddr_t
modifier|*
name|temp
decl_stmt|;
comment|/* swap P and Q pointers to fake out the code */
name|temp
operator|=
name|asmap
operator|->
name|parityInfo
expr_stmt|;
name|asmap
operator|->
name|parityInfo
operator|=
name|asmap
operator|->
name|qInfo
expr_stmt|;
name|asmap
operator|->
name|qInfo
operator|=
name|temp
expr_stmt|;
name|rf_CommonCreateLargeWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
literal|1
argument_list|,
name|rf_RegularQFunc
argument_list|,
name|RF_FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Dead Q - act like a RAID 5 large write */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_001_CreateLargeWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CommonCreateLargeWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
literal|1
argument_list|,
name|rf_RegularPFunc
argument_list|,
name|RF_FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * writes, double failure  */
end_comment

begin_comment
comment|/*  * Lost P& Q - do a nonredundant write  */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_011_CreateWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|rf_CreateNonRedundantWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
name|RF_IO_TYPE_WRITE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*    In the two cases below,    A nasty case arises when the write a (strict) portion of a failed stripe unit    and parts of another su. For now, we do not support this. */
end_comment

begin_comment
comment|/*   Lost Data and  P - do a Q write. */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_110_CreateWriteDAG
argument_list|)
end_macro

begin_block
block|{
name|RF_PhysDiskAddr_t
modifier|*
name|temp
decl_stmt|;
if|if
condition|(
name|asmap
operator|->
name|numStripeUnitsAccessed
operator|!=
literal|1
operator|&&
name|asmap
operator|->
name|failedPDAs
index|[
literal|0
index|]
operator|->
name|numSector
operator|!=
name|raidPtr
operator|->
name|Layout
operator|.
name|sectorsPerStripeUnit
condition|)
block|{
name|RF_PANIC
argument_list|()
expr_stmt|;
block|}
comment|/* swap P and Q to fake out parity code */
name|temp
operator|=
name|asmap
operator|->
name|parityInfo
expr_stmt|;
name|asmap
operator|->
name|parityInfo
operator|=
name|asmap
operator|->
name|qInfo
expr_stmt|;
name|asmap
operator|->
name|qInfo
operator|=
name|temp
expr_stmt|;
name|rf_CommonCreateSimpleDegradedWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
literal|1
argument_list|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|RF_DagNode_t
operator|*
argument_list|)
operator|)
name|rf_PQ_DegradedWriteQFunc
argument_list|,
name|RF_FALSE
argument_list|)
expr_stmt|;
comment|/* is the regular Q func the right one to call? */
block|}
end_block

begin_comment
comment|/*    Lost Data and Q - do degraded mode P write */
end_comment

begin_macro
name|RF_CREATE_DAG_FUNC_DECL
argument_list|(
argument|rf_PQ_101_CreateWriteDAG
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|asmap
operator|->
name|numStripeUnitsAccessed
operator|!=
literal|1
operator|&&
name|asmap
operator|->
name|failedPDAs
index|[
literal|0
index|]
operator|->
name|numSector
operator|!=
name|raidPtr
operator|->
name|Layout
operator|.
name|sectorsPerStripeUnit
condition|)
name|RF_PANIC
argument_list|()
expr_stmt|;
name|rf_CommonCreateSimpleDegradedWriteDAG
argument_list|(
name|raidPtr
argument_list|,
name|asmap
argument_list|,
name|dag_h
argument_list|,
name|bp
argument_list|,
name|flags
argument_list|,
name|allocList
argument_list|,
literal|1
argument_list|,
name|rf_RecoveryXorFunc
argument_list|,
name|RF_FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (RF_INCLUDE_DECL_PQ> 0) || 				 * (RF_INCLUDE_RAID6> 0) */
end_comment

end_unit

