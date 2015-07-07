begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DMTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__DMTYPES_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/ostypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osdebug.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/saapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/saosapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/dm.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/dmapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/tddmapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/dm/dmlist.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TBD
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiscsi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for SMP only */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dmSMPCompleted_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
parameter_list|,
name|agsaIORequest_t
modifier|*
parameter_list|,
name|bit32
parameter_list|,
name|bit32
parameter_list|,
name|agsaFrameHandle_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* timer functions ; both I and T */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dmTimerCBFunc_t
function_decl|)
parameter_list|(
name|dmRoot_t
modifier|*
name|dmRoot
parameter_list|,
name|void
modifier|*
name|timerData1
parameter_list|,
name|void
modifier|*
name|timerData2
parameter_list|,
name|void
modifier|*
name|timerData3
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** \brief data structure for timer request  *  Timer requests are enqueued and dequeued using dmList_t  *  and have a callback function  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dmTimerRequest_s
block|{
comment|/* the number of ticks */
name|bit32
name|timeout
decl_stmt|;
name|void
modifier|*
name|timerData1
decl_stmt|;
name|void
modifier|*
name|timerData2
decl_stmt|;
name|void
modifier|*
name|timerData3
decl_stmt|;
name|dmTimerCBFunc_t
name|timerCBFunc
decl_stmt|;
name|dmList_t
name|timerLink
decl_stmt|;
name|bit32
name|timerRunning
decl_stmt|;
block|}
name|dmTimerRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmRootOsData_s
block|{
name|dmRoot_t
modifier|*
name|dmRoot
decl_stmt|;
comment|/**< Pointer back to dmRoot                 */
name|void
modifier|*
name|dmAllShared
decl_stmt|;
comment|/**< Pointer to dmContext_t               */
name|void
modifier|*
name|dmIni
decl_stmt|;
comment|/**< Pointer to SAS/SATA initiator               */
block|}
name|dmRootOsData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DMSASAddressID_s
block|{
name|bit32
name|sasAddressLo
decl_stmt|;
comment|/**< HOST SAS address lower part */
name|bit32
name|sasAddressHi
decl_stmt|;
comment|/**< HOST SAS address higher part */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/**< PHY IDENTIFIER of the PHY */
block|}
name|DMSASAddressID_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|dmExpander_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|dmDiscovery_s
block|{
name|dmList_t
name|discoveringExpanderList
decl_stmt|;
name|dmList_t
name|UpdiscoveringExpanderList
decl_stmt|;
comment|//  tdList_t                   freeExpanderList;
name|bit32
name|status
decl_stmt|;
name|DMSASAddressID_t
name|sasAddressIDDiscoverError
decl_stmt|;
name|agsaSATAIdentifyData_t
modifier|*
name|pSataIdentifyData
decl_stmt|;
name|struct
name|dmExpander_s
modifier|*
name|RootExp
decl_stmt|;
comment|/* Root expander of discovery */
name|bit32
name|NumOfUpExp
decl_stmt|;
name|bit32
name|type
decl_stmt|;
comment|/* discovery type: TDSA_DISCOVERY_OPTION_FULL_START                                     or TDSA_DISCOVERY_OPTION_INCREMENTAL_START*/
name|bit32
name|retries
decl_stmt|;
name|bit32
name|configureRouteRetries
decl_stmt|;
name|bit32
name|deviceRetistrationRetries
decl_stmt|;
name|dmTimerRequest_t
name|discoveryTimer
decl_stmt|;
name|dmTimerRequest_t
name|configureRouteTimer
decl_stmt|;
name|dmTimerRequest_t
name|deviceRegistrationTimer
decl_stmt|;
name|dmTimerRequest_t
name|BCTimer
decl_stmt|;
comment|/* Broadcast Change timer for ResetTriggerred */
name|smpRespDiscover_t
name|SMPDiscoverResp
decl_stmt|;
name|smpRespDiscover2_t
name|SMPDiscover2Resp
decl_stmt|;
name|bit32
name|pendingSMP
decl_stmt|;
comment|/* the number of pending SMP for this discovery */
name|bit32
name|SeenBC
decl_stmt|;
comment|/* received Broadcast change */
name|bit32
name|forcedOK
decl_stmt|;
comment|/* report DiscOK when chance is missed */
name|dmTimerRequest_t
name|SMPBusyTimer
decl_stmt|;
comment|/* SMP retry timer for saSMPStart busy */
name|bit32
name|SMPRetries
decl_stmt|;
comment|/* number of SMP retries when LL returns busy for saSMPStart*/
name|bit32
name|ResetTriggerred
decl_stmt|;
comment|/* Hard/Link reset triggerred by discovery */
name|dmTimerRequest_t
name|DiscoverySMPTimer
decl_stmt|;
comment|/* discovery-related SMP application Timer */
comment|/* For SAS 2 */
name|bit32
name|DeferredError
decl_stmt|;
comment|/* Deferred Error for SAS 2 */
name|bit32
name|ConfiguresOthers
decl_stmt|;
comment|/* exp configures others; no routing configuration */
block|}
name|dmDiscovery_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmSASSubID_s
block|{
name|bit32
name|sasAddressHi
decl_stmt|;
name|bit32
name|sasAddressLo
decl_stmt|;
name|bit8
name|initiator_ssp_stp_smp
decl_stmt|;
name|bit8
name|target_ssp_stp_smp
decl_stmt|;
block|}
name|dmSASSubID_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|dmDeviceData_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|dmIntPortContext_s
block|{
comment|/**< current number of devices in this PortContext */
name|bit32
name|Count
decl_stmt|;
name|bit32
name|DiscoveryState
decl_stmt|;
name|bit32
name|DiscoveryAbortInProgress
decl_stmt|;
comment|/* passed by tiINIDiscoverTargets()      eg) discovery or rediscovery ....   */
name|bit32
name|discoveryOptions
decl_stmt|;
comment|/* Discovery ready is given? */
name|bit32
name|DiscoveryRdyGiven
decl_stmt|;
comment|/* Port has received link up */
name|bit32
name|SeenLinkUp
decl_stmt|;
comment|/* statistics */
name|bit32
name|numAvailableTargets
decl_stmt|;
comment|/* flag: indicates that discovery is trigggered by tiINIDiscoverTargets */
name|bit32
name|osInitiatedDiscovery
decl_stmt|;
name|bit32
name|id
decl_stmt|;
comment|/* for debugging only */
name|dmList_t
name|FreeLink
decl_stmt|;
comment|/**< free portcontext list */
name|dmList_t
name|MainLink
decl_stmt|;
comment|/**< in-use portcontext list */
comment|/**< SAS address of the remote device */
name|bit32
name|sasRemoteAddressHi
decl_stmt|;
comment|/**< SAS address high part */
name|bit32
name|sasRemoteAddressLo
decl_stmt|;
comment|/**< SAS address low part */
comment|/**< SAS ID frame of the remote device */
name|agsaSASIdentify_t
name|sasIDframe
decl_stmt|;
comment|/**< SAS address of the local device*/
name|bit32
name|sasLocalAddressHi
decl_stmt|;
comment|/**< SAS address high part */
name|bit32
name|sasLocalAddressLo
decl_stmt|;
comment|/**< SAS address low part */
ifdef|#
directive|ifdef
name|TBD
comment|/**< the list of PhyID belonging to this port */
name|bit8
name|PhyIDList
index|[
name|DM_MAX_NUM_PHYS
index|]
decl_stmt|;
endif|#
directive|endif
name|dmPortContext_t
modifier|*
name|dmPortContext
decl_stmt|;
name|dmRoot_t
modifier|*
name|dmRoot
decl_stmt|;
ifdef|#
directive|ifdef
name|TBD
comment|/* used in tiINIDiscoverTarget() */
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
name|agsaPortContext_t
modifier|*
name|agPortContext
decl_stmt|;
comment|/* maybe needs timers for saPhyStart() */
name|bit8
name|nativeSATAMode
decl_stmt|;
comment|/* boolean flag: whether the port is in Native SATA mode */
name|bit8
name|remoteSignature
index|[
literal|8
index|]
decl_stmt|;
comment|/* the remote signature of the port is the port is in native SATA mode */
endif|#
directive|endif
name|bit8
name|directAttatchedSAS
decl_stmt|;
comment|/* boolean flag: whether the port connected directly to SAS end device*/
comment|/* SAS/SATA discovery information such as discoveringExpanderList */
name|dmDiscovery_t
name|discovery
decl_stmt|;
name|bit32
name|valid
decl_stmt|;
name|bit8
name|LinkRate
decl_stmt|;
name|bit32
name|RegisteredDevNums
decl_stmt|;
comment|/* registered number of devices */
name|bit32
name|eventPhyID
decl_stmt|;
comment|/* used for saHwEventAck() */
name|bit32
name|Transient
decl_stmt|;
comment|/* transient period between link up and link down/port recovery */
name|bit32
name|RegFailed
decl_stmt|;
comment|/* Registration of expander belonging to this port failure */
block|}
name|dmIntPortContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmDeviceData_s
block|{
name|dmList_t
name|FreeLink
decl_stmt|;
comment|/* free dev list */
name|dmList_t
name|MainLink
decl_stmt|;
comment|/* main(in use) dev list */
name|dmList_t
name|IncDisLink
decl_stmt|;
comment|/* Used for incremental Discovery only */
name|bit32
name|id
decl_stmt|;
comment|/* for debugging only */
name|bit8
name|DeviceType
decl_stmt|;
comment|/* used in tiINIIOStart() */
name|dmRoot_t
modifier|*
name|dmRoot
decl_stmt|;
comment|//  agsaDevHandle_t         *agDevHandle;
comment|/* for SAS; remote device */
comment|//  agsaSASDeviceInfo_t     agSASDeviceInfo;
comment|/* device's sas address */
name|DMSASAddressID_t
name|SASAddressID
decl_stmt|;
name|bit8
name|initiator_ssp_stp_smp
decl_stmt|;
name|bit8
name|target_ssp_stp_smp
decl_stmt|;
name|bit8
name|numOfPhys
decl_stmt|;
comment|/* SATA specific data */
name|bit8
name|satSignature
index|[
literal|8
index|]
decl_stmt|;
comment|/* SATA device Signature*/
comment|/**< pointer to tdsaPortcontext which the device belongs to */
name|struct
name|dmIntPortContext_s
modifier|*
name|dmPortContext
decl_stmt|;
comment|/* validity of device */
name|bit8
name|valid
decl_stmt|;
name|bit8
name|valid2
decl_stmt|;
name|bit8
name|processed
decl_stmt|;
comment|/* used in TD discovery */
ifdef|#
directive|ifdef
name|AGTIAPI_CTL
name|bit8
name|discovered
decl_stmt|;
endif|#
directive|endif
name|agsaDeviceInfo_t
name|agDeviceInfo
decl_stmt|;
name|dmDeviceInfo_t
name|dmDeviceInfo
decl_stmt|;
name|agsaContext_t
name|agContext
decl_stmt|;
comment|/* used in saRegisterNewDevice()*/
comment|/**< pointer to dmExpander if Device is expander */
name|struct
name|dmExpander_s
modifier|*
name|dmExpander
decl_stmt|;
name|struct
name|dmDeviceData_s
modifier|*
name|ExpDevice
decl_stmt|;
comment|/* Expander device which this device is attached to */
name|bit8
name|phyID
decl_stmt|;
comment|/* PhyID this device is attached to SPC or expander */
name|agsaSASIdentify_t
name|sasIdentify
decl_stmt|;
comment|/* used only in TD discovery */
name|bit8
name|connectionRate
decl_stmt|;
comment|//  bit8                  registered;
name|bit8
name|directlyAttached
decl_stmt|;
name|bit8
name|SASSpecDeviceType
decl_stmt|;
comment|/* 0 - 3; SAS_NO_DEVICE - SAS_FANOUT_EXPANDER_DEVICE */
name|bit32
name|IOStart
decl_stmt|;
name|bit32
name|IOResponse
decl_stmt|;
name|agsaContext_t
name|agDeviceResetContext
decl_stmt|;
comment|/* used in saLocalPhyControl() */
name|bit32
name|TRflag
decl_stmt|;
comment|/* transport recovery flag; used only for tiINITransportRecovery */
name|bit32
name|ResetCnt
decl_stmt|;
comment|/* number of reset to the device */
name|bit32
name|registered
decl_stmt|;
comment|/* registered to LL */
name|bit32
name|reported
decl_stmt|;
comment|/* reproted to TDM */
name|bit32
name|MCN
decl_stmt|;
comment|/* MCN; initialized to 0; current value in discovery */
name|bit32
name|MCNDone
decl_stmt|;
comment|/* done in updating MCN */
name|bit32
name|PrevMCN
decl_stmt|;
comment|/* MCN; initialized to 0; previous value in discovery */
block|}
name|dmDeviceData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmExpander_s
block|{
comment|/* start of dmDeviceData */
ifdef|#
directive|ifdef
name|TBD
name|dmList_t
name|FreeLink
decl_stmt|;
comment|/* free dev list */
name|dmList_t
name|MainLink
decl_stmt|;
comment|/* main(in use) dev list */
endif|#
directive|endif
name|bit32
name|id
decl_stmt|;
comment|/* for debugging only */
name|bit32
name|InQID
decl_stmt|;
comment|/* Inbound queue ID */
name|bit32
name|OutQID
decl_stmt|;
comment|/* Outbound queue ID */
name|bit8
name|DeviceType
decl_stmt|;
comment|/* used in tiINIIOStart() */
name|dmRoot_t
modifier|*
name|dmRoot
decl_stmt|;
name|agsaDevHandle_t
modifier|*
name|agDevHandle
decl_stmt|;
name|dmList_t
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the expander */
name|dmList_t
name|upNode
decl_stmt|;
comment|/**< the link node data structure of the expander */
name|dmDeviceData_t
modifier|*
name|dmDevice
decl_stmt|;
comment|/**< the pointer to the device data */
name|struct
name|dmExpander_s
modifier|*
name|dmUpStreamExpander
decl_stmt|;
comment|/**< the pointer to the upstream expander device */
name|bit8
name|hasUpStreamDevice
decl_stmt|;
name|bit8
name|discoveringPhyId
decl_stmt|;
name|bit16
name|routingIndex
decl_stmt|;
comment|/* maximum routing table index reported by expander */
name|bit16
name|currentIndex
index|[
name|DM_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
comment|/* routing table index in use */
comment|/*ReportPhySataSend in DM */
name|dmDeviceData_t
modifier|*
name|dmDeviceToProcess
decl_stmt|;
comment|/* on some callbacks, this is a link to the device of interest */
name|bit32
name|configSASAddressHi
decl_stmt|;
name|bit32
name|configSASAddressLo
decl_stmt|;
name|struct
name|dmExpander_s
modifier|*
name|dmCurrentDownStreamExpander
decl_stmt|;
name|bit8
name|upStreamPhys
index|[
name|DM_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
name|bit16
name|numOfUpStreamPhys
decl_stmt|;
name|bit16
name|currentUpStreamPhyIndex
decl_stmt|;
name|bit32
name|upStreamSASAddressHi
decl_stmt|;
name|bit32
name|upStreamSASAddressLo
decl_stmt|;
name|bit32
name|underDiscovering
decl_stmt|;
name|bit32
name|configRouteTable
range|:
literal|1
decl_stmt|;
name|bit32
name|configuring
range|:
literal|1
decl_stmt|;
name|bit32
name|configReserved
range|:
literal|30
decl_stmt|;
ifdef|#
directive|ifdef
name|TBD
name|bit32
name|id
decl_stmt|;
comment|/* for debugging */
endif|#
directive|endif
name|struct
name|dmExpander_s
modifier|*
name|dmReturnginExpander
decl_stmt|;
name|bit8
name|downStreamPhys
index|[
name|DM_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
name|bit16
name|numOfDownStreamPhys
decl_stmt|;
name|bit8
name|currentDownStreamPhyIndex
decl_stmt|;
name|bit32
name|discoverSMPAllowed
decl_stmt|;
comment|/* used only for configurable routers */
name|bit8
name|routingAttribute
index|[
name|DM_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
name|bit32
name|configSASAddressHiTable
index|[
name|DM_MAX_DEV
index|]
decl_stmt|;
name|bit32
name|configSASAddressLoTable
index|[
name|DM_MAX_DEV
index|]
decl_stmt|;
name|bit32
name|configSASAddrTableIndex
decl_stmt|;
comment|/* for SAS 2 */
name|bit32
name|SAS2
decl_stmt|;
comment|/* supports SAS2 spec of not. The value of LONG RESPONSE                                       in report general response */
name|bit32
name|TTTSupported
decl_stmt|;
comment|/* Table to Table is supported */
name|bit32
name|UndoDueToTTTSupported
decl_stmt|;
comment|/* flag that indicates undo exp, device, route                                                       configuration due to TTT */
block|}
name|dmExpander_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmIndirectSMPRequestBody_s
block|{
name|dmList_t
name|Link
decl_stmt|;
name|bit32
name|id
decl_stmt|;
block|}
name|dmIndirectSMPRequestBody_t
typedef|;
end_typedef

begin_comment
comment|/*   should DM allocate a pool of SMP and manages it    or   depend on ostiAllocMemory() */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dmSMPRequestBody_s
block|{
name|dmList_t
name|Link
decl_stmt|;
name|dmSMPCompleted_t
name|SMPCompletionFunc
decl_stmt|;
comment|/* must be the second */
ifdef|#
directive|ifdef
name|TBD
name|tiDeviceHandle_t
modifier|*
name|tiDevHandle
decl_stmt|;
comment|/* not used for TD generated SMP */
endif|#
directive|endif
name|agsaIORequest_t
name|agIORequest
decl_stmt|;
name|agsaSASRequestBody_t
name|agSASRequestBody
decl_stmt|;
name|agsaSATAInitiatorRequest_t
name|agSATARequestBody
decl_stmt|;
comment|/**< SMP response */
comment|//agsaSMPFrame_t                 SMPRsp;
name|dmDeviceData_t
modifier|*
name|dmDevice
decl_stmt|;
ifdef|#
directive|ifdef
name|TBD
name|void
modifier|*
name|osMemHandle
decl_stmt|;
comment|// can this be simply dmExpander_t
name|dmDeviceData_t
modifier|*
name|dmDevice
decl_stmt|;
name|tiIORequest_t
modifier|*
name|CurrentTaskTag
decl_stmt|;
comment|/* SMP is used for simulate target reset */
endif|#
directive|endif
name|dmRoot_t
modifier|*
name|dmRoot
decl_stmt|;
comment|//  dmExpander_t                   *dmExpander;
name|dmIntPortContext_t
modifier|*
name|dmPortContext
decl_stmt|;
comment|/* portcontext where SMP is sent from */
name|bit8
name|smpPayload
index|[
name|SMP_DIRECT_PAYLOAD_LIMIT
index|]
decl_stmt|;
comment|/* for smp retries;                                                                            only for direct SMP */
name|bit32
name|retries
decl_stmt|;
comment|/* number of retries */
comment|/* for indirect SMP req/rsp */
name|void
modifier|*
name|IndirectSMP
decl_stmt|;
name|bit32
name|IndirectSMPUpper32
decl_stmt|;
name|bit32
name|IndirectSMPLower32
decl_stmt|;
comment|/* used only when SMP is INDIRECT SMP request. On SMP completion,       this is used to free up INDIRECT SMP response    */
name|void
modifier|*
name|IndirectSMPResponse
decl_stmt|;
comment|/* dmSMPRequestBody_t */
ifdef|#
directive|ifdef
name|TBD
name|void
modifier|*
name|IndirectSMPReqosMemHandle
decl_stmt|;
name|void
modifier|*
name|IndirectSMPReq
decl_stmt|;
name|bit32
name|IndirectSMPReqLen
decl_stmt|;
name|bit32
name|IndirectSMPReqUpper32
decl_stmt|;
name|bit32
name|IndirectSMPReqLower32
decl_stmt|;
name|void
modifier|*
name|IndirectSMPResposMemHandle
decl_stmt|;
name|void
modifier|*
name|IndirectSMPResp
decl_stmt|;
name|bit32
name|IndirectSMPRespLen
decl_stmt|;
name|bit32
name|IndirectSMPRespUpper32
decl_stmt|;
name|bit32
name|IndirectSMPRespLower32
decl_stmt|;
endif|#
directive|endif
name|bit32
name|id
decl_stmt|;
name|agsaContext_t
name|agContext
decl_stmt|;
block|}
name|dmSMPRequestBody_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmIntContext_s
block|{
comment|/**< agsaRoot_t->osData points to this */
name|struct
name|dmRootOsData_s
name|dmRootOsData
decl_stmt|;
name|bit32
name|usecsPerTick
decl_stmt|;
ifdef|#
directive|ifdef
name|TBD
name|dmRoot_t
name|dmRootInt
decl_stmt|;
comment|/* for interrupt */
name|dmRoot_t
name|dmRootNonInt
decl_stmt|;
comment|/* for non-interrupt */
endif|#
directive|endif
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
comment|/**< software-related initialization params used in saInitialize() */
name|dmSwConfig_t
name|SwConfig
decl_stmt|;
comment|/**< timers used commonly in SAS/SATA */
name|dmList_t
name|timerlist
decl_stmt|;
comment|/**< pointer to PortContext memory;  */
name|dmIntPortContext_t
modifier|*
name|PortContextMem
decl_stmt|;
name|dmList_t
name|FreePortContextList
decl_stmt|;
name|dmList_t
name|MainPortContextList
decl_stmt|;
comment|/**< pointer to Device memory */
name|dmDeviceData_t
modifier|*
name|DeviceMem
decl_stmt|;
name|dmList_t
name|FreeDeviceList
decl_stmt|;
name|dmList_t
name|MainDeviceList
decl_stmt|;
comment|/**< pointer to Expander memory */
name|dmExpander_t
modifier|*
name|ExpanderMem
decl_stmt|;
name|dmList_t
name|freeExpanderList
decl_stmt|;
name|dmList_t
name|mainExpanderList
decl_stmt|;
comment|/**< pointer to SMP command memory */
name|dmSMPRequestBody_t
modifier|*
name|SMPMem
decl_stmt|;
name|dmList_t
name|freeSMPList
decl_stmt|;
comment|/**< pointer to Indirect SMP request/repsonse memory */
name|bit8
modifier|*
name|IndirectSMPMem
decl_stmt|;
name|bit32
name|IndirectSMPUpper32
decl_stmt|;
name|bit32
name|IndirectSMPLower32
decl_stmt|;
name|bit32
name|itNexusTimeout
decl_stmt|;
name|bit32
name|MaxRetryDiscovery
decl_stmt|;
name|bit32
name|RateAdjust
decl_stmt|;
block|}
name|dmIntContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dmIntRoot_s
block|{
comment|/**<< common data structure for SAS/SATA */
name|dmIntContext_t
name|dmAllShared
decl_stmt|;
block|}
name|dmIntRoot_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DMTYPES_H__ */
end_comment

end_unit

