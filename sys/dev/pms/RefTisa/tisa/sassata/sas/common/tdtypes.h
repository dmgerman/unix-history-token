begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * The file defines data structures for SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDTYPES_H__
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

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_SM
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/sm.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/src/smtypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_DM
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/dm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tddefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdlist.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiscsi.h>
end_include

begin_comment
comment|/* function definitions */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tdssSSPReqReceived_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
parameter_list|,
name|agsaDevHandle_t
modifier|*
parameter_list|,
name|agsaFrameHandle_t
parameter_list|,
name|bit32
parameter_list|,
name|bit32
parameter_list|,
name|bit32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tdssSMPReqReceived_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
parameter_list|,
name|agsaDevHandle_t
modifier|*
parameter_list|,
name|agsaSMPFrameHeader_t
modifier|*
parameter_list|,
name|agsaFrameHandle_t
parameter_list|,
name|bit32
parameter_list|,
name|bit32
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bit32
function_decl|(
modifier|*
name|tdssGetSGLChunk_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agChunkOffset
parameter_list|,
name|bit32
modifier|*
name|agChunkUpper32
parameter_list|,
name|bit32
modifier|*
name|agChunkLower32
parameter_list|,
name|bit32
modifier|*
name|agChunkLen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* for SSP only */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tdssIOCompleted_t
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
parameter_list|,
name|bit32
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* for SMP only */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tdssSMPCompleted_t
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
comment|/** \brief data structure for callback function jumptableESLG page  *  * This data structure defines callback fucntions for SSP, SMP and SATA  * This is used for jump table used for instance specific function callback jump  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaJumpTable_s
block|{
comment|/**< function that called to process received SSP frame */
name|tdssSSPReqReceived_t
name|pSSPReqReceived
decl_stmt|;
comment|/**< function that called to process received SSP frame */
name|tdssSMPReqReceived_t
name|pSMPReqReceived
decl_stmt|;
comment|/**< SSP IO completion callback function eg) ossaSSPcompleted() */
name|tdssIOCompleted_t
name|pSSPIOCompleted
decl_stmt|;
comment|/**< SMP IO completion callback function eg) ossaSMPcompleted() */
name|tdssSMPCompleted_t
name|pSMPCompleted
decl_stmt|;
comment|/* callback function for LL getSGL. Simple place holder for now */
name|tdssGetSGLChunk_t
name|pGetSGLChunk
decl_stmt|;
block|}
name|tdsaJumpTable_t
typedef|;
end_typedef

