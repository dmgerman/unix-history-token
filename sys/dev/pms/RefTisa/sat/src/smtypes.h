begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMTYPES_H__
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
file|<dev/pms/RefTisa/sat/api/sm.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/smapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/tdsmapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/src/smlist.h>
end_include

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

begin_define
define|#
directive|define
name|SAT_APAPI_CMDQ_MAX
value|2
end_define

begin_comment
comment|/* SMP direct payload size limit: IOMB direct payload size = 48 */
end_comment

begin_define
define|#
directive|define
name|SMP_DIRECT_PAYLOAD_LIMIT
value|44
end_define

begin_comment
comment|/* timer functions ; both I and T */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|smTimerCBFunc_t
function_decl|)
parameter_list|(
name|smRoot_t
modifier|*
name|smRoot
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
comment|/** \brief data structure for timer request  *  Timer requests are enqueued and dequeued using smList_t  *  and have a callback function  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smTimerRequest_s
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
name|smTimerCBFunc_t
name|timerCBFunc
decl_stmt|;
name|smList_t
name|timerLink
decl_stmt|;
name|bit32
name|timerRunning
decl_stmt|;
block|}
name|smTimerRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smSatInternalIo_s
block|{
name|smList_t
name|satIntIoLink
decl_stmt|;
name|smIORequest_t
name|satIntSmIORequest
decl_stmt|;
comment|/* old satIntTiIORequest */
name|void
modifier|*
name|satIntRequestBody
decl_stmt|;
comment|/* maps to smIOrequestBody */
name|smScsiInitiatorRequest_t
name|satIntSmScsiXchg
decl_stmt|;
comment|/* old satIntTiScsiXchg*/
name|smMem_t
name|satIntDmaMem
decl_stmt|;
name|smMem_t
name|satIntReqBodyMem
decl_stmt|;
name|bit32
name|satIntFlag
decl_stmt|;
name|smIORequest_t
modifier|*
name|satOrgSmIORequest
decl_stmt|;
comment|/* old satOrgTiIORequest */
name|bit32
name|id
decl_stmt|;
block|}
name|smSatInternalIo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smDeviceData_s
block|{
name|smList_t
name|FreeLink
decl_stmt|;
comment|/* free dev list */
name|smList_t
name|MainLink
decl_stmt|;
comment|/* main(in use) dev list */
name|bit32
name|id
decl_stmt|;
comment|/* for debugging only */
name|smRoot_t
modifier|*
name|smRoot
decl_stmt|;
name|agsaDevHandle_t
modifier|*
name|agDevHandle
decl_stmt|;
name|bit32
name|valid
decl_stmt|;
comment|/* valid or registered */
name|smTimerRequest_t
name|SATAIDDeviceTimer
decl_stmt|;
comment|/* ID Device Data timer for SATA device */
name|bit32
name|SMAbortAll
decl_stmt|;
comment|/* flag for abortall case */
name|smDeviceHandle_t
modifier|*
name|smDevHandle
decl_stmt|;
name|bit32
name|directlyAttached
decl_stmt|;
name|agsaDevHandle_t
modifier|*
name|agExpDevHandle
decl_stmt|;
comment|/* expander a device is attached to if expander attached */
name|bit32
name|phyID
decl_stmt|;
name|agsaContext_t
name|agDeviceResetContext
decl_stmt|;
comment|/* used in saLocalPhyControl() */
name|bit32
name|SMNumOfFCA
decl_stmt|;
comment|/* from satDeviceData_t */
name|smList_t
name|satIoLinkList
decl_stmt|;
comment|/* Normal I/O from TISA         */
name|smList_t
name|satFreeIntIoLinkList
decl_stmt|;
comment|/* SAT internal I/O free list   */
name|smList_t
name|satActiveIntIoLinkList
decl_stmt|;
comment|/* SAT internal I/O active list */
name|smSatInternalIo_t
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
name|satUltraDMAMode
decl_stmt|;
comment|/* Ultra DMA mode value        */
name|bit32
name|satDMADIRSupport
decl_stmt|;
comment|/* Flag for DMA direction       */
name|bit32
name|satReadLookAheadSupport
decl_stmt|;
comment|/* Flag for Read Look Ahead */
name|bit32
name|satVolatileWriteCacheSupport
decl_stmt|;
comment|/* Flag for Volatile Write Cache support*/
name|bit32
name|satWWNSupport
decl_stmt|;
comment|/* Flag for DMA Enabled         */
name|bit32
name|satDMASetupAA
decl_stmt|;
comment|/* Flag for DMA Setup Auto-Activate */
name|bit32
name|satNCQQMgntCmd
decl_stmt|;
comment|/* Flag for NCQ Queue Management Command */
name|bit32
specifier|volatile
name|satPendingIO
decl_stmt|;
comment|/* Number of pending I/O        */
name|bit32
specifier|volatile
name|satPendingNCQIO
decl_stmt|;
comment|/* Number of pending NCQ I/O    */
name|bit32
specifier|volatile
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
name|smIORequest_t
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
name|OSAbortAll
decl_stmt|;
comment|/* OS calls abort all           */
name|bit32
name|ReadCapacity
decl_stmt|;
comment|/* Read Capacity Type; 10, 16   */
name|bit32
name|sasAddressLo
decl_stmt|;
comment|/**< HOST SAS address lower part */
name|bit32
name|sasAddressHi
decl_stmt|;
comment|/**< HOST SAS address higher part */
block|}
name|smDeviceData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smAtaPassThroughHdr_s
block|{
name|bit8
name|opc
decl_stmt|;
name|bit8
name|mulCount
range|:
literal|3
decl_stmt|;
name|bit8
name|proto
range|:
literal|4
decl_stmt|;
name|bit8
name|extend
range|:
literal|1
decl_stmt|;
name|bit8
name|offline
range|:
literal|2
decl_stmt|;
name|bit8
name|ckCond
range|:
literal|1
decl_stmt|;
name|bit8
name|tType
range|:
literal|1
decl_stmt|;
name|bit8
name|tDir
range|:
literal|1
decl_stmt|;
name|bit8
name|byteBlock
range|:
literal|1
decl_stmt|;
name|bit8
name|tlength
range|:
literal|2
decl_stmt|;
block|}
name|smAtaPassThroughHdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * SCSI Sense Data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
name|snsRespCode
decl_stmt|;
name|bit8
name|snsSegment
decl_stmt|;
name|bit8
name|senseKey
decl_stmt|;
comment|/* sense key                                */
name|bit8
name|info
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|addSenseLen
decl_stmt|;
comment|/* 11 always                                */
name|bit8
name|cmdSpecific
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|addSenseCode
decl_stmt|;
comment|/* additional sense code                    */
name|bit8
name|senseQual
decl_stmt|;
comment|/* additional sense code qualifier          */
name|bit8
name|fru
decl_stmt|;
name|bit8
name|skeySpecific
index|[
literal|3
index|]
decl_stmt|;
block|}
name|smScsiRspSense_t
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
name|smSatCompleteCbPtr_t
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
comment|/* for SMP only */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|smSMPCompleted_t
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
comment|/*   * SATA SAT specific function for I/O context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smSatIOContext_s
block|{
name|smList_t
name|satIoContextLink
decl_stmt|;
name|smDeviceData_t
modifier|*
name|pSatDevData
decl_stmt|;
name|agsaFisRegHostToDevice_t
modifier|*
name|pFis
decl_stmt|;
name|smIniScsiCmnd_t
modifier|*
name|pScsiCmnd
decl_stmt|;
name|smScsiRspSense_t
modifier|*
name|pSense
decl_stmt|;
name|smSenseData_t
modifier|*
name|pSmSenseData
decl_stmt|;
comment|/* old pTiSenseData */
name|void
modifier|*
name|smRequestBody
decl_stmt|;
comment|/* smIORequestBody_t; old tiRequestBody*/
name|void
modifier|*
name|smScsiXchg
decl_stmt|;
comment|/* for writesame10(); old tiScsiXchg */
name|bit32
name|reqType
decl_stmt|;
name|bit32
name|interruptContext
decl_stmt|;
name|smSatCompleteCbPtr_t
name|satCompleteCB
decl_stmt|;
name|smSatInternalIo_t
modifier|*
name|satIntIoContext
decl_stmt|;
comment|/* SATM generated IOs */
name|smDeviceHandle_t
modifier|*
name|psmDeviceHandle
decl_stmt|;
comment|/* old ptiDeviceHandle */
name|bit8
name|sataTag
decl_stmt|;
name|bit8
name|superIOFlag
decl_stmt|;
comment|/* Flag indicating type for smScsiXchg */
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
name|smSatIOContext_s
modifier|*
name|satToBeAbortedIOContext
decl_stmt|;
name|struct
name|smSatIOContext_s
modifier|*
name|satOrgIOContext
decl_stmt|;
name|bit32
name|UpperAddr
decl_stmt|;
name|bit32
name|LowerAddr
decl_stmt|;
name|bit32
name|SplitIdx
decl_stmt|;
name|bit32
name|AdjustBytes
decl_stmt|;
name|bit32
name|EsglLen
decl_stmt|;
comment|/* For the SAT Passthrough */
name|bit8
name|ck_cond
decl_stmt|;
name|bit8
name|extend
decl_stmt|;
name|bit8
name|sectorCnt07
decl_stmt|;
name|bit8
name|LBAHigh07
decl_stmt|;
name|bit8
name|LBAMid07
decl_stmt|;
name|bit8
name|LBALow07
decl_stmt|;
name|bit8
name|Sector_Cnt_Upper_Nonzero
decl_stmt|;
name|bit8
name|LBA_Upper_Nonzero
decl_stmt|;
name|bit32
name|pid
decl_stmt|;
comment|/* port id; used to protect double completion */
name|bit32
name|id
decl_stmt|;
comment|/* for debugging */
block|}
name|smSatIOContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smIORequestBody_s
block|{
name|smList_t
name|satIoBodyLink
decl_stmt|;
name|smDeviceHandle_t
modifier|*
name|smDevHandle
decl_stmt|;
name|smIORequest_t
modifier|*
name|smIORequest
decl_stmt|;
name|agsaIORequest_t
name|agIORequest
decl_stmt|;
name|smIORequest_t
modifier|*
name|smIOToBeAbortedRequest
decl_stmt|;
comment|/* IO to be aborted; old tiIOToBeAbortedRequest */
name|bit32
name|id
decl_stmt|;
name|bit32
name|InUse
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|agsaSATAInitiatorRequest_t
name|agSATARequestBody
decl_stmt|;
name|smScsiRspSense_t
name|sensePayload
decl_stmt|;
name|smSenseData_t
name|smSenseData
decl_stmt|;
comment|/* old tiSenseData */
name|smSatIOContext_t
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
union|union
block|{
struct|struct
block|{
name|bit32
name|expDataLength
decl_stmt|;
name|smSgl_t
name|smSgl1
decl_stmt|;
comment|/* old tiSgl1 */
name|smSgl_t
name|smSgl2
decl_stmt|;
comment|/* old tiSgl2 */
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
name|smIORequest_t
modifier|*
name|CurrentTaskTag
decl_stmt|;
name|smIORequest_t
modifier|*
name|TaskTag
decl_stmt|;
block|}
name|InitiatorTMIO
struct|;
comment|/* task management */
block|}
name|IOType
union|;
block|}
name|smIORequestBody_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smSMPRequestBody_s
block|{
name|smSMPCompleted_t
name|SMPCompletionFunc
decl_stmt|;
comment|/* must be the second */
name|smDeviceHandle_t
modifier|*
name|smDevHandle
decl_stmt|;
comment|/* not used for SM generated SMP */
name|agsaIORequest_t
name|agIORequest
decl_stmt|;
name|agsaSASRequestBody_t
name|agSASRequestBody
decl_stmt|;
name|void
modifier|*
name|osMemHandle
decl_stmt|;
name|smDeviceData_t
modifier|*
name|smDeviceData
decl_stmt|;
name|smIORequest_t
modifier|*
name|CurrentTaskTag
decl_stmt|;
comment|/* SMP is used for simulate target reset */
comment|//  tdsaPortContext_t              *tdPortContext; /* portcontext where SMP is sent from */
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
block|}
name|smSMPRequestBody_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smRootOsData_s
block|{
name|smRoot_t
modifier|*
name|smRoot
decl_stmt|;
comment|/**< Pointer back to smRoot                 */
name|void
modifier|*
name|smAllShared
decl_stmt|;
comment|/**< Pointer to smIntContext_t               */
name|void
modifier|*
name|smIni
decl_stmt|;
comment|/**< Pointer to SAS/SATA initiator               */
block|}
name|smRootOsData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smIntContext_s
block|{
comment|/**< agsaRoot_t->osData points to this */
name|struct
name|smRootOsData_s
name|smRootOsData
decl_stmt|;
name|bit32
name|usecsPerTick
decl_stmt|;
name|agsaRoot_t
modifier|*
name|agRoot
decl_stmt|;
comment|/**< software-related initialization params used in saInitialize() */
name|smSwConfig_t
name|SwConfig
decl_stmt|;
comment|/**< timers used commonly in SAS/SATA */
name|smList_t
name|timerlist
decl_stmt|;
comment|/**< pointer to Device memory */
name|smDeviceData_t
modifier|*
name|DeviceMem
decl_stmt|;
name|smList_t
name|FreeDeviceList
decl_stmt|;
name|smList_t
name|MainDeviceList
decl_stmt|;
comment|/**< pointer to IO memory */
name|smIORequestBody_t
modifier|*
name|IOMem
decl_stmt|;
name|smList_t
name|freeIOList
decl_stmt|;
name|smList_t
name|mainIOList
decl_stmt|;
name|bit32
name|FCA
decl_stmt|;
block|}
name|smIntContext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smIntRoot_s
block|{
comment|/**<< common data structure for SAS/SATA */
name|smIntContext_t
name|smAllShared
decl_stmt|;
block|}
name|smIntRoot_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SMTYPES_H__ */
end_comment

end_unit

