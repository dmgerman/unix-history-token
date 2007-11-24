begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************\ |*                                                                           *| |*         Copyright 2001-2003 NVIDIA, Corporation.  All rights reserved.    *| |*                                                                           *| |*     THE INFORMATION CONTAINED HEREIN  IS PROPRIETARY AND CONFIDENTIAL     *| |*     TO NVIDIA, CORPORATION.   USE,  REPRODUCTION OR DISCLOSURE TO ANY     *| |*     THIRD PARTY IS SUBJECT TO WRITTEN PRE-APPROVAL BY NVIDIA, CORP.       *| |*                                                                           *| |*     THE INFORMATION CONTAINED HEREIN IS PROVIDED  "AS IS" WITHOUT         *| |*     EXPRESS OR IMPLIED WARRANTY OF ANY KIND, INCLUDING ALL IMPLIED        *| |*     WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A     *| |*     PARTICULAR PURPOSE.                                                   *| |*                                                                           *| \***************************************************************************/
end_comment

begin_comment
comment|/*     *   This file contains the header info common to the network drivers and applications.  *   Currently, these applications include ASF, co-installers, and qstats.  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRVINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRVINFO_H_
end_define

begin_comment
comment|// Switch to byte packing, regardless of global packing specified by the compiler switch
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// For the ADAPTER_GetStatistics call used by qstats.  This
end_comment

begin_comment
comment|// is the template used by the legacy driver.
end_comment

begin_define
define|#
directive|define
name|MAX_TRANSMIT_COLISION_STATS
value|16
end_define

begin_define
define|#
directive|define
name|ADAPTER_STATS_LEGACY_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|ADAPTER_STATS_RM_VERSION
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ADAPTER_STATS_V1
block|{
name|NV_UINT32
name|ulVersion
decl_stmt|;
name|NV_UINT32
name|ulSuccessfulTransmissions
decl_stmt|;
name|NV_UINT32
name|ulFailedTransmissions
decl_stmt|;
name|NV_UINT32
name|ulRetryErrors
decl_stmt|;
name|NV_UINT32
name|ulUnderflowErrors
decl_stmt|;
name|NV_UINT32
name|ulLossOfCarrierErrors
decl_stmt|;
name|NV_UINT32
name|ulLateCollisionErrors
decl_stmt|;
name|NV_UINT32
name|ulDeferredTransmissions
decl_stmt|;
name|NV_UINT32
name|ulExcessDeferredTransmissions
decl_stmt|;
name|NV_UINT32
name|aulSuccessfulTransmitsAfterCollisions
index|[
name|MAX_TRANSMIT_COLISION_STATS
index|]
decl_stmt|;
name|NV_UINT32
name|ulMissedFrames
decl_stmt|;
name|NV_UINT32
name|ulSuccessfulReceptions
decl_stmt|;
name|NV_UINT32
name|ulFailedReceptions
decl_stmt|;
name|NV_UINT32
name|ulCRCErrors
decl_stmt|;
name|NV_UINT32
name|ulFramingErrors
decl_stmt|;
name|NV_UINT32
name|ulOverFlowErrors
decl_stmt|;
name|NV_UINT32
name|ulFrameErrorsPrivate
decl_stmt|;
comment|//Not for public.
name|NV_UINT32
name|ulNullBufferReceivePrivate
decl_stmt|;
comment|//Not for public, These are the packets which we didn't indicate to OS
comment|//interrupt related statistics
name|NV_UINT32
name|ulRxInterrupt
decl_stmt|;
name|NV_UINT32
name|ulRxInterruptUnsuccessful
decl_stmt|;
name|NV_UINT32
name|ulTxInterrupt
decl_stmt|;
name|NV_UINT32
name|ulTxInterruptUnsuccessful
decl_stmt|;
name|NV_UINT32
name|ulPhyInterrupt
decl_stmt|;
block|}
name|ADAPTER_STATS_V1
operator|,
typedef|*
name|PADAPTER_STATS_V1
typedef|;
end_typedef

begin_comment
comment|//////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// For the ADAPTER_GetStatistics call used by qstats.  This
end_comment

begin_comment
comment|// is the template used by the FD.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ADAPTER_STATS
block|{
name|NV_UINT32
name|ulVersion
decl_stmt|;
name|NV_UINT8
name|ulMacAddress
index|[
literal|6
index|]
decl_stmt|;
comment|//
comment|// Tx counters.
comment|//
name|NV_UINT64
name|ulSuccessfulTransmissions
decl_stmt|;
name|NV_UINT64
name|ulFailedTransmissions
decl_stmt|;
name|NV_UINT64
name|ulRetryErrors
decl_stmt|;
name|NV_UINT64
name|ulUnderflowErrors
decl_stmt|;
name|NV_UINT64
name|ulLossOfCarrierErrors
decl_stmt|;
name|NV_UINT64
name|ulLateCollisionErrors
decl_stmt|;
name|NV_UINT64
name|ulDeferredTransmissions
decl_stmt|;
name|NV_UINT64
name|ulExcessDeferredTransmissions
decl_stmt|;
name|NV_UINT64
name|aulSuccessfulTransmitsAfterCollisions
index|[
name|MAX_TRANSMIT_COLISION_STATS
index|]
decl_stmt|;
comment|//
comment|// New Tx counters for GigE.
comment|//
name|NV_UINT64
name|ulTxByteCount
decl_stmt|;
comment|//
comment|// Rx counters.
comment|//
name|NV_UINT64
name|ulMissedFrames
decl_stmt|;
name|NV_UINT64
name|ulSuccessfulReceptions
decl_stmt|;
name|NV_UINT64
name|ulFailedReceptions
decl_stmt|;
name|NV_UINT64
name|ulCRCErrors
decl_stmt|;
name|NV_UINT64
name|ulLengthErrors
decl_stmt|;
name|NV_UINT64
name|ulFramingErrors
decl_stmt|;
name|NV_UINT64
name|ulOverFlowErrors
decl_stmt|;
name|NV_UINT64
name|ulRxNoBuffer
decl_stmt|;
name|NV_UINT64
name|ulFrameErrorsPrivate
decl_stmt|;
comment|//Not for public.
name|NV_UINT64
name|ulNullBufferReceivePrivate
decl_stmt|;
comment|//Not for public, These are the packets which we didn't indicate to OS
comment|//
comment|// New Rx counters for GigE.
comment|//
name|NV_UINT64
name|ulRxExtraByteCount
decl_stmt|;
name|NV_UINT64
name|ulRxFrameTooLongCount
decl_stmt|;
name|NV_UINT64
name|ulRxFrameAlignmentErrorCount
decl_stmt|;
name|NV_UINT64
name|ulRxLateCollisionErrors
decl_stmt|;
name|NV_UINT64
name|ulRxRuntPacketErrors
decl_stmt|;
name|NV_UINT64
name|ulRxUnicastFrameCount
decl_stmt|;
name|NV_UINT64
name|ulRxMulticastFrameCount
decl_stmt|;
name|NV_UINT64
name|ulRxBroadcastFrameCount
decl_stmt|;
name|NV_UINT64
name|ulRxPromiscuousModeFrameCount
decl_stmt|;
comment|//Interrupt related statistics
name|NV_UINT64
name|ulRxInterrupt
decl_stmt|;
name|NV_UINT64
name|ulRxInterruptUnsuccessful
decl_stmt|;
name|NV_UINT64
name|ulTxInterrupt
decl_stmt|;
name|NV_UINT64
name|ulTxInterruptUnsuccessful
decl_stmt|;
name|NV_UINT64
name|ulPhyInterrupt
decl_stmt|;
comment|//
comment|// Handy things to know
comment|//
name|NV_UINT64
name|ulDescriptorVersion
decl_stmt|;
name|NV_UINT64
name|ulPollingCfg
decl_stmt|;
comment|// configured for cpu or throughput
name|NV_UINT64
name|ulPollingState
decl_stmt|;
comment|// current optimizefor state.
name|NV_UINT64
name|ulNumTxDesc
decl_stmt|;
name|NV_UINT64
name|ulNumRxDesc
decl_stmt|;
comment|//
comment|// Useful to determine if TX is stuck.
comment|//
name|NV_UINT64
name|ulNumTxPktsQueued
decl_stmt|;
name|NV_UINT64
name|ulNumTxPktsInProgress
decl_stmt|;
comment|//
comment|// Rx Xsum Cntrs
comment|//
name|NV_UINT64
name|ulNoRxPktsNoXsum
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpPassTcpFail
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpPassUdpFail
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpFail
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpPassNoTcpUdp
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpPassTcpPass
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumIpPassUdpPass
decl_stmt|;
name|NV_UINT64
name|ulNoRxPktsXsumReserved
decl_stmt|;
ifdef|#
directive|ifdef
name|_PERF_LOOP_CNTRS
name|NV_UINT64
name|ulNumTxCmplsToProcess
decl_stmt|;
name|NV_UINT64
name|ulNumRxCmplsToProcess
decl_stmt|;
name|NV_UINT64
name|ulNumIntsToProcess
decl_stmt|;
name|NV_UINT64
name|IntLoop0Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop1Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop2Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop3Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop4Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop5Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop6To10Cnt
decl_stmt|;
name|NV_UINT64
name|IntLoop11Cnt
decl_stmt|;
name|NV_UINT64
name|IntMaxLoopCnt
decl_stmt|;
name|NV_UINT64
name|IntRxCnt0
decl_stmt|;
name|NV_UINT64
name|IntTxCnt0
decl_stmt|;
name|NV_UINT64
name|MaxRxLoopCnt
decl_stmt|;
name|NV_UINT64
name|MaxTxLoopCnt
decl_stmt|;
endif|#
directive|endif
block|}
name|ADAPTER_STATS
operator|,
typedef|*
name|PADAPTER_STATS
typedef|;
end_typedef

begin_comment
comment|//////////////////////////////////////////////////////////////////
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #define _DRVINFO_H_
end_comment

end_unit