begin_comment
comment|/* timer functions ; both I and T */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tdsaTimerCBFunc_t
function_decl|)
parameter_list|(
name|tiRoot_t
modifier|*
name|tiRoot
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
comment|/** \brief data structure for timer request  *  Timer requests are enqueued and dequeued using tdList_t  *  and have a callback function  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaTimerRequest_s
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
name|tdsaTimerCBFunc_t
name|timerCBFunc
decl_stmt|;
name|tdList_t
name|timerLink
decl_stmt|;
name|bit32
name|timerRunning
decl_stmt|;
block|}
name|tdsaTimerRequest_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for IO request data  *  used at target only in ttdtxchg_t structure  *  just a place holder for now  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdssIORequestData_s
block|{
comment|/* jump table has to be the first */
name|tdsaJumpTable_t
modifier|*
name|pJumpTable
decl_stmt|;
comment|/* this is just a pointer */
block|}
name|tdssIORequestData_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure OS root from the view of lower layer.  * TD Layer interrupt/non-interrupt context support structure for agsaRoot_t.  * The osData part of agsaRoot points to this tdsaRootOsData_t structure.  * In other words, agsaRoot_t->osData points to this structure and used for  * both SAS and SATA  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaRootOsData_s
block|{
name|tiRoot_t
modifier|*
name|tiRoot
decl_stmt|;
comment|/**< Pointer back to tiRoot                 */
name|void
modifier|*
name|tdsaAllShared
decl_stmt|;
comment|/**< Pointer to tdsaContext_t               */
name|void
modifier|*
name|itdsaIni
decl_stmt|;
comment|/**< Pointer to SAS/SATA initiator               */
name|void
modifier|*
name|ttdsaTgt
decl_stmt|;
comment|/**< Pointer to SAS/SATA target                  */
comment|/* for sata */
name|void
modifier|*
name|tdstHost
decl_stmt|;
comment|/**< Pointer to SATA Host                   */
name|void
modifier|*
name|tdstDevice
decl_stmt|;
comment|/**< Pointer to SATA Device                 */
name|agBOOLEAN
name|IntContext
decl_stmt|;
comment|/**< Interrupt context                      */
block|}
name|tdsaRootOsData_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for port/phy related flags  *  Some fields are just place holders and not used yet  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdssPortFlags_s
block|{
comment|/**< port started flag */
name|agBOOLEAN
name|portStarted
decl_stmt|;
comment|/**< port initialized flag */
name|agBOOLEAN
name|portInitialized
decl_stmt|;
name|agBOOLEAN
name|portReadyForDiscoverySent
decl_stmt|;
comment|/**< port stopped by oslayer */
name|agBOOLEAN
name|portStoppedByOSLayer
decl_stmt|;
comment|/**< fail portinit/start */
name|agBOOLEAN
name|failPortInit
decl_stmt|;
name|agBOOLEAN
name|pseudoPortInitDone
decl_stmt|;
name|agBOOLEAN
name|pseudoPortStartDone
decl_stmt|;
block|}
name|tdssPortFlags_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for both SAS/SATA related flags  *  Some fields are just place holders and not used yet  *   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaComMemFlags_s
block|{
comment|/**< current interrupt setting */
name|agBOOLEAN
name|sysIntsActive
decl_stmt|;
comment|/**< reset in progress */
name|agBOOLEAN
name|resetInProgress
decl_stmt|;
comment|/**< reset status */
name|agBOOLEAN
name|resetFailed
decl_stmt|;
block|}
name|tdsaComMemFlags_t
typedef|;
end_typedef

begin_comment
comment|/*   * SAT related structure   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satInternalIo_s
block|{
name|tdList_t
name|satIntIoLink
decl_stmt|;
name|tiIORequest_t
name|satIntTiIORequest
decl_stmt|;
name|void
modifier|*
name|satIntRequestBody
decl_stmt|;
name|tiScsiInitiatorRequest_t
name|satIntTiScsiXchg
decl_stmt|;
name|tiMem_t
name|satIntDmaMem
decl_stmt|;
name|tiMem_t
name|satIntReqBodyMem
decl_stmt|;
name|bit32
name|satIntFlag
decl_stmt|;
name|tiIORequest_t
modifier|*
name|satOrgTiIORequest
decl_stmt|;
name|bit32
name|id
decl_stmt|;
block|}
name|satInternalIo_t
typedef|;
end_typedef

begin_comment
comment|/*  * SAT specific structure per SATA drive   */
end_comment

begin_define
define|#
directive|define
name|SAT_NONNCQ_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SAT_NCQ_MAX
value|32
end_define

