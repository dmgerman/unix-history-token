begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* ** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, * *INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, *WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF *THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE ** * $FreeBSD$ ** *******************************************************************************/
end_comment

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
file|<dev/pms/freebsd/driver/ini/src/agdef.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/lxcommon.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_ISCSI
end_ifdef

begin_include
include|#
directive|include
file|"cmtypes.h"
end_include

begin_include
include|#
directive|include
file|"bktypes.h"
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
file|<dev/pms/RefTisa/tisa/sassata/sas/ini/itdtypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/common/tdtypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_typedef
typedef|typedef
name|u_int32_t
name|atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(*(p) = (v))
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|atomic_add_int(p,1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_int(p,1)
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_add_int(p,n)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_subtract_int(p,n)
end_define

begin_define
define|#
directive|define
name|AGSCSI_INIT_XCHG_LEN
value|sizeof(tiScsiInitiatorRequest_t)
end_define

begin_define
define|#
directive|define
name|AGSMP_INIT_XCHG_LEN
value|sizeof(tiSMPFrame_t)
end_define

begin_define
define|#
directive|define
name|CMND_DMA_UNMAP
parameter_list|(
name|pCard
parameter_list|,
name|cmnd
parameter_list|)
end_define

begin_comment
comment|// define PMC lean flags used for bit operations to track dev listing state
end_comment

begin_define
define|#
directive|define
name|DPMC_LEANFLAG_NOAGDEVYT
value|2
end_define

begin_comment
comment|// agDev handle not present yet
end_comment

begin_define
define|#
directive|define
name|DPMC_LEANFLAG_NOWWNLIST
value|4
end_define

begin_comment
comment|// WWNList entry not present
end_comment

begin_define
define|#
directive|define
name|DPMC_LEANFLAG_AGDEVUSED
value|8
end_define

begin_comment
comment|// agDev handle used
end_comment

begin_define
define|#
directive|define
name|DPMC_LEANFLAG_PDEVSUSED
value|16
end_define

begin_comment
comment|// pDevice slot used
end_comment

begin_typedef
typedef|typedef
name|bus_dmamap_t
name|dma_addr_t
typedef|;
end_typedef

begin_comment
comment|// ##
end_comment

begin_define
define|#
directive|define
name|timer_list
value|callout
end_define

begin_typedef
typedef|typedef
struct|struct
name|ccb_hdr_s
block|{
name|void
modifier|*
name|next
decl_stmt|;
block|}
name|ccb_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CCB
block|{
name|U32
name|targetId
decl_stmt|;
name|U32
name|lun
decl_stmt|;
name|U32
name|channel
decl_stmt|;
name|U16
name|ccbStatus
decl_stmt|;
name|U16
name|scsiStatus
decl_stmt|;
name|U32
name|dataLen
decl_stmt|;
name|U08
name|senseLen
decl_stmt|;
name|U08
name|addrMode
decl_stmt|;
name|U08
name|retryCount
decl_stmt|;
name|U16
name|numSgElements
decl_stmt|;
name|U32
name|flags
decl_stmt|;
name|U32_64
name|dmaHandle
decl_stmt|;
name|caddr_t
name|pSenseData
decl_stmt|;
comment|// auto request sense data
name|tiSgl_t
modifier|*
name|sgList
decl_stmt|;
comment|// [AGTIAPI_MAX_DMA_SEGS]
name|bus_addr_t
name|tisgl_busaddr
decl_stmt|;
comment|//  dma_addr_t        sglDmaHandle;      // ## dmaHandle for sgList
name|tiDeviceHandle_t
modifier|*
name|devHandle
decl_stmt|;
name|struct
name|_CCB
modifier|*
name|pccbNext
decl_stmt|;
name|struct
name|_CCB
modifier|*
name|pccbChainNext
decl_stmt|;
comment|// forward link pointers
name|struct
name|scsi_cmnd
modifier|*
name|cmd
decl_stmt|;
comment|// call back owner pointer
name|struct
name|_CCB
modifier|*
name|pccbIO
decl_stmt|;
comment|// for TM TARGET_RESET
name|U32_64
name|startTime
decl_stmt|;
name|tiIORequest_t
name|tiIORequest
decl_stmt|;
name|tdIORequestBody_t
name|tdIOReqBody
decl_stmt|;
name|tiSuperScsiInitiatorRequest_t
name|tiSuperScsiRequest
decl_stmt|;
name|tiSMPFrame_t
name|tiSMPFrame
decl_stmt|;
ifdef|#
directive|ifdef
name|CCBUILD_TEST_EPL
name|caddr_t
name|epl_ptr
decl_stmt|;
name|dma_addr_t
name|epl_dma_ptr
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CCBUILD_TEST_DPL
name|caddr_t
name|dplPtr
decl_stmt|;
name|dma_addr_t
name|dplDma
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PERF_COUNT
argument_list|)
name|u64
name|startCmnd
decl_stmt|;
comment|// temp var to hold cmnd arrival
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENABLE_NONSTANDARD_SECTORS
name|caddr_t
name|metaPtr
decl_stmt|;
name|dma_addr_t
name|dmaHandleMeta
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENABLE_SATA_DIF
name|caddr_t
name|holePtr
decl_stmt|;
name|dma_addr_t
name|dmaHandleHole
decl_stmt|;
name|int
name|scaling_done
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SUPER_FAST_IO_TEST
name|agsaIORequest_t
name|IoContext
decl_stmt|;
name|agsaSASRequestBody_t
name|sasRequestBody
decl_stmt|;
name|u32
name|reqType
decl_stmt|;
name|u32
name|queueId
decl_stmt|;
name|agsaSgl_t
modifier|*
name|sgl
decl_stmt|;
comment|// Used for esgl
endif|#
directive|endif
comment|//new
name|bus_dmamap_t
name|CCB_dmamap
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* replacement of struct scsi_cmnd */
name|struct
name|agtiapi_softc
modifier|*
name|pmcsc
decl_stmt|;
block|}
name|ccb_t
operator|,
typedef|*
name|pccb_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AGTIAPI_CCB_SIZE
value|sizeof(struct _CCB)
end_define

