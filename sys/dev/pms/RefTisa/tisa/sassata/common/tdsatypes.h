begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  *  * The file defines data structures for SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDSATYPES_H
end_ifndef

begin_define
define|#
directive|define
name|__TDSATYPES_H
end_define

begin_define
define|#
directive|define
name|ESGL_PAGES_SIZE
value|sizeof(agsaEsgl_t)
end_define

begin_comment
comment|/** the esgl page size */
end_comment

begin_define
define|#
directive|define
name|NUM_ESGL_PAGES
value|0
end_define

begin_comment
comment|/* old value 512 */
end_comment

begin_comment
comment|/**< the default number of esgl pages */
end_comment

begin_comment
comment|/**< target device type */
end_comment

begin_define
define|#
directive|define
name|TD_DEFAULT_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|TD_SAS_DEVICE
value|1
end_define

begin_define
define|#
directive|define
name|TD_SATA_DEVICE
value|2
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdioctl.h>
end_include

begin_comment
comment|/** \brief data structure for SATA Host  *  * to be developed  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|itdstHost_s
block|{
name|int
name|i
decl_stmt|;
block|}
name|itdstHost_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SATA Device  *  * to be developed  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ttdstDevice_s
block|{
name|int
name|i
decl_stmt|;
block|}
name|ttdstDevice_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|itdsaIni_s
block|{
comment|/**< point to the shared structure bothe SAS and SATA */
name|struct
name|tdsaContext_s
modifier|*
name|tdsaAllShared
decl_stmt|;
name|itdssOperatingOption_t
name|OperatingOption
decl_stmt|;
name|tdSCSIStatusCount_t
name|ScsiStatusCounts
decl_stmt|;
name|tdSenseKeyCount_t
name|SenseKeyCounter
decl_stmt|;
name|bit32
name|NumIOsActive
decl_stmt|;
comment|/* the list of initiator timer; upon expiration timer CB fn is called      eg) itdProcessTimers()    */
name|tdList_t
name|timerlist
decl_stmt|;
block|}
name|itdsaIni_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ttdsaXchgAllocFreeInfoList_s
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DRIVER
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|ttdsaTgt_s
block|{
comment|/* point to the shared across SAS and SATA */
name|struct
name|tdsaContext_s
modifier|*
name|tdsaAllShared
decl_stmt|;
name|ttdssOperatingOption_t
name|OperatingOption
decl_stmt|;
name|tiTargetOption_t
name|tiOperatingOption
decl_stmt|;
name|ttdsaXchgData_t
name|ttdsaXchgData
decl_stmt|;
ifdef|#
directive|ifdef
name|PASSTHROUGH
comment|/* registered passthrough CB */
name|ostiProcessPassthroughCmnd_t
name|PasthroughCB
decl_stmt|;
endif|#
directive|endif
block|}
name|ttdsaTgt_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** \brief data structure for SATA Device  *  * not in use yet. just a place holderto be develped  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdHardwareInfo_s
block|{
name|bit16
name|DeviceID
decl_stmt|;
name|bit16
name|VendorID
decl_stmt|;
name|bit8
name|ChipRev
decl_stmt|;
name|bit32
name|PciFunctionNumber
decl_stmt|;
name|bit32
name|FlashRomPresent
decl_stmt|;
block|}
name|tdHardwareInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for ESLG page  *  * This data structure describes the ESGL page maintained in TD layer.  * One important field is agEsgl which is pointer to assaEsgl_t data structure,  * which describes ESGL used in lower layer.  * Memory for this data structure is allocated using tiTdSharedMem_t data  * structure. However, Memory for agsaEsgl_t data structure is allocated using  * tiLoLevelResource_t.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaEsglPageInfo_s
block|{
name|tdList_t
name|tdlist
decl_stmt|;
comment|/**< pointers to next and previous pages */
name|bit32
name|physAddressUpper
decl_stmt|;
comment|/**< upper physical address of the page */
name|bit32
name|physAddressLower
decl_stmt|;
comment|/**< lower physical address of the page */
name|bit32
name|len
decl_stmt|;
name|agsaEsgl_t
modifier|*
name|agEsgl
decl_stmt|;
name|bit32
name|id
decl_stmt|;
comment|/**< for debugging only */
block|}
name|tdsaEsglPageInfo_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for ESLG page pool  *  * This data structure describes the pool of esgl pages  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaEsglPagePool_s
block|{
name|tdsaEsglPageInfo_t
name|EsglPages
index|[
literal|1
index|]
decl_stmt|;
comment|/**< variable size array */
block|}
name|tdsaEsglPagePool_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for ESGL pool information  *  * This data structure maintains information about ESGL pool. For example, this  * data structure maintains the number of free and total ESGL pages and uses  * tdList_t data structure for listing of ESGL pages.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaEsglAllInfo_s
block|{
comment|/*      used in tdGetEsglPages()    */
name|tdList_t
name|mainlist
decl_stmt|;
comment|/* not used */
name|tdList_t
name|freelist
decl_stmt|;
name|bit32
name|NumEsglPages
decl_stmt|;
name|bit32
name|NumFreeEsglPages
decl_stmt|;
name|bit32
name|EsglPageSize
decl_stmt|;
name|bit32
name|physAddrUpper
decl_stmt|;
name|bit32
name|physAddrLower
decl_stmt|;
name|void
modifier|*
name|virtPtr
decl_stmt|;
name|tdsaEsglPagePool_t
modifier|*
name|EsglPagePool
decl_stmt|;
block|}
name|tdsaEsglAllInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|smp_pass_through_req
block|{
name|bit8
name|exp_sas_addr
index|[
literal|8
index|]
decl_stmt|;
comment|//Storing the 16 digit expander SAS-address
name|bit32
name|smp_req_len
decl_stmt|;
comment|//Length of the request frame
name|bit32
name|smp_resp_len
decl_stmt|;
comment|//Length of the response frame
name|bit8
name|smp_req_resp
index|[
literal|1
index|]
decl_stmt|;
comment|//Pointer to the request-response frame
block|}
name|smp_pass_through_req_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|TD_INT_COALESCE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|tdsaIntCoalesceContext_s
block|{
name|tdList_t
name|MainLink
decl_stmt|;
comment|/* free */
name|tdList_t
name|FreeLink
decl_stmt|;
comment|/* in use */
name|struct
name|tdsaContext_s
modifier|*
name|tdsaAllShared
decl_stmt|;
ifdef|#
directive|ifdef
name|OS_INT_COALESCE
name|tiIntCoalesceContext_t
modifier|*
name|tiIntCoalesceCxt
decl_stmt|;
endif|#
directive|endif
name|agsaIntCoalesceContext_t
name|agIntCoalCxt
decl_stmt|;
comment|/* for debug */
name|bit32
name|id
decl_stmt|;
block|}
name|tdsaIntCoalesceContext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|tdsaHwEventSource_s
block|{
name|bit32
name|EventValid
decl_stmt|;
name|agsaEventSource_t
name|Source
decl_stmt|;
block|}
name|tdsaHwEventSource_t
typedef|;
end_typedef