begin_define
define|#
directive|define
name|SAT_MAX_INT_IO
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|TDSASAddressID_s
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
name|TDSASAddressID_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|tdsaExpander_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|tdsaDiscovery_s
block|{
name|tdList_t
name|discoveringExpanderList
decl_stmt|;
name|tdList_t
name|UpdiscoveringExpanderList
decl_stmt|;
comment|//  tdList_t                   freeExpanderList;
name|bit32
name|status
decl_stmt|;
name|TDSASAddressID_t
name|sasAddressIDDiscoverError
decl_stmt|;
name|agsaSATAIdentifyData_t
modifier|*
name|pSataIdentifyData
decl_stmt|;
name|struct
name|tdsaExpander_s
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
name|tdsaTimerRequest_t
name|discoveryTimer
decl_stmt|;
name|tdsaTimerRequest_t
name|configureRouteTimer
decl_stmt|;
name|tdsaTimerRequest_t
name|deviceRegistrationTimer
decl_stmt|;
name|tdsaTimerRequest_t
name|BCTimer
decl_stmt|;
comment|/* Broadcast Change timer for ResetTriggerred */
name|smpRespDiscover_t
name|SMPDiscoverResp
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
name|tdsaTimerRequest_t
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
name|tdsaTimerRequest_t
name|DiscoverySMPTimer
decl_stmt|;
comment|/* discovery-related SMP application Timer */
block|}
name|tdsaDiscovery_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|tdList_t
name|satIoLinkList
decl_stmt|;
comment|/* Normal I/O from TISA         */
name|tdList_t
name|satFreeIntIoLinkList
decl_stmt|;
comment|/* SAT internal I/O free list   */
name|tdList_t
name|satActiveIntIoLinkList
decl_stmt|;
comment|/* SAT internal I/O active list */
name|satInternalIo_t
name|satIntIo
index|[
name|SAT_MAX_INT_IO
index|]
decl_stmt|;
comment|/* Internal I/O resource        */
name|agsaSATAIdentifyData_t
name|satIdentifyData
decl_stmt|;
comment|/* Copy of SATA Id Dev data     */
name|bit8
name|SN_id_limit
index|[
literal|25
index|]
decl_stmt|;
comment|/* temporary serial number id info */
name|bit32
name|satNCQ
decl_stmt|;
comment|/* Flag for NCQ support         */
name|bit32
name|sat48BitSupport
decl_stmt|;
comment|/* Flag for 48-bit addressing   */
name|bit32
name|satSMARTSelfTest
decl_stmt|;
comment|/* Flag for SMART self test     */
name|bit32
name|satSMARTFeatureSet
decl_stmt|;
comment|/* Flag for SMART feature set   */
name|bit32
name|satSMARTEnabled
decl_stmt|;
comment|/* Flag for SMART enabled       */
name|bit32
name|satRemovableMedia
decl_stmt|;
comment|/* Flag for Removable Media     */
name|bit32
name|satRemovableMediaEnabled
decl_stmt|;
comment|/* Flag for Removable Media Enabled */
name|bit32
name|satDMASupport
decl_stmt|;
comment|/* Flag for DMA Support         */
name|bit32
name|satDMAEnabled
decl_stmt|;
comment|/* Flag for DMA Enabled         */
name|bit32
name|satDMADIRSupport
decl_stmt|;
comment|/* Flag in PACKET command for DMA transfer */
name|bit32
name|satWWNSupport
decl_stmt|;
comment|/* Flag for DMA Enabled         */
name|bit32
name|satPendingIO
decl_stmt|;
comment|/* Number of pending I/O        */
name|bit32
name|satPendingNCQIO
decl_stmt|;
comment|/* Number of pending NCQ I/O    */
name|bit32
name|satPendingNONNCQIO
decl_stmt|;
comment|/* Number of pending NON NCW I/O*/
name|bit32
name|satNCQMaxIO
decl_stmt|;
comment|/* Max NCQ I/O in SAT or drive  */
name|bit32
name|satDriveState
decl_stmt|;
comment|/* State of SAT/drive           */
name|bit32
name|satAbortAfterReset
decl_stmt|;
comment|/* Flag: abort after SATA reset */
name|bit32
name|satAbortCalled
decl_stmt|;
comment|/* Flag: abort called indication*/
name|bit32
name|satVerifyState
decl_stmt|;
comment|/* Flag: Read Vrf state for diag*/
name|bit32
name|satMaxUserAddrSectors
decl_stmt|;
comment|/* max user addressable setctors*/
name|bit32
name|satWriteCacheEnabled
decl_stmt|;
comment|/* Flag for write cache enabled */
name|bit32
name|satLookAheadEnabled
decl_stmt|;
comment|/* Flag for look ahead enabled  */
name|bit32
name|satDeviceFaultState
decl_stmt|;
comment|/* State of DF                  */
name|bit32
name|satStopState
decl_stmt|;
comment|/* State of Start and Stop      */
name|bit32
name|satFormatState
decl_stmt|;
comment|/* State of format              */
name|bit32
name|satPMField
decl_stmt|;
comment|/* PM field, first 4 bits       */
name|bit8
name|satSignature
index|[
literal|8
index|]
decl_stmt|;
comment|/* Signature                    */
name|bit32
name|satDeviceType
decl_stmt|;
comment|/* ATA device type              */
name|bit32
name|satSectorDone
decl_stmt|;
comment|/* Number of Sector done by Cmnd*/
name|bit32
name|freeSATAFDMATagBitmap
decl_stmt|;
comment|/* SATA NCQ tag bit map         */
name|bit32
name|IDDeviceValid
decl_stmt|;
comment|/* ID DeviceData valid bit      */
name|bit8
name|satMaxLBA
index|[
literal|8
index|]
decl_stmt|;
comment|/* MAXLBA is from read capacity */
name|bit32
name|satBGPendingDiag
decl_stmt|;
comment|/* Pending Diagnostic in backgound */
name|bit32
name|NumOfFCA
decl_stmt|;
comment|/* number of SMP HARD RESET on this device */
name|bit32
name|NumOfIDRetries
decl_stmt|;
comment|/* number of SMP HARD RESET after ID retries */
name|tiIORequest_t
modifier|*
name|satTmTaskTag
decl_stmt|;
comment|/* TM Task Tag                  */
name|void
modifier|*
name|satSaDeviceData
decl_stmt|;
comment|/* Pointer back to sa dev data  */
name|bit32
name|ID_Retries
decl_stmt|;
comment|/* identify device data retries */
name|bit32
name|IDPending
decl_stmt|;
comment|/* number of pending identify device data */
block|}
name|satDeviceData_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SAS device list  *  This structure maintains the device as a list and information about  *  the device such as the device type and ID address frame.  *  agsaDeviceHandle_t->osData points to this structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaDeviceData_s
block|{
comment|/* in tdtypes.h */
name|tdsaJumpTable_t
modifier|*
name|pJumpTable
decl_stmt|;
comment|/**< a pointer to callback function jumptable */
name|tiDeviceHandle_t
name|tiDeviceHandle
decl_stmt|;
name|tdList_t
name|FreeLink
decl_stmt|;
comment|/* free dev list */
name|tdList_t
name|MainLink
decl_stmt|;
comment|/* main(in use) dev list */
name|tdList_t
name|IncDisLink
decl_stmt|;
comment|/* Used for incremental Discovery only */
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
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
name|agsaDevHandle_t
modifier|*
name|agDevHandle
decl_stmt|;
comment|/* for SAS; remote device */
comment|//  agsaSASDeviceInfo_t     agSASDeviceInfo;
comment|/* device's sas address */
name|TDSASAddressID_t
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
name|satDeviceData_t
name|satDevData
decl_stmt|;
comment|/**< pointer to tdsaPortcontext which the device belongs to */
name|struct
name|tdsaPortContext_s
modifier|*
name|tdPortContext
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
name|agsaContext_t
name|agContext
decl_stmt|;
comment|/* used in saRegisterNewDevice()*/
comment|/**< pointer to tdsaExpander if Device is expander */
name|struct
name|tdsaExpander_s
modifier|*
name|tdExpander
decl_stmt|;
name|struct
name|tdsaDeviceData_s
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
name|bit8
name|registered
decl_stmt|;
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
name|tiIORequest_t
name|TransportRecoveryIO
decl_stmt|;
name|bit32
name|TRflag
decl_stmt|;
comment|/* transport recovery flag; used only for tiINITransportRecovery */
name|bit32
name|ResetCnt
decl_stmt|;
comment|/* number of reset to the device */
name|tdsaTimerRequest_t
name|SATAIDDeviceTimer
decl_stmt|;
comment|/* ID Device Data timer for SATA device */
name|bit32
name|OSAbortAll
decl_stmt|;
ifdef|#
directive|ifdef
name|FDS_DM
name|bit32
name|devMCN
decl_stmt|;
comment|/* MCN reported by DM */
name|bit32
name|finalMCN
decl_stmt|;
comment|/* final MCN using devMCN and local MCN */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FDS_SM
name|smDeviceHandle_t
name|smDeviceHandle
decl_stmt|;
comment|/* for SATM */
name|bit32
name|SMNumOfFCA
decl_stmt|;
name|bit32
name|SMNumOfID
decl_stmt|;
name|tdsaTimerRequest_t
name|tdIDTimer
decl_stmt|;
comment|/* ID Device Data timer for SATA device */
endif|#
directive|endif
block|}
name|tdsaDeviceData_t
typedef|;
end_typedef