begin_comment
comment|/* typedef struct _ag_portal_data {   ag_portal_info_t    portalInfo;   void                *pCard; } ag_portal_data_t; */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEK_TABLE_0
init|=
literal|0
block|,
name|DEK_TABLE_1
init|=
literal|1
block|,
name|DEK_TABLE_INVALID
init|=
name|DEK_MAX_TABLES
block|,      }
name|dek_table_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ag_encrypt_map_s
block|{
name|unsigned
name|long
name|long
name|lbaMin
decl_stmt|;
name|unsigned
name|long
name|long
name|lbaMax
decl_stmt|;
name|dek_table_e
name|dekTable
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
name|bit32
name|kekIndex
decl_stmt|;
name|bit32
name|kekTagCheck
decl_stmt|;
name|bit32
name|kekTag
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|list_head
modifier|*
name|list
decl_stmt|;
block|}
name|ag_encrypt_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ag_kek_table_s
block|{
define|#
directive|define
name|KEK_TABLE_MAX_ENTRY
value|8
name|bit32
name|wrapperIndex
decl_stmt|;
name|tiEncryptKekBlob_t
name|kekBlob
decl_stmt|;
block|}
name|ag_kek_table_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ag_dek_kek_map_s
block|{
name|bit32
name|kekIndex
decl_stmt|;
block|}
name|ag_dek_kek_map_t
typedef|;
end_typedef

begin_comment
comment|/* ** There is no LUN filed for the device structure. ** The reason is if the device is a single lun device, it ** will be lun 0.  If is a multi-lun device such as EMC  ** or Galaxi, only one device structure is associated with ** the device since only one device handler is provided. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_device
block|{
comment|//#ifdef HOTPLUG_SUPPORT
comment|/* used for hot-plug, temporarily either in new or removed devices list */
name|LINK_NODE
name|devLink
decl_stmt|;
comment|//#endif
name|U32
name|targetId
decl_stmt|;
name|U32
name|flags
decl_stmt|;
name|U16
name|devType
decl_stmt|;
name|U16
name|resetCount
decl_stmt|;
name|U32
name|portalId
decl_stmt|;
name|void
modifier|*
name|pCard
decl_stmt|;
name|U32
name|sector_size
decl_stmt|;
name|U32
name|CCBCount
decl_stmt|;
ifdef|#
directive|ifdef
name|HOTPLUG_SUPPORT
name|struct
name|scsi_device
modifier|*
name|sdev
decl_stmt|;
endif|#
directive|endif
name|tiDeviceHandle_t
modifier|*
name|pDevHandle
decl_stmt|;
name|tiDeviceInfo_t
name|devInfo
decl_stmt|;
name|ag_portal_info_t
modifier|*
name|pPortalInfo
decl_stmt|;
name|U08
name|targetName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
name|U16
name|targetLen
decl_stmt|;
name|U32
name|qbusy
decl_stmt|;
name|U32
name|qdepth
decl_stmt|;
block|}
name|ag_device_t
typedef|;
end_typedef

