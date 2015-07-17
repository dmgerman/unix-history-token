begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file satypes.h  *  \brief The file defines the internal data structure types used by LL layer  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SATYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__SATYPES_H__
end_define

begin_comment
comment|/** \brief the callback function of an timer  *  * the definition of the timer callback function  */
end_comment

begin_typedef
typedef|typedef
name|bit32
function_decl|(
modifier|*
name|agsaCallback_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|bit32
name|Event
parameter_list|,
name|void
modifier|*
name|Parm
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief the data structure of a timer  *  * use to describe timer  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaTimerDesc_s
block|{
name|SALINK
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the timer */
name|bit32
name|valid
decl_stmt|;
comment|/**< the valid bit of the timer descriptor */
name|bit32
name|timeoutTick
decl_stmt|;
comment|/**< the timeout tick of the timer */
name|agsaCallback_t
name|pfnTimeout
decl_stmt|;
comment|/**< the callback function fo the timer */
name|bit32
name|Event
decl_stmt|;
comment|/**< the event paramter of the timer callback function */
name|void
modifier|*
name|pParm
decl_stmt|;
comment|/**< the point to the paramter passed to callback function */
block|}
name|agsaTimerDesc_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the port  *  * describe port data structure  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPort_s
block|{
name|SALINK
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the port */
name|agsaPortContext_t
name|portContext
decl_stmt|;
comment|/**< the port context of the port */
name|SALINK_LIST
name|listSASATADevices
decl_stmt|;
comment|/**< SAS/SATA devices list of the port */
name|bit32
name|phyMap
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
comment|/**< Boolean arrar: the Phys included in the port. */
name|bit32
name|status
decl_stmt|;
comment|/**< port state */
name|bit32
name|tobedeleted
decl_stmt|;
comment|/**< mark for deletetion after callback  */
name|bit32
name|portId
decl_stmt|;
comment|/** Port Id from SPC */
name|bit8
name|portIdx
decl_stmt|;
comment|/**< the Index of the port */
name|bit8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|agsaPort_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the phy  *  * phy data structure  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhy_s
block|{
name|agsaPort_t
modifier|*
name|pPort
decl_stmt|;
comment|/**< pointer to the port includes the phy */
name|agsaSASIdentify_t
name|sasIdentify
decl_stmt|;
comment|/**< the SAS identify of the phy */
name|agsaContext_t
modifier|*
name|agContext
decl_stmt|;
comment|/**< agContext for the Phy */
name|bit32
name|status
decl_stmt|;
comment|/**< the status of the phy */
name|bit8
name|phyId
decl_stmt|;
comment|/**< the Id of the phy */
name|bit8
name|linkstatus
decl_stmt|;
comment|/**< the link status of the phy */
name|bit8
name|reserved
index|[
literal|2
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SALLSDK_DEBUG
argument_list|)
name|bit8
name|remoteSignature
index|[
literal|8
index|]
decl_stmt|;
comment|/* the remote signature of the phy is the phy is in native SATA mode */
endif|#
directive|endif
block|}
name|agsaPhy_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the LL defined SAS/SATA device information  *  * LL defined SAS/SATA device information  *  */
end_comment

begin_typedef
typedef|typedef
union|union
name|agsaSASSATADevInfo_s
block|{
name|agsaSASDeviceInfo_t
name|sasDeviceInfo
decl_stmt|;
comment|/**< SAS device information of the device */
name|agsaSATADeviceInfo_t
name|sataDeviceInfo
decl_stmt|;
comment|/**< SATA device information of the device */
block|}
name|agsaSASSATADevInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the LL defined device descriptor  *  * LL defined device descriptor  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceDesc_s
block|{
name|SALINK
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the device */
name|agsaDevHandle_t
name|initiatorDevHandle
decl_stmt|;
comment|/**< the device handle of an initiator device */
name|agsaDevHandle_t
name|targetDevHandle
decl_stmt|;
comment|/**< the device handle of a target device */
name|SALINK_LIST
name|pendingIORequests
decl_stmt|;
comment|/**< the pending IO requests, for SSP or SATA */
name|agsaPort_t
modifier|*
name|pPort
decl_stmt|;
comment|/**< the port discovered the device */
name|bit8
name|deviceType
decl_stmt|;
comment|/**< the device type */
name|bit8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|bit32
name|option
decl_stmt|;
name|bit32
name|param
decl_stmt|;
name|agsaSASSATADevInfo_t
name|devInfo
decl_stmt|;
comment|/**< SAS/SATA device information */
name|bit32
name|DeviceMapIndex
decl_stmt|;
comment|/**< device index for device handle */
block|}
name|agsaDeviceDesc_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the LL defined IO request descriptor  *  * LL defined IO Request descriptor  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaIORequestDesc_s
block|{
name|SALINK
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the IO request */
name|agsaIORequest_t
modifier|*
name|pIORequestContext
decl_stmt|;
comment|/**< the IO request context */
name|agsaDeviceDesc_t
modifier|*
name|pDevice
decl_stmt|;
comment|/**< the pointer to the device, to which the request is sent */
name|agsaPort_t
modifier|*
name|pPort
decl_stmt|;
comment|/**< the pointer to the port - using by HW_EVENT_ACK with PHY_DOWN event */
name|ossaSSPCompletedCB_t
name|completionCB
decl_stmt|;
comment|/**< completion callback to be called */
name|bit32
name|requestType
decl_stmt|;
comment|/**< the request type */
name|bit16
name|HwAckType
decl_stmt|;
comment|/**< Track HW_acks */
name|bit16
name|SOP
decl_stmt|;
comment|/**< SetPhyProfile page not returned in reply */
name|bit32
name|startTick
decl_stmt|;
comment|/**< start time for this IO */
name|bit32
name|HTag
decl_stmt|;
comment|/**< the host tag to index into the IORequest array */
name|bit8
name|valid
decl_stmt|;
comment|/**< boolean flag: the request is valid */
name|bit8
name|IRmode
decl_stmt|;
comment|/**< indirect smp response mode */
name|bit8
name|modePageContext
decl_stmt|;
comment|/**< request is for security mode change */
name|bit8
name|DeviceInfoCmdOption
decl_stmt|;
comment|/**<  */
ifdef|#
directive|ifdef
name|FAST_IO_TEST
name|SALINK
name|fastLink
decl_stmt|;
comment|/* Fast I/O's chain */
endif|#
directive|endif
block|}
name|agsaIORequestDesc_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the LL defined SMP Response Frame header and payload  *  * LL defined SMP Response Frame header and payload  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPRspFrame_s
block|{
name|agsaSMPFrameHeader_t
name|smpHeader
decl_stmt|;
name|bit8
name|smpPayload
index|[
literal|1020
index|]
decl_stmt|;
block|}
name|agsaSMPRspFrame_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the agsaIOMap_t  *  * data storage for IO Request Mapping  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaIOMap_s
block|{
name|bit32
name|Tag
decl_stmt|;
name|agsaIORequestDesc_t
modifier|*
name|IORequest
decl_stmt|;
name|agsaContext_t
modifier|*
name|agContext
decl_stmt|;
block|}
name|agsaIOMap_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the agsaPortMap_t  *  * data storage for Port Context Mapping  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPortMap_s
block|{
name|bit32
name|PortID
decl_stmt|;
name|bit32
name|PortStatus
decl_stmt|;
name|void
modifier|*
name|PortContext
decl_stmt|;
block|}
name|agsaPortMap_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the agsaDeviceMap_t  *  * data storage for Device Handle Mapping  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceMap_s
block|{
name|bit32
name|DeviceIdFromFW
decl_stmt|;
name|void
modifier|*
name|DeviceHandle
decl_stmt|;
block|}
name|agsaDeviceMap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_comment
comment|/* interleaved Fast IO's are not allowed */
end_comment

begin_define
define|#
directive|define
name|LL_FAST_IO_SIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** \brief the LLRoot  *  * root data structure  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaLLRoot_s
block|{
name|agsaMem_t
name|deviceLinkMem
decl_stmt|;
comment|/**< Device Link System Memory */
name|SALINK_LIST
name|freeDevicesList
decl_stmt|;
comment|/**< List of free IO device handles */
name|agsaMem_t
name|IORequestMem
decl_stmt|;
comment|/**< IO Request Link System Memory */
name|SALINK_LIST
name|freeIORequests
decl_stmt|;
comment|/**< List of free IORequests */
name|SALINK_LIST
name|freeReservedRequests
decl_stmt|;
comment|/**< List of reserved IORequests not for normal IO! */
name|agsaMem_t
name|timerLinkMem
decl_stmt|;
comment|/**< Timer Link System Memory */
name|SALINK_LIST
name|freeTimers
decl_stmt|;
comment|/**< List of free timers */
name|SALINK_LIST
name|validTimers
decl_stmt|;
comment|/**< List of valid timers */
name|agsaPhy_t
name|phys
index|[
name|AGSA_MAX_VALID_PHYS
index|]
decl_stmt|;
comment|/**< Phys */
name|agsaPort_t
name|ports
index|[
name|AGSA_MAX_VALID_PORTS
index|]
decl_stmt|;
comment|/**< Ports */
name|SALINK_LIST
name|freePorts
decl_stmt|;
comment|/**< List of free ports */
name|SALINK_LIST
name|validPorts
decl_stmt|;
comment|/**< List of valid ports */
name|bit8
name|phyCount
decl_stmt|;
comment|/**< number of phys */
name|bit8
name|portCount
decl_stmt|;
comment|/**< number of ports */
name|bit8
name|sysIntsActive
decl_stmt|;
comment|/**< whether interrupt is enabled */
name|bit8
name|reserved
decl_stmt|;
comment|/**< reserved */
name|bit32
name|usecsPerTick
decl_stmt|;
comment|/**< timer tick unit */
name|bit32
name|minStallusecs
decl_stmt|;
comment|/**< shorest available stall */
name|bit32
name|timeTick
decl_stmt|;
comment|/**< the current timer tick */
name|bit32
name|ResetStartTick
decl_stmt|;
comment|/* Reset StartTick */
name|bit32
name|chipStatus
decl_stmt|;
comment|/**< chip status */
name|bit32
name|interruptVecIndexBitMap
index|[
name|MAX_NUM_VECTOR
index|]
decl_stmt|;
comment|/**< Interrupt Vector Index BitMap */
name|bit32
name|interruptVecIndexBitMap1
index|[
name|MAX_NUM_VECTOR
index|]
decl_stmt|;
comment|/**< Interrupt Vector Index BitMap1 */
name|agsaBarOffset_t
name|SpcBarOffset
index|[
literal|60
index|]
decl_stmt|;
name|bit32
name|ChipId
decl_stmt|;
comment|/* Subversion PCI ID */
name|agsaPortMap_t
name|PortMap
index|[
name|AGSA_MAX_VALID_PORTS
index|]
decl_stmt|;
comment|/**< Port Mapping for PortContext */
name|agsaDeviceMap_t
name|DeviceMap
index|[
name|MAX_IO_DEVICE_ENTRIES
index|]
decl_stmt|;
comment|/**< Device Map for Device Handle */
name|agsaIOMap_t
name|IOMap
index|[
name|MAX_ACTIVE_IO_REQUESTS
index|]
decl_stmt|;
comment|/**< IO MAP for IO Request */
name|agsaDevHandle_t
modifier|*
name|DeviceHandle
index|[
name|MAX_IO_DEVICE_ENTRIES
index|]
decl_stmt|;
comment|/**< used for get device handles */
name|agsaDevHandle_t
modifier|*
name|pDeviceHandle
decl_stmt|;
comment|/**< used for get device handles */
name|agsaMemoryRequirement_t
name|memoryAllocated
decl_stmt|;
comment|/**< SAS LL memory Allocation */
name|agsaHwConfig_t
name|hwConfig
decl_stmt|;
comment|/**< copy of hwConfig */
name|agsaSwConfig_t
name|swConfig
decl_stmt|;
comment|/**< copy of swConfig */
name|agsaQueueConfig_t
name|QueueConfig
decl_stmt|;
comment|/* copy of MPI IBQ/OBQ configuration */
name|mpiConfig_t
name|mpiConfig
decl_stmt|;
comment|/**< MPI Configuration */
name|mpiMemReq_t
name|mpiMemoryAllocated
decl_stmt|;
comment|/**< MPI memory */
name|mpiICQueue_t
name|inboundQueue
index|[
name|AGSA_MAX_INBOUND_Q
index|]
decl_stmt|;
comment|/**< Outbound queue descriptor array */
name|mpiOCQueue_t
name|outboundQueue
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
comment|/**< Outbound queue descriptor array */
name|mpiHostLLConfigDescriptor_t
name|mainConfigTable
decl_stmt|;
comment|/**< LL main Configuration Table */
name|ossaDeviceRegistrationCB_t
name|DeviceRegistrationCB
decl_stmt|;
comment|/**< Device Registration CB */
name|ossaDeregisterDeviceHandleCB_t
name|DeviceDeregistrationCB
decl_stmt|;
comment|/**< Device DeRegistration CB */
name|bit32
name|numInterruptVectors
decl_stmt|;
comment|/**< Number of Interrupt Vectors configured from OS */
name|bit32
name|Use64bit
decl_stmt|;
comment|/**< Only write upper bits if needed */
name|EnadDisabHandler_t
name|DisableInterrupts
decl_stmt|;
comment|/*Interrupt type dependant function pointer to disable interrupts */
name|EnadDisabHandler_t
name|ReEnableInterrupts
decl_stmt|;
comment|/*Interrupt type dependant reenable  */
name|InterruptOurs_t
name|OurInterrupt
decl_stmt|;
comment|/*Interrupt type dependant check for our interrupt */
ifdef|#
directive|ifdef
name|SA_FW_TEST_BUNCH_STARTS
comment|/**    * Following variables are needed to handle Bunch Starts (bulk update of PI)    * - saRoot (agsaLLRoot_t): Global Flags, apply to all queues    *   1. BunchStarts_Enable     *   2. BunchStarts_Threshold    *   3. BunchStarts_Pending    *   4. BunchStarts_TimeoutTicks    *    * - Circular Q (mpiICQueue_s): Queue specific flags    *   1. BunchStarts_QPending    *   2. BunchStarts_QPendingTick    */
name|bit32
name|BunchStarts_Enable
decl_stmt|;
comment|// enables/disables whole feature
name|bit32
name|BunchStarts_Threshold
decl_stmt|;
comment|// global min number of IOs to bunch per queue.
name|bit32
name|BunchStarts_Pending
decl_stmt|;
comment|// global counter collects all Q->BunchStarts_QPending
name|bit32
name|BunchStarts_TimeoutTicks
decl_stmt|;
comment|// global time out value beyond which bunched IOs will be started even below BunchStarts_Threshold.
endif|#
directive|endif
comment|/* SA_FW_TEST_BUNCH_STARTS */
ifdef|#
directive|ifdef
name|SA_FW_TIMER_READS_STATUS
name|spc_GSTableDescriptor_t
name|mpiGSTable
decl_stmt|;
name|bit32
name|MsguTcnt_last
decl_stmt|;
comment|/**< DW3 - MSGU Tick count */
name|bit32
name|IopTcnt_last
decl_stmt|;
comment|/**< DW4 - IOP Tick count */
name|bit32
name|Iop1Tcnt_last
decl_stmt|;
comment|/**< DW4 - IOP Tick count */
endif|#
directive|endif
comment|/* SA_FW_TIMER_READS_STATUS */
name|agsaControllerInfo_t
name|ControllerInfo
decl_stmt|;
name|agsaIOErrorEventStats_t
name|IoErrorCount
decl_stmt|;
name|agsaIOErrorEventStats_t
name|IoEventCount
decl_stmt|;
name|bit32
name|ResetFailed
decl_stmt|;
comment|//bit32           FatalDone;
name|bit32
name|ForensicLastOffset
decl_stmt|;
comment|//bit32           FatalAccumLen;
comment|//bit32           NonFatalForensicLastOffset;
comment|//bit32           FatalCurrentLength;
name|bit32
name|FatalForensicStep
decl_stmt|;
name|bit32
name|FatalForensicShiftOffset
decl_stmt|;
name|bit32
name|FatalBarLoc
decl_stmt|;
ifdef|#
directive|ifdef
name|HIALEAH_ENCRYPTION
name|agsaEncryptGeneralPage_t
name|EncGenPage
decl_stmt|;
endif|#
directive|endif
comment|/* HIALEAH_ENCRYPTION */
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
name|bit8
name|traceBuffLookup
index|[
literal|16
index|]
decl_stmt|;
name|bit32
name|TraceDestination
decl_stmt|;
name|bit32
name|TraceMask
decl_stmt|;
name|bit32
name|TraceBufferLength
decl_stmt|;
name|bit32
name|CurrentTraceIndexWrapCount
decl_stmt|;
name|bit32
name|CurrentTraceIndex
decl_stmt|;
name|bit32
name|traceLineFeedCnt
decl_stmt|;
name|bit8
modifier|*
name|TraceBuffer
decl_stmt|;
name|bit32
name|TraceBlockReInit
decl_stmt|;
endif|#
directive|endif
comment|/*SA_ENABLE_TRACE_FUNCTIONS*/
name|bit32
name|registerDump0
index|[
name|REGISTER_DUMP_BUFF_SIZE
operator|/
literal|4
index|]
decl_stmt|;
comment|/**< register dump buffer 0 */
name|bit32
name|registerDump1
index|[
name|REGISTER_DUMP_BUFF_SIZE
operator|/
literal|4
index|]
decl_stmt|;
comment|/**< register dump buffer 1 */
name|bit32
name|autoDeregDeviceflag
index|[
name|AGSA_MAX_VALID_PORTS
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|SA_FW_TEST_INTERRUPT_REASSERT
name|bit32
name|CheckAll
decl_stmt|;
name|bit32
name|OldPi
index|[
literal|64
index|]
decl_stmt|;
name|bit32
name|OldCi
index|[
literal|64
index|]
decl_stmt|;
name|bit32
name|OldFlag
index|[
literal|64
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* SA_FW_TEST_INTERRUPT_REASSERT */
ifdef|#
directive|ifdef
name|SALL_API_TEST
name|agsaLLCountInfo_t
name|LLCounters
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FAST_IO_TEST
name|void
modifier|*
name|freeFastReq
index|[
name|LL_FAST_IO_SIZE
index|]
decl_stmt|;
comment|/* saFastRequest_t* */
name|int
name|freeFastIdx
decl_stmt|;
endif|#
directive|endif
block|}
name|agsaLLRoot_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_comment
comment|/*   one struct per all prepared Fast IO's;   freed after all IO's are posted to FW and interrupt is triggered;   maintained for error rollback or cancel functionality */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|saFastRequest_s
block|{
name|bit32
name|beforePI
index|[
name|AGSA_MAX_INBOUND_Q
index|]
decl_stmt|;
name|bit32
name|inqList
index|[
name|AGSA_MAX_INBOUND_Q
index|]
decl_stmt|;
name|bit32
name|inqMax
decl_stmt|;
name|SALINK_LIST
name|requests
decl_stmt|;
comment|/* List of all Fast IORequests */
name|void
modifier|*
name|agRoot
decl_stmt|;
comment|/* agsaRoot_t * */
name|bit8
name|valid
decl_stmt|;
comment|/* to avoid usage when the struct is freed */
block|}
name|saFastRequest_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SATYPES_H__ */
end_comment

end_unit