begin_comment
comment|/*   this field is used to add or remove SAS device from sharedcontext */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaSASSubID_s
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
name|tdsaSASSubID_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|tdsaDeviceData_s
struct_decl|;
end_struct_decl

begin_comment
comment|//struct itdssDiscoveryData_s;
end_comment

begin_comment
comment|/** \brief data structure for TD port context  *  This structure maintains information about the port such as ID address frame  *  and the discovery status and the list of devices discovered by this port.  *  itdsaIni_t->PortContext[] points to this structure.  *  agsaPortContext->osData points to this structure, too.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaPortContext_s
block|{
comment|/**< current number of devices in this PortContext */
name|bit32
name|Count
decl_stmt|;
name|bit32
name|DiscoveryState
decl_stmt|;
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
name|tdList_t
name|FreeLink
decl_stmt|;
comment|/**< free portcontext list */
name|tdList_t
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
comment|/**< the list of PhyID belonging to this port */
name|bit8
name|PhyIDList
index|[
name|TD_MAX_NUM_PHYS
index|]
decl_stmt|;
name|tiPortalContext_t
modifier|*
name|tiPortalContext
decl_stmt|;
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
name|bit8
name|directAttatchedSAS
decl_stmt|;
comment|/* boolean flag: whether the port connected directly to SAS end device*/
comment|/* SAS/SATA discovery information such as discoveringExpanderList */
name|tdsaDiscovery_t
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
name|agsaContext_t
name|agContext
decl_stmt|;
comment|/* used in tiCOMPortStop()*/
name|bit32
name|PortRecoverPhyID
decl_stmt|;
comment|/* used to remember PhyID in Port_Recover event; used in ossaDeviceRegistrationCB() */
name|bit32
name|DiscFailNSeenBC
decl_stmt|;
comment|/* used to remember broadcast change after discovery failure */
name|bit8
name|remoteName
index|[
literal|68
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|FDS_DM
name|dmPortContext_t
name|dmPortContext
decl_stmt|;
name|bit32
name|DMDiscoveryState
decl_stmt|;
comment|/* DM discovery state returned by tddmDiscoverCB or tddmQueryDiscoveryCB */
name|bit32
name|UseDM
decl_stmt|;
comment|/* set only when the directly attached target is SMP target(expander) */
name|bit32
name|UpdateMCN
decl_stmt|;
comment|/* flag for inidicating update MCN */
endif|#
directive|endif
block|}
name|tdsaPortContext_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for TD port information  *  This structure contains information in order to start the port  *  The most of fields are filled in by OS layer and there can be up to  *  8 of these structures  *  tiPortalContext_t->tdData points to this structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaPortStartInfo_s
block|{
name|tiPortalContext_t
modifier|*
name|tiPortalContext
decl_stmt|;
name|tdsaPortContext_t
modifier|*
name|portContext
decl_stmt|;
comment|/* tdsaportcontext */
name|agsaSASIdentify_t
name|SASID
decl_stmt|;
comment|/* SAS ID of the local */
name|tdssPortFlags_t
name|flags
decl_stmt|;
name|agsaPhyConfig_t
name|agPhyConfig
decl_stmt|;
block|}
name|tdsaPortStartInfo_t
typedef|;
end_typedef