begin_comment
comment|/*       ** Use an array of these structures to map from assigned ** device target id (which is the index into the array) to ** the entry in the bd_devlist. ** ** Please note that an extra entry has been added to both ** the bd_devlist array and the bd_WWN_list.  This last ** entry is the "no mapping" entry -- used for initialization ** and to indicate an inactive entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_tgt_map
block|{
name|U16
name|devListIndex
decl_stmt|;
name|U16
name|flags
decl_stmt|;
name|U08
name|targetName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
name|U16
name|targetLen
decl_stmt|;
name|U08
name|portId
decl_stmt|;
name|int
name|sasLrIdx
decl_stmt|;
comment|// Index into SAS Local/Remote list (part of extend-portID)
name|uint32_t
name|devRemoved
decl_stmt|;
comment|// when set, ghost target device is timing out
block|}
name|ag_tgt_map_t
typedef|;
end_typedef

begin_comment
comment|// use an array of this struct to map local/remote dyads to ag_tgt_map_t
end_comment

begin_comment
comment|// entries
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_slr_map
block|{
name|U08
name|localeName
index|[
name|AGTIAPI_MIN_NAME
index|]
decl_stmt|;
name|U08
name|remoteName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
name|int
name|localeNameLen
decl_stmt|;
name|int
name|remoteNameLen
decl_stmt|;
block|}
name|ag_slr_map_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|LINUX_PERBI_SUPPORT
end_ifdef

begin_comment
comment|// Use a list of these structures to hold target-WWN
end_comment

begin_comment
comment|// mapping assignments on the boot line during driver
end_comment

begin_comment
comment|// loading.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ag_mapping_s
block|{
name|struct
name|_ag_mapping_s
modifier|*
name|next
decl_stmt|;
name|U16
name|targetId
decl_stmt|;
name|U08
name|cardNo
decl_stmt|;
name|U08
name|targetLen
decl_stmt|;
name|U08
name|targetName
index|[
name|AGTIAPI_MAX_NAME
index|]
decl_stmt|;
block|}
name|ag_mapping_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_ag_portal_data
block|{
name|ag_portal_info_t
name|portalInfo
decl_stmt|;
name|void
modifier|*
name|pCard
decl_stmt|;
block|}
name|ag_portal_data_t
typedef|;
end_typedef

begin_comment
comment|// The softc holds our per-instance data
end_comment

begin_struct
struct|struct
name|agtiapi_softc
block|{
name|device_t
name|my_dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|my_cdev
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|resource
modifier|*
name|resirq
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
name|int
name|rscID
index|[
name|MAX_MSIX_NUM_VECTOR
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
index|[
name|MAX_MSIX_NUM_VECTOR
index|]
decl_stmt|;
name|void
modifier|*
name|intrcookie
index|[
name|MAX_MSIX_NUM_VECTOR
index|]
decl_stmt|;
comment|// timer stuff; mc lean
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
name|struct
name|cam_devq
modifier|*
name|devq
decl_stmt|;
name|struct
name|callout
name|OS_timer
decl_stmt|;
name|struct
name|mtx
name|OS_timer_lock
decl_stmt|;
name|struct
name|callout
name|IO_timer
decl_stmt|;
name|struct
name|mtx
name|IO_timer_lock
decl_stmt|;
name|struct
name|callout
name|devRmTimer
decl_stmt|;
name|struct
name|mtx
name|devRmTimerLock
decl_stmt|;
name|uint16_t
name|rmChkCt
decl_stmt|;
comment|// for tiSgl_t memory
name|tiSgl_t
modifier|*
name|tisgl_mem
decl_stmt|;
name|bus_addr_t
name|tisgl_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|tisgl_dmat
decl_stmt|;
name|bus_dmamap_t
name|tisgl_map
decl_stmt|;
comment|// for ostiAllocMemory() pre allocation pool
name|void
modifier|*
name|osti_mem
decl_stmt|;
name|bus_addr_t
name|osti_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|osti_dmat
decl_stmt|;
name|bus_dmamap_t
name|osti_mapp
decl_stmt|;
comment|// pre-allocation pool
name|U32
name|typhn
decl_stmt|;
comment|// size needed
name|void
modifier|*
name|typh_mem
decl_stmt|;
name|bus_addr_t
name|typh_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|typh_dmat
decl_stmt|;
name|bus_dmamap_t
name|typh_mapp
decl_stmt|;
name|U32
name|typhIdx
decl_stmt|;
name|U32
name|tyPhsIx
decl_stmt|;
comment|// begin ag_card_t references (AKA pCard)
name|struct
name|Scsi_Host
modifier|*
name|pHost
decl_stmt|;
name|tiRoot_t
name|tiRoot
decl_stmt|;
comment|// tiRoot for the card
name|U32
name|VidDid
decl_stmt|;
name|U32
name|SVID_SSID
decl_stmt|;
name|U32
name|flags
decl_stmt|;
comment|// keep track of state
name|U32
name|freezeSim
decl_stmt|;
name|U32
name|up_count
decl_stmt|;
name|U32
name|down_count
decl_stmt|;
name|U08
name|hostNo
decl_stmt|;
comment|// host number signed by OS
name|U08
name|cardNo
decl_stmt|;
comment|// host no signed by driver
name|U16
name|tgtCount
decl_stmt|;
comment|// total target devices
name|U16
name|badTgtCount
decl_stmt|;
comment|// total bad target devices
name|U16
name|activeCCB
decl_stmt|;
comment|// number of active CCB
name|U32
name|ccbTotal
decl_stmt|;
comment|// total # of CCB allocated
name|U32
name|devDiscover
decl_stmt|;
comment|// # of device to be discovered
name|U32
name|resetCount
decl_stmt|;
name|U32
name|timeoutTicks
decl_stmt|;
name|U32
name|portCount
decl_stmt|;
comment|// portal count
name|U32
name|SimQFrozen
decl_stmt|;
comment|// simq frozen state
name|U32
name|devq_flag
decl_stmt|;
comment|//device busy flag
name|U32
name|dev_scan
decl_stmt|;
comment|//device ready
name|pccb_t
name|ccbSendHead
decl_stmt|;
comment|// CCB send list head
name|pccb_t
name|ccbSendTail
decl_stmt|;
comment|// CCB send list tail
name|pccb_t
name|ccbDoneHead
decl_stmt|;
comment|// CCB done list head
name|pccb_t
name|ccbDoneTail
decl_stmt|;
comment|// CCB done list tail
name|pccb_t
name|smpSendHead
decl_stmt|;
comment|// CCB send list head
name|pccb_t
name|smpSendTail
decl_stmt|;
comment|// CCB send list tail
name|pccb_t
name|smpDoneHead
decl_stmt|;
comment|// CCB done list head
name|pccb_t
name|smpDoneTail
decl_stmt|;
comment|// CCB done list tail
name|caddr_t
modifier|*
name|ccbChainList
decl_stmt|;
comment|// ccb chain list head
name|caddr_t
modifier|*
name|ccbFreeList
decl_stmt|;
comment|// free ccb list head
name|ccb_hdr_t
modifier|*
name|ccbAllocList
decl_stmt|;
comment|// ### ccb allocation chain list head
name|struct
name|pci_pool
modifier|*
name|sglPool
decl_stmt|;
comment|// for SGL pci_alloc_consistent
name|struct
name|timer_list
name|osTimerList
decl_stmt|;
comment|// card timer list
ifdef|#
directive|ifdef
name|TD_TIMER
name|struct
name|timer_list
name|tdTimerList
decl_stmt|;
comment|// tdlayer timer list
endif|#
directive|endif
name|struct
name|timer_list
name|tiTimerList
decl_stmt|;
comment|// tilayer timer list
name|ag_portal_data_t
modifier|*
name|pPortalData
decl_stmt|;
comment|// wrapper
name|ag_card_info_t
modifier|*
name|pCardInfo
decl_stmt|;
name|ag_device_t
modifier|*
name|pDevList
decl_stmt|;
define|#
directive|define
name|CIPHER_MODE_INVALID
value|0xffffffffUL
define|#
directive|define
name|DEK_INDEX_INVALID
value|0xffffffffUL
define|#
directive|define
name|KEK_INDEX_INVALID
value|0xffffffffUL
name|int
name|encrypt
decl_stmt|;
comment|// enable/disable encryption flag
name|bit32
name|dek_size
decl_stmt|;
comment|// size of dek
name|void
modifier|*
name|ioctl_data
decl_stmt|;
comment|// encryption ioctl data pointer
name|struct
name|list_head
modifier|*
name|encrypt_map
decl_stmt|;
comment|// encryption map
name|ag_kek_table_t
name|kek_table
index|[
name|KEK_TABLE_MAX_ENTRY
index|]
decl_stmt|;
comment|// KEK table
name|ag_dek_kek_map_t
name|dek_kek_map
index|[
name|DEK_MAX_TABLES
index|]
index|[
name|DEK_MAX_TABLE_ITEMS
index|]
decl_stmt|;
comment|// storage for dek index in tables (sysfs)
name|int
name|dek_index
index|[
literal|2
index|]
decl_stmt|;
define|#
directive|define
name|DEK_SIZE_PLAIN
value|72
define|#
directive|define
name|DEK_SIZE_ENCRYPT
value|80
define|#
directive|define
name|ENCRYPTION_MAP_MEMPOOL_SIZE
value|64
name|char
name|map_cache_name
index|[
literal|32
index|]
decl_stmt|;
comment|// name of mapping memory pool
name|struct
name|kmem_cache
modifier|*
name|map_cache
decl_stmt|;
comment|// handle to mapping cache
name|bit32
name|cipher_mode
decl_stmt|;
comment|// storage of cipher mode
define|#
directive|define
name|ENCRYPTION_IO_ERR_MEMPOOL_SIZE
value|256
name|struct
name|mtx
name|ioerr_queue_lock
decl_stmt|;
name|char
name|ioerr_cache_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|kmem_cache
modifier|*
name|ioerr_cache
decl_stmt|;
comment|// handle to IO error cache
comment|//#ifdef LINUX_PERBI_SUPPORT
name|ag_tgt_map_t
modifier|*
name|pWWNList
decl_stmt|;
name|ag_slr_map_t
modifier|*
name|pSLRList
decl_stmt|;
comment|// SAS Local/Remote map list
name|U32
name|numTgtHardMapped
decl_stmt|;
comment|// hard mapped target number
comment|//#endif
name|struct
name|sema
modifier|*
name|pIoctlSem
decl_stmt|;
comment|// for ioctl sync.
name|U32_64
name|osLockFlag
decl_stmt|;
comment|// flag for oslayer spin lock TBU
ifdef|#
directive|ifdef
name|AGTIAPI_LOCAL_LOCK
name|struct
name|mtx
name|sendLock
decl_stmt|;
comment|// local queue lock
name|struct
name|mtx
name|doneLock
decl_stmt|;
comment|// local queue lock
name|struct
name|mtx
name|sendSMPLock
decl_stmt|;
comment|// local queue lock
name|struct
name|mtx
name|doneSMPLock
decl_stmt|;
comment|// local queue lock
name|struct
name|mtx
name|ccbLock
decl_stmt|;
comment|// ccb list lock
name|struct
name|mtx
modifier|*
name|STLock
decl_stmt|;
comment|// Low Level& TD locks
name|unsigned
name|long
modifier|*
name|STLockFlags
decl_stmt|;
comment|// Low Level& TD locks flags
name|struct
name|mtx
name|memLock
decl_stmt|;
comment|// dynamic memory allocation lock
name|struct
name|mtx
name|freezeLock
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AGTIAPI_DPC
comment|// card deferred intr process tasklet
name|struct
name|callout
name|tasklet_dpc
index|[
name|MAX_MSIX_NUM_DPC
index|]
decl_stmt|;
endif|#
directive|endif
comment|//#ifdef HOTPLUG_SUPPORT
name|struct
name|mtx
name|devListLock
decl_stmt|;
comment|// device lists lock
comment|//#endif
block|}
struct|;
end_struct

begin_function_decl
name|int
name|agtiapi_getdevlist
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|,
name|tiIOCTLPayload_t
modifier|*
name|agIOCTLPayload
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agtiapi_getCardInfo
parameter_list|(
name|struct
name|agtiapi_softc
modifier|*
name|pCard
parameter_list|,
name|U32_64
name|size
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_PERBI_SUPPORT
end_ifndef

begin_define
define|#
directive|define
name|INDEX
parameter_list|(
name|_pCard
parameter_list|,
name|_T
parameter_list|)
value|(_T)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INDEX
parameter_list|(
name|_pCard
parameter_list|,
name|_T
parameter_list|)
value|(((_pCard)->pWWNList + (_T))->devListIndex)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

