begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_optnames.h,v 1.6 1999/12/07 02:54:08 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_optnames.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Don't protect against multiple inclusion here- we actually want this.  */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|accessDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|accessTraceBufSize
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|cscanDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* debug CSCAN sorting */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|dagDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|debugPrintUseBuffer
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|degDagDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|disableAsyncAccs
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|diskDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|enableAtomicRMW
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* this debug var enables locking of 					 * the disk arm during small-write 					 * operations.  Setting this variable 					 * to anything other than 0 will 					 * result in deadlock.  (wvcii) */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|engineDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|fifoDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* debug fifo queueing */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|floatingRbufDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|forceHeadSepLimit
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|forceNumFloatingReconBufs
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_comment
comment|/* wire down number of 							 * extra recon buffers 							 * to use */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|keepAccTotals
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* turn on keep_acc_totals */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|lockTableSize
argument_list|,
argument|RF_DEFAULT_LOCK_TABLE_SIZE
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|mapDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|maxNumTraces
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|memChunkDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|memDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|memDebugAddress
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|numBufsToAccumulate
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* number of buffers to 						 * accumulate before doing XOR */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|prReconSched
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|printDAGsDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|printStatesDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|protectedSectors
argument_list|,
literal|64L
argument_list|)
end_macro

begin_comment
comment|/* # of sectors at start of 						 * disk to exclude from RAID 						 * address space */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|pssDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|queueDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|quiesceDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|raidSectorOffset
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* added to all incoming sectors to 					 * debug alignment problems */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|reconDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|reconbufferDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|scanDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* debug SCAN sorting */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|showXorCallCounts
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* show n-way Xor call counts */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|shutdownDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* show shutdown calls */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|sizePercentage
argument_list|,
literal|100
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|sstfDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* turn on debugging info for sstf queueing */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|stripeLockDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|suppressLocksAndLargeWrites
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|suppressTraceDelays
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|useMemChunks
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|validateDAGDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|validateVisitedDebug
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* XXX turn to zero by 						 * default? */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|verifyParityDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|debugKernelAccess
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* DoAccessKernel debugging */
end_comment

begin_if
if|#
directive|if
name|RF_INCLUDE_PARITYLOGGING
operator|>
literal|0
end_if

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|forceParityLogReint
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|numParityRegions
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* number of regions in the array */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|numReintegrationThreads
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|parityLogDebug
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* if nonzero, enables debugging of 					 * parity logging */
end_comment

begin_macro
name|RF_DBG_OPTION
argument_list|(
argument|totalInCoreLogCapacity
argument_list|,
literal|1024
argument|*
literal|1024
argument_list|)
end_macro

begin_comment
comment|/* target bytes 							 * available for in-core 							 * logs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RF_INCLUDE_PARITYLOGGING> 0 */
end_comment

end_unit