begin_comment
comment|/*   expander data structure */
end_comment

begin_define
define|#
directive|define
name|REPORT_LUN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|REPORT_LUN_OPCODE
value|0xa0
end_define

begin_typedef
typedef|typedef
struct|struct
name|tdDeviceLUNInfo_s
block|{
name|unsigned
name|long
name|tiDeviceHandle
decl_stmt|;
name|bit32
name|numOfLun
decl_stmt|;
block|}
name|tdDeviceLUNInfoIOCTL_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdsaExpander_s
block|{
name|tdList_t
name|linkNode
decl_stmt|;
comment|/**< the link node data structure of the expander */
name|tdList_t
name|upNode
decl_stmt|;
comment|/**< the link node data structure of the expander */
name|tdsaDeviceData_t
modifier|*
name|tdDevice
decl_stmt|;
comment|/**< the pointer to the device */
name|struct
name|tdsaExpander_s
modifier|*
name|tdUpStreamExpander
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
name|TD_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
comment|/* routing table index in use */
name|tdsaDeviceData_t
modifier|*
name|tdDeviceToProcess
decl_stmt|;
comment|/* on some callbacks, this is a link to the device of interest */
name|bit32
name|configSASAddressHi
decl_stmt|;
name|bit32
name|configSASAddressLo
decl_stmt|;
name|struct
name|tdsaExpander_s
modifier|*
name|tdCurrentDownStreamExpander
decl_stmt|;
name|bit8
name|upStreamPhys
index|[
name|TD_MAX_EXPANDER_PHYS
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
name|bit32
name|id
decl_stmt|;
comment|/* for debugging */
name|struct
name|tdsaExpander_s
modifier|*
name|tdReturnginExpander
decl_stmt|;
name|bit8
name|downStreamPhys
index|[
name|TD_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
name|bit16
name|numOfDownStreamPhys
decl_stmt|;
name|bit16
name|currentDownStreamPhyIndex
decl_stmt|;
name|bit32
name|discoverSMPAllowed
decl_stmt|;
comment|/* used only for configurable routers */
name|bit8
name|routingAttribute
index|[
name|TD_MAX_EXPANDER_PHYS
index|]
decl_stmt|;
name|bit32
name|configSASAddressHiTable
index|[
name|DEFAULT_MAX_DEV
index|]
decl_stmt|;
name|bit32
name|configSASAddressLoTable
index|[
name|DEFAULT_MAX_DEV
index|]
decl_stmt|;
name|bit32
name|configSASAddrTableIndex
decl_stmt|;
block|}
name|tdsaExpander_t
typedef|;
end_typedef

begin_comment
comment|/*   * SATA SAT specific function pointer for SATA completion for SAT commands.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|satCompleteCbPtr_t
function_decl|)
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaIORequest_t
modifier|*
name|agIORequest
parameter_list|,
name|bit32
name|agIOStatus
parameter_list|,
name|agsaFisHeader_t
modifier|*
name|agFirstDword
parameter_list|,
name|bit32
name|agIOInfoLen
parameter_list|,
name|agsaFrameHandle_t
name|agFrameHandle
parameter_list|,
name|void
modifier|*
name|satIOContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*   * SATA SAT specific function for I/O context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|satIOContext_s
block|{
name|tdList_t
name|satIoContextLink
decl_stmt|;
name|satDeviceData_t
modifier|*
name|pSatDevData
decl_stmt|;
name|agsaFisRegHostToDevice_t
modifier|*
name|pFis
decl_stmt|;
name|tiIniScsiCmnd_t
modifier|*
name|pScsiCmnd
decl_stmt|;
name|scsiRspSense_t
modifier|*
name|pSense
decl_stmt|;
name|tiSenseData_t
modifier|*
name|pTiSenseData
decl_stmt|;
name|void
modifier|*
name|tiRequestBody
decl_stmt|;
name|void
modifier|*
name|tiScsiXchg
decl_stmt|;
comment|/* for writesame10() */
name|bit32
name|reqType
decl_stmt|;
name|bit32
name|interruptContext
decl_stmt|;
name|satCompleteCbPtr_t
name|satCompleteCB
decl_stmt|;
name|satInternalIo_t
modifier|*
name|satIntIoContext
decl_stmt|;
name|tiDeviceHandle_t
modifier|*
name|ptiDeviceHandle
decl_stmt|;
name|bit8
name|sataTag
decl_stmt|;
name|bit8
name|superIOFlag
decl_stmt|;
comment|/* Flag indicating type for tiScsiXchg */
name|bit8
name|reserved1
decl_stmt|;
comment|/* Padding for allignment */
name|bit8
name|reserved2
decl_stmt|;
comment|/* Padding for allignment */
name|bit32
name|currentLBA
decl_stmt|;
comment|/* current LBA for read and write */
name|bit32
name|ATACmd
decl_stmt|;
comment|/* ATA command */
name|bit32
name|OrgTL
decl_stmt|;
comment|/* original tranfer length(tl) */
name|bit32
name|LoopNum
decl_stmt|;
comment|/* denominator tl */
name|bit32
name|LoopNum2
decl_stmt|;
comment|/* denominator tl */
name|bit8
name|LBA
index|[
literal|8
index|]
decl_stmt|;
comment|/* for reassign blocks; current LBA */
name|bit32
name|ParmIndex
decl_stmt|;
comment|/* for reassign blocks;current idx in defective LBA LIST */
name|bit32
name|ParmLen
decl_stmt|;
comment|/* for reassign blocks; defective LBA list length */
name|bit32
name|NotifyOS
decl_stmt|;
comment|/* only for task management */
name|bit32
name|TMF
decl_stmt|;
comment|/* task management function */
name|struct
name|satIOContext_s
modifier|*
name|satToBeAbortedIOContext
decl_stmt|;
name|struct
name|satIOContext_s
modifier|*
name|satOrgIOContext
decl_stmt|;
name|bit32
name|pid
decl_stmt|;
comment|/* port id; used to protect double completion */
block|}
name|satIOContext_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SAS SSP IO reuqest body  *  This structure contains IO related fields.  *  agsaIORequest->osData points to this   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdIORequestBody_s
block|{
name|tdssIOCompleted_t
name|IOCompletionFunc
decl_stmt|;
name|tiDeviceHandle_t
modifier|*
name|tiDevHandle
decl_stmt|;
name|tiIORequest_t
modifier|*
name|tiIORequest
decl_stmt|;
comment|/* for ini */
name|agsaIORequest_t
name|agIORequest
decl_stmt|;
comment|/* for command and task and tm response and response */
name|tiIORequest_t
modifier|*
name|tiIOToBeAbortedRequest
decl_stmt|;
comment|/* IO to be aborted */
name|agsaContext_t
name|agContext
decl_stmt|;
ifdef|#
directive|ifdef
name|FDS_SM
name|smIORequestBody_t
name|smIORequestBody
decl_stmt|;
comment|/*SATA IO request body*/
name|smIORequest_t
name|smIORequest
decl_stmt|;
comment|/* for SATM */
name|void
modifier|*
name|osMemHandle
decl_stmt|;
comment|/* for ID data */
name|bit32
name|pid
decl_stmt|;
comment|/* port id for SATA completion */
name|bit32
name|superIOFlag
decl_stmt|;
comment|/* Super IO or not */
union|union
block|{
name|smScsiInitiatorRequest_t
name|smSCSIRequest
decl_stmt|;
name|smSuperScsiInitiatorRequest_t
name|smSuperSCSIRequest
decl_stmt|;
block|}
name|SM
union|;
endif|#
directive|endif
union|union
block|{
struct|struct
block|{
name|agsaSASRequestBody_t
name|agSASRequestBody
decl_stmt|;
comment|//      agsaSASRequestBody_t           agSASResponseBody;
comment|/* SSP response */
comment|//      agsaSSPResponseInfoUnit_t      agSSPRspIU;
block|}
name|SAS
struct|;
struct|struct
block|{
name|agsaSATAInitiatorRequest_t
name|agSATARequestBody
decl_stmt|;
name|scsiRspSense_t
name|sensePayload
decl_stmt|;
name|tiSenseData_t
name|tiSenseData
decl_stmt|;
name|satIOContext_t
name|satIOContext
decl_stmt|;
block|}
name|SATA
struct|;
block|}
name|transport
union|;
name|bit32
name|ioStarted
decl_stmt|;
name|bit32
name|ioCompleted
decl_stmt|;
name|bit32
name|reTries
decl_stmt|;
comment|/**< for ESGL */
name|tdList_t
name|EsglPageList
decl_stmt|;
name|bit32
name|agRequestType
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|bit32
name|expDataLength
decl_stmt|;
name|tiSgl_t
name|tiSgl1
decl_stmt|;
name|tiSgl_t
name|tiSgl2
decl_stmt|;
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
block|}
name|InitiatorRegIO
struct|;
comment|/* regular IO */
struct|struct
block|{
name|void
modifier|*
name|osMemHandle
decl_stmt|;
name|tiIORequest_t
modifier|*
name|CurrentTaskTag
decl_stmt|;
name|tiIORequest_t
modifier|*
name|TaskTag
decl_stmt|;
block|}
name|InitiatorTMIO
struct|;
comment|/* task management */
struct|struct
block|{
name|tiIORequest_t
name|tiIORequest
decl_stmt|;
comment|/* for target */
union|union
block|{
struct|struct
block|{
name|tiSgl_t
name|tiSgl1
decl_stmt|;
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
block|}
name|RegIO
struct|;
struct|struct
block|{
name|tiSgl_t
name|tiSgl1
decl_stmt|;
name|void
modifier|*
name|sglVirtualAddr
decl_stmt|;
name|tiSgl_t
name|tiSglMirror
decl_stmt|;
name|void
modifier|*
name|sglMirrorVirtualAddr
decl_stmt|;
name|tdList_t
name|EsglMirrorPageList
decl_stmt|;
block|}
name|MirrorIO
struct|;
block|}
name|TargetIOType
union|;
block|}
name|TargetIO
struct|;
comment|/* target regular IO */
block|}
name|IOType
union|;
block|}
name|tdIORequestBody_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SAS SMP reuqest body  *  This structure contains IO related fields.  *  agsaIORequest->osData points to this  *    */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdssSMPRequestBody_s
block|{
name|tdIORequestBody_t
name|IORequestBody
decl_stmt|;
comment|/* for combo, must be the first */
name|tdssSMPCompleted_t
name|SMPCompletionFunc
decl_stmt|;
comment|/* must be the second */
name|tiDeviceHandle_t
modifier|*
name|tiDevHandle
decl_stmt|;
comment|/* not used for TD generated SMP */
name|agsaIORequest_t
name|agIORequest
decl_stmt|;
name|agsaSASRequestBody_t
name|agSASRequestBody
decl_stmt|;
name|agsaSATAInitiatorRequest_t
name|agSATARequestBody
decl_stmt|;
name|void
modifier|*
name|osMemHandle
decl_stmt|;
name|tdsaDeviceData_t
modifier|*
name|tdDevice
decl_stmt|;
name|tiIORequest_t
modifier|*
name|CurrentTaskTag
decl_stmt|;
comment|/* SMP is used for simulate target reset */
name|tdsaPortContext_t
modifier|*
name|tdPortContext
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
name|bit32
name|queueNumber
decl_stmt|;
comment|/* number of retries */
comment|/* for indirect SMP req/rsp */
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
block|}
name|tdssSMPRequestBody_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_CTL
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|tdIORequest_s
block|{
name|tiIORequest_t
name|tiIORequest
decl_stmt|;
name|tdIORequestBody_t
name|tdIORequestBody
decl_stmt|;
name|void
modifier|*
name|osMemHandle
decl_stmt|;
name|void
modifier|*
name|osMemHandle2
decl_stmt|;
name|bit32
name|physUpper32
decl_stmt|;
name|bit32
name|physLower32
decl_stmt|;
name|void
modifier|*
name|virtAddr
decl_stmt|;
name|tiIntrEventType_t
name|eventType
decl_stmt|;
name|bit32
name|eventStatus
decl_stmt|;
block|}
name|tdIORequest_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PASSTHROUGH
end_ifdef