begin_comment
comment|/** \brief data structure for SAS/SATA context at TD layer  *  * This data structure is used for both SAS and SATA.  * In addition, this is the data structure used mainly to communicate with  * lower layer.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaContext_s
block|{
name|bit32
name|currentOperation
decl_stmt|;
comment|/**< agsaRoot_t->osData points to this */
name|struct
name|tdsaRootOsData_s
name|agRootOsDataForInt
decl_stmt|;
comment|/* for interrupt */
name|struct
name|tdsaRootOsData_s
name|agRootOsDataForNonInt
decl_stmt|;
comment|/* for non-interrupt */
name|agsaRoot_t
name|agRootInt
decl_stmt|;
comment|/* for interrupt */
name|agsaRoot_t
name|agRootNonInt
decl_stmt|;
comment|/* for non-interrupt */
comment|/* flags values commonly used for both SAS and SATA */
name|struct
name|tdsaComMemFlags_s
name|flags
decl_stmt|;
comment|/**< software-related initialization params used in saInitialize() */
name|agsaSwConfig_t
name|SwConfig
decl_stmt|;
comment|/**< Queue-related initialization params used in saInitialize() */
name|agsaQueueConfig_t
name|QueueConfig
decl_stmt|;
comment|/**< hardware-related initialization params used in saInitialize() */
name|agsaHwConfig_t
name|HwConfig
decl_stmt|;
comment|/**< Copy of TI low level resoure */
name|tiLoLevelResource_t
name|loResource
decl_stmt|;
comment|/* information of ESGL pages allocated   tdsaEsglAllInfo_t          EsglAllInfo;   */
comment|/*  hardware information; just place holder   tdHardwareInfo_t      hwInfo;   */
name|bit32
name|currentInterruptDelay
decl_stmt|;
comment|/**< timers used commonly in SAS/SATA */
name|tdList_t
name|timerlist
decl_stmt|;
comment|/***********************************************************************/
comment|/* used to be in tdssContext_t  tdssSASShared;*/
name|struct
name|itdsaIni_s
modifier|*
name|itdsaIni
decl_stmt|;
comment|/* Initiator; */
name|struct
name|ttdsaTgt_s
modifier|*
name|ttdsaTgt
decl_stmt|;
comment|/* Target */
comment|/**< pointer to PortContext memory;  */
name|tdsaPortContext_t
modifier|*
name|PortContextMem
decl_stmt|;
comment|/**< pointer to Device memory */
name|tdsaDeviceData_t
modifier|*
name|DeviceMem
decl_stmt|;
name|tdList_t
name|FreePortContextList
decl_stmt|;
name|tdList_t
name|MainPortContextList
decl_stmt|;
name|tdList_t
name|FreeDeviceList
decl_stmt|;
name|tdList_t
name|MainDeviceList
decl_stmt|;
comment|/**< actual storage for jump table */
name|tdsaJumpTable_t
name|tdJumpTable
decl_stmt|;
comment|/**< Local SAS port start information such as ID addr */
name|tdsaPortStartInfo_t
name|Ports
index|[
name|TD_MAX_NUM_PHYS
index|]
decl_stmt|;
comment|/***********************************************************************/
comment|/**< storage for FW download contents */
name|tdFWControlEx_t
name|tdFWControlEx
decl_stmt|;
ifdef|#
directive|ifdef
name|SPC_ENABLE_PROFILE
name|tdFWProfileEx_t
name|tdFWProfileEx
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TD_INT_COALESCE
name|tdsaIntCoalesceContext_t
modifier|*
name|IntCoalesce
decl_stmt|;
endif|#
directive|endif
comment|/* first time a card is processed set this true */
name|bit32
name|first_process
decl_stmt|;
comment|/* expander list */
name|tdsaExpander_t
modifier|*
name|ExpanderHead
decl_stmt|;
comment|//  tdList_t                   discoveringExpanderList;
name|tdList_t
name|freeExpanderList
decl_stmt|;
name|bit32
name|phyCount
decl_stmt|;
name|bit32
name|IBQnumber
decl_stmt|;
name|bit32
name|OBQnumber
decl_stmt|;
name|bit32
name|InboundQueueSize
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|InboundQueueEleSize
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|OutboundQueueSize
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|OutboundQueueEleSize
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|OutboundQueueInterruptDelay
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|OutboundQueueInterruptCount
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|OutboundQueueInterruptEnable
index|[
name|AGSA_MAX_OUTBOUND_Q
index|]
decl_stmt|;
name|bit32
name|InboundQueuePriority
index|[
name|AGSA_MAX_INBOUND_Q
index|]
decl_stmt|;
name|bit32
name|QueueOption
decl_stmt|;
name|bit32
name|tdDeviceIdVendId
decl_stmt|;
name|bit32
name|tdSubVendorId
decl_stmt|;
comment|/* instance number */
name|bit8
name|CardIDString
index|[
name|TD_CARD_ID_LEN
index|]
decl_stmt|;
name|bit32
name|CardID
decl_stmt|;
ifdef|#
directive|ifdef
name|VPD_TESTING
comment|/* temp; for testing VPD indirect */
name|bit32
name|addrUpper
decl_stmt|;
name|bit32
name|addrLower
decl_stmt|;
endif|#
directive|endif
name|bit32
name|resetCount
decl_stmt|;
name|tdsaHwEventSource_t
name|eventSource
index|[
name|TD_MAX_NUM_PHYS
index|]
decl_stmt|;
name|bit32
name|portTMO
decl_stmt|;
comment|/* in 100ms */
name|bit32
name|phyCalibration
decl_stmt|;
comment|/* enables or disables phy calibration */
name|bit32
name|FCA
decl_stmt|;
comment|/* force to clear affiliation by sending SMP HARD RESET */
name|bit32
name|SMPQNum
decl_stmt|;
comment|/* first high priority queue number for SMP */
name|bit32
name|ResetInDiscovery
decl_stmt|;
comment|/* hard/link reset in discovery */
name|bit32
name|FWMaxPorts
decl_stmt|;
name|bit32
name|IDRetry
decl_stmt|;
comment|/* SATA ID failurs are retired */
name|bit32
name|RateAdjust
decl_stmt|;
comment|/* allow retry open with lower connection rate */
ifdef|#
directive|ifdef
name|AGTIAPI_CTL
name|bit16
name|SASConnectTimeLimit
decl_stmt|;
comment|/* used by tdsaCTLSet() */
endif|#
directive|endif
name|bit32
name|MaxNumOSLocks
decl_stmt|;
comment|/* max number of OS layer locks */
name|bit32
name|MaxNumLLLocks
decl_stmt|;
comment|/* max num of LL locks */
name|bit32
name|MaxNumLocks
decl_stmt|;
comment|/* max num of locks for layers and modules (LL, TDM, SATM, DM) */
ifdef|#
directive|ifdef
name|FDS_DM
name|bit32
name|MaxNumDMLocks
decl_stmt|;
comment|/* max num of DM locks */
name|dmRoot_t
name|dmRoot
decl_stmt|;
comment|/* discovery root */
name|dmSwConfig_t
name|dmSwConfig
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FDS_SM
name|bit32
name|MaxNumSMLocks
decl_stmt|;
comment|/* max num of SM locks */
name|smRoot_t
name|smRoot
decl_stmt|;
comment|/* SATM root */
name|smSwConfig_t
name|smSwConfig
decl_stmt|;
endif|#
directive|endif
name|bit32
name|MCN
decl_stmt|;
comment|/* temp; only for testing and to be set by registry or adj file */
name|bit32
name|sflag
decl_stmt|;
comment|/* Sflag bit */
ifdef|#
directive|ifdef
name|CCFLAGS_PHYCONTROL_COUNTS
name|agsaPhyAnalogSetupRegisters_t
name|analog
index|[
name|TD_MAX_NUM_PHYS
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* CCFLAGS_PHYCONTROL_COUNTS */
name|bit32
name|stp_idle_time
decl_stmt|;
comment|/* stp idle time for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|STP_MCT_TMO
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|SSP_MCT_TMO
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|MAX_OPEN_TIME
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|SMP_MAX_CONN_TIMER
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|STP_FRM_TMO
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|MFD
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|OPNRJT_RTRY_INTVL
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|DOPNRJT_RTRY_TMO
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|COPNRJT_RTRY_TMO
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|DOPNRJT_RTRY_THR
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|COPNRJT_RTRY_THR
decl_stmt|;
comment|/*  for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|bit32
name|itNexusTimeout
decl_stmt|;
comment|/*  set by registry */
name|bit32
name|MAX_AIP
decl_stmt|;
comment|/* for agsaSASProtocolTimerConfigurationPage_t; set by registry or adj file */
name|agsaMPIContext_t
name|MpiOverride
decl_stmt|;
ifdef|#
directive|ifdef
name|TI_GETFOR_ONRESET
name|bit8
name|FatalErrorData
index|[
operator|(
literal|5
operator|*
operator|(
literal|1024
operator|*
literal|1024
operator|)
operator|)
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* TI_GETFOR_ONRESET */
name|bit32
name|sgpioResponseSet
decl_stmt|;
comment|/*Used to sync between SGPIO Req and Resp */
specifier|volatile
name|NvmdResponseSet
expr_stmt|;
block|}
name|tdsaContext_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_define
define|#
directive|define
name|CMDS_PER_IO_IOPS
value|1
end_define

begin_define
define|#
directive|define
name|CMDS_PER_IO_DUP
value|1
end_define

begin_comment
comment|//4
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** \brief the root data structure for TD layer  *  * This data structure is the main data structure used in communicating  * with OS layer. For example, tiRoot_t->tdData points to this data structure  * From this data structure, SATA host/Device and SAS initiator/target are found.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdsaRoot_s
block|{
comment|/**<< common data structure for SAS/SATA */
name|tdsaContext_t
name|tdsaAllShared
decl_stmt|;
name|bit32
name|autoGoodRSP
decl_stmt|;
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
name|itdsaIni_t
modifier|*
name|itdsaIni
decl_stmt|;
comment|/**< SAS/SATA initiator */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TARGET_DRIVER
name|ttdsaTgt_t
modifier|*
name|ttdsaTgt
decl_stmt|;
comment|/**< SAS/SATA target    */
endif|#
directive|endif
block|}
name|tdsaRoot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tmf_pass_through_req
block|{
name|bit8
name|pathId
decl_stmt|;
name|bit8
name|targetId
decl_stmt|;
name|bit8
name|lun
decl_stmt|;
block|}
name|tmf_pass_through_req_t
typedef|;
end_typedef

begin_comment
comment|/* Context Field accessors */
end_comment

begin_define
define|#
directive|define
name|TD_GET_TIROOT
parameter_list|(
name|sa_root
parameter_list|)
value|(((tdsaRootOsData_t *)(sa_root)->osData)->tiRoot)
end_define

begin_define
define|#
directive|define
name|TD_GET_TDROOT
parameter_list|(
name|ti_root
parameter_list|)
value|((tdsaRoot_t *)(ti_root)->tdData)
end_define

begin_define
define|#
directive|define
name|TD_GET_TICONTEXT
parameter_list|(
name|ti_root
parameter_list|)
value|((tdsaContext_t *)&TD_GET_TDROOT(ti_root)->tdsaAllShared)
end_define

begin_define
define|#
directive|define
name|TD_GET_TIINI_CONTEXT
parameter_list|(
name|ti_root
parameter_list|)
value|((itdsaIni_t *)TD_GET_TICONTEXT(ti_root)->itdsaIni)
end_define

begin_define
define|#
directive|define
name|TD_GET_TITGT_CONTEXT
parameter_list|(
name|ti_root
parameter_list|)
value|((ttdsaTgt_t *)TD_GET_TICONTEXT(ti_root)->ttdsaTgt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TDSATYPES_H */
end_comment

end_unit