begin_comment
comment|/* this is allocated by OS layer but used in TD layer just like tdIORequestBody */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdPassthroughCmndBody_s
block|{
name|ostiPassthroughCmndEvent_t
name|EventCB
decl_stmt|;
name|tiPassthroughRequest_t
modifier|*
name|tiPassthroughRequest
decl_stmt|;
name|tiDeviceHandle_t
modifier|*
name|tiDevHandle
decl_stmt|;
name|bit32
name|tiPassthroughCmndType
decl_stmt|;
comment|/* used in local abort */
union|union
block|{
struct|struct
block|{
ifdef|#
directive|ifdef
name|TO_DO
name|tiSMPFunction_t
name|SMPFn
decl_stmt|;
name|tiSMPFunctionResult_t
name|SMPFnResult
decl_stmt|;
comment|/* for SMP target only */
name|bit32
name|IT
decl_stmt|;
comment|/* 0: initiator 1: target */
name|tiSMPFrameHeader_t
name|SMPHeader
decl_stmt|;
endif|#
directive|endif
name|tdssSMPRequestBody_t
name|SMPBody
decl_stmt|;
block|}
name|SMP
struct|;
struct|struct
block|{
name|tiDataDirection_t
name|dataDirection
decl_stmt|;
block|}
name|RMC
struct|;
block|}
name|protocol
union|;
block|}
name|tdPassthroughCmndBody_t
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
comment|/* __TDTYPES_H__ */
end_comment

end_unit

